#include <ps2.h>
/*
 * an arduino sketch to interface with a ps/2 mouse.
 * Also uses serial protocol to talk back to the host
 * and report what it finds.
 */
/*
 * Pin 5 is the mouse data pin, pin 6 is the clock pin
 * Feel free to use whatever pins are convenient.
 */
PS2 mouse(6, 5);
/*
 * initialize the mouse. Reset it, and place it into remote
 * mode, so we can get the encoder data on demand.
 */
 int somax;
 int somay;
 int nAquisicao;
void mouse_init()
{
 mouse.write(0xff); // reset
 mouse.read(); // ack byte
 mouse.read(); // blank */
 mouse.read(); // blank */
 mouse.write(0xf0); // remote mode
 mouse.read(); // ack
 delayMicroseconds(100);
}
void setup()
{
 Serial.begin(9600);
 mouse_init();
 somax = 0;
 somay = 0;
 nAquisicao = 0;
}
/*
 * get a reading from the mouse and report it back to the
 * host via the serial line.
 */
void loop()
{
 char mstat;
 char mx;
 char my;
 char mz;
 /* get a reading from the mouse */
 mouse.write(0xeb); // give me data!
 mouse.read(); // ignore ack
 mstat = mouse.read();
 mx = mouse.read();
 my = mouse.read();

 char clickl = mstat & (B00000001);
 char clickr = (mstat>>1) & (B00000001);

 Serial.print("mstat:\t");
 Serial.print(mstat,DEC);
 Serial.print("mx:\t");
 Serial.print(mx,DEC);
 Serial.print("\tmy:\t");
 Serial.print(my,DEC); 
 Serial.print("\tclickl:\t");
 Serial.print(clickl); 
 Serial.print("\tclickr:\t");
 Serial.print(clickr); 
 Serial.println();

}
