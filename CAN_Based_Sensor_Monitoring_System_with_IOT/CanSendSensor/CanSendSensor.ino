#include <DHT.h>
#include <DHT_U.h>

#include<mcp2515.h>
#include<SPI.h>

#define DHTPIN 5     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


const int SENSOR_PIN = 7; // the Arduino's input pin that connects to the sensor's SIGNAL pin 
// Variables will change:
int lastState = LOW;      // the previous state from the input pin
int currentState;         // the current reading from the input pin

struct can_frame canMsg; 
MCP2515 mcp2515(10); // SPI CS Pin 10 
struct can_frame canMsg2;

void setup() {
    Serial.begin(9600);
    dht.begin();
    
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

   pinMode(SENSOR_PIN, INPUT);

    SPI.begin();   //Begins SPI communication
    Serial.begin(9600); //Begins Serial Communication at 9600 baud rate 
    mcp2515.reset();                          
    mcp2515.setBitrate(CAN_125KBPS,MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz 
    mcp2515.setNormalMode();  //Sets CAN at normal mode  
    Serial.println("DHT11");
    Serial.println("Ultrasonic Sensor HC-SR04 "); // print some text in Serial Monitor
    Serial.println("Touch Sensor "); // print some text in Serial Monitor
}

void loop() {

    
    // Taking Values of sensors 
    //1 . DHT 11 

    int h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    int t = dht.readTemperature();
    if (isnan(h) || isnan(t)) {
      t = 500;
       Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }

    //2 . Ultrasonic Sensors
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Ultrasonic sensor
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor


      currentState = digitalRead(SENSOR_PIN);
      if(lastState == LOW && currentState == HIGH){
       Serial.println("The sensor is touched");
      }
       lastState = currentState;
   
 
  canMsg.can_id = 0x0A8; //CAN id as 0x036
  canMsg.can_dlc = 8; //CAN data length as 8
  canMsg.data[0] = t; //Update humidity value in [0]
  canMsg.data[1] = distance; //Update temperature value in [1]
  canMsg.data[2] = lastState; //Rest all with 0
  canMsg.data[3] = 0x00;
  canMsg.data[4] = 0x00;
  canMsg.data[5] = 0x00;
  canMsg.data[6] = 0x00;
  canMsg.data[7] = 0x00;
  mcp2515.sendMessage(&canMsg); //Sends the CAN message
  
//  
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.println(F("°C "));
    
    if ((mcp2515.readMessage(&canMsg2) == MCP2515::ERROR_OK) && (canMsg.can_id == 0x123)){
    
      int x = canMsg2.data[0];         
      int y = canMsg2.data[1];  
      Serial.print("1st Value: ");
      Serial.print(x);
      Serial.print(" 2nd Value: ");
      Serial.println(y);      
    }
    delay(3000);
}
