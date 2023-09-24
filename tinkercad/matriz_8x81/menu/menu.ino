void publik() {
    Serial.println("Opciones del menu:");
    Serial.println("1. verificar matriz");
    Serial.println("2. digitar imagen");
    Serial.println("3. verificar matriz por usuario");
    Serial.println("4. elegir imagen ");
    Serial.println("5. mostrar patrones ");
    Serial.print("Seleccione una opcion: ");

    while (!Serial.available()) {}
    int opcion = Serial.parseInt();
    Serial.println(opcion);

    switch (opcion) {
        case 1:
            verificacion();
            break;
        case 2:
            user_patterns();
            break;
        case 3:
            mostrador(verificacion);
            break;
        case 4:
            delay_millis();
            break;
        case 5:
            delay_millis();
            break;
        default:
            Serial.println("Opción no válida");
            break;
    }
}