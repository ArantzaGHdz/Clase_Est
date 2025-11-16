// Constantes a las que se les asgina el numero de pin físico que estan conectados a los botones
int BOTON_SOS = 4;   // Pin 4 conectado al boton que ejecuta 'SOS()'
int BOTON_Blink = 5; // Pin 5 conectado al boton que ejecuta 'Blink()'
int BOTON_Pulse = 6; // Pin 6 conectado al boton que ejecuta 'Pulse()'
int BOTON_Int = 7;   // Pin 7, ejecuta el metodo de interrupcion

// Método de interrupción que se almacena en la RAM(para más velocidad)
// Se ejecutan las instrucciones especificadas dentro del método
void IRAM_ATTR FunInterrup(){
  rgbLedWrite(LED_BUILTIN,0,0,0);
}

void setup() {
  // Comandos para detectar el LED y los botones conectados
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(BOTON_SOS, INPUT_PULLUP);
  pinMode(BOTON_Blink, INPUT_PULLUP);
  pinMode(BOTON_Pulse, INPUT_PULLUP);
  pinMode(BOTON_Int, INPUT_PULLUP);

  // Función principal que configura la interrupción. Le dice al microcontrolador que pause su tarea actual 
  // y ejecute una función especial cuando ocurra un evento específico en el pin previamente determinado por la constante BOTON_Int
  // El evento esta conformado por la pulsación del boton de interrupción conectado al pin 7(BOTON_Int) para llamar al método FunInterrup
  attachInterrupt(digitalPinToInterrupt(BOTON_Int),FunInterrup,FALLING);
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

  rgbLedWrite(LED_BUILTIN, 0,0,0);
}

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

  rgbLedWrite(LED_BUILTIN, 0,0,0);
}

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