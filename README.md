# Minerva Rockets - PS 2021.2 - Desafios de programação
_Por Gabriel Aleksandravicius | Gerente da Aviônica, Minerva Rockets_

Na 3a semana da capacitação foi atribuída aos trainees da aviônica uma série de desafios de programação. O objetivo disso foi apresentar a IDE do VS Code, mostrar como fazemos para programar microcontroladores e destrinchar alguns conceitos básicos de C++ e Arduino, 

Abaixo estão listados os conceitos que foram apresentados e desenvolvidos neste dia de capacitação:
- VS Code:
    - Uso do VS Code: navegação, extensões, personalização de configurações e keybindings
    - Uso do PlatformIO: criação de projetos, importação de bibliotecas, compilação, upload

<br>

- 1-blink:
    - Explicação da necessidade do '#include <Arduino.h>'
    - Apresentação do setup() e loop()
    - Criando variáveis para pinos do Arduino
    - Apresentação do dado tipo 'byte'
    - Usando variáveis como argumento de funções
    - Constantes OUTPUT, HIGH, LOW
    - Funções pinMode(), digitalWrite() e delay()

<br>

- 2-blink_diff_freq:
    - Apresentação do problema do uso da função delay()
    - Uso de 'unsigned long' para variáveis que lidam com o tempo
    - Apresentação da função millis()
    - Como executar trechos de código de forma intervalada sem o uso da função delay()

<br>

- 2.1-blink_diff_freq_multiple:
    - Apresentação dos problemas existentes no último arquivo:
        - 1 - Repetição de código
        - 2 - Hardcode (mistura de dados com programa). 
    - Apresentação das soluções:
        - 1 - Tornar o programa o mais genérico possível
        - 2 - Separar dados em um arquivo de configuração separado (nestes exemplos trabalhamos definindo as constantes no início do arquivo)
    - Explicação de structs
    - Como criar um array contendo structs
    - Como acessar elementos de um array
    - Como acessar e mudar os valores de elementos de um struct
    - Como alterar o valor de uma variável booleana sem usar 'if'
    - Alteração de '(intervalLed/2)' pra 1000/(leds[i].frequency*2), já que nos interessa mais definir a frequência do que o intervalo

<br>

- 3-inatest:
    - Como baixar uma biblioteca do INA no PlatformIO e incluí-la no arquivo
    - Criando objetos da classe do sensor
    - Inicializando o sensor
    - Acessandos os valores de leitura do sensor através de funções da biblioteca
    - Printando os valores

<br>

- 3.1-inafunctions:
    - Criando funções para lidar com:
        - Inicialização do sensor
        - Update dos valores lidos
        - Print dos dados

<br>

- 4-bmptest:
    - Como baixar uma biblioteca do BMP280 no PlatformIO e incluí-la no arquivo
    - Criando objetos da classe do sensor
    - Inicializando o sensor
    - Acessandos os valores de leitura do sensor através de funções da biblioteca
    - Printando os valores

<br>

- 4.1-bmpfunctions:
    - Criação de funções para lidar com:
        - Inicialização e configuração do sensor
        - Update dos valores lidos
        - Print dos dados
    - Criação de constantes com #define

<br>

- 5-multiple_sensors:
    - Reunião das bibliotecas e funções feitas pro BMP e pro INA em um único arquivo
    - Criação de um struct para lidar com as variáveis de tempo usadas para printar os dados de cada sensor
    - Definição de constantes de frequência para cada sensor
    - Criação de funções que operam utilizando as funções previamente criadas:
        - Criação da função printData(), que usa updateIna(), updateBmp(), printDataIna() e printDataBmp(). Faz o update dos dados do sensores e os printa na tela. Cada sensor possui uma frequência de leitura diferente, portanto usamos o mesmo conceito de millis() visto no arquivo 2.1.
        - Criação da função initSystem(), que usa initIna() e initBmp(). Explicação do por que isso é interessante.

<br>

- 6-sdtest_setup:
    - Apresentação da biblioteca 'SD':
        - Inicialização do módulo do cartão SD
        - Criação de arquivo
        - Apresentação da constante FILE_WRITE
        - Escrita de dados no arquivo criado
        - Salvamento dos dados
        - Diferença entre close() e flush()
    - Escrita de arquivos no setup()

<br>

- 7-sdtest_loop:
    - Escrita de arquivos no loop()

<br>

- 8-sd_functions:
    - Criação de funções para as operações do SD
    - Criação de constantes para pinos
    - Explicação do por que é interessante criarmos funções que operam em cima de funções das biblitecas

<br>

- 9-sd_single_file:
    - Reunião do conteúdo do arquivo 5 com o arquivo 8
    - Salvamento dos dados de leitura em um arquivo "snsrs.txt"