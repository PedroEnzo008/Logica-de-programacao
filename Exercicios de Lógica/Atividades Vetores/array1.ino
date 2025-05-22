// C++ code
float precosFrutas[6];
float precoDigitado;
String frutas[6];
void setup()
{
  Serial.begin(9600);

  Serial.println("*** SACOLAO DO ZE***");
  Serial.println();
  //vetor tamanho 6: vai de 0 a 5
  String frutas[6];//cria um vetor tamanho 6 (preenchendo as posições com string vazias)

  Serial.println("Oh Ze, bora cadastrar as frutas!");

  Serial.println();
  //Pede as frutas para o usuario
  for(int i = 0; i <= 5; i++){
    //Pega a fruta do usuario
    Serial.println("informe a " + String(i + 1) + "a Fruta");
    while(! Serial.available());
    String frutaDigitada = Serial.readString();

    //Pega a fruta do usuario
    Serial.println(" Qual o preco de " + frutaDigitada + "?");
    while(! Serial.available());
    float precoDigitada = Serial.parseFloat();


    //poe a fruta na sacola/ cadastra a fruta no array/vetor
    frutas[i] = frutaDigitada;
    precosFrutas[i] = precoDigitado;

  }//fim do for

  Serial.println("Exibindo os valores cadastrados: ");
  Serial.println();

  for(int i =0; i <=5; i++){
    Serial.println(String(i + 1) + "a Fruta: " + frutas[i]);
    Serial.println("Preco da Fruta: " + String(precosFrutas[i]));

  }

}


void loop()
{

}