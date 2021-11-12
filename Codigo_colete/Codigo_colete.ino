#define SETA_ESQUERDA 13
#define SETA_DIREITA 7

String mensagem;
unsigned long int tempoAtual;
unsigned long int tempoAuxEsquerdo;
unsigned long int tempoAuxDireito;
bool estadoDaSetaEsquerda = 0;
bool estadoDaSetaDireita = 0;

void setup(){
  pinMode(SETA_ESQUERDA, OUTPUT);
  pinMode(SETA_DIREITA, OUTPUT);
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

  /*  Begin Renata  */
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
  /*  End Renata  */

  

  
}
