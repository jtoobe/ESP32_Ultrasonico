/*
 *  conectar 2 sensores a un ESP32
 * 
 */



const int TRIGGER_PIN_1 = 32;
const int ECHO_PIN_1 = 34;
const int TRIGGER_PIN_2 = 33;
const int ECHO_PIN_2 = 35;

void setup() {
  Serial.begin(115200);
  pinMode(TRIGGER_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  pinMode(TRIGGER_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
}

void loop() {
  unsigned long duration1, distance1;
  unsigned long duration2, distance2;

  // Medición con el primer sensor
  digitalWrite(TRIGGER_PIN_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_1, LOW);
  duration1 = pulseIn(ECHO_PIN_1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  // Medición con el segundo sensor
  digitalWrite(TRIGGER_PIN_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_2, LOW);
  duration2 = pulseIn(ECHO_PIN_2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  // Mostrar las lecturas en el monitor serie
  Serial.print("Sensor 1: ");
  Serial.print(distance1);
  Serial.print(" cm   |   ");
  Serial.print("Sensor 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  delay(1000); // Esperar un tiempo antes de realizar la próxima medición
}
