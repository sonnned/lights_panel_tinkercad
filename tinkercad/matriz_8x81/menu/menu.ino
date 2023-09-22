
void mostrarMenu() {
 
  Serial.println("Opciones del menu:");
  Serial.println("1. verificar matriz");
  Serial.println("2. digitar imagen");
  Serial.println("3. verificar matriz por usuario");
  Serial.println("4. elegir imagen ");
  Serial.println("5. mostrar patrones ");
 


  Serial.print("Seleccione una opcion: ");
  while (!Serial.available()) {
   
  }

  int opcion = Serial.parseInt(); 
  
  switch (opcion) {
    case 1:
  verificacion();
  
      break;
    case 2:
    
      break;
    case 3:
      break;
    case 4:
    
      break;
    case 5:
    
      break;
    default:
    
      Serial.println("Opción no válida");
  }
}
