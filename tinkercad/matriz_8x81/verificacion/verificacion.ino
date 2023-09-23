

void verificacion() {


  digitalWrite(reloj_salida, LOW);
  shiftOut(entrada, reloj_desplazamiento, MSBFIRST, 0b11111111);
  shiftOut(entrada, reloj_desplazamiento, MSBFIRST, 0);
  digitalWrite(reloj_salida, HIGH);

}

}    
 


