

void verificacion(){
byte dato=0b11111111;
int conta=0; 
while(conta<5){
shiftOut(entrada, reloj_desplazamiento, MSBFIRST,dato);  
shiftOut(entrada, reloj_desplazamiento, MSBFIRST,0);
digitalWrite(reloj_salida,HIGH);
dato=~dato; 
delay(1000);
digitalWrite(reloj_salida,LOW);
 conta++;   
}
}






