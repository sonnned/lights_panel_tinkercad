int reloj_salida=3;
int reloj_desplazamiento=4;
int entrada=2;
int data = 500;

unsigned long tiempo_inicial = millis();
unsigned long tiempo_esperado = 0;
boolean tiempo_completado = false;

int cantidad_iteraciones = 0;
int contador = 0;

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
  while(vuelta < repe){
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

void mostrador_automatico(int r, int i, void (*func)()) {   
  bool condicion=true;
  unsigned long tiempo;
  int vuelta=0;
  unsigned long repe = r;
  unsigned long intervalo = i * 1000;
  
  tiempo=millis();
  while(vuelta < repe){
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

void clean_patterns() {
  shiftOut(entrada, reloj_desplazamiento, MSBFIRST, B00000000);
  shiftOut(entrada, reloj_desplazamiento, MSBFIRST, 0);

  digitalWrite(reloj_salida, HIGH);
  digitalWrite(reloj_salida, LOW);
}

void delay_millis() {
  int contador_externo = 0;
  int repe, intervalo;
  
  while (contador_externo < 4) {
    if (!tiempo_completado) {
      cantidad_iteraciones = 4;
      Serial.print("Ingrese tiempo en segundos para retardar los patrones (0-9): ");

      while (!Serial.available()) {}
      	tiempo_esperado = Serial.read() - '0';
    	Serial.println(tiempo_esperado);

    	tiempo_inicial = millis();
    	tiempo_completado = true;
      
      Serial.print("Cantidad repeticiones patron: ");
      while (!Serial.available()) {}
      repe = Serial.parseInt();
      Serial.println(repe);
      
      Serial.print("Cantidad tiempo ejecucion patron: ");
      while (!Serial.available()) {}
      intervalo = Serial.parseInt();
      Serial.println(intervalo);
    }

    while (tiempo_completado && (millis() - tiempo_inicial < tiempo_esperado * 1000)) {}
  
    if (tiempo_completado && (millis() - tiempo_inicial >= tiempo_esperado * 1000)) {
      if (contador == 0) {
        mostrador_automatico(repe, intervalo, create_first_pattern);
        contador_externo++;
      } else if (contador == 1) {
        mostrador_automatico(repe, intervalo, create_second_pattern);
        contador_externo++;
      } else if (contador == 2) {
        mostrador_automatico(repe, intervalo, create_third_pattern);
        contador_externo++;
      } else if (contador == 3) {
        mostrador_automatico(repe, intervalo, create_fourth_pattern);
        contador_externo++;
      }
      clean_patterns();
      tiempo_inicial = millis();
      contador++;

      if (contador >= cantidad_iteraciones) {
        tiempo_completado = false;
        contador = 0;
      }
    }
  }
}

void user_patterns() {
  Serial.println("Opciones patrones usuario:");
  Serial.println("1. patron nubes");
  Serial.println("2. patron ajedrez");
  Serial.println("3. patron cambio");
  Serial.println("4. patron parpadeo");
  Serial.print("Seleccione una opcion: ");
  
  while (!Serial.available()) {}
  int opcion = Serial.parseInt(); 
  Serial.println(opcion);
  
  switch (opcion) {
    case 1:
    	create_cloud_pattern();
    	clean_patterns();
    	break;
    case 2:
    	create_chess_pattern();
    	clean_patterns();
      	break;
    case 3:
    	create_sweep_pattern();
    	clean_patterns();
      	break;
    case 4:
    	create_blink_pattern();
    	clean_patterns();
      	break;
    default:
    	Serial.println("Opción no válida");
    	break;
  }
}

void local_pattern() {
  Serial.println("Opciones patrones:");
  Serial.println("1. patron 1");
  Serial.println("2. patron 2");
  Serial.println("3. patron 3");
  Serial.println("4. patron 4");
  Serial.print("Seleccione una opcion: ");
  
  while (!Serial.available()) {}
  int opcion = Serial.parseInt(); 
  Serial.println(opcion);
  
  switch (opcion) {
    case 1:
    	mostrador(create_first_pattern);
    	clean_patterns();
    	break;
    case 2:
    	mostrador(create_second_pattern);
    	clean_patterns();
      	break;
    case 3:
    	mostrador(create_third_pattern);
    	clean_patterns();
      	break;
    case 4:
    	mostrador(create_fourth_pattern);
    	clean_patterns();
      	break;
    default:
    	Serial.println("Opción no válida");
    	break;
  }
}

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
            local_pattern();
            break;
        case 5:
            delay_millis();
            break;
        default:
            Serial.println("Opción no válida");
            break;
    }
}

void setup() {
  pinMode(entrada, OUTPUT);
  pinMode(reloj_salida, OUTPUT);
  pinMode(reloj_desplazamiento, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  publik();
}
