// Faça um programa que receba o ano de nascimento de uma pessoa e
//o ano atual. Calcule e imprima:
//a. A idade dessa pessoa 
//b. Essa idade convertida em semana

//Variaveis
int anonascimento = 0;
int anoatual = 0;
int idade = 0;
int idadesemanas = 0;
void setup()
{
   Serial.begin(9600);
}

void loop()
{
  
  //cabeçalho - 2 pipes + 30 tracinhos
  Serial.println("|------------------------------|");
  Serial.println("|                              |");
  Serial.println("|         LOPAL - EX02         |");
  Serial.println("|                              |");
  Serial.println("|------------------------------|");
  
  
  Serial.println();//pula uma linha
  Serial.println();//pula uma linha
  
  //entrada
  Serial.println("Digite seu ano de nascimento");
   while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
  anonascimento = Serial.parseInt();
   Serial.println("Digite o ano atual");
   while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
  anoatual = Serial.parseInt();
  //processamento
  idade = anoatual - anonascimento;
  idadesemanas = idade * 12 * 4;
  
  //saída
   Serial.println("Sua idade: " + String(idade) );
   Serial.println("Sua idade em semanas: " + String(idadesemanas) );
}