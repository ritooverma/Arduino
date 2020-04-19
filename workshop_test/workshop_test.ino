/**
 * Helloworld style, connect an ESP8266 to the IBM IoT Foundation
 * 
 * Author: Ant Elder
 * License: Apache License v2
 */
#include <ESP8266WiFi.h>
#include <PubSubClient.h> // https://github.com/knolleary/pubsubclient/releases/tag/v2.3
#include <DHT.h>

//-------- Customise these values -----------
const char* ssid = "Rv2000";
const char* password = "panasonic";
                              
#define ORG "2w6uz0"
#define DEVICE_TYPE "ESP8266"
#define DEVICE_ID "1"
#define TOKEN "LJ+4W21Pm*koegbfms"
#define DHTPIN D5
#define DHTTYPE DHT11
//-------- Customise the above values --------

char server[] = ORG ".messaging.internetofthings.ibmcloud.com";
char topic[] = "iot-2/evt/status/fmt/json";
char authMethod[] = "use-token-auth";
char token[] = TOKEN;
char clientId[] = "d:" ORG ":" DEVICE_TYPE ":" DEVICE_ID;

WiFiClient wifiClient;
PubSubClient client(server, 1883, wifiClient);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200); Serial.println();

  Serial.print("Connecting to "); Serial.print(ssid);
  if (strcmp (WiFi.SSID().c_str(), ssid) != 0) {
     WiFi.begin(ssid, password);
  }
  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
  }  
  Serial.println("");
  Serial.print("WiFi connected, IP address: "); Serial.println(WiFi.localIP());

  Serial.println("View the published data on Watson at: "); 
  if (ORG == "quickstart") {
    Serial.println("https://quickstart.internetofthings.ibmcloud.com/#/device/" DEVICE_ID "/sensor/");
  } else {
    Serial.println("https://" ORG ".internetofthings.ibmcloud.com/dashboard/#/devices/browse/drilldown/" DEVICE_TYPE "/" DEVICE_ID);
  }
  dht.begin();
}

void loop() {
   if (!!!client.connected()) {
      Serial.print("Reconnecting client to "); Serial.println(server);
      while ( ! (ORG == "quickstart" ? client.connect(clientId) : client.connect(clientId, authMethod, token))) {
        Serial.print(".");
        delay(500);
     }
     Serial.println();
   }
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  
 // String payload = "{\"Temperature\":";
 String payload = "{\"Temperature\":";
  payload += t;
  payload += ",\"Humidity\":";
  payload += h;
  payload += "}";



//  String payload = "{\"_id\":\"1\",\"_rev\": \"1\",\"topic\": \"iot-2/type/ESP8266/id/1/evt/status/fmt/json\",\"payload\":";
//  payload += "{\"Temperature\":";
//  payload += t;
//  payload += ",\"Humidity\":";
//  payload += h;
//  payload += "},";
//  payload += "\"qos\": 0, \"retain\": false}";
  Serial.print("Sending payload: "); Serial.println(payload);
    
  if (client.publish(topic, (char*) payload.c_str())) {
    Serial.println("Publish ok");
  } else {
    Serial.println("Publish failed");
  }

  delay(5000);
}
