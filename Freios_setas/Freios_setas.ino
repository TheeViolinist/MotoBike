#define SETA_ESQUERDA 13
#define SETA_DIREITA 7

#define LED 2 //Definição da porta em que está conectado o pino do primeiro Led
#define BLED 5//Definiçaõ da porta em que está conectado o pino do Segundo Led
#define tLED 6//Definiçaõ da porta em que está conectado o pino do terceiro Led
#define qLED 7//Definiçaõ da porta em que está conectado o pino do quarto Led
#define cLED 8//Definiçaõ da porta em que está conectado o pino do quinto Led
#define BOTAOA 3 // Definição da porta em que está conectado o botão do freio dianteiro
#define BOTAOB 4 // Definição da porta em que está conectado o botão do freio traseiro

int estadoA; // Variáveis globais para os botões
int estadoB;

String mensagem;
unsigned long int tempoAtual;
unsigned long int tempoAuxEsquerdo;
unsigned long int tempoAuxDireito;
bool estadoDaSetaEsquerda = 0;
bool estadoDaSetaDireita = 0;

void setup(){
  pinMode(SETA_ESQUERDA, OUTPUT);
  pinMode(SETA_DIREITA, OUTPUT);
  pinMode(LED, OUTPUT); // Modo de leitura do led, Output = saída
  pinMode(BLED, OUTPUT); // Modo de leitura do led, Output = saída
  pinMode(tLED, OUTPUT); // Modo de leitura do led, Output = saída
  pinMode(qLED, OUTPUT); // Modo de leitura do led, Output = saída
  pinMode(cLED, OUTPUT); // Modo de leitura do led, Output = saída
  pinMode(BOTAOA, INPUT); // Modo de leitura do botão A, Input = entrada
  pinMode(BOTAOB, INPUT); // Modo de leitura do botão B, Input = entrada
  Serial.begin(9600);
}

void SetaDireita(unsigned long int tempo, unsigned long int *comparacao){
  if(tempo - *comparacao == 200){
      digitalWrite(SETA_DIREITA, !digitalRead(SETA_DIREITA));
    *comparacao = millis();
  }
}

void SetaEsquerda(unsigned long int tempo, unsigned long int *comparacao){
  if(tempo - *comparacao == 200){
      digitalWrite(SETA_ESQUERDA, !digitalRead(SETA_ESQUERDA));
    *comparacao = millis();
  }
}

void loop(){
  tempoAtual = millis();
  
  if(Serial.available() > 0){
    mensagem = Serial.readStringUntil('\n');
    
    if(mensagem == "Seta Esquerda"){
      estadoDaSetaEsquerda = !estadoDaSetaEsquerda;
      tempoAuxEsquerdo = tempoAtual;
    }
    if(mensagem == "Seta Direita"){
      estadoDaSetaDireita = !estadoDaSetaDireita;
      tempoAuxDireito = tempoAtual;
    }
  }
  
  if(estadoDaSetaEsquerda){
    SetaEsquerda(tempoAtual, &tempoAuxEsquerdo);
  }else{
    digitalWrite(SETA_ESQUERDA, LOW);
  }
  if(estadoDaSetaDireita){
    SetaDireita(tempoAtual, &tempoAuxDireito);
  }else{
    digitalWrite(SETA_DIREITA, LOW);
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
}
