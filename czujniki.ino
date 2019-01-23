#define trigPin 4
#define echoPin 2
#define TMP36 A5
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  int odebrana = analogRead(TMP36);
  float napiecie = odebrana * 5.0;
  napiecie /= 1024.0; 
  long czas, dystans; 
  float temperatura = (napiecie - 0.5) * 100 ;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;
  {
  digitalWrite(8,HIGH);
  Serial.println("Aktualna temperatura: ");
  Serial.print(temperatura);
  Serial.println(" *C");
  Serial.println("Odleglosc od czujnika: ");
  Serial.print(dystans);
  Serial.println(" cm");

 
  digitalWrite(8,LOW);
  delay(1000);
  }
}