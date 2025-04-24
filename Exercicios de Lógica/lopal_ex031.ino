//Faça um programa que receba um número e exiba o seu dobro.

//variáveis
int numero = 0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  
  //cabeçalho - 2 pipes + 30 tracinhos
  Serial.println("|------------------------------|");
  Serial.println("|                              |");
  Serial.println("|         LOPAL - EX03         |");
  Serial.println("|                              |");
  Serial.println("|------------------------------|");
  
  
  Serial.println();//pula uma linha
  Serial.println();//pula uma linha
//entrada
  Serial.println("digite um numero");
  while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
  numero = Serial.parseInt();
  //processamento
  numero = numero * 2;
  //saída
 Serial.println("o dobro do seu numero: " + String(numero) );
  
}