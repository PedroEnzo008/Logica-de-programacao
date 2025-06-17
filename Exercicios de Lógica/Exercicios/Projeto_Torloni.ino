//bibliotecas
#include <DHT11.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>
//#include <Servo.h> //Biblioteco do servo no arduino
#include <ESP32Servo.h>  //Biblioteca do servo do ESP32
#include <WiFi.h>
#include <PubSubClient.h>

// --- WiFi & MQTT ---
const char* ssid = "ProjetosIoT_Esp32";         //sua rede wifi
const char* password = "senai@134";             //senha da sua rede wifi
const char* mqtt_server = "broker.hivemq.com";  //endereço do broker público
const int mqtt_port = 1883;                     //porta do broker público, geralmente 1883

//Tópicos
const char* topic_temp = "smartnest/cozinha/temperatura";
const char* topic_umid = "smartnest/cozinha/umidade";
const char* topic_porta = "smartnest/cozinha/porta";

// --- Pinos ---
const int luzSala = 18;
const int rele = 15;
const int servoMotor = 2;
const int PIR = 5;
const int ledAmarelo = 4;
const int buzzer = 12;
const int mq135 = 34;
#define DHTPINO 33
#define DHTTIPO DHT11

// --- Variáveis ---
int contadorGas = 0;
unsigned long ultimaLeitura = 0;

WiFiClient espClient;
PubSubClient client(espClient);
Servo motor;

DHT dht(DHTPINO, DHTTIPO);  //Inicializa o objeto DHT
LiquidCrystal_I2C lcd(0x27, 20, 4);

void alarme_dois_tons() {
  int freqAlta = 2000;
  int freqBaixa = 800;
  int duracaoTom = 250;

  tone(buzzer, freqAlta, duracaoTom);
  delay(duracaoTom);
  tone(buzzer, freqBaixa, duracaoTom);
  delay(duracaoTom);
}

void verificarTemperaturaEUmidade() {
  float umidade = dht.readHumidity();          //lê a umidade
  float tempreratura = dht.readTemperature();  // lê a temperatura em Celsius (Padrão)

  lcd.clear();          //limpa o backlight do lcd
  lcd.setCursor(0, 0);  // informa a coluna e linha para inserção de dados
  lcd.print("Umidade: " + String(umidade) + "%");

  lcd.setCursor(0, 1);  // informa a coluna e linha para inserção de dados
  lcd.print("Temperatura: " + String(tempreratura) + "C");


  //Serial.println("Umidade: " + String(umidade) + "%");
  //Serial.println("Temperatura: " + String(tempreratura) + "C");
  delay(7000);
}

void abrirPortaComServoMotor() {
  motor.write(180);  //Ira girar o hélice em 180 graus
  apitar();
  delay(2000);
}

void fecharPortaComServoMotor() {
  Serial.println("entrou");
  motor.write(0);  //Ira girar o hélice em 0 graus
  noTone(buzzer);

  delay(1500);
}


void trancarPorta() {
  digitalWrite(rele, LOW);
  Serial.println("Porta trancada");
  delay(2000);
}

void destrancarPorta() {
  digitalWrite(rele, HIGH);
  Serial.println("Porta destrancada");
  delay(2000);
}

void apitar() {
  /*if (abrirPortaComServoMotor()) {
 alarme_dois_tons()
  }else{noTone(buzzer)}*/
  // Faz o buzzer apitar (frequência de 1000Hz) por 1 segundo
  tone(buzzer, 1000);
}

void conectarWiFi() {  //verifica conexão wifi para somente depois iniciar o sistema
  Serial.println("Conectando ao WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
}

void reconectarMQTT() {  //verifica e reconecta a conexão com o broker mqtt
  while (!client.connected()) {
    Serial.print("Reconectando MQTT...");
    if (client.connect("ESP32ClientTest")) {
      Serial.println("Conectado!");
      //client.subscribe(topic_porta);  //conecta ao topico da porta assim que estabelecer ligação com o broker
    } else {
      Serial.print("Falha: ");
      Serial.println(client.state());
      delay(5000);
    }
  }
}

/**
  Função para tratamento das mensagens de callback/retorno do broker de cada tópico subscrito (led, porta, etc.)

  char* é uma cadeia de caracteres em C como um vetor onde cada caractter/letra está em uma posição, 
  diferente de uma String em C++ que pode ser lida completamente
*/
void tratarMensagem(char* topic, byte* payload, unsigned int length) {  //
  String mensagem = "";
  for (int i = 0; i < length; i++) {  //concatena todas os char* para se ter o texto completo em String
    mensagem += (char)payload[i];
  }

  Serial.printf("Mensagem recebida [%s]: %s\n", topic, mensagem.c_str());

  /*
    Verifica se o tópico recebido é o topico da porta
  é uma função da linguagem C que compara duas strings (topic e topic_porta)
  */
  //porta
  if (strcmp(topic, topic_porta) == 0) {  //tópico atual é o da porta?
    if (mensagem == "abrir") {
      destrancarPorta();
      delay(500);
      abrirPortaComServoMotor();
    } else if (mensagem == "fechar") {
      fecharPortaComServoMotor();
      delay(500);
      trancarPorta();
    }
  }
}

// --- Sensores e atuadores ---

void lerSensorEDisponibilizar() {
  float temperatura = dht.readTemperature();  //lê a temperatura do sensor
  float umidade = dht.readHumidity();         // lê a umidade do sensor

  if (isnan(temperatura) || isnan(umidade)) {  //avisa no console se deu erro
    Serial.println("Erro ao ler DHT!");
    return;
  }

  Serial.printf("Temp: %.1f °C | Umid: %.1f %%\n", temperatura, umidade);  //mostra temperatura e umidade no console

  char tempStr[10], umidStr[10];
  dtostrf(temperatura, 4, 1, tempStr);  //converte o valor da temperatura do sensor que para string (ele vem float do sensor)
  dtostrf(umidade, 4, 1, umidStr);      //converte o valor da umidade do sensor que para string (ele vem float do sensor)
  client.publish(topic_temp, tempStr);  //publica a temperatura no tópico, lá no Broker Server
  client.publish(topic_umid, umidStr);  //publica a umidade no tópico, lá no Broker Server
}






void setup() {
  Serial.begin(115200);

  //INICIALIZA O SENSOR DHT
  dht.begin();

  //INICIALIZANDO O LCD
  lcd.init();  //lcd.begin();

  lcd.backlight();  //Liga o lcd

  conectarWiFi();                            //conecta no wifi
  client.setServer(mqtt_server, mqtt_port);  //conecta no broker server
  client.setCallback(tratarMensagem);        //trata as mensagens recebidas do broker

  //fala ao programa que o pino 13 será uma saída/output
  //configura os pinos dos sensores
  pinMode(luzSala, OUTPUT);     //Inicia o led como saída
  pinMode(PIR, INPUT);          //Inicia o sensor PIR como entrada
  pinMode(ledAmarelo, OUTPUT);  //inicia o led amarelo como saída que será utilizado em conjunto com o sensor PIR
  pinMode(mq135, INPUT);        //inicia o sensor de gás como entrada
  pinMode(buzzer, OUTPUT);      //inicia o sensor buzzer como saída para controle do alarme
  pinMode(rele, OUTPUT);
  motor.attach(servoMotor);  //inicia o servo motor (interamente é como se ele desse o comando pinMode() pela biblioteca do Servo)


  digitalWrite(rele, LOW);  //O valor LOW deixa a Solenoide travada

  //
  motor.write(100);  //por enquanto

  Serial.println("Calibrando os sensores");
  delay(1000);
  Serial.println("Sensores calibrado!!! Pode testar ai bbzao");

  Serial.println("Testando o Servo Motor...");

  //abrirPortaComServoMotor();

  //delay(5000);
}

void loop() {
  // As instruções no loop será somente chamada de funções
  if (!client.connected()) { reconectarMQTT(); }  //se não tem conexão com o broker, tenta reconectar
  client.loop();                                  //mantém a conexão com o broker serve sempre aberta

  //acenderLEDAoDetectarPresenca();
  //acenderLEDAoDetectarPrensenca()
  //verificarVazamentoDeGas();
  //verificarTemperaturaEUmidade();
  //abrirPortaComServoMotor();
  //fecharPortaComServoMotor();

  if (millis() - ultimaLeitura > 5000) {
    ultimaLeitura = millis();    //contador de milisegundos
    lerSensorEDisponibilizar();  //Dados do sensor de umidade e temperatura
  }
  //destrancarPorta();
  //trancarPorta();
  //delay(500);
}