Simulador de ULA com Arduino e LEDs

Este projeto implementa uma simulação de uma Unidade Lógica e Aritmética (ULA) utilizando Arduino e LEDs como forma de exibir os resultados.
A ULA recebe instruções em formato hexadecimal via porta serial, interpreta os operandos e o código de operação (opcode), realiza o cálculo correspondente e acende os LEDs para representar o resultado em binário.

🚀 Funcionalidades

Recebimento de instruções via Serial Monitor no formato XYO, onde:

X → Operando A (hexadecimal de 0 a F)

Y → Operando B (hexadecimal de 0 a F)

O → Opcode que define a operação da ULA

Implementação de operações lógicas e aritméticas básicas, como:

AND, OR, XOR, NOT

Transferência direta de operandos

Operações de negação e combinações bit a bit

Conversão de números hexadecimais para decimais e vice-versa.

Representação visual do resultado em 4 LEDs:

🔴 Vermelho

🟢 Verde

🟡 Amarelo

🔵 Azul

Cada LED acende ou apaga representando um bit do resultado (0 a 15).

🛠️ Tecnologias utilizadas

Arduino (C/C++)

Comunicação Serial

Manipulação de Strings e conversões numéricas

Controle de LEDs digitais
