const int trigPin = 9;
const int echoPin = 8;
const int motor = 5;
const int buzzerPin = 4;
long duration = 0;

void setup()
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(motor, OUTPUT);
pinMode(buzzerPin, OUTPUT); 
Serial.begin(9600);
}

long distance(long time)
{
long distanceCalc;
distanceCalc = ((time * 0.034) / 2); // centimeters
return distanceCalc;
}

void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(500);
digitalWrite(trigPin, HIGH);
delayMicroseconds(1000);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
long distanceCm = distance(duration);

if (distanceCm <= 160 && distanceCm > 50)
{
digitalWrite(motor,HIGH);
tone(buzzerPin, 1000, 500); 
}
else
{
digitalWrite(motor,LOW);
noTone(buzzerPin); 
}

Serial.print("Distance = ");
Serial.print(distanceCm);
Serial.println (" cm");
delay(500);
}
