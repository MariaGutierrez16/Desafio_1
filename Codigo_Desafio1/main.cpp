// Pines de conexión
const int pinSenal = A0;     // Pin donde se recibe la señal analógica
const int botonAdquirir = 2;  // Pin del botón para iniciar la adquisición
const int botonMostrar = 3;  // Pin del botón para mostrar características

// Variables para almacenar las características de la señal
float* amplitudes;  // Puntero para almacenar amplitudes
float* frecuencias; // Puntero para almacenar frecuencias
String* tiposOnda;  // Puntero para almacenar tipos de onda
int tamanoDatos = 10;  // Tamaño del arreglo

bool adquiriendo = false;  // Variable para controlar la adquisición

void setup() {
    // Configuración de pines
    pinMode(botonAdquirir, INPUT_PULLUP);  // Configura el botón con resistencia interna
    pinMode(botonMostrar, INPUT_PULLUP);

    // Inicialización del LCD
    lcd.begin(16, 2);  // Inicializa el LCD de 16x2
    lcd.print("Listo"); // Mensaje inicial
    delay(1000);
    lcd.clear();

    // Inicialización de memoria dinámica
    amplitudes = new float[tamanoDatos];
    frecuencias = new float[tamanoDatos];
    tiposOnda = new String[tamanoDatos];
}

void loop() {
    if (digitalRead(botonAdquirir) == LOW) {
        adquiriendo = true;
        lcd.clear();
        lcd.print("Adquiriendo...");
        delay(1000);
        adquirirSenal();
        adquiriendo = false;
        lcd.clear();
        lcd.print("Datos listos");
        delay(1000);
        lcd.clear();
    }

    if (digitalRead(botonMostrar) == LOW) {
        if (adquiriendo) {
            adquiriendo = false;  // Suspender la adquisición
        }
        lcd.clear();
        lcd.print("Amp: ");
        lcd.print(amplitudes[0], 2);
        lcd.print(" V");
        delay(2000);
        lcd.clear();
        lcd.print("Freq: ");
        lcd.print(frecuencias[0], 2);
        lcd.print(" Hz");
        delay(2000);
        lcd.clear();
        lcd.print("Onda: ");
        lcd.print(tiposOnda[0]);
        delay(2000);
        lcd.clear();
        adquiriendo = true;  // Reanudar la adquisición
    }
}

// Función para adquirir la señal
void adquirirSenal() {
    for (int i = 0; i < tamanoDatos; i++) {
        // Simulamos la adquisición de datos de la señal desde el pin analógico
        int valorSenal = analogRead(pinSenal);

        // Calcula la amplitud (ejemplo simplificado)
        amplitudes[i] = (valorSenal / 1023.0) * 5.0;  // Convertimos el valor analógico a voltaje (0-5V)

        // Calcula la frecuencia (ejemplo simplificado)
        frecuencias[i] = random(50, 1500);  // Valor simulado de frecuencia entre 50 Hz y 1500 Hz

        // Determina el tipo de onda basado en la señal (ejemplo simplificado)
        if (valorSenal > 800) {
            tiposOnda[i] = "Senoidal";
        } else if (valorSenal > 400) {
            tiposOnda[i] = "Cuadrada";
        } else {
            tiposOnda[i] = "Triangular";
        }
    }
}

void limpiar() {
    // Liberar memoria dinámica
    delete[] amplitudes;
    delete[] frecuencias;
    delete[] tiposOnda;
}
