#define trigPin 9
#define echoPin 10

int ldr = A0;
int led = 13;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(led, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int lightValue = analogRead(ldr);

  // Ultrasonic Distance Measurement

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  int distance = duration * 0.034 / 2;

  Serial.print("LDR = ");
  Serial.print(lightValue);

  Serial.print("  Distance = ");
  Serial.println(distance);

  // Night condition
  if(lightValue < 500)
  {
    // Vehicle detected within 20 cm
    if(distance < 100)
    {
      digitalWrite(led, HIGH);
    }
    else
    {
      digitalWrite(led, LOW);
    }
  }
  else
  {
    digitalWrite(led, LOW);
  }

  delay(500);
} 