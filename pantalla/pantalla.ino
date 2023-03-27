#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>
LiquidCrystal_I2C lcd(0x27,16,2);


const char* ssid = "LABO18";
const char* password = "catolica18";
const char* host = "192.168.74.148";
const int port = 1000;

void setup() {
  Serial.begin(9600);

  // Conectarse a la red WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    //delay(500);
    Serial.println("Conectando a la red WiFi...");
  }
  Serial.println("Conectado a la red WiFi");
  // Conectarse al servidor
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {
  WiFiClient client;
  delay(1000);
  while (!client.connect(host, port)) {
    //delay(500);
    Serial.println("Conectando al servidor...");  
  }
  Serial.println("Conectado al servidor");

  String line = client.readStringUntil('\n');
  Serial.print("Variable recibida desde el servidor: ");
  Serial.println(line);
 
  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");
  lcd.print(45);
  delay(1000);

  int medida = line.toInt();
  //int medida=line;
  if(medida > 40){
    lcd.setCursor(0,1);
    lcd.print("PELIGRO");
  }
  else{
     lcd.setCursor(0,1);
     lcd.print("SEGURO");
  }
  client.stop();
  }