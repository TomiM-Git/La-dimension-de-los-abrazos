
int RelayController = 8 ;




void setup() {
   pinMode(RelayController, OUTPUT); // we will control the relay with one pin to choose either CW or CCW
}

void loop() {
 digitalWrite(RelayController, LOW); // to attach the relay with +12 Volts to turn the DC-Motor in CW direction for 3 seconds

   delay(3000);
 digitalWrite(RelayController, HIGH); //to attach the relay with -12 Volts to turn the DC-Motor in CCW direction for 3 seconds

   delay(3000);
}
