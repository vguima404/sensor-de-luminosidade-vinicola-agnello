int LEDVerde = 10; // Define a variável LEDVerde com o pino digital 10
int LEDAmarelo = 9; // Define a variável LEDAmarelo com o pino digital 9
int LEDVermelho = 8; // Define a variável LEDVermelho com o pino digital 8
int Buzzer = 7; // Define a variável Buzzer com o pino digital 7

void setup(){
  Serial.begin(9600); // Inicia a comunicação serial com a taxa de 9600 bps
  pinMode(Buzzer, OUTPUT); // Configura o pino do Buzzer como saída
  pinMode(LEDVerde, OUTPUT); // Configura o pino do LED verde como saída
  pinMode(LEDAmarelo, OUTPUT); // Configura o pino do LED amarelo como saída
  pinMode(LEDVermelho, OUTPUT); // Configura o pino do LED vermelho como saída
}

void loop(){
  int LDR = analogRead(A0); // Lê o valor do sensor LDR conectado na porta analógica A0
  Serial.println(LDR); // Mostra o valor lido do LDR no monitor serial

  // Utiliza um switch para verificar em qual faixa de luminosidade está o valor lido do LDR
  switch(LDR){
    
    case 0 ... 10: // Caso o valor do LDR esteja entre 0 e 700 (ambiente escuro)
      digitalWrite(LEDVerde, HIGH); // Acende o LED verde
      digitalWrite(LEDAmarelo, LOW); // Apaga o LED amarelo
      digitalWrite(LEDVermelho, LOW); // Apaga o LED vermelho
      digitalWrite(Buzzer, LOW); // Desliga o buzzer
      break;
    
    case 11 ... 20: // Caso o valor do LDR esteja entre 701 e 950 (luminosidade média)
  	  digitalWrite(LEDVerde, LOW); // Apaga o LED verde
      digitalWrite(LEDAmarelo, HIGH); // Acende o LED amarelo
      digitalWrite(LEDVermelho, LOW); // Apaga o LED vermelho
      tone(Buzzer, 250); // Toca uma nota de 250 Hz no buzzer
      delay(3000); // Mantém o som por 3 segundos
      noTone(Buzzer); // Para de emitir o som no buzzer
      delay(300); // Espera 300 milissegundos antes de continuar
      break;
    
    case 21 ... 1023: // Caso o valor do LDR esteja entre 951 e 1023 (ambiente muito claro)
      digitalWrite(LEDVerde, LOW); // Apaga o LED verde
      digitalWrite(LEDAmarelo, LOW); // Apaga o LED amarelo
      digitalWrite(LEDVermelho, HIGH); // Acende o LED vermelho
      tone(Buzzer, 250); // Toca uma nota de 250 Hz no buzzer
      delay(3000); // Mantém o som por 3 segundos
      noTone(Buzzer); // Para de emitir o som no buzzer
      delay(300); // Espera 300 milissegundos antes de continuar
      break;
  }
}
