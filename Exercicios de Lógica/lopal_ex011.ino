//Faça um programa que receba a idade de uma pessoa em anos e
//imprima essa idade em: Meses, Dias, Horas, Minutos.

//variáveis
int idade = 0;//inicia a idade
long idadeMeses = 0;
long idadedias = 0;
long idadehoras = 0;
long idademinutos = 0;

void setup()
{
 Serial.begin(9600);
}
void loop()
{
  
 //cabeçalho - 2 pipes + 30 tracinhos
  Serial.println("|------------------------------|");
  Serial.println("|                              |");
  Serial.println("|         LOPAL - EX01         |");
  Serial.println("|                              |");
  Serial.println("|------------------------------|");
  
  
  Serial.println();//pula uma linha
  Serial.println();//pula uma linha
 //entrada
 Serial.println("digite a sua idade");//pergunta a idade do usuário
  while( ! Serial.available() ){}//Aguarda o usuário digitar (para o loop)
  idade = Serial.parseInt();
  
 //processamento
 idadeMeses = idade * 12;
 idadedias = idade * 365;
 idadehoras = idade * 24 * 365;
 idademinutos = idadehoras * 60;
  
 //saída
 Serial.println("Sua idade em meses: " + String(idadeMeses) );
 Serial.println("Sua idade em dias: " + String(idadedias) );
 Serial.println("Sua idade em horas: " + String(idadehoras) );
 Serial.println("Sua idade em minutos: " + String(idademinutos) );
}