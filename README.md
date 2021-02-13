# adri_button

Bibliothèque pour bouton poussoir momentané, permet détecter l’état du bouton : le nombre de clique ou si il est maintenue et d’attribuer des fonction à chaque état.


Supports AVR and ESP8266 platform

<pre>
Librairies
<details>
adri_button                     = https://github.com/AdriLighting/adri_button

esp8266/arduino                 = https://github.com/esp8266/Arduino/tree/master/libraries
</details>
Dependency Graph
<details>
|-- [adri_button] 1.0.0</details>
</pre>


<hr>examples

- adri_button_1
<pre>
platformio.ini
<details>
[env:nodemcuv2]
platform=espressif8266
board=nodemcuv2
framework=arduino
lib_extra_dirs= ${env.lib_extra_dirs}
[platformio]
src_dir= ${env.src_dir}

</details></pre><hr>