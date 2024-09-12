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
