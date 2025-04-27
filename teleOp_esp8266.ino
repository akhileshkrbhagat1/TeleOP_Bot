
#include <ESP8266WiFi.h>
#include <PubSubClient.h>


const char* ssid = "your-wifi-ssid";    
const char* password = "your-password";    
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastMsg = 0;
String msgStr = "";

int 
M11 = 2, 
M12 = 12, 
M21 = 13, 
M22 = 15;  


void forward() {
     digitalWrite(M11, HIGH);
     digitalWrite(M12, LOW); 
     digitalWrite(M21, HIGH);
     digitalWrite(M22, LOW); 
     Serial.println("forward");
     }
     
void backward(){
     digitalWrite(M11, LOW);
     digitalWrite(M12, HIGH); 
     digitalWrite(M21, LOW);
     digitalWrite(M22, HIGH); 
     Serial.println("backward");
     
}
void left(){
     digitalWrite(M11, LOW);
     digitalWrite(M12, LOW); 
     digitalWrite(M21, HIGH);
     digitalWrite(M22, LOW); 
     Serial.println("left");
     }
void right(){
     digitalWrite(M11, HIGH);
     digitalWrite(M12, LOW); 
     digitalWrite(M21, LOW);
     digitalWrite(M22, LOW); 
     Serial.println("right");
     }
void stay(){
     digitalWrite(M11, LOW);
     digitalWrite(M12, LOW); 
     digitalWrite(M21, LOW);
     digitalWrite(M22, LOW); 
     Serial.println("stop");
     }


void setup_wifi() {

  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    
    Serial.print(".");
    digitalWrite(2,0);
    delay(200);
    digitalWrite(2,1);
    delay(200);
    
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  

  if ((char)payload[0] == '0') {
    forward(); 
  } else if ((char)payload[0] == '1') {
    left(); 
  }
  else if ((char)payload[0] == '2') {
    stay();  
  }
  else if ((char)payload[0] == '3') {
    right(); 
  }
  else if ((char)payload[0] == '4') {
    backward();  
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.subscribe("robot/movementplayer3");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {

pinMode(LED_BUILTIN, OUTPUT); // Initialize the built-in LED pin as output (usually GPIO2 on ESP8266)
pinMode(2, OUTPUT);           // D4 corresponds to GPIO2 on ESP8266
pinMode(12, OUTPUT);          // D6 corresponds to GPIO12
pinMode(13, OUTPUT);          // D7 corresponds to GPIO13
pinMode(15, OUTPUT);          // D8 corresponds to GPIO15

  
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    
    msgStr = "";
    delay(50);
  }
}
