int r = 3;
int g = 5;
int b = 6;
int buz = 7;

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(buz, OUTPUT);
}

void intermedio() {
  analogWrite(buz, 128);
  delay(100);
  analogWrite(buz, 0);

  digitalWrite(r, LOW);
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);

  for (int i = 0; i < 4; i++) {
    analogWrite(r, 255);
    analogWrite(g, 50);
    delay(50);
    analogWrite(r, 0);
    analogWrite(g, 0);
    delay(50);
  }
}

void loop() {
  analogWrite(r, 255);
  analogWrite(g, 0);
  analogWrite(b, 0);
  delay(1000);

  intermedio();

  digitalWrite(r, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(b, HIGH);
  delay(1000);

  intermedio();

  analogWrite(r, 0);
  analogWrite(g, 30);
  analogWrite(b, 30);
  delay(1000);

  intermedio();
}