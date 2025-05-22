//Faça um programa que receba a medida em polegadas e exiba esse número em
//centímetros.

//variaveis
float centimetros = 0;
 float polegadas = 0;
void setup()
{
 Serial.begin(9600);
}

void loop()
{
  
  //cabeçalho - 2 pipes + 30 tracinhos
  Serial.println("|------------------------------|");
  Serial.println("|                              |");
  Serial.println("|         LOPAL - EX06         |");
  Serial.println("|                              |");
  Serial.println("|------------------------------|");
  
  
  Serial.println();//pula uma linha
  Serial.println();//pula uma linha
 //entrada
 Serial.println("Digite a medida em polegadas");
  while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
  polegadas = Serial.parseFloat();
  
 //processamento
  centimetros = centimetros = polegadas * 2.54;
  
  //saída
  Serial.println();//pula uma linha
  Serial.println("sua medida (pol) em centimetros: " + String(centimetros) );
  Serial.println();//pula uma linha
}