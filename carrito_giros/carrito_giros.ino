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

void loop() {
  // 1. Probar llanta izquierda delantera (Motor izquierdo usando IN1)
  Serial.println("Probando llanta izquierda delantera - Adelante");
  digitalWrite(enA, HIGH);    // Activar motor izquierdo
  digitalWrite(enB, LOW);     // Desactivar motor derecho
  digitalWrite(in1, HIGH);    // Llanta izquierda delantera hacia adelante
  digitalWrite(in2, LOW);
  delay(3000);

  Serial.println("Probando llanta izquierda delantera - Atras");
  digitalWrite(in1, LOW);     // Llanta izquierda delantera hacia atrás
  digitalWrite(in2, HIGH);
  delay(3000);

  // Detener llanta izquierda delantera
  digitalWrite(in1, LOW);  
  digitalWrite(in2, LOW);
  delay(1000);

  // 2. Probar llanta izquierda trasera (Motor izquierdo usando IN2)
  Serial.println("Probando llanta izquierda trasera - Adelante");
  digitalWrite(enA, HIGH);    // Activar motor izquierdo
  digitalWrite(in1, LOW);     // Asegurarse de que la delantera está apagada
  digitalWrite(in2, HIGH);    // Llanta izquierda trasera hacia adelante
  delay(3000);

  Serial.println("Probando llanta izquierda trasera - Atras");
  digitalWrite(in1, HIGH);    // Llanta izquierda trasera hacia atrás
  digitalWrite(in2, LOW);
  delay(3000);

  // Detener llanta izquierda trasera
  digitalWrite(in1, LOW);  
  digitalWrite(in2, LOW);
  delay(1000);

  // 3. Probar llanta derecha delantera (Motor derecho usando IN3)
  Serial.println("Probando llanta derecha delantera - Adelante");
  digitalWrite(enB, HIGH);    // Activar motor derecho
  digitalWrite(enA, LOW);     // Desactivar motor izquierdo
  digitalWrite(in3, HIGH);    // Llanta derecha delantera hacia adelante
  digitalWrite(in4, LOW);
  delay(3000);

  Serial.println("Probando llanta derecha delantera - Atras");
  digitalWrite(in3, LOW);     // Llanta derecha delantera hacia atrás
  digitalWrite(in4, HIGH);
  delay(3000);

  // Detener llanta derecha delantera
  digitalWrite(in3, LOW);  
  digitalWrite(in4, LOW);
  delay(1000);

  // 4. Probar llanta derecha trasera (Motor derecho usando IN4)
  Serial.println("Probando llanta derecha trasera - Adelante");
  digitalWrite(enB, HIGH);    // Activar motor derecho
  digitalWrite(in3, LOW);     // Asegurarse de que la delantera está apagada
  digitalWrite(in4, HIGH);    // Llanta derecha trasera hacia adelante
  delay(3000);

  Serial.println("Probando llanta derecha trasera - Atras");
  digitalWrite(in3, HIGH);    // Llanta derecha trasera hacia atrás
  digitalWrite(in4, LOW);
  delay(3000);

  // Detener llanta derecha trasera
  digitalWrite(in3, LOW);  
  digitalWrite(in4, LOW);
  delay(1000);
}
