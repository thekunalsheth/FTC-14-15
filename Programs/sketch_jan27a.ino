int LED_PIN = 12;
void setup() 
{                
  pinMode(LED_PIN, OUTPUT);  
}

void loop() 
{
    
  tone(LED_PIN, 1200, 10000);
  delay(10000);
}
