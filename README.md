# Buffer-Overflow-Payment-Lab
Laboratório acadêmico de segurança demonstrando corrupção de memória e desvio de fluxo em um programa vulnerável.


# Buffer Overflow Payment Lab

Laboratório acadêmico de Cibersegurança desenvolvido para estudar
corrupção de memória, organização da pilha e desvio de fluxo de execução.

## Objetivo

Demonstrar, em um ambiente controlado, como uma vulnerabilidade de
buffer overflow pode modificar dados armazenados na stack e alterar
o fluxo de execução de um programa.

O laboratório utiliza dois programas:

- `payment_server.c` — programa vulnerável utilizado no experimento.
- `attacker.c` — programa desenvolvido para demonstrar o desvio
  controlado de execução.

## Conceitos estudados

- Buffer overflow
- Stack frame
- Stack pointer e base pointer
- Endereço de retorno
- Corrupção de memória
- Desvio de fluxo de execução
- Stack canaries
- GDB
- Compilação de programas C
- Mitigações contra corrupção de memória

## Ambiente

- Linux
- GCC
- GDB
- Linguagem C
