#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 5     // Digital pin connected to the DHT sensor

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);

//------------------------------------------------------

const int trigPin = 4;  
const int echoPin = 3;
long duration;
int distance;

#include <Servo.h>
 Servo myservo; 
 int pos = 0; 

//------------------------------------------------------

void setup() {
  Serial.begin(115200);

  dht.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
//------------------------------------------------------

 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT); 
 Serial.begin(115200);
 myservo.attach(9);  
 void ultra();
  
}
void ultra()
{
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance= duration*0.034/2;
 Serial.print("Distance: ");
 Serial.println(distance);
 
 Serial.print("Angle: ");
 Serial.println(pos);
 
 delay(75);
}

void loop()
{
 for (pos = 0; pos <= 180; pos += 4) 
 {
  myservo.write(pos);
  ultra();
 }
     
 for (pos = 180; pos >= 0; pos -= 4) 
 { 
  myservo.write(pos);
  ultra(); 

                       
 }
 //------------------------------------------------------
delay(10);

  //read temperature and humidity
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
  }

  //clear display
  display.clearDisplay();

  // display angle
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Angle: ");
  display.setTextSize(1);
  display.setCursor(75,0);
  display.print("150");
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(1);
  display.print(" ");
  
  // display dist
  display.setTextSize(1);
  display.setCursor(0, 16);
  display.print("Distance: ");
  display.setTextSize(1);
  display.setCursor(75, 16);
  display.print(distance);
  display.print("cm"); 
  
  display.display();

//---------------------------------------------------
  display.setTextSize(1);
  display.setCursor(0,32);
  display.print("Temperature: ");
  display.setTextSize(1);
  display.setCursor(75,32);
  display.print(t);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(1);
  display.print("C");
  
  // display humidity
  display.setTextSize(1);
  display.setCursor(0,48);
  display.print("Humidity: ");
  display.setTextSize(1);
  display.setCursor(75,48);
  display.print(h);
  display.print(" %"); 
  
  display.display(); 
}
   
