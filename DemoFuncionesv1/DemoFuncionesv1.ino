// Pines conectados al controlador L298D
int enA = 25;  // Pin ENABLE A (Llantas Izquierdas)
int enB = 33;  // Pin ENABLE B (Llantas Derechas)
int in1 = 26;  // IN1 del motor izquierdo
int in2 = 27;  // IN2 del motor izquierdo
int in3 = 14;  // IN3 del motor derecho
int in4 = 12;  // IN4 del motor derecho

void setup() {
  // Configurar los pines como salidas
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(115200); // Para ver los resultados en el monitor serial
}

// Función para avanzar (mover todas las llantas hacia adelante)
void avanzar(int tiempo) {
  Serial.println("Avanzando...");
  digitalWrite(enA, HIGH);    // Activar motor izquierdo
  digitalWrite(enB, HIGH);    // Activar motor derecho
  digitalWrite(in1, HIGH);    // Llanta izquierda hacia adelante
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);    // Llanta derecha hacia adelante
  digitalWrite(in4, LOW);
  delay(tiempo); // Avanzar por el tiempo especificado
  detener();     // Detener al finalizar
}

// Función para retroceder (mover todas las llantas hacia atrás)
void retroceder(int tiempo) {
  Serial.println("Retrocediendo...");
  digitalWrite(enA, HIGH);    // Activar motor izquierdo
  digitalWrite(enB, HIGH);    // Activar motor derecho
  digitalWrite(in1, LOW);     // Llanta izquierda hacia atrás
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);     // Llanta derecha hacia atrás
  digitalWrite(in4, HIGH);
  delay(tiempo); // Retroceder por el tiempo especificado
  detener();     // Detener al finalizar
}

// Función para girar a la derecha (mover llantas izquierdas hacia adelante y derechas hacia atrás)
void girarDerecha(int tiempo) {
  Serial.println("Girando a la derecha...");
  digitalWrite(enA, HIGH);    // Activar motor izquierdo
  digitalWrite(enB, HIGH);    // Activar motor derecho
  digitalWrite(in1, HIGH);    // Llantas izquierdas hacia adelante
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);     // Llantas derechas hacia atrás
  digitalWrite(in4, HIGH);
  delay(tiempo); // Girar por el tiempo especificado
  detener();     // Detener al finalizar
}

// Función para girar a la izquierda (mover llantas derechas hacia adelante y las izquierdas hacia atrás)
void girarIzquierda(int tiempo) {
  Serial.println("Girando a la izquierda...");
  digitalWrite(enA, HIGH);    // Activar motor izquierdo
  digitalWrite(enB, HIGH);    // Activar motor derecho
  digitalWrite(in1, LOW);     // Llantas izquierdas hacia atrás
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);    // Llantas derechas hacia adelante
  digitalWrite(in4, LOW);
  delay(tiempo); // Girar por el tiempo especificado
  detener();     // Detener al finalizar
}

// Función para detener el carrito (parar todos los motores)
void detener() {
  Serial.println("Deteniendo el carrito...");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, LOW);     // Desactivar motor izquierdo
  digitalWrite(enB, LOW);     // Desactivar motor derecho
  delay(1000); // Esperar 1 segundo para asegurar que todo esté detenido
}

void loop() {
  avanzar(3000);      // Avanzar durante 3 segundos
  retroceder(3000);   // Retroceder durante 3 segundos
  girarDerecha(2000); // Girar a la derecha durante 2 segundos
  girarIzquierda(2000); // Girar a la izquierda durante 2 segundos
}
