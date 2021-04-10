// This isn't always required, but it's a good habit to get into 
// and it never hurts.
#include "Particle.h"

// We define MY_LED to be the LED that we want to blink. 
//
// In this tutorial, we're using the blue D7 LED (next to D7 on the Photon 
// and Electron, and next to the USB connector on the Argon and Boron).
const pin_t MY_LED = D6;

// The following line is optional, but recommended in most firmware. 
// It allows your code to run before the cloud is connected.
SYSTEM_THREAD(ENABLED);

// This function is called when the Particle.function is called
int ledToggle(String command) {
	if (command.equals("on")) {
        digitalWrite(MY_LED, HIGH);
        return 1;
    }
    else if (command.equals("off")) {
        digitalWrite(MY_LED, LOW);
        return 0;
    }
    else {
		// Unknown option
        return -1;
    }
}

void threeonoff() {
    ledToggle("on");
    delay(100);
    ledToggle("off");
    delay(100);
    ledToggle("on");
    delay(100);
    ledToggle("off");
    delay(100);
    ledToggle("on");
    delay(100);
    ledToggle("off");
    delay(100);
}

void twoonoff() {
    ledToggle("on");
    delay(500);
    ledToggle("off");
    delay(500);
    ledToggle("on");
    delay(500);
    ledToggle("off");
    delay(500);
}

void myHandler(const char *event, const char *data); 

// The setup() method is called once when the device boots.
void setup() {
	// In order to set a pin, you must tell Device OS that the 
    // pin is an OUTPUT pin.
	// This is often done from setup() since you only need to 
    // do it once.
	pinMode(MY_LED, OUTPUT);

	Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
}

void loop() {
    Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "wave");
    delay(30s);
    Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "pat");
    delay(30s);
}

void myHandler(const char *event, const char *data) {
	if (strcmp(data,"wave")==0){
		threeonoff();
	}
	else if (strcmp(data,"pat")==0){
		twoonoff();
	}
	else {}
}