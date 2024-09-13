const int ldr = A0; // pino do sensor LDR
const int relePin = 2;  // pino de controle do relé

int valorldr = 0; 
int valoresLDR[3]; 
int indice; // controlar o índice do vetor
int media = 0;  //media do valor de luminosidade obtido pelo ldr

unsigned long releStartTime = 0;  // marcar o tempo de ativação do relé
unsigned long lastMotorActivationTime = 0;  // marcar a última vez que o motor foi ativado
const unsigned long motorInterval = 10 * 60 * 60 * 1000L; //  10 horas intervalo de ativação
const unsigned long motorDuration = 20000; // motor ligado por 20 segundos
bool releOn = false;

void setup() {
  pinMode(ldr, INPUT); // define ldr pino doldr como entrada
  pinMode(relePin, OUTPUT);  // configura o pino do relé como saída
  Serial.begin(9600); 
  Serial.println("Começou!");
  digitalWrite(relePin, LOW); 
  indice = 0;
}

void loop() {
  unsigned long currentTime = millis(); 

  // le o valor do sensor LDR e armazena no vetor a cada 1 segundo
  if (currentTime - releStartTime >= 1000) {
    valorldr = analogRead(ldr);
    valoresLDR[indice] = valorldr;

    Serial.print("Leitura do LDR: ");
    Serial.println(valoresLDR[indice]);


    if (indice == 2) {      
      media = 0;
      for (int i = 0; i <= 2; i++) {
        media += valoresLDR[i];
      }
      media /= 3;
      Serial.print("Média do LDR: ");
      Serial.println(media);

      indice = 0;
    } else {
      indice++;  
    }

    // acionamento
    if (media > 50 && (currentTime - lastMotorActivationTime >= motorInterval)) {
      digitalWrite(relePin, HIGH);  
      releOn = true;
      releStartTime = currentTime;  // marca o momento em que o motor foi acionado
      lastMotorActivationTime = currentTime;  // atualiza o tempo da última ativação
      Serial.println("Motor acionado.");
    }
  }

  // desacionamento
  if (releOn && (currentTime - releStartTime >= motorDuration)) {
    digitalWrite(relePin, LOW);  
    releOn = false;
    Serial.println("Motor desligado.");
  }
}
