/* Calcule a média entre duas notas.
Verifique se o aluno foi aprovado:
Aprovado se média é MAIR OU IGUAL A 6 e SE A frequênciaÉ MAIOR OU IGUAL 75%.
Caso contrário, exiba se foi reprovado por nota, por frequência ou por ambos.
Se a média for exatamente 10, exiba: "Parabéns! Nota máxima!
*/


float n1, n2, media;
float frequencia;
  
  
void setup()
{
 Serial.begin(9600);
}

void loop()
{
 //ENTRADA
  
 Serial.println("digite a primeira nota = ");
 while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
 n1 = Serial.parseFloat(); // le o texto digitado pelo usuario
  
 Serial.println("digite a segunda nota = ");
 while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
 n2 = Serial.parseFloat(); // le o texto digitado pelo usuario 
  
 Serial.println("digite a frequencia do aluno  = ");
 while( ! Serial.available() ){}//Aguarda o usuário digitar (para loop)
 frequencia = Serial.parseFloat(); // le o texto digitado pelo usuario
  
 //PROCESSAMENTO
  
 media = (n1 + n2) /2; //peguei o codigo
 frequencia = ( frequencia /270) *100;
   
  if( media >= 6 && frequencia >202 ) {
    Serial.println("APROVADO");
  } else if(media <6 || frequencia <202){
    Serial.println("reprovado");
  } 
}