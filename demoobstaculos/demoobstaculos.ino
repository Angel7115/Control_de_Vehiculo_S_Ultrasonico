// Pines conectados al controlador L298D
int enA = 25;  // Pin ENABLE A (Llantas Izquierdas)
int enB = 33;  // Pin ENABLE B (Llantas Derechas)
int in1 = 26;  // IN1 del motor izquierdo
int in2 = 27;  // IN2 del motor izquierdo
int in3 = 14;  // IN3 del motor derecho
int in4 = 12;  // IN4 del motor derecho

const int EchoPin = 5;     // Pin para el sensor de distancia
const int TriggerPin = 4;  // Pin para el Trigger del sensor

void setup() {
  // Configurar los pines como salidas
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  
  Serial.begin(115200); // Para ver los resultados en el monitor serial
}

// Función para mover el carrito hacia adelante
void avanzar() {
  Serial.println("Avanzando...");
  digitalWrite(enA, HIGH);    // Activar motor izquierdo
  digitalWrite(enB, HIGH);    // Activar motor derecho
  digitalWrite(in1, HIGH);    // Llanta izquierda hacia adelante
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);    // Llanta derecha hacia adelante
  digitalWrite(in4, LOW);
}

// Función para girar a la derecha
void girarDerecha() {
  Serial.println("Girando a la derecha...");
  digitalWrite(enA, HIGH);    // Activar motor izquierdo
  digitalWrite(enB, HIGH);    // Activar motor derecho
  digitalWrite(in1, LOW);     // Llantas izquierdas hacia atrás
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);    // Llantas derechas hacia adelante
  digitalWrite(in4, LOW);
}

// Función para girar a la izquierda
void girarIzquierda() {
  Serial.println("Girando a la izquierda...");
  digitalWrite(enA, HIGH);    // Activar motor izquierdo
  digitalWrite(enB, HIGH);    // Activar motor derecho
  digitalWrite(in1, HIGH);    // Llantas izquierdas hacia adelante
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);     // Llantas derechas hacia atrás
  digitalWrite(in4, HIGH);
}

// Función para detener el carrito
void detener() {
  Serial.println("Deteniendo el carrito...");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, LOW);     // Desactivar motor izquierdo
  digitalWrite(enB, LOW);     // Desactivar motor derecho
}

// Función para medir distancia
float ping(int TriggerPin, int EchoPin) {
  unsigned short int duration;
  float distanceCm;

  digitalWrite(TriggerPin, LOW);  // Para generar un pulso limpio ponemos a LOW
  delayMicroseconds(10);
  digitalWrite(TriggerPin, HIGH); // Generamos Trigger (disparo) de 10us
  delayMicroseconds(10);          // Reducido el tiempo del pulso
  digitalWrite(TriggerPin, LOW);

  duration = pulseIn(EchoPin, HIGH); // Medimos el tiempo entre pulsos, en microsegundos
  distanceCm = float(duration) / 58.2; // Convertimos a distancia, en cm
  return distanceCm;
}

void loop() {
  avanzar(); // Avanza continuamente
  
  // Medir la distancia cada 200 ms
  delay(200);
  float distancia = ping(TriggerPin, EchoPin);
  
  Serial.print("Distancia medida: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  // Si detecta un obstáculo a 30 cm o menos
  if (distancia <= 30) {
    detener(); // Detener el carrito
    delay(300); // Reducir el tiempo de espera

    // Intentar girar a la derecha primero
    girarDerecha();
    delay(700); // Aumentar el tiempo de giro a la derecha
    detener(); // Detener el carrito después de girar

    // Verificar la distancia nuevamente
    distancia = ping(TriggerPin, EchoPin);
    
    // Si todavía hay un obstáculo, girar a la izquierda
    if (distancia <= 30) {
      girarIzquierda();
      delay(1000); // Aumentar el tiempo de giro a la izquierda
      detener(); // Detener el carrito después de girar
    }
  }
}
