#include <IRremote.h>    // importa libreria IRremote
#define b_1 0x51731C91
#define b_2 0x4A1144F9
#define b_3 0x226873C1
#define b_4 0x10957521
#define b_5 0xC0E837B9
#define b_6 0x7A3D9EE1

#define b_stop 0x1D15F4D7
#define b_pause 0xAA7B2167
#define b_play 0xDEC919A5

#define b_enter 0xB520CEC

#define b_NORTH 0xE246AFCA
#define b_SOUTH 0x3AFB26D4
#define b_EAST 0x4D43596A
#define b_WEST 0xBB0EDD22

int SENSOR = 11;    // sensor KY-022 a pin digital 11  
IRrecv irrecv(SENSOR);    // establece al 11 para objeto irrecv
decode_results codigo;    // crea objeto codigo de la clase decode_results

int NORTH_LEDS = 3;
int SOUTH_LEDS = 2;
int EAST_LEDS = 5;
int WEST_LEDS = 4;

void setup() { 
  Serial.begin(9600);     // inicializa comunicacion serie a 9600 bps
  irrecv.enableIRIn();    // inicializa recepcion de datos
  pinMode(NORTH_LEDS,OUTPUT);
  pinMode(SOUTH_LEDS,OUTPUT);
  pinMode(EAST_LEDS,OUTPUT);
  pinMode(WEST_LEDS,OUTPUT);
} 

void loop() { 
  if (irrecv.decode(&codigo)) {   // si existen datos ya decodificados entonces:
    Serial.println(codigo.value, HEX);  // imprime valor en hexadecimal en monitor
    if (codigo.value == b_NORTH)
    digitalWrite(NORTH_LEDS,!digitalRead(NORTH_LEDS));
    if (codigo.value == b_SOUTH)
    digitalWrite(SOUTH_LEDS,!digitalRead(SOUTH_LEDS));
    if (codigo.value == b_EAST)
    digitalWrite(EAST_LEDS,!digitalRead(EAST_LEDS));
    if (codigo.value == b_WEST)
    digitalWrite(WEST_LEDS,!digitalRead(WEST_LEDS));
    
    irrecv.resume();      // resume la adquisicion de datos
  }
  delay (100);        // breve demora de 100 ms.
}
