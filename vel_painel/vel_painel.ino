//Vamos ligar o TX do bluetooth a porta 10 do arduino//
//Vamos ligar o RX do bluetooth a porta 11 do arduino//
//Lembrar que o TX transmite os dados do bluetooth para a placa
//RX recebe os dados que veem do arduino

#include <SoftwareSerial.h> // Biblioteca para se comunicar com o blueotooth

#include <LiquidCrystal.h> // biblioteca do painel

#define pot A5 // porta de entrada do potenciometro

//Comando cria a comunicação com nome bluetooth
//E atribui os pinos 10 e 11 a ela.O primeiro pino se refere ao RX do arduíno
// E o segundo ao TX do arduino
//Para que haja comunicação serial o RX de um tem que está conectado ao TX do outro
//e o TX de um tem que está conectado ao RX do outro.
SoftwareSerial bluetooth(10,11);


// Objeto nomeado lcd para podermos utilizar as funções
LiquidCrystal lcd(7,6,5,4,3,2);

unsigned long int tempoInicial = 0;
unsigned long int tempoAnterior = 0;
unsigned long int intervalo = 1000;
bool verificado = 0; // variável irá verificar se algo foi enviado via bluetooth



char b1; //caractere responsável por armazenar os dados recebidos
String command = "";
String vel;
int leitura;
int conversao;
int anterior = 0;



void setup() {
  Serial.begin(9600);
  
  bluetooth.begin(9600);
  
  lcd.begin(16,2); // tamanho do lcd
  lcd.clear();// Utilizado para limpar a tela
 

}



/*  Temporizador serve para mudar a velocidade mostradano LCD a cada 1 segundo  */
void temporizador()
{
  tempoInicial = millis();
  
  if (tempoInicial - tempoAnterior >= intervalo)
  {
    tempoAnterior = tempoInicial;
    MudaVelocidade();
  }
}


void MudaVelocidade()
{

  /*  Esse seria o algoritmo responsável por receber dados do arduino e printar no LCD as velocidades do celular  */

  /*  Se eu recebi algo via bluetooth */
  if(bluetooth.available() > 0)
  {

    b1 = bluetooth.read(); /* Ler e armazena o caractere*/
    command += b1;

   /* Caso eu tenha recebido todos os valores */
    if(b1 == '\n')
    {
      if(command.compareTo("Seta Direita") != 0 and command.compareTo("Seta Esquerda") != 0)
      {
          /*  Caso não tenha nada no buffer */
          /*  Não limparemos  */
          /*  Se tiver algo, devemos limpar a tela e imprimir a nova imagem */
          if(command != NULL)
          {
             lcd.clear();
          }
          /*  Setamos a posição para printar a proxima string */
          lcd.setCursor(4,0);
          lcd.print("Velocidade");
          /*  Setamos a posição para printar a proxima string */
          lcd.setCursor(8,1);
          lcd.print(command);
          lcd.setCursor(11,1);
          lcd.print("km/h");
      }
      
    }
    
  }
  

  
}

void loop() {

  temporizador();

  
  leitura = analogRead(pot);              /*  Realizando a leitura do potenciômetro */
  conversao = map(leitura,0,1023,0,400);  /*  Convertendo os valores de entrada do analógico que são de 0 a 1023 para 0 até 400 */
  
  if(conversao != anterior) /*  Toda vez que eu mudar de velocidade, limpe a tela e troque a velocidade anterior  */
  {
    lcd.clear();
    anterior = conversao;
  }
  
  lcd.setCursor(4,0);
  lcd.print("Velocidade");
  /*  Setamos a posição para printar a proxima string */
  lcd.setCursor(8,1);
  lcd.print(anterior);
  lcd.setCursor(11,1);
  lcd.print("km/h");
  
  

}
