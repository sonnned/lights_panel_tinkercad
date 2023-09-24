unsigned long tiempo_inicial = 0;
unsigned long tiempo_esperado = 0;
boolean tiempo_completado = false;

int cantidad_iteraciones = 0;
int contador = 0;

void delay_millis() {
    if (!tiempo_completado) {
        cantidad_iteraciones = 4;

        Serial.print("Ingrese tiempo en segundos para retardar los patrones (0-9): ");

        while (!Serial.available()) {}
        tiempo_esperado = Serial.read() - '0';
        Serial.println(tiempo_esperado);

        tiempo_inicial = millis();
        tiempo_completado = true;
    }

    if (tiempo_completado && (millis() - tiempo_inicial >= tiempo_esperado * 1000)) {
        if (contador == 0) {
            mostrador(create_first_pattern);
            clean_patterns();
        } else if (contador == 1) {
            mostrador(create_second_pattern);
            clean_patterns();
        } else if (contador == 2) {
            mostrador(create_third_pattern);
            clean_patterns();
        } else if (contador == 3) {
            mostrador(create_fourth_pattern);
            clean_patterns();
        }
        tiempo_inicial = millis();
        contador++;

        if (contador >= cantidad_iteraciones) {
            tiempo_completado = false;
            contador = 0;
        }
    }
}