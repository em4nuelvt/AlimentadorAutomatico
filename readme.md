# Projeto de Alimentador Automático para Pets

## Disciplinas
- Sinais e Sistemas Lineares
- Eletrônica
- Microcontroladores/Microprocessadores

## Arquivos

### ldrGetData.ino
- **Descrição**: Código Arduino para obter os valores de luminosidade do sensor LDR ao longo de 24 horas.
- **Detalhes**: Coleta amostras a cada 30 minutos.

### ldrRegression.ipynb
- **Descrição**: Código Python para tratar os dados obtidos após a coleta de amostras.
- **Detalhes**: Realiza regressão dos dados e aplica a Transformada de Fourier.

### control.ino
- **Descrição**: Código de controle do acionamento do motor do alimentador.
- **Detalhes**: Aciona o motor nos tempos especificados e de acordo com os dados coletados em tempo real com o sensor LDR.


## Vídeo do Projeto Funcionando

O projeto do alimentador automático funciona com o acionamento do motor para liberação de comida por 20 segundos em um intervalo de 10 horas. Ou seja, a cada 10 horas o motor é acionado e o alimento é liberado para o animal. Dessa forma, o alimentador tem o motor acionado duas vezes ao dia no período diurno. 
Entretanto, para exemplificar o funcionamento em vídeo, foi necessário limitar o tempo em que o motor fica em repouso. Dessa forma, ao invés de permanecer desligado pelo intervalo de 10 horas, o tempo foi reduzido para 10 segundos. Portanto, no vídeo apresentado obtemos o acionamento por 20 segundos do motor a cada 10 segundos de repouso.


[Assista ao vídeo do projeto](https://youtu.be/W1JV-Qg_nB8)

Este vídeo mostra o funcionamento do alimentador automático para animais de estimação. O sistema é composto por um Arduino Uno, uma fonte de alimentação e um relé, que controlam o motor do alimentador. O projeto foi configurado para alimentar um cão com aproximadamente 140g de ração duas vezes ao dia. Para garantir que o motor seja acionado apenas durante o dia, utilizamos um sensor LDR (Light Dependent Resistor).

No vídeo, o tempo de operação do motor e o intervalo entre os acionamentos foram reduzidos para uma demonstração mais clara e simplificada. O motor é acionado por 20 segundos, tempo calculado para dispensar 140g de ração em um intervalo de 10 horas entre os acionamentos. A visualização em tempo reduzido facilita a compreensão do funcionamento do sistema.
