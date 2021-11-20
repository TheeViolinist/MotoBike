#define BOTAO_ESQUERDO 13
#define BOTAO_DIREITO 7
#define LED 2 //Definição da porta em que está conectado o pino do primeiro Led
#define BLED 5//Definiçaõ da porta em que está conectado o pino do Segundo Led
#define tLED 6//Definiçaõ da porta em que está conectado o pino do terceiro Led
#define qLED 9//Definiçaõ da porta em que está conectado o pino do quarto Led
#define cLED 8//Definiçaõ da porta em que está conectado o pino do quinto Led
#define BOTAOA 3 // Definição da porta em que está conectado o botão do freio dianteiro
#define BOTAOB 4 // Definição da porta em que está conectado o botão do freio traseiro
#define BOTAO  11  

int estadoA; // Variáveis globais para os botões
int estadoB;

unsigned long tempoAtual;
unsigned long tempoAuxiliar;
int estadoDoBotaoEsquerdo;
int estadoDoBotaoDireito;
int auxiliar = 1;

void setup(){
  Serial.begin(9600);
  pinMode(BOTAO_ESQUERDO, INPUT);
  pinMode(BOTAO_DIREITO, INPUT);
  pinMode(LED, OUTPUT); // Modo de leitura do led, Output = saída
  pinMode(BLED, OUTPUT); // Modo de leitura do led, Output = saída
  pinMode(tLED, OUTPUT); // Modo de leitura do led, Output = saída
  pinMode(qLED, OUTPUT); // Modo de leitura do led, Output = saída
  pinMode(cLED, OUTPUT); // Modo de leitura do led, Output = saída
  pinMode(BOTAOA, INPUT); // Modo de leitura do botão A, Input = entrada
  pinMode(BOTAOB, INPUT); // Modo de leitura do botão B, Input = entrada
  pinMode(BOTAO, INPUT);
}

void loop(){
  tempoAtual = millis();
  estadoDoBotaoEsquerdo = digitalRead(BOTAO_ESQUERDO);
  estadoDoBotaoDireito = digitalRead(BOTAO_DIREITO);
  
  if(tempoAtual-2000 >= tempoAuxiliar){
    auxiliar = 1;
  }
  if(estadoDoBotaoEsquerdo && auxiliar){
    Serial.write("Seta Esquerda\n");
    tempoAuxiliar = tempoAtual;
    auxiliar = 0;
  }
  if(estadoDoBotaoDireito && auxiliar){
      Serial.write("Seta Direita\n");
    tempoAuxiliar = tempoAtual;
    auxiliar = 0;
  }
  estadoA = digitalRead(BOTAOA); // Leitura para identificação do estado dos botões, se estão recebendo energia ou não
  estadoB = digitalRead(BOTAOB);

  //As linhas de código abaixo são para quando os botões 
  //acionados, todos os leds conectados ao circuito acendam
 // independentemente do botão ser o direito ou esquerdo, todos os leds ficarão acessos!
   digitalWrite(LED, estadoA); 
   digitalWrite(LED, estadoB);
   digitalWrite(BLED, estadoA); 
   digitalWrite(BLED, estadoB);
   digitalWrite(tLED, estadoA);
   digitalWrite(tLED, estadoB); 
   digitalWrite(qLED, estadoA); 
   digitalWrite(qLED, estadoB); 
   digitalWrite(cLED, estadoA); 
   digitalWrite(cLED, estadoB);
  
  
  int estadoBotao = digitalRead(BOTAO);
  switch (estadoBotao)
{
   case HIGH:
    Serial.println("A");
   break;

   case LOW:
      Serial.println("a");
   break;

   default:
   break; 
}
  
}
