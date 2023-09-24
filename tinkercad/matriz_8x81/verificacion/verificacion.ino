void verificacion() {
    bool condicion=true;
    unsigned long tiempo;
    int vuelta=0;
    unsigned long repe=2;
    unsigned long intervalo=1000;

    tiempo=millis();
    while(vuelta<repe){
        if(millis()-tiempo<intervalo){
            if(condicion){
                digitalWrite(reloj_salida, LOW);
                shiftOut(entrada, reloj_desplazamiento, MSBFIRST, 0b11111111);
                shiftOut(entrada, reloj_desplazamiento, MSBFIRST, 0);
                digitalWrite(reloj_salida, HIGH);
            }
        } else {
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