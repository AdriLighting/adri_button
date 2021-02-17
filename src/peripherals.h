/*
 * buttons.h
 *
 *  Created on: 27 févr. 2018
 *      Author: Nri
 */


#ifndef BUTTONS_H
#define BUTTONS_H
#include <Arduino.h>
#include "def.h"

#define PULLUP		true
#define PULLDOWN	false

#define BUTTON_MAX 	10


class button {
public:
	unsigned long   _last_change;
	int             _id;
	int				_click_number;
	button_status   _status;
	boolean         _pullup;
	int				_short_press;
	boolean			_long_press = false;
	boolean			_long_press_loop = false;
	boolean         _press;
	int 			_pin_number;


					button(int id, int pin, boolean direction, boolean input);
	void			loop();
	void			setup();
	void			end();
	boolean			on();
	int				click();
	boolean			long_press();
	void			change_state();
	void			reset();
	String 			hw_config();
};
extern	button	* buttons[BUTTON_MAX];
int 	button_create(int pin, boolean pullup, boolean input);
void	peripherals_setup() ;
void	peripherals_loop() ;
void	peripherals_end();

#endif /* BUTTONS_H_ */
