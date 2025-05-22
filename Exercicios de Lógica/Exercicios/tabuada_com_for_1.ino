int tabuadaEscolhida = 0;//variavel global
int resultado;
  
void setup()
{
 Serial.begin(9600);
}

void loop()
{
  Serial.println("Bem-Vindo (a)! :)");
  Serial.println("Dgite qual tabuada voce quer:");
  while(!Serial.available()){}
  tabuadaEscolhida = Serial.parseInt();
  
  for(int contador = 1; contador <= 10; contador ++){
   resultado = tabuadaEscolhida * contador;
     
     // Exibir assim: 2 X 1 = 20
     Serial.println(String(tabuadaEscolhida) + " X " + String(contador) + " = " + String(resultado));
  }
}

 
  