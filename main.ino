#define LED_PIN_GREEN     8
#define LED_PIN_BLUE      10
#define LED_PIN_RED       9
#define POWER_PIN   7
#define SIGNAL_PIN  A0
#define THRESHOLD   300
#define MYHEADACHE 3

int value = 0; // variable to store the sensor value

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN_GREEN,   OUTPUT);   // configure D2 pin as an OUTPUT
  pinMode(LED_PIN_BLUE,   OUTPUT);
  pinMode(LED_PIN_RED,   OUTPUT);
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  pinMode(MYHEADACHE, OUTPUT);
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
  digitalWrite(LED_PIN_GREEN,   HIGH); // turn LED OFF
  digitalWrite(LED_PIN_BLUE,   HIGH);
  digitalWrite(LED_PIN_RED,   HIGH);
  digitalWrite(MYHEADACHE,HIGH);
  
  
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  if (value > THRESHOLD) {
    Serial.println(value);
    if (value<325){
      digitalWrite(LED_PIN_GREEN, HIGH);
      digitalWrite(LED_PIN_BLUE, HIGH);
      digitalWrite(LED_PIN_RED, LOW);
      digitalWrite(MYHEADACHE,HIGH);
    }
    else if (value<370 and value>=325){
      digitalWrite(LED_PIN_GREEN, HIGH);
      digitalWrite(LED_PIN_BLUE, LOW);
      digitalWrite(LED_PIN_RED, HIGH);
      digitalWrite(MYHEADACHE,HIGH);
    }
    else if (value>=370){
      digitalWrite(LED_PIN_GREEN, LOW);
      digitalWrite(LED_PIN_BLUE, HIGH);
      digitalWrite(LED_PIN_RED, HIGH);
      digitalWrite(MYHEADACHE,LOW);
      //delay(1000);                       // wait for a second
      tone(MYHEADACHE, 1000); // Send 1KHz sound signal...
      
    }
    /*else if(value>370){
      digitalWrite(MYHEADACHE,LOW);
      //delay(1000);                       // wait for a second
      tone(MYHEADACHE, 1000); // Send 1KHz sound signal...
      //delay(1000);        // ...for 1 sec
      //noTone(3); 
    }*/
    } 
  else{
    digitalWrite(MYHEADACHE,HIGH);
  }
}
