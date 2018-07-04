# iotFan

This Xiot agent is intended to control a fan that offers 3 rotation speeds as well as an oscillation mode.

To use it, you'll preferrably also need the iotinator master module (https://github.com/reivaxy/iotinator), or you can just use it's REST API to integrate to your own designs.

You will find <a href="https://github.com/reivaxy/iotinator/wiki/07.-Dev-environnement-and-debug">here</a> all the information to install your dev environment.


The goal is to transform this 25 year old fan into an iot-equipped fan to control its speed and optional oscillation:
 
<img src="https://raw.githubusercontent.com/reivaxy/iotFan/master/resources/fanPanel.jpg" width="500"/>


The controls are a bit oldish, hope they'll stand the transformation...

<img src="https://raw.githubusercontent.com/reivaxy/iotFan/master/resources/fanControl.jpg" width="500"/>



<img src="https://raw.githubusercontent.com/reivaxy/iotFan/master/resources/fanOpen.jpg" width="500"/>


Here is the module prototype, with 4 leds to simulate the 4 static relays that will control the fan speed and oscillation:

<img src="https://raw.githubusercontent.com/reivaxy/iotFan/master/resources/prototype.jpg" width="500"/>

Here is the power module, with the power down circuit, 4 static relays, and connectors

<img src="https://raw.githubusercontent.com/reivaxy/iotFan/master/resources/powerModule.jpg" width="500"/>

Here is the full device, with the power module, the esp8266 module, and the oled screen:

<img src="https://raw.githubusercontent.com/reivaxy/iotFan/master/resources/all.jpg" width="500"/>

Here is the working device, not yet properly attached and not yet with a window for the screen.

<img src="https://raw.githubusercontent.com/reivaxy/iotFan/master/resources/working.jpg" width="500"/>

And here is the module control panel in the webApp:

<img src="https://raw.githubusercontent.com/reivaxy/iotFan/master/resources/app.png" width="200"/>



