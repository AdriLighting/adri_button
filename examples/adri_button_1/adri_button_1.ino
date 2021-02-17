#include <adri_button.h>


int bp_1;
#define BPPIN_1 D1


void setup()
{
	Serial.begin(115200);

	delay(1500);

	Serial.print(F("\n[setup]\n"));

    bp_1 = button_create (BPPIN_1, PULLUP, true);
}

void loop()
{
	peripherals_loop();
	button_process_events();
}

boolean button_getNbrClick(int nbr) {
	if (nbr == 1) return true;
	if (nbr == 2) return true;
	if (nbr == 3) return true;
	return false;
}
boolean button_getNbrClick(int nbr, int maxClick) {
	if (nbr == maxClick) return true;
	return false;
}
void button_process_events() {
	int clickBp_1 = buttons[bp_1]->click();
	if (clickBp_1 == 0){
		if (buttons[bp_1]->long_press()) {
			Serial.println(F("[longClick]"));
			buttons[bp_1]->_long_press_loop = true;
		} 
		if ( buttons[bp_1]->_long_press_loop) {
			while (buttons[bp_1]->on()) {
				delay(10);
				Serial.println(F("[_long_press_loop]"));
			} 		
			buttons[bp_1]->_long_press_loop	= false;  
			buttons[bp_1]->reset();
		} 
	} else {
		if (button_getNbrClick(clickBp_1, 1) ) {Serial.println(F("[shotClick x1]"));}     
		if (button_getNbrClick(clickBp_1, 2) ) {Serial.println(F("[shotClick x2]"));}     
		if (button_getNbrClick(clickBp_1, 3) ) {Serial.println(F("[shotClick x3]"));}   		
	}

}