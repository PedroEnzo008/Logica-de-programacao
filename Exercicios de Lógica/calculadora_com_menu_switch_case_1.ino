float numero1 = 0.0;
float numero2 = 0.0;
float soma = 0.0;

float resultado;
int escolhaDaOperacao;
int contador;
int numero3;
float somar(float numero1,float numero2,float numero3 = 5){
  int numero6; //variável local
  
  return (numero1 + numero2 + numero3);
}

void subtrair(float numero1,float numero2){
  resultado = numero1 - numero2;
  Serial.println("WOW! O resultado foi: " + String(resultado));

}

void multiplicar(float numero1, float numero2){
resultado = numero1 * numero2;
  Serial.println("WOW! O resultado foi:" + String(resultado));
}
 
void dividir(float numero1,float numero2){
resultado = numero1/ numero2;
Serial.println("WOW! O resultado foi:" + String(resultado));

}


 


void setup()
{
  Serial.begin(9600);
  
  float numero1 = 0.0;
  float numero2 = 0.0;
 
  
  
  
  do{
    Serial.println("Bem-vindo (a) a calculadora inteligente.");
    Serial.println("Escolha uma das opcoes/operacoes:");
    Serial.println("1 - Somar");
    Serial.println("2 - Subtrair");
    Serial.println("3 - multiplicar");
    Serial.println("4 - Dividir");

    while(!Serial.available());{} //Espera o usuário digitar

    escolhaDaOperacao = Serial.parseInt(); // Armazena o que o usuário digitou na variavel

    Serial.println("Certo, Agora, para realizar a operacao, digite o primeiro numero");
    while(!Serial.available());{} //Espera o usuário digitar
    numero1 = Serial.parseFloat();

    Serial.println("Agora, digite o segundo numero");
    while(!Serial.available());{} //Espera o usuário digitar
    numero2 = Serial.parseFloat();
    
     Serial.println("Agora, digite o terceiro numero");
    while(!Serial.available());{} //Espera o usuário digitar
    numero3 = Serial.parseFloat();
    
    
    switch(escolhaDaOperacao){
      case 1:
      resultado = somar(numero1,numero2,10);
      Serial.println("WOW! O resultado foi:" + String(resultado));
      break;
      
      case 2:
      subtrair(numero1,numero2);

      
      break;
      
      case 3:
      multiplicar(numero1,numero2);
      
      break;
      
      case 4:
      dividir(numero1,numero2);
      break;
    }
   Serial.println("voce deseja continuar? Se sim, digite [s], se nao digite [n]");
    while(!Serial.available()){} //Esperar o usuario digitar
    
    if (Serial.readString() == "s"){
    contador++;
    }
    else{
     contador = 0;
     Serial.println("Ate breve,obrigado por usar a calculadora inteligente");
     Serial.println("Caso queira voltar,reinicie o sistema.");
    }
    
  }
  while(contador != 0);
  

  }
  void loop()
  {
  
  }
