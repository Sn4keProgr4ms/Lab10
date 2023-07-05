SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

void setup()
{
  pinMode(D5, OUTPUT);
  pinMode(D7, INPUT);
  Serial1.begin(9600);
}

void loop()
{
  if (Serial1.available() > 0)
  {
    char value = Serial1.read();

    if (value == '?')
    {
      Serial.println("? Recieved");

      bool buttonValue = digitalRead(D7);
      if (buttonValue == true)
      {
        digitalWrite(D5, HIGH);
        Serial1.print("X");
      }
      else if (buttonValue = false)
      {
        digitalWrite(D5, LOW);
        Serial1.print("O");
      }
    }
    else if (value == '0')
    {
      digitalWrite(D5, LOW);
    }
    else if (value == '1')
    {
      digitalWrite(D5, HIGH);
    }
  }
}
