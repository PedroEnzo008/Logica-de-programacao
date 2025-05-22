//Exibir os números pares de 60 a 80 e impares de 81 a 101 nom mesmo laço while

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  for(int contador = 60; contador <=80; contador +=2){
   Serial.println("contador de numeros pares = " + String(contador));
    
   delay(500);
  }
  for(int contador = 81; contador <=101; contador +=2){
   Serial.println("contador de numeros impares = " + String(contador));
    
   delay(500);
  }
}