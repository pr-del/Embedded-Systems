#include "DHT.h"
#define DHTPIN 5     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


int sensor = 4;              // the pin that the sensor is atteched to
int val = 0;                 // variable to store the sensor status (value)

void setup() {
    Serial.begin(9600);
    dht.begin();
    
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

    pinMode(sensor, INPUT);    // initialize sensor as an input

    Serial.println("DHT11");
    Serial.println("Ultrasonic Sensor HC-SR04 "); // print some text in Serial Monitor
    Serial.println("Pir Sensor "); // print some text in Serial Monitor
}

void loop() {

    
    // Taking Values of sensors 
    //1 . DHT 11 

    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t)) {
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


    //3 . PIR Motion detection Sensors
    val = digitalRead(sensor);   // read sensor value

    // Printing Serial Data On Monitor
    // 1 . DHT 11
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.println(F("°C "));
   
   
    // 2. UltraSonic Sensors
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // 3 . PIR Motion Sensors
        if (val == HIGH) {  
        Serial.println("NO Motion detected" );
    }
    else{
        Serial.println(" Motion detected" );
        }
        delay (3000);

}