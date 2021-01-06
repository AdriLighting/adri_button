


#ifndef BP_H
   #define BP_H
   #include <arduino.h>

	typedef void (*click_func)();  
	typedef void (*longclick_func)();  
   
	class button_lc {
	public:
		unsigned long   _last_change;
		int             _id;
		boolean         _pullup;
		int             _long_press;
		int 			_pin_number;
		int 			_delay_lc;
		click_func 		_click_func;
		longclick_func 	_longclick_func;
		boolean 		_longclick = false;


		button_lc(int id, int pin, boolean pullup, int input, int delay_lc, click_func sc_func, longclick_func lc_func);
		button_lc(int id, int pin, boolean pullup, int input, int delay_lc);
		boolean statu();
	};
	
	extern button_lc * button_lc_array[];

	int button_create_sc(int pin, boolean pullup, int input, click_func function);
	int button_create_scLc(int pin, boolean pullup, int input, click_func function, click_func function_2, int delay);

	int button_create_sc(int pin, boolean pullup, int input);
	int button_create_scLc(int pin, boolean pullup, int input, int delay);

	void button_lc_loop();
#endif