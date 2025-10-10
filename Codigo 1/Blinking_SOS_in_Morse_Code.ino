// La función corre una vez cuando se presiona reset o power en el ESP32
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
}

// Función loop para hacer una repetición del codigo
void loop() {
#ifdef LED_BUILTIN
  int blinkCount = 0; // Variables para iniciar los contadores
  int blinkCount2 = 0;
  int blinkCount3 = 0;

  // Destello del LED 3 veces usando un do-while y un contador
  // Este ciclo simboliza S en codigo morse
  do {
    digitalWrite(LED_BUILTIN, HIGH); // Enciende el LED
    delay(200);                 // Espera por 200 milisegundos
    digitalWrite(LED_BUILTIN, LOW);  // Apaga el LED
    delay(200);                 // Espera por 200 milisegundos
    blinkCount++;               // Incremento del contador +1
  } while (blinkCount < 3);     // El ciclo se repite hasta que el contador tenga un valor de 3

  digitalWrite(LED_BUILTIN, LOW); //Apagado del LED para simbolizar el nuevo ciclo de parpadeo que representa una letra nueva
  delay(600);
  
  // Este ciclo simboliza O en codigo morse
  do {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(800);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    blinkCount2++;
  } while (blinkCount2 < 3);

  digitalWrite(LED_BUILTIN, LOW);
  delay(600);

  // Este ciclo simboliza S en codigo morse
  do {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);                 
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    blinkCount3++;
  } while (blinkCount3 < 3);

  digitalWrite(LED_BUILTIN, LOW); // Apagado de LED durante un tiempo más largo en comparación a los que separa cada letra de SOS para simbolizar un reinicio
  delay(2000); 

#endif
}
