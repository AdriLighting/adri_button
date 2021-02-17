#include "bp.h"

#define BUTTON_MAX 5

namespace  {
	int button_nbr=0;
} // 

button_lc * button_lc_array[BUTTON_MAX];

void button_nofunc(){Serial.println("NOFUNC");}

int button_create_sc(int pin, boolean pullup, int input, click_func function) {
	if (button_nbr<BUTTON_MAX) {
		button_lc_array[button_nbr]=new button_lc(button_nbr, pin, pullup, input, -1, function, button_nofunc);
		button_nbr++;
		return button_nbr-1;
	}
	return -1;
}
int button_create_scLc(int pin, boolean pullup, int input, click_func function, click_func function_2, int delay) {
	if (button_nbr<BUTTON_MAX) {
		button_lc_array[button_nbr]=new button_lc(button_nbr, pin, pullup, input, delay, function, function_2);
		button_nbr++;
		return button_nbr-1;
	}
	return -1;
}
button_lc::button_lc(int id, int pin, boolean pullup, int input, int delay_lc, click_func sc_func, longclick_func lc_func) {
	_id				= id;
	_pin_number		= pin;
	_pullup			= pullup;
	_longclick_func	= lc_func;
	_click_func 	= sc_func;
	_delay_lc 		= delay_lc;
	if (_pin_number>=0) {
		if (input == 0) pinMode(_pin_number, INPUT);
		if (input == 1) pinMode(_pin_number, INPUT_PULLUP);
	}
}

int button_create_sc(int pin, boolean pullup, int input) {
	if (button_nbr<BUTTON_MAX) {
		button_lc_array[button_nbr]=new button_lc(button_nbr, pin, pullup, input, -1);
		button_nbr++;
		return button_nbr-1;
	}
	return -1;
}
int button_create_scLc(int pin, boolean pullup, int input, int delay) {
	if (button_nbr<BUTTON_MAX) {
		button_lc_array[button_nbr]=new button_lc(button_nbr, pin, pullup, input, delay);
		button_nbr++;
		return button_nbr-1;
	}
	return -1;
}
button_lc::button_lc(int id, int pin, boolean pullup, int input, int delay_lc) {
	_id				= id;
	_pin_number		= pin;
	_pullup			= pullup;
	_longclick_func	= NULL;
	_click_func 	= NULL;
	_delay_lc 		= delay_lc;
	if (_pin_number>=0) {
		if (input == 0) pinMode(_pin_number, INPUT);
		if (input == 1) pinMode(_pin_number, INPUT_PULLUP);
	}
}


boolean button_lc::statu() {
	if (digitalRead(_pin_number) == _pullup) return true;
	return false;

}


boolean _longclick = false;
void button_lc_loop() {
	// char buffer[120];
	for (int i=0; i<button_nbr;	i++) {
		if (button_lc_array[i]->statu()) {
			// sprintf(buffer, "button_lc stau nbr:%d pin:%d delay_lc:%d\n", button_lc_array[i]->_id, button_lc_array[i]->_pin_number, button_lc_array[i]->_delay_lc);
			// Serial.println(String(buffer));
			if (button_lc_array[i]->_delay_lc > 0) {
				delay(250);
				while (digitalRead(button_lc_array[i]->_pin_number) == button_lc_array[i]->_pullup) {
					delay(button_lc_array[i]->_delay_lc);
					button_lc_array[i]->_longclick_func();
					_longclick  = true;  
				} 	
				if (!_longclick) 	{button_lc_array[i]->_click_func();}
				else				{_longclick = false;delay(250);}      
			} else {
				delay(250);
				while (digitalRead(button_lc_array[i]->_pin_number) == button_lc_array[i]->_pullup) {
					delay(10);
					_longclick  = true;  
				} 	
				if (!_longclick) 	{button_lc_array[i]->_click_func();}
				else				{button_lc_array[i]->_longclick_func();_longclick = false;delay(250);}  
			}
		}
	}
}