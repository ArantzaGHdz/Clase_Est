// Constantes a las que se les asgina el numero de pin físico que estan conectados a los botones
int BOTON_SOS = 4;   // Pin 4 conectado al boton que ejecuta 'SOS()'
int BOTON_Blink = 5; // Pin 5 conectado al boton que ejecuta 'Blink()'
int BOTON_Pulse = 6; // Pin 6 conectado al boton que ejecuta 'Pulse()'

void setup() {
  // Comandos para detectar el LED y los botones conectados
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(BOTON_SOS, INPUT_PULLUP);
  pinMode(BOTON_Blink, INPUT_PULLUP);
  pinMode(BOTON_Pulse, INPUT_PULLUP);
}

void loop() {
  // Condicionales que detectan los estados de los botones para ejecutar los metodos especificados
  // Si el boton conectado al pin 4(BOTON_SOS) se presiona: Ejecuta el metodo del efecto de destellos SOS
  if (digitalRead(BOTON_SOS) == LOW) {
    SOS(); 
  }

  // Si el boton conectado al pin 5(BOTON_Blink) se presiona: Ejecuta el metodo del efecto Blink
  else if (digitalRead(BOTON_Blink) == LOW) {
    Blink();
  }

  // Si el boton conectado al pin 6(BOTON_Pulse) se presiona: Ejecuta el metodo del efecto Pulse
  else if (digitalRead(BOTON_Pulse) == LOW) {
    Pulse(); 
  }
}

// Efecto de SOS
void SOS() {
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

  // Apagado del LED
  rgbLedWrite(LED_BUILTIN, 0,0,0);
}

// Efecto de blink
void Blink() {
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
  
  // Apagado del LED
  rgbLedWrite(LED_BUILTIN, 0,0,0);
}


// Efecto de pulse
void Pulse() {
  for (int r=0; r<=255; r++){
    rgbLedWrite(LED_BUILTIN, r,r,r);
    delay(10);
  }

  for (int r=255; r>=0; r--){
    rgbLedWrite(LED_BUILTIN, r,r,r);
    delay(10);
  }
}

