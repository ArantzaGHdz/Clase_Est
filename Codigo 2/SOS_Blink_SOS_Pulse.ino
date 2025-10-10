// La función corre una vez cuando se presiona reset o power en el ESP32
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
}

// Función loop para hacer una repetición del codigo
void loop() {
#ifdef LED_BUILTIN

  //rgbLedWrite(valor de rojo, valor de verde, valor de azul) se utiliza para ajustar los valores de color rojo, verde y azul 
  // con el fin de modificar la intensidad y/o el color del LED
  // 255 es el valor que representa la mayor intensidad mientras que 0 representa nada de intensidad o apagado.
  //  - - - P R I M E R  S O S - - -
  // Simboliza un S en codigo morse
  rgbLedWrite(LED_BUILTIN, 255,0,0); // Enciende el LED en color rojo
  delay(200);                 // Espera por 200 milisegundos
  rgbLedWrite(LED_BUILTIN, 0,0,0);  // Apaga el LED
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,255,0); // Enciende el LED en color verde
  delay(200);                 // Espera por 200 milisegundos
  rgbLedWrite(LED_BUILTIN, 0,0,0);  // Apaga el LED
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,255); // Enciende el LED en color azul
  delay(200);                 // Espera por 200 milisegundos

  rgbLedWrite(LED_BUILTIN, 0,0,0); //Apagado del LED para simbolizar el nuevo bloque de parpadeos que representan una letra nueva
  delay(600);
  
  // Simboliza O en codigo morse
  rgbLedWrite(LED_BUILTIN, 255,0,0);
  delay(800);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,255,0);
  delay(800);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,255);
  delay(800);

  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(600);

  // Simboliza S en codigo morse
  rgbLedWrite(LED_BUILTIN, 255,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,255,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,255);
  delay(200);

  rgbLedWrite(LED_BUILTIN, 0,0,0); // Separador de tipos de destello o acciones diferentes sobre el LED
  delay(1000); 

  // - - - 7  B L I N K S - - -
  // 7 destellos en diferentes colores dependiendo de las variaciones puestas en las entradas de valores rojo, verde y azul
  rgbLedWrite(LED_BUILTIN, 255,0,0); // Rojo
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 255,165,0); // Naranja
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 255,255,0); //Amarillo
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,255,0); // Verde
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,255); // Azul
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 25,25,112); // Azul oscuro
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 128,0,128); // Morado
  delay(200);

  digitalWrite(LED_BUILTIN, 0); // Separador de tipos de destello o acciones diferentes sobre el LED
  delay(1000);

  // - - - S E G U N D O  S O S - - -
  // Simboliza un S en codigo morse
  rgbLedWrite(LED_BUILTIN, 255,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,255,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,255);
  delay(200);

  rgbLedWrite(LED_BUILTIN, 0,0,0); //Apagado del LED para simbolizar el nuevo bloque de parpadeos que representan una letra nueva
  delay(600);
  
  // Simboliza O en codigo morse
  rgbLedWrite(LED_BUILTIN, 255,0,0);
  delay(800);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,255,0);
  delay(800);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,255);
  delay(800);

  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(600);

  // Simboliza S en codigo morse
  rgbLedWrite(LED_BUILTIN, 255,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,255,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,0);
  delay(200);
  rgbLedWrite(LED_BUILTIN, 0,0,255);
  delay(200);

  rgbLedWrite(LED_BUILTIN, 0,0,0); // Separador de tipos de destello o acciones diferentes sobre el LED
  delay(1000);

  // - - - P U L S E - - -
  // 2 ciclos for para realizar la subida y la bajada de la intensidad del brillo del LED
  // r representa un valor unitario que sube o baja, dependiendo de la situación, por ejemplo; 0,0,0; 1,1,1; 2,2,2; etc.
  // el valor de r representa la intensidad del brillo que se añade a esa sección; la resta o suma se hacen de manera uniforme
  // para sumar los tres valores de rojo, verde y azul con el fin de realizar una adición que resulta en el color blanco
  // NOTA: este es el principio de la teoría del color RGB

  int pulseCount = 0; // Se crea una variable que representa un contador con la finalidad de repetir el proceso 7 veces

  do {
    for (int r=0; r<=255; r++){
    rgbLedWrite(LED_BUILTIN, r,r,r);
    delay(10);
    }

    for (int r=255; r>=0; r--){
    rgbLedWrite(LED_BUILTIN, r,r,r);
    delay(10);
    }
    pulseCount++;
  } while(pulseCount < 7); // El ciclo de pulse se repite hasta que el contador llegue a 7
  

  digitalWrite(LED_BUILTIN, 0); // Apagado de LED durante un tiempo largo para simbolizar un reinicio de todo el proceso
  delay(2000);

#endif
}
