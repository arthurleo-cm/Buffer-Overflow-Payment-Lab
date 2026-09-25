#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Função-alvo: autoriza o pagamento e libera o valor. No fluxo normal do programa ela NUNCA é chamada, pois nenhum caminho do código conduz até aqui. O objetivo do atacante é alcançar essa função sobrescrevendo o endereço de retorno da função vulnerável por meio de um buffer overflow. */
void authorize_payment(void)
{
    printf("[A] PAYMENT AUTHORIZED. Funds released to the attacker.\n");
    exit(0);
}

/* Copia o identificador da transação para um vetor local de tamanho fixo SEM verificar se ele cabe. Nisto reside a vulnerabilidade. */
void process_transaction(char *transaction_id)
{
    char received_id[16];
    strcpy(received_id, transaction_id);   /* vulnerável: não verifica o tamanho */
    printf("[A] Transaction received: %s\n", received_id);
    /* retorna normalmente para a main, sem autorizar pagamento algum */
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <transaction_id>\n", argv[0]);
        return 1;
    }
    process_transaction(argv[1]);
    printf("[A] Transaction processed. No payment was authorized.\n");
    return 0;
}
