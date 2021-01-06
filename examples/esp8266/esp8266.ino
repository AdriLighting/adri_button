#include <adri_button.h>

	int push1;

	#define btn_up    D5



void oled_button_startup_events(){
	    push1 = button_create (btn_up, 		PULLUP);

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

void oled_button_process_events() {

	int click1         = buttons[push1]->click();

	if (button_getNbrClick(click1) ) {;} 
	if (button_getNbrClick(click1, 1) ) {;}     

	if (buttons[click1]->long_press()) {;} 


}
void setup()
{
    		// button_create_scLc(BP_1_PIN, BP_PULLUP, BP_INPUT, bp_toggle, bp_mod_loop, 	50);
    // bp_lc = button_create_scLc(BP_2_PIN, BP_PULLUP, BP_INPUT, bp_toggle, bp_color_loop, 10);
	peripherals_setup();
	oled_button_startup_events();
}

void loop()
{
	peripherals_loop();
	
	oled_button_process_events();
	button_lc_loop();

}