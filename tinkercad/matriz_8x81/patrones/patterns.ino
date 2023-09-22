void create_first_pattern() {
    byte left = B00010000;
    byte right = B00001000;

    byte left_2 = B10000000;
    byte right_2 = B00000001;
    byte prev_2 = B00000000;

    for (int i = 0; i < 8; i++) {
        byte dato = left | right;
        byte dato_2 = prev_2;

        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato);
        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato_2);

        digitalWrite(reloj_salida, HIGH);
        left <<= 1;
        right >>= 1;
        prev_2 = left_2 | prev_2 | right_2;
        left_2 >>= 1;
        right_2 <<= 1;
        digitalWrite(reloj_salida, LOW);
    }
}


void create_second_pattern() {
    //DP
    byte dato = B10000000;
    //habilita filas
    byte dato_2 = B01111111;
    //DS
    byte dato_3 = B10000000;
    byte dato_4 = B11111110;
    int counter = 0;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++) {
            if (i == j) {
                shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato);
                shiftOut(entrada, reloj_desplazamiento, MSBFIRST,dato_2);

                digitalWrite(reloj_salida,HIGH);
                dato >>= 1;
                dato_2 = ~dato_2;
                dato_2 = dato_2 >> 1;
                dato_2 = ~dato_2;
                digitalWrite(reloj_salida,LOW);
            } else if (i + j == 8 - 1) {
                shiftOut(entrada, reloj_desplazamiento, MSBFIRST,dato_3);
                shiftOut(entrada, reloj_desplazamiento, MSBFIRST,dato_4);

                digitalWrite(reloj_salida,HIGH);
                dato_3 >>= 1;
                dato_4 = ~dato_4;
                dato_4 = dato_4 << 1;
                dato_4 = ~dato_4;
                digitalWrite(reloj_salida,LOW);
            }
        }
    }
}

void create_third_pattern() {
    byte dato = B11011011;
    byte dato_2 = B00110011;

    for (int i = 0; i < 2; i++) {
        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato);

        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato_2);
        digitalWrite(reloj_salida,HIGH);
        dato >>= 1;
        dato_2 <<= 1;
        dato_2 <<= 1;

        digitalWrite(reloj_salida,LOW);
    }
}

void create_fourth_pattern() {
    byte dato = B11110000;
    byte dato_2 = B01111111;
    byte auxiliar = B10000000;
    byte prev;

    for (int i = 0; i < 4; i++) {
        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato);

        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato_2);
        digitalWrite(reloj_salida,HIGH);
        dato >>= 1;

        prev = auxiliar;
        auxiliar >>= 1;
        auxiliar = prev | auxiliar;
        dato_2 >>= 1;
        dato_2 = dato_2 | prev;
        digitalWrite(reloj_salida,LOW);
    }

    dato = B11110000;
    dato_2 = B11111110;
    auxiliar = B00000001;
    for (int i = 0; i < 4; i++) {
        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato);

        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato_2);
        digitalWrite(reloj_salida,HIGH);
        dato >>= 1;

        prev = auxiliar;
        auxiliar <<= 1;
        auxiliar = prev | auxiliar;
        dato_2 <<= 1;
        dato_2 = dato_2 | prev;
        digitalWrite(reloj_salida,LOW);
    }
}

void create_chess_pattern() {
    byte dato = B10101010;
    byte dato_2 = B01010101;

    for (int i = 0; i < 2; i++) {
        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato);
        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato_2);

        digitalWrite(reloj_salida, HIGH);
        dato >>= 1;
        dato_2 <<= 1;
        delay(200);

        digitalWrite(reloj_salida, LOW);
    }
}

void create_blink_pattern() {
    for (int i = 0; i < 4; i++) {
        byte dato = B11111111;
        byte dato_2 = B00000000;

        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato);
        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato_2);

        digitalWrite(reloj_salida, HIGH);
        delay(100);
        digitalWrite(reloj_salida, LOW);

        dato = B00000000;
        dato_2 = B11111111;

        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato);
        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato_2);

        digitalWrite(reloj_salida, HIGH);
        delay(100);
        digitalWrite(reloj_salida, LOW);
    }
}

void create_sweep_pattern() {
    byte dato = B00000001;
    byte dato_2 = B11111110;

    for (int i = 0; i < 4; i++) {
        for (int i = 0; i < 7; i++) {
            shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato);
            shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato_2);

            digitalWrite(reloj_salida, HIGH);
            delay(100);
            digitalWrite(reloj_salida, LOW);

            dato <<= 1;
            dato_2 >>= 1;
        }

        for (int i = 0; i < 7; i++) {
            shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato);
            shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato_2);

            digitalWrite(reloj_salida, HIGH);
            delay(100);
            digitalWrite(reloj_salida, LOW);

            dato >>= 1;
            dato_2 <<= 1;
        }
    }
}

void create_diagonal_blink_pattern() {
    while (true) {
        for (int i = 0; i < 8; i++) {
            byte dato = 1 << i;
            byte dato_2 = 1 << (7 - i);

            shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato);
            shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato_2);

            digitalWrite(reloj_salida, HIGH);
            delay(100);
            digitalWrite(reloj_salida, LOW);
        }
    }
}

void create_cloud_pattern() {
    byte dato = B11001100;
    byte dato_2 = B00110011;

    for (int i = 0; i < 8; i++) {
        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato);
        shiftOut(entrada, reloj_desplazamiento, MSBFIRST, dato_2);

        digitalWrite(reloj_salida, HIGH);
        dato = dato >> 1;
        dato_2 = dato_2 << 1;
        delay(100);
        digitalWrite(reloj_salida, LOW);
    }
}