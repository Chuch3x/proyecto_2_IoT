#include <WiFi.h>
#include <DHT.h>

#define DHTPIN 16          // El pin digital al que está conectado el sensor
#define DHTTYPE DHT11     // Tipo de sensor (DHT11 o DHT22)

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "AXS_2.4G_pMmbfK";
const char* password = "YeMDXteu";
const char* host = "192.168.1.18";
const int port = 1000;

void setup() {
    Serial.begin(9600);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        //delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
    dht.begin(); 
       
}

void loop() {
  
    WiFiClient client;
    int h = dht.readTemperature(); 
    if (isnan(h)) {
    Serial.println("Error al leer el sensor DHT!");
    return;
    }
    if (client.connect(host, port)) {
        Serial.println("Connected to server");
        client.print(h);
        delay(1000);
      
        client.stop();
    } else {
        Serial.println("Connection failed");
    }
  Serial.print("Temperatura: ");
  Serial.print(h);
}
/*
#include <DHT.h>

#define DHTPIN 16          // El pin digital al que está conectado el sensor
#define DHTTYPE DHT11     // Tipo de sensor (DHT11 o DHT22)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);   // Inicia la comunicación serial
  dht.begin();          // Inicia el sensor DHT
}

void loop() {
  delay(2000);          // Espera 2 segundos entre lecturas
  
  float h = dht.readHumidity();       // Lee la humedad relativa
  float t = dht.readTemperature();    // Lee la temperatura en grados Celsius

  // Si la lectura del sensor falla, muestra un mensaje de error
  if (isnan(h) || isnan(t)) {
    Serial.println("Error al leer el sensor DHT!");
    return;
  }

  // Muestra los valores de temperatura y humedad en la consola serial
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print("%\tTemperatura: ");
  Serial.print(t);
  Serial.println("°C");
}
*/

