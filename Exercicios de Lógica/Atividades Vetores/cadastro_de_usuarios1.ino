//
//variáveis globais
/*
           cria um vetor tamanho 4,
           fazendo parte do mesmo cadasstro
*/
int qtdCadastrado = 4;
String  convidados[4];
int  idadeConvidados[4];//Camel Case
String  emailConvidados[4];

//Funções
void desenhaCabecalho(){
  
 Serial.println("*******---->FESTA DO PEDRIN<----*******");
 Serial.println();
 Serial.println();
}


void setup()
{
 Serial.begin(9600);//inicia a comunicação serial
  
  
  
  
  
  
}

void loop()
{
 //fazer um cabeçalho bolnito para o programa
 desenhaCabecalho();//chama a função para desenhar o cabeçalho
  
 //cadastrar os dados
  
  for(int i = 0; i<= qtdCadastrado; i++){
    
  //socilicitar o nome do usuário
    
    Serial.println("informe " +String(i + 1)+ "o nome para cadastro:");
    while(! Serial.available());
    convidados[i] = Serial.readString();
    
  //socilicitar a idade
    
    Serial.println("informe a sua idade " + convidados[i]);
    while(! Serial.available());
    idadeConvidados[i] = Serial.parseInt();
    
  //socilicitar o Email
    
    Serial.println("informe o seu email " + convidados[i]);
    while(! Serial.available());
    emailConvidados[i] = Serial.readString();
    Serial.println();
    
    
  
  
  }//fim do for
  
   Serial.println("***exibindo convidados da festa***");
   Serial.println();
  
  for(int i =0; i < qtdCadastrado; i++){
    
    Serial.println("Nome: " + convidados[i]);
      Serial.println("Idade " + String (idadeConvidados[i]));
      Serial.println("Email: " + emailConvidados[i]);
      Serial.println("permissao para a festa: " + String(idadeConvidados[i] >= 18 ? "OK" : "menor de idade"));                 
      Serial.println("<----------->");               
      Serial.println(); 
                                    
      }//fim do if               
                  
      //fim do for
    
                   


    
    
    
    
    
    
    
    
  //Exibir a lista de convidados
  //obs: só vai na festa quem for maior de idade >= 18
  
  
  
  
  
 delay(2000);//pausa de 2 segundos
  
}