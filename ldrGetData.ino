int ldr = A0; // Atribui A0 à variável ldr
int valorldr = 0; // Declara a variável valorldr como inteiro
int valoresLDR[48]; // Declara um vetor de 48 posições para armazenar os valores do LDR
int indice; // Variável para controlar o índice do vetor

void setup() {
  pinMode(ldr, INPUT); // Define ldr (pino analógico A0) como entrada
  Serial.begin(9600); // Inicializa a comunicação serial, com taxa de transferência de 9600
  Serial.println("Começou!");
  indice = 0;
}

void loop() {
  // Lê o valor do sensor LDR e armazena no vetor
    Serial.println("Começou o loop!"); // Imprime mensagem de início

  valorldr = analogRead(ldr);
  valoresLDR[indice] = valorldr;
  if(indice < 48){
    indice++;
  }else{
    delay(1000000000000000000000000000000000000000000000);
  }
  
  
    Serial.println("Valores lidos pelo LDR:");
    for (int i = 0; i < 48; i++) {
      Serial.print("Valor ");
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.println(valoresLDR[i]);
    }

  
  delay(5000); // Delay de 5 segundos
}