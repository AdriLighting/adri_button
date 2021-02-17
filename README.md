# adri_button

Bibliothèque pour bouton poussoir momentané, permet détecter l’état du bouton : le nombre de clique ou si il est maintenue et d’attribuer des fonction à chaque état.


Supports AVR and ESP8266 platform

<br>

## peripherals.h 

Créateur : Nri

<hr>

## QuickStart
### Variables statique
```c++
int bp_1;
#define BPPIN_1 D1
```
### Setup
* int button_create(int pin, boolean pullup, boolean input);
```c++
    bp_1 = button_create (BPPIN_1, PULLUP, true);
```
### Loop
* detecte l'état du bouton
    * void peripherals_loop();
```c++
        peripherals_loop();
```
* attibuer les focntion suivant l'état du bouton
```c++
    int clickBp_1 = buttons[bp_1]->click();
    if (clickBp_1 == 0){
        if (buttons[bp_1]->long_press()) {
            Serial.println("[longClick]");
        } 
    } else {
        if (button_getNbrClick(clickBp_1, 1) ) {Serial.println(F("[shotClick x1]"));}     
        if (button_getNbrClick(clickBp_1, 2) ) {Serial.println(F("[shotClick x2]"));}     
        if (button_getNbrClick(clickBp_1, 3) ) {Serial.println(F("[shotClick x3]"));}   
        }           
    }       
```

<br>

## bp.h
Créateur : AdriLighting
<hr>

## QuickStart
### Variables statique
```c++
int bp_1;
#define BPPIN_1 D1
```
### functions
* attibuer les focntion suivant l'état du bouton
```c++
    void simplClick()   {Serial.print(F("[simplClick]\n"));}
    void longClicl()    {Serial.print(F("[longClicl]\n"));}      
```
### Setup
* int button_create_scLc(int pin, boolean pullup, int input, click_func function, click_func function_2, int delay = 10);
    * delay a 0 pour une action une fois la pression terminer
    * delay > 0 pour une action pendant la pression 
```c++
    button_create_scLc(D1, PULLDOWN, 1, simplClick, longClicl);
```
### Loop
* detecte l'état du bouton
    * void button_lc_loop();
```c++
        button_lc_loop();
```
