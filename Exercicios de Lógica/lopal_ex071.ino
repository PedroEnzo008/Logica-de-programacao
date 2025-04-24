//Faça um programa que receba o nome, cargo e salário de um funcionário. Calcule o
//salário acrescido de 10%. Ao final exiba o nome, o cargo e o novo salário desse
//funcionário.

//VARIÁVEIS
String nome = "";
String cargo = "";
float salario = 0;

void setup()
{
 Serial.begin(9600);
}

void loop()
{
  
  //cabeçalho - 2 pipes + 30 tracinhos
  Serial.println("|------------------------------|");
  Serial.println("|                              |");
  Serial.println("|         LOPAL - EX07         |");
  Serial.println("|                              |");
  Serial.println("|------------------------------|");
  
  
  Serial.println();//pula uma linha
  Serial.println();//pula uma linha
//entrada
  Serial.println("Digite seu nome");
  while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
  nome = Serial.readString(); // le o texto digitado pelo usuario
  nome.trim();
  
  Serial.println("Digite seu cargo");
  while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
  cargo = Serial.readString(); // le o texto digitado pelo usuario
  nome.trim();
  
  Serial.println("Digite seu salario");
  while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
  salario = Serial.parseFloat();
  
 //processamento
 salario = salario * 1.10;
 
 //saida
  Serial.println();//pula uma linha 
  Serial.println("nome: " + nome );
  Serial.println("Seu cargo: " + String(cargo) );
  Serial.println("Seu novo salario: " + String(salario) );
  

}