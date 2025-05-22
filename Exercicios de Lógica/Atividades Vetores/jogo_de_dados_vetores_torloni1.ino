
// C++ code
//
void cabecalho()
{
  Serial.println("                            ----------------------------");
  Serial.println("                            |                          |");
  Serial.println("                            |                          |");
  Serial.println("                            |BEM VINDO AO JOGO DE DADOS|");
  Serial.println("                            |                          |");
  Serial.println("                            |                          |");
  Serial.println("                            ----------------------------");
  Serial.println();
  Serial.println();
}
void pontinhos(int qtdPontos = 5, int tempo = 700)
{
  for(int i = 1; i <= qtdPontos; i++){
    Serial.print(".");
    delay(tempo);
  }
}
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  randomSeed(analogRead(0));
  cabecalho();

  Serial.println("Quantas vezes quer jogar?");
  while(!Serial.available());
  int qtdRodadas = Serial.parseInt();

  int vetPalpites[qtdRodadas];
  int vetResultados[qtdRodadas];
  for(int r = 0; r <= qtdRodadas; r++){

    Serial.println("Digite o seu palpite");
    while(! Serial.available());
    int palpite = Serial.parseInt();

    int numeroSorteado = random(1, 7);
    vetPalpites[r] = palpite;
    vetResultados[r] = numeroSorteado;
    Serial.println("Jogando o dado");
    pontinhos();

    Serial.println();
    Serial.println("Seu palpite: " + String(palpite));
    Serial.println("Numero do dado: " + String(numeroSorteado));
    if(palpite == numeroSorteado){
      Serial.println("Parabens, voce ganhou");
    }else{
      Serial.println("Que pena, tente novamente"); 
    }
    Serial.println();

    delay(4000);
  }
  for(int i = 0; i < qtdRodadas; i++){
  Serial.println("Rodada " + String(i + 1) + ":");
  Serial.println("  Palpite: " + String(vetPalpites[i]));
  Serial.println("  Dado: " + String(vetResultados[i])); 
  Serial.println("  Resultado: " + String(vetResultados[i] == vetPalpites[i] ? "Acertou!" : "Errou!"));
  Serial.println("-------------------------------------");
  Serial.println();
  }
  Serial.println("Reiniciando o jogo");
} 