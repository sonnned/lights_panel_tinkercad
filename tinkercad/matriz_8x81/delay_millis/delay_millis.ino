unsigned long tiempo_inicial = 0;
unsigned long tiempo_esperado = 0;
boolean tiempo_completado = false;

int cantidad_iteraciones = 0;
int contador = 0;

void delay_millis() {
    if (!tiempo_completado) {
        Serial.print("Cuantas iteraciones desea: ");

        while (!Serial.available()) {}
        cantidad_iteraciones = Serial.read() - '0';
        Serial.println(cantidad_iteraciones);

        Serial.print("Ingrese tiempo en segundos para retardar los patrones (0-9): ");

        while (!Serial.available()) {}
        tiempo_esperado = Serial.read() - '0';
        Serial.println(tiempo_esperado);

        tiempo_inicial = millis();
        tiempo_completado = true;
    }

    if (tiempo_completado && (millis() - tiempo_inicial >= tiempo_esperado * 1000)) {
        Serial.println("Paso el tiempo deseado");
        tiempo_inicial = millis();
        contador++;

        if (contador >= cantidad_iteraciones) {
            tiempo_completado = false;
            contador = 0;
        }
    }
}
