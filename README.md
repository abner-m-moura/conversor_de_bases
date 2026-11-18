# Conversor de Bases Numéricas

Este é um programa em C++ que converte números entre diferentes sistemas de numeração: binário, octal, decimal, duodecimal e hexadecimal.

## Como funciona

O programa pede ao usuário três informações:

1. A base em que o número está (base de origem)
2. A base para a qual ele quer converter (base de destino)
3. O número

Para fazer a conversão, o programa usa o sistema decimal como **ponte**:


#### base de origem  →  decimal  →  base de destino



Por exemplo, para converter 1A (hexadecimal) para binário, o programa primeiro descobre que 1A vale 26 no sistema decimal e depois transforma o 26 em 11010.

### As partes do programa

 Tabela de símbolos:
  o programa guarda a sequência **0123456789ABCDEF**. A posição de cada símbolo nessa sequência é o seu valor. Assim, A vale 10, B vale 11, e assim por diante.

 Da base de origem para o decimal:
  o programa lê o número da esquerda para a direita. A cada dígito, multiplica o que já tinha pela base e soma o valor do novo dígito.
  
#### Exemplo com 1A na base 16:
  - Primeiro dígito: 1
  - Segundo dígito: 1 × 16 + 10 = 26

 Do decimal para a base de destino: 
  o programa divide o número pela base de destino várias vezes, até chegar a zero. Os restos dessas divisões são os dígitos do resultado, lidos de trás para frente.
  
#### Exemplo com 26 para a base 2:

**|   Divisão   | Resto |**

*| 26 ÷ 2 = 13 | 0 |*

*| 13 ÷ 2 = 6  | 1 |*

*| 6 ÷ 2 = 3   | 0 |*
   
*| 3 ÷ 2 = 1   | 1 |*
  
*| 1 ÷ 2 = 0   | 1 |*

Lendo os restos de baixo para cima, o resultado é **11010**.

### Como usar

Compile e execute o programa:

*g++ conversor.cpp -o conversor.exe*

*./conversor*


### Exemplo de uso:

*Bases disponíveis: 2, 8, 10, 12, 16*

*Base de origem: 16*

*Base de destino: 2*

*Numero (inserir letras em maiúsculo): 1A*

*Resultado: 11010**


## Observações
- As letras devem ser digitadas em maiúsculo (por exemplo, 1A e não 1a).
- O programa não avisa se o número digitado não existe na base escolhida (por exemplo, o dígito 9 na base 8).
- Ele funciona apenas com números inteiros positivos e não é indicado para números muito grandes.
