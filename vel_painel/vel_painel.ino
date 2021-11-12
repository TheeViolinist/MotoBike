//Vamos ligar o TX do bluetooth a porta 10 do arduino//
//Vamos ligar o RX do bluetooth a porta 11 do arduino//
//Lembrar que o TX transmite os dados do bluetooth para a placa
//RX recebe os dados que veem do arduino

#include <SoftwareSerial.h> // Biblioteca para se comunicar com o blueotooth

#include <LiquidCrystal.h> // biblioteca do painel

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

  if(Serial.available() > 0)
  {
    /*Esse codigo abaixo é utilizado somente para simulação  */
    /*Como o thinkercard não deixa enviar informações via bluetooth de um outro dispositivo*/
    /*Vamos receber informações do bluetooth via monitor serial e verificar se esse valor está sendo enviado ou não */
    /*Caso ele seja enviado, vamos mostrar a informação que foi enviada no lcd  */
    /*Assim mostramos que a conexão bluetooth é válida e os valores da velocidade estão corretos  */
    
    vel = Serial.readStringUntil('\n'); /*  Recebe a velocidade do monitor serial */
    verificado = bluetooth.write(Serial.read());  /*  Verifica se o valor foi enviado corretamente e envia via bluetooth, retorna 1 caso sim e 0 caso não*/
    
    
    if(verificado)
    {
      if(vel.compareTo("Seta Direita") != 0 and vel.compareTo("Seta Esquerda") != 0)
      {
           /*  Caso não tenha nada no buffer */
          /*  Não limparemos  */
          /*  Se tiver algo, devemos limpar a tela e imprimir a nova imagem */
          if(vel != NULL)
          {
             lcd.clear();
          }
          /*  Setamos a posição para printar a proxima string */
          lcd.setCursor(4,0);
          lcd.print("Velocidade");
          /*  Setamos a posição para printar a proxima string */
          lcd.setCursor(8,1);
          lcd.print(vel);
          lcd.setCursor(11,1);
          lcd.print("km/h");
      }
      
    }

     
    
    
  }
  
}

void loop() {

  temporizador();
  

}
