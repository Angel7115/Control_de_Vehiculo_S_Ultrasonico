const int EchoPin = 5;
const int TriggerPin = 4;

void setup() {
  Serial.begin(9600);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  float cm = ping(TriggerPin, EchoPin);
  
  // Mostrar siempre la distancia detectada
  Serial.print("Distancia detectada: ");
  Serial.print(cm);
  Serial.println(" cm");

  // Si la distancia es menor a 30 cm, mostrar el mensaje de obstáculo
  if (cm < 30) {
    Serial.println("¡Obstáculo detectado cerca!");
  }

  delay(1000);  // Esperar 1 segundo antes de la siguiente medición
}

int ping(int TriggerPin, int EchoPin) {
  unsigned short int duration;
  float distanceCm;

  digitalWrite(TriggerPin, LOW);  // Para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, HIGH); // Generamos Trigger (disparo) de 10us
  delayMicroseconds(100);
  digitalWrite(TriggerPin, LOW);

  duration = pulseIn(EchoPin, HIGH); // Medimos el tiempo entre pulsos, en microsegundos

  distanceCm = float(duration) / 58.2; // Convertimos a distancia, en cm
  return distanceCm;
}
