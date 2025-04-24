//Faça um programa que receba a medida em centímetros e exiba esse
//número em polegadas. OBS: Uma polegada equivale a 2.54
//centímetros.

//variáveis
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
  Serial.println("|         LOPAL - EX05         |");
  Serial.println("|                              |");
  Serial.println("|------------------------------|");
  
  
  Serial.println();//pula uma linha
  Serial.println();//pula uma linha
 //entrada
 Serial.println("Digite a medida em centimetros");
  while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
  centimetros = Serial.parseFloat();
  
 //processamento
  polegadas = polegadas = centimetros * 0.39370;
    
 //saída
  Serial.println();//pula uma linha
  Serial.println("sua medida (cm) em polegadas: " + String(polegadas) );
}