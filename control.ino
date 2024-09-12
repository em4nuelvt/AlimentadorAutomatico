const int ldr = A0; // Pino do sensor LDR
const int relePin = 2;  // Pino de controle do relé

int valorldr = 0; // Declara a variável valorldr como inteiro
int valoresLDR[3]; // Declara um vetor de 3 posições para armazenar os valores do LDR
int indice; // Variável para controlar o índice do vetor
int media = 0;// Variável para calcular a média do valor obtido pelo sensor de luminosidade

unsigned long releStartTime = 0;  // Marca o tempo de ativação do relé
unsigned long lastMotorActivationTime = 0;  // Marca a última vez que o motor foi ativado
const unsigned long motorInterval = 10L * 60L * 60L * 1000L; // 10 horas em milissegundos
const unsigned long motorDuration = 20000; // Motor ligado por 30 segundos
bool releOn = false;

void setup() {
  pinMode(ldr, INPUT); // Define ldr (pino analógico A0) como entrada
  pinMode(relePin, OUTPUT);  // Configura o pino do relé como saída
  Serial.begin(9600); // Inicializa a comunicação serial
  Serial.println("Começou!");
  digitalWrite(relePin, LOW); // Garante que o relé comece desligado
  indice = 0;
}

void loop() {
  unsigned long currentTime = millis();  // Pega o tempo atual

  // Lê o valor do sensor LDR e armazena no vetor a cada 1 segundo
  if (currentTime - releStartTime >= 1000) {
    valorldr = analogRead(ldr);
    valoresLDR[indice] = valorldr;

    Serial.print("Leitura do LDR: ");
    Serial.println(valoresLDR[indice]);

    if (indice == 2) {
      // Calcula a média dos valores do LDR
      media=0
      for (int i = 0; i <= 2; i++) {
        media += valoresLDR[i];
      }
      media /= 3;
      Serial.print("Média do LDR: ");
      Serial.println(media);
      
      indice = 0; // Reinicia o índice para novas leituras

      // Verifica se a média da luminosidade é maior que 50 e se já passaram 10 horas
      
    } else {
      indice++;  // Incrementa o índice para a próxima leitura
    }
    if (media > 50 && (currentTime - lastMotorActivationTime >= motorInterval)) {
        digitalWrite(relePin, HIGH);  // Liga o motor
        releOn = true;
        releStartTime = currentTime;  // Atualiza o tempo de início do motor
        lastMotorActivationTime = currentTime;  // Marca o tempo da última ativação
        Serial.println("Motor acionado.");
      }
  }

  // Verifica se o motor já ficou ligado por 30 segundos
  if (releOn && (currentTime - releStartTime >= motorDuration)) {
    digitalWrite(relePin, LOW);  // Desliga o motor
    releOn = false;
    Serial.println("Motor desligado.");
  }
}
