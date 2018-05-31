#include <IRLremote.h>

#include <IRLib.h>
#include <IRLibMatch.h>
#include <IRLibTimer.h>

#include <IRLib.h>

IRsend My_Sender;

const int interruptIR = 0;                 // Arduino interrupcion 0: Pin 2

uint8_t IRProtocol = 0;  // Variables para recibir los datos
uint16_t IRAddress = 0;
uint32_t IRCommand = 0;


byte vida=0,disparo=0;
void leerIR(){
  uint8_t oldSREG = SREG;  // Parar las interrupciones
         cli();
         if (IRProtocol)          // Si reconoce el protocolo
            {
                 Serial.print("Protocol:");
                 Serial.println(IRProtocol);
                 Serial.print("Address:");
                 Serial.println(IRAddress, HEX);
                 Serial.print("Command:");
                 Serial.println(IRCommand, HEX);
                 IRProtocol = 0;
                 
            }
         SREG = oldSREG;
}
void calcVida(){
   
 }
 void enviarIR(){

 for ( int n=0;n<1000000;n++){
    //send a code  every time a character is received from the serial port
    //Sony DVD power A8BCA
     My_Sender.send(SONY,0xfffff, 20);
    delay(10);
 } 
 Serial.print("end");
 }
void setup() {
 Serial.begin(115200);
Serial.println("Start!");
IRLbegin<IR_ALL>(interruptIR);
}

void loop() {

leerIR();
calcVida();
enviarIR();
}
void IREvent(uint8_t protocol, uint16_t address, uint32_t command)
    {
        IRProtocol = protocol;  // Recogemos los valores y nos volvemos
        IRAddress = address;
        IRCommand = command;
    }
