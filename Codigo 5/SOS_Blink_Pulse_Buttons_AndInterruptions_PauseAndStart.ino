// Constantes a las que se les asigna el numero de pin físico que estan conectados a los botones
int BOTON_SOS = 4;   // Pin 4 conectado al boton que ejecuta 'SOS()'
int BOTON_Blink = 5; // Pin 5 conectado al boton que ejecuta 'Blink()'
int BOTON_Pulse = 6; // Pin 6 conectado al boton que ejecuta 'Pulse()'
int BOTON_Int = 7;   // Pin 7, ejecuta el metodo de interrupcion

// Es un manejador que permite interruptir y resumir tareas
TaskHandle_t xControllableTaskHandle = NULL;

// Metodo que revisa si el boton de interrupcion es presionado
void pausa(void *pvParameters) {
  bool pausado = false;

  for (;;) {
    if (digitalRead(BOTON_Int) == LOW) {
      vTaskDelay(pdMS_TO_TICKS(50)); // Desactiva el rebote de la entrada para evitar múltiples activaciones con una sola presión
      if (digitalRead(BOTON_Int) == LOW) { // Se confirma la pulsacion
        // Se revisa el bool de pausado para revisar si la tarea debe ser resumida o pausada
        if (pausado) {
          vTaskResume(xControllableTaskHandle); // Se continua con la tarea
          pausado = false;
        } else {
          vTaskSuspend(xControllableTaskHandle); // Se pausa la tarea
          pausado = true;
        }
        while (digitalRead(BOTON_Int) == LOW); // La función espera a que el boton deje de ser pulsado para iniciar
      }
    }
    vTaskDelay(pdMS_TO_TICKS(10)); // Pequeño retraso para evitar una espera activa donde constantemente se espera confirmación
  }
}

void setup() {
  // Comandos para detectar el LED y los botones conectados
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(BOTON_SOS, INPUT_PULLUP);
  pinMode(BOTON_Blink, INPUT_PULLUP);
  pinMode(BOTON_Pulse, INPUT_PULLUP);
  pinMode(BOTON_Int, INPUT_PULLUP);

  xTaskCreate(
    actividadesLED,              // Nombre del metodo que se convierte en tarea
    "Actividades con el LED",    // Un nombre descriptivo para la tarea
    2048,                        // El tamaño de la pila (stack) de la tarea, especificado en bytes en el entorno ESP32
    NULL,                        // Un puntero que pasa parámetros o datos a la función de la tarea cuando esta se inicia.
    1,                           // La prioridad en la que se ejecutará la tarea.
    &xControllableTaskHandle 
    // Un puntero a una variable de tipo TaskHandle_t*. Si la creación es exitosa, se utiliza para devolver un identificador
    // mediante el cual la tarea puede ser referenciada y manipulada
  );

  xTaskCreate(
    pausa,
    "Pausa",
    2048,
    NULL,
    2,
    NULL
  );
}

void loop() {
  // El contenido de loop se movio al metodo de actividadesLED para realizar las pausas y continuaciones.
}

// Metodo que se convierte en una tarea que contiene la selección de botones.
void actividadesLED(void *pvParameters) {
  // Ciclo infintito para que la función que se convierte en un tarea siempre este funcionando
  for(;;){
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