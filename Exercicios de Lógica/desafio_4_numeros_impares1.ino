// sistema para exibir do 0 ao 100 somente com numeros impares



void setup()
{
 Serial.begin(9600);
}

void loop()
{
  
  for(int contador = 1; contador <=100; contador +=2){
   Serial.println("contador de numeros impares = " + String(contador));
    
   delay(2000);
  }
  
}