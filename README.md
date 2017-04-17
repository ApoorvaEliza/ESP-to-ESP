# ESP-to-ESP
Here we are using two ESP-01 to communicate between input and output systems connected to an arduino uno at each end. The example taken here is to control the LEDs connected to the output arduino using switches at the input end. 
We can control the LEDs using switches connected to the GPIO pins of ESP-01, as well as switches connected to arduino at input side.
At both ends, we have an ESP-01 - Arduino uno serial connection. 

the program files given are intended for :
1. esp_op is the ESP-01 at the output
2. espswitchgp is for controlling the LEDs using switches connected to GPIO pins of ESP-01
3. uno_op is the program for output arduino(one with LEDs)
4. unocase2 is another program for output arduino-(so faar this has not produced any favourable results).
