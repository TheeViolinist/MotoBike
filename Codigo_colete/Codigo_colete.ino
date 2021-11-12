

/* begin Marllon  */ 
#include <Adafruit_NeoPixel.h> 
 #ifdef __AVR__  
  #include <avr/power.h>  
 #endif  
   
 
 int LED = 6;
 
 #define NUMPIXELS   15
   
   
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED, NEO_GRB + NEO_KHZ800); 
/* End marlon */

/* begin Renata  */
#define SETA_ESQUERDA 13
#define SETA_DIREITA 7

/* End Renata  */



/*  Begin Renata  */
String mensagem;
unsigned long int tempoAtual;
unsigned long int tempoAuxEsquerdo;
unsigned long int tempoAuxDireito;
bool estadoDaSetaEsquerda = 0;
bool estadoDaSetaDireita = 0;
/* End Renata */

/*  Begin Marllon  */
char B;
 
 int a = 0; 
 int b = 1;  
 int c = 2;
 int d = 3;
 int e = 4;
 int f = 5;
 int g = 6;
 int h = 7;
 int i = 8;
 int j = 9;
 int k = 10;
 int l = 11;
 int m = 12; 
 int n = 13;
 int o = 14;
/*  End Marllon */

void setup(){
  /*  Begin Renata  */
  pinMode(SETA_ESQUERDA, OUTPUT);
  pinMode(SETA_DIREITA, OUTPUT);
  Serial.begin(9600);
  /*  End Renata  */

  /*  Begin Marllon */
  pinMode(LED, OUTPUT);
  pixels.begin();
  /*  End Marllon   */
  
}

/*  Begin Renata  */
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
/*  End Renata  */

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

  /* Begin Marllon  */
    switch (mensagem)
{
 case 'A':
   pixels.setPixelColor(a, pixels.Color(255,0,0));
   pixels.show();   
   
   pixels.setPixelColor(b, pixels.Color(255,0,0));
   pixels.show();   
   
   pixels.setPixelColor(c, pixels.Color(255,0,0));
   pixels.show();   
   
   pixels.setPixelColor(d, pixels.Color(255,0,0));
   pixels.show();   
   
   pixels.setPixelColor(e, pixels.Color(255,0,0));
   pixels.show();   
   
   pixels.setPixelColor(f, pixels.Color(255,0,0));
   pixels.show(); 

   pixels.setPixelColor(g, pixels.Color(255,0,0));
   pixels.show(); 

   pixels.setPixelColor(h, pixels.Color(255,0,0));
   pixels.show(); 

   pixels.setPixelColor(i, pixels.Color(255,0,0));
   pixels.show(); 
   
   pixels.setPixelColor(j, pixels.Color(255,0,0));
   pixels.show(); 

   pixels.setPixelColor(k, pixels.Color(255,0,0));
   pixels.show(); 

   pixels.setPixelColor(l, pixels.Color(255,0,0));
   pixels.show(); 

   pixels.setPixelColor(m, pixels.Color(255,0,0));
   pixels.show();

   pixels.setPixelColor(n, pixels.Color(255,0,0));
   pixels.show();

   pixels.setPixelColor(o, pixels.Color(255,0,0));
   pixels.show();

   break;

   case 'a':
      
   pixels.setPixelColor(a, pixels.Color(0,0,0));
   pixels.show();   
   
   pixels.setPixelColor(b, pixels.Color(0,0,0));
   pixels.show();   
  
   pixels.setPixelColor(c, pixels.Color(0,0,0));
   pixels.show();   
   
   pixels.setPixelColor(d, pixels.Color(0,0,0));
   pixels.show();   
  
   pixels.setPixelColor(e, pixels.Color(0,0,0));
   pixels.show();   
  
   pixels.setPixelColor(f, pixels.Color(0,0,0));
   pixels.show();

   pixels.setPixelColor(g, pixels.Color(0,0,0));
   pixels.show();

   pixels.setPixelColor(h, pixels.Color(0,0,0));
   pixels.show();

   pixels.setPixelColor(i, pixels.Color(0,0,0));
   pixels.show();

   pixels.setPixelColor(j, pixels.Color(0,0,0));
   pixels.show();

   pixels.setPixelColor(k, pixels.Color(0,0,0));
   pixels.show();

   pixels.setPixelColor(l, pixels.Color(0,0,0));
   pixels.show();

   pixels.setPixelColor(m, pixels.Color(0,0,0));
   pixels.show();

   pixels.setPixelColor(n, pixels.Color(0,0,0));
   pixels.show();

   pixels.setPixelColor(o, pixels.Color(0,0,0));
   pixels.show();
   
   break;
}

  
  /*  End Marllon */
 

  
 

  

  
}
