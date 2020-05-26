int pin = 8;
unsigned long duration;

void setup() {
  // Serial for closer inspection
  Serial.begin(9600);

  // PWM signal input.
  pinMode(pin, INPUT);
  
  // 3 outputs for status LEDs
  pinMode(13, OUTPUT);  // Red LED
  pinMode(12, OUTPUT);  // Yellow LED
  pinMode(11, OUTPUT);  // Green LED
}

void loop() {

  // Measure the input pulse at the specified pin
  duration = pulseIn(pin, HIGH);
  // Print it out for detailed inspection.
  Serial.println(duration);

  if(duration == 0) { // duration = 0 usually means no input signal at all.
    // Turn red LED on, others off.
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  } else if(duration > 900 && duration < 2100) {  //  900 < duration < 2100 means we are getting a valid RC signal. 
    digitalWrite(13, (duration < 1150));  // turn on red LED if input duration < 1150, signal is close to most ESC zero inputs
    digitalWrite(12, (duration > 1450 && duration < 1550)); // Turn on yellow LED if input duration is close to 1500, reversible ESC zero input
    digitalWrite(11, HIGH); // Turn on green LED to indicate a valid signal. 
  } else if(duration > 2100 && duration < 3000) { // Weird case to see if the input signal is valid, but a little high
    // turn on yellow LED only. 
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
  } else {
    // All other cases, blink red LED only. 
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    delay(250);
    
    digitalWrite(13, LOW);
    delay(250);
    
  }
}
