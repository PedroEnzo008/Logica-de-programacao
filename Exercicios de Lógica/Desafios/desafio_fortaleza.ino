/*Na entrada da fortaleza, há um painel com uma entrada serial. Um guardião digital (o
Arduino) propõe um desafio: “Adivinhe corretamente o número sagrado do dado,
que varia de 1 a 6.”
Se você errar, o sistema piscará um LED vermelho, indicando que você foi testado e falhou.
Se acertar, um LED verde piscará como sinal de aprovação divina, e uma das joias azuis do
templo (representadas por LEDs azuis) se acenderá, marcando o seu progresso.
Ao conquistar 3 acertos, todas as joias estarão acesas — e a Porta da Sabedoria
(controlada por um servo motor) se abrirá magicamente, permitindo sua
passagem ao templo.
*/

//VARIAVEIS


#include <Servo.h>
Servo motor;
int ledVerde = 7;
int ledVermelho = 4;
int ledsAzuis1 = 13;
int ledsAzuis2 = 11;
int ledsAzuis3 = 9;
int acertos = 0;



void desenhaCabecalho()
{
  Serial.println("** -->>>> !!! | BEM VINDO A FORTALEZA SAGRADA !!! | <<<<-- **");


  Serial.println();
  delay(500);
}

void setup()
{
  Serial.begin(9600);

  motor.attach(2);
  motor.write(0);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledsAzuis1, OUTPUT);
  pinMode(ledsAzuis2, OUTPUT);
  pinMode(ledsAzuis3, OUTPUT);

  randomSeed(analogRead(0));
}

void loop()
{
  desenhaCabecalho();

  Serial.println("fale um numero de 1 a 6:");

  while (!Serial.available()); 

  int palpite = Serial.parseInt(); 

  int numeroSorteado = random(1, 7); 

  Serial.println("Jogando o dado...");
  Serial.println();
  Serial.print("Numero sorteado!! =  ");
  Serial.println(numeroSorteado);

  if (palpite == numeroSorteado)
  {
    Serial.println("numero Correto! '-'");
     Serial.println();

    digitalWrite(ledVerde, HIGH);
    delay(500);
    digitalWrite(ledVerde, LOW);

    if (acertos == 1)
      digitalWrite(ledsAzuis1, HIGH);
    else if (acertos == 2)
      digitalWrite(ledsAzuis2, HIGH); 
    else if (acertos == 3)
      digitalWrite(ledsAzuis3, HIGH);
      Serial.println("TODA AS JOIAS ACENDERAM! A porta se abrira......");
      motor.write(90);
  }
  else
    digitalWrite(ledVermelho, HIGH);
    delay(500);
    digitalWrite(ledVermelho, LOW);
    Serial.println("NUMERO ERRADOO! Tente novamente...");
    

  
  delay(1000);
}
