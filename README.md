# 🌞 Sensor de Luminosidade com Alerta Visual e Sonoro para Vinícola

Este projeto tem como objetivo proteger garrafas de vinho armazenadas em uma vinícola contra a exposição excessiva à luz. Utilizando um sensor de luminosidade (LDR), três LEDs (verde, amarelo e vermelho) e um buzzer, o sistema sinaliza em tempo real o nível de iluminação incidente sobre as garrafas. Quando a luminosidade ultrapassa um valor de alerta (701), o LED vermelho amarelo e um buzzer é ativado como alerta sonoro.

### 👥 Participantes
- Felipe Godoi
- Guilherme Augusto
- Raphael Taketa
- Victor Guimarães

## 📦 Descrição do Projeto

O funcionamento do sistema se baseia na leitura dos valores de luz captados pelo LDR (Light Dependent Resistor). Esses valores variam de 0 a 1023, sendo que:

- **0 a 700**: iluminação adequada (LED verde aceso)
- **701 a 950**: alerta de atenção (LED amarelo e buzzer ativados)
- **951 a 1023**: iluminação crítica (LED vermelho e buzzer ativados)

Este sistema é ideal para ambientes de armazenamento sensível, como adegas e vinícolas, onde o controle da luminosidade é essencial para manter a qualidade do produto.

## 📚 Dependências

### 🧰 Materiais
- 1x Arduino Uno
- 1x Sensor LDR
- 3x LEDs (verde, amarelo, vermelho)
- 3x Resistores para LEDs (220Ω)
- 1x Resistor para o LDR (10kΩ)
- 1x Buzzer
- Cabos jumpers
- Protoboard

### 💻 Software
- IDE do Arduino → [Download](https://www.arduino.cc/en/software)

ou

- Utilização do simulador no Tinkercard → [Site do Tinkercard](https://www.tinkercad.com)

## 🛠️ Como Reproduzir

1. **Monte o circuito:**
   - Conecte o **LDR entre GND e A0**.
   - Conecte um **resistor de 10kΩ entre A0 e 5V (VCC)**.
   - Conecte os LEDs nos pinos 10 (verde), 9 (amarelo) e 8 (vermelho) com resistores.
   - Conecte o buzzer no pino 7 e GND.

2. **Abra a IDE do Arduino** e conecte o Arduino via cabo USB.

3. **Copie o código abaixo para a IDE:**

```cpp
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
    
    case 0 ... 700: // Caso o valor do LDR esteja entre 0 e 700 (ambiente escuro)
      digitalWrite(LEDVerde, HIGH); // Acende o LED verde
      digitalWrite(LEDAmarelo, LOW); // Apaga o LED amarelo
      digitalWrite(LEDVermelho, LOW); // Apaga o LED vermelho
      digitalWrite(Buzzer, LOW); // Desliga o buzzer
      break;
    
    case 701 ... 950: // Caso o valor do LDR esteja entre 701 e 950 (luminosidade média)
  	  digitalWrite(LEDVerde, LOW); // Apaga o LED verde
      digitalWrite(LEDAmarelo, HIGH); // Acende o LED amarelo
      digitalWrite(LEDVermelho, LOW); // Apaga o LED vermelho
      tone(Buzzer, 250); // Toca uma nota de 250 Hz no buzzer
      delay(3000); // Mantém o som por 3 segundos
      noTone(Buzzer); // Para de emitir o som no buzzer
      delay(300); // Espera 300 milissegundos antes de continuar
      break;
    
    case 951 ... 1023: // Caso o valor do LDR esteja entre 951 e 1023 (ambiente muito claro)
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
```

4. **Clique em “Upload” para enviar o código.**

5. **Abra o Monitor Serial** (Ctrl+Shift+M) para visualizar os dados do sensor.

## ⚠️ Dificuldades Encontradas

Durante o desenvolvimento, enfrentamos alguns desafios:

- **Manipular a frequência do buzzer:** foi necessário entender como a função `tone()` funciona para não deixar o som incômodo e para ter a duração de 3 segundos.
- **Aprender sobre o LDR:** interpretar os valores lidos pelo sensor e aprender a manipulá-los exigiu muitos testes, foram realizadas pesquisas através de vídeos e documentação.

## 📽️ Demonstração

- ▶️ [Vídeo no YouTube](https://youtu.be/0kUGRKxl1lo)
- 💻 [Simulação no Tinkercad](https://www.tinkercad.com/things/gdHTAxjC7YB-fantastic-inari-snaget/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=jaI-__Ze8QaAmT90-9VHP9olcMvoVjhQlYrbrBaEM-A)