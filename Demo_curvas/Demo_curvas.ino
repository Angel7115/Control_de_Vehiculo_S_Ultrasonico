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
  digitalWrite(enA, HIGH);    // Activar llantas izquierdas
  digitalWrite(enB, HIGH);    // Activar llantas derechas
  digitalWrite(in1, HIGH);    // Llanta izquierda delantera hacia adelante
  digitalWrite(in2, LOW);     // Llanta izquierda trasera hacia adelante
  digitalWrite(in3, HIGH);    // Llanta derecha delantera hacia adelante
  digitalWrite(in4, LOW);     // Llanta derecha trasera hacia adelante
  delay(tiempo);              // Avanzar por el tiempo especificado
  detener();                  // Detener al finalizar
}

// Función para retroceder (mover todas las llantas hacia atrás)
void retroceder(int tiempo) {
  Serial.println("Retrocediendo...");
  digitalWrite(enA, HIGH);    // Activar llantas izquierdas
  digitalWrite(enB, HIGH);    // Activar llantas derechas
  digitalWrite(in1, LOW);     // Llanta izquierda delantera hacia atrás
  digitalWrite(in2, HIGH);    // Llanta izquierda trasera hacia atrás
  digitalWrite(in3, LOW);     // Llanta derecha delantera hacia atrás
  digitalWrite(in4, HIGH);    // Llanta derecha trasera hacia atrás
  delay(tiempo);              // Retroceder por el tiempo especificado
  detener();                  // Detener al finalizar
}

// Función para girar a la derecha (mover llantas izquierdas hacia adelante y derechas hacia atrás)
void girarDerecha(int tiempo) {
  Serial.println("Girando a la derecha...");
  digitalWrite(enA, HIGH);    // Activar llantas izquierdas
  digitalWrite(enB, HIGH);    // Activar llantas derechas
  digitalWrite(in1, HIGH);    // Llanta izquierda delantera hacia adelante
  digitalWrite(in2, LOW);     // Llanta izquierda trasera hacia adelante
  digitalWrite(in3, LOW);     // Llanta derecha delantera hacia atrás
  digitalWrite(in4, HIGH);    // Llanta derecha trasera hacia atrás
  delay(tiempo);              // Girar por el tiempo especificado
  detener();                  // Detener al finalizar
}

// Función para girar a la izquierda (mover llantas derechas hacia adelante y las izquierdas hacia atrás)
void girarIzquierda(int tiempo) {
  Serial.println("Girando a la izquierda...");
  digitalWrite(enA, HIGH);    // Activar llantas izquierdas
  digitalWrite(enB, HIGH);    // Activar llantas derechas
  digitalWrite(in1, LOW);     // Llanta izquierda delantera hacia atrás
  digitalWrite(in2, HIGH);    // Llanta izquierda trasera hacia atrás
  digitalWrite(in3, HIGH);    // Llanta derecha delantera hacia adelante
  digitalWrite(in4, LOW);     // Llanta derecha trasera hacia adelante
  delay(tiempo);              // Girar por el tiempo especificado
  detener();                  // Detener al finalizar
}

// Función para hacer una curva a la derecha (llantas izquierdas a velocidad máxima, llantas derechas más lento)
void curvaDerecha(int tiempo) {
  Serial.println("Curva a la derecha...");
  digitalWrite(in1, HIGH);     // Llantas izquierdas hacia adelante
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);       // Velocidad máxima en llantas izquierdas
  
  digitalWrite(in3, HIGH);     // Llantas derechas hacia adelante
  digitalWrite(in4, LOW);
  analogWrite(enB, 150);       // Velocidad reducida en llantas derechas

  delay(tiempo);               // Tiempo de la curva
  detener();
}

// Función para hacer una curva a la izquierda (llantas derechas a velocidad máxima, llantas izquierdas más lento)
void curvaIzquierda(int tiempo) {
  Serial.println("Curva a la izquierda...");
  digitalWrite(in1, HIGH);     // Llantas izquierdas hacia adelante
  digitalWrite(in2, LOW);
  analogWrite(enA, 150);       // Velocidad reducida en llantas izquierdas
  
  digitalWrite(in3, HIGH);     // Llantas derechas hacia adelante
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);       // Velocidad máxima en llantas derechas

  delay(tiempo);               // Tiempo de la curva
  detener();
}

// Función para detener el carrito (parar todos los motores)
void detener() {
  Serial.println("Deteniendo el carrito...");
  digitalWrite(in1, LOW);     // Detener llanta izquierda delantera
  digitalWrite(in2, LOW);     // Detener llanta izquierda trasera
  digitalWrite(in3, LOW);     // Detener llanta derecha delantera
  digitalWrite(in4, LOW);     // Detener llanta derecha trasera
  digitalWrite(enA, LOW);     // Desactivar llantas izquierdas
  digitalWrite(enB, LOW);     // Desactivar llantas derechas
  delay(1000);                // Esperar 1 segundo para asegurar que todo esté detenido
}

void loop() {
  avanzar(1000);        // Avanzar durante 1 segundo
  retroceder(1000);     // Retroceder durante 1 segundo
  girarDerecha(550);    // Girar a la derecha durante 0.5 segundos
  girarIzquierda(610);  // Girar a la izquierda durante 0.6 segundos

  // Curvas suaves al final
  curvaDerecha(2000); // Curva a la derecha durante 2 segundos
  curvaIzquierda(2000); // Curva a la izquierda durante 2 segundos
  detener();
}
