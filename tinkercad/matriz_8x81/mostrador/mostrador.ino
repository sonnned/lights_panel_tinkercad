void mostrador(void (*func)()) {
    bool condicion=true;
    unsigned long tiempo;
    int vuelta=0;
    unsigned long repe;
    unsigned long intervalo;

    Serial.print("Ingrese el numero de repeticiones que quiere(entero positivo): ");
    while (!Serial.available()) {}
    repe =Serial.parseInt();
    Serial.println(repe);

    Serial.print("Ingrese el intervalo (en segundos): ");
    while (!Serial.available()) {}
    intervalo = 1000 * Serial.parseInt();
    Serial.println(intervalo);


    tiempo=millis();
    while(vuelta<repe){
        if(millis()-tiempo<intervalo){
            if(condicion){
                func();
            }
        }
        else{
            digitalWrite(reloj_salida, LOW);
            shiftOut(entrada, reloj_desplazamiento, MSBFIRST, 0);
            shiftOut(entrada, reloj_desplazamiento, MSBFIRST, 0);
            digitalWrite(reloj_salida, HIGH);
            condicion=!condicion;
            tiempo=millis();
            if(condicion){
                vuelta++;
            }
        }
    }
}