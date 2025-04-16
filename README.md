# 🌞 Sensor de Luminosidade com Alerta Visual e Sonoro para Vinícola

Este projeto tem como objetivo proteger garrafas de vinho armazenadas em uma vinícola contra a exposição excessiva à luz. Utilizando um sensor de luminosidade (LDR), três LEDs (verde, amarelo e vermelho) e um buzzer, o sistema sinaliza em tempo real o nível de iluminação incidente sobre as garrafas. Quando a luminosidade ultrapassa do nível de alerta (701), o LED amarelo acende e um buzzer é ativado como alerta sonoro.

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
- IDE do Arduino (https://www.arduino.cc/en/software/) ou TinkerCard (www.tinkercad.com)
- Placa Arduino configurada e drivers instalados

## 🛠️ Como Reproduzir

1. **Monte o circuito**:
   - LDR entre A0 e VCC.
   - Resistor de 10kΩ entre A0 e GND.
   - LEDs conectados aos pinos digitais 10 (verde), 9 (amarelo) e 8 (vermelho), com resistores limitadores.
   - Buzzer conectado ao pino 7 (positivo) e GND (negativo).

2. **Conecte o Arduino ao computador** via cabo USB.

3. **Abra a IDE do Arduino**, selecione a placa correta e a porta COM usada.

4. **Copie o código abaixo** para a IDE:

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

5. **Envie o código para o Arduino** clicando em "Upload".

6. **Abra o Monitor Serial** para observar os valores do LDR e testar os diferentes níveis de luminosidade.

## ⚠️ Dificuldades Encontradas

Durante o desenvolvimento do projeto, algumas dificuldades foram enfrentadas:

- **Manipulação da frequência do buzzer**: Entender como controlar o som emitido pelo buzzer com a função `tone()` exigiu muitos testes e pesquisa. Foi necessário ajustar o tempo de execução e a frequência para que o alarme não se tornasse contínuo ou irritante.
- **Aprendizado sobre o sensor LDR**: Interpretar corretamente os valores fornecidos e como manipular o LDR levou um certo tempo. Foram realizados vários testes para calibrar os valores ideais de corte entre os LEDs.