#include <IRremote.h>    // importa libreria IRremote

int SENSOR = 11;    // sensor KY-022 a pin digital 11  
IRrecv irrecv(SENSOR);    // establece al 11 para objeto irrecv
decode_results codigo;    // crea objeto codigo de la clase decode_results

void setup() { 
  Serial.begin(9600);     // inicializa comunicacion serie a 9600 bps
  irrecv.enableIRIn();    // inicializa recepcion de datos
} 

void loop() { 
  if (irrecv.decode(&codigo)) {   // si existen datos ya decodificados entonces:
    Serial.println(codigo.value, HEX);  // imprime valor en hexadecimal en monitor
    irrecv.resume();      // resume la adquisicion de datos
  }
  delay (100);        // breve demora de 100 ms.
}
