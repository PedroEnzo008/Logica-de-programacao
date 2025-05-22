//Faça um programa que receba o nome, o peso e a altura de uma
//pessoa. Calcule e imprima o nome e o IMC dessa pessoa - IMC = peso
//(altura * altura).

//VARIÁVEIS
String nome = "";
float altura = 0;
float peso = 0;
float imc = 0;

void setup()
{
 Serial.begin(9600);
}

void loop()
{
  
  //cabeçalho - 2 pipes + 30 tracinhos
  Serial.println("|------------------------------|");
  Serial.println("|                              |");
  Serial.println("|         LOPAL - EX04         |");
  Serial.println("|                              |");
  Serial.println("|------------------------------|");
  
  
  Serial.println();//pula uma linha
  Serial.println();//pula uma linha
 //entrada
  Serial.println("Digite seu nome");
  while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
  nome = Serial.readString(); // le o texto digitado pelo usuario
  nome.trim();
  
  Serial.println("Digite sua altura");
  while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
  altura = Serial.parseFloat();
  
  Serial.println("Digite seu peso");
  while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
  peso = Serial.parseFloat();
 
  
  
  //processamento 
  imc = peso /(altura * altura);
  
  //saída
  Serial.println();//pula uma linha 
  Serial.println("nome: " + nome );
  Serial.println("Sua IMC: " + String(imc) );
  
  Serial.println();//pula uma linha 
}