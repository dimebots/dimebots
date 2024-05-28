
![IMG_20230501_121034](https://github.com/dimebots/dimebots/assets/139924965/8d8c6747-6d2d-4196-b067-b591959a2c15)

Dimebots are a collection of autonomous and self-contained micro-robots that are as small as a dime and weigh less than a nickel, making Dimebots some of the smallest robots in the world. 

![IMG_20230429_160315](https://github.com/dimebots/dimebots/assets/139924965/ea043635-1a79-446b-b299-f12e75829b2a)
![IMG_20230429_155623](https://github.com/dimebots/dimebots/assets/139924965/6b5892ba-6ebe-4dd0-a2ab-0156e3d4bcc4)
![IMG_20230429_155456 (2)](https://github.com/dimebots/dimebots/assets/139924965/1aacc8e3-4221-4821-8f1b-4198305bee7e)
		
<p><strong>Microchip/Atmel ATTiny1614 &amp; Texas Instruments DRV8837</strong></p>

<p>The search for a suitable microcontroller is constrained by a number 
of factors. These factors included providing the necessary peripherals 
that are required, such as <a href="https://en.wikipedia.org/wiki/Pulse-width_modulation" target="_blank" rel="noreferrer noopener">Pulse Width Modulation (PWM)</a>, at least one <a href="https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter" target="_blank" rel="noreferrer noopener">Universal Asynchronous Receiver/Transmitter (UART)</a>, support for at least one Inter-Integrated Circuit <a href="https://en.wikipedia.org/wiki/I%C2%B2C" target="_blank" rel="noreferrer noopener">(I²C)</a> communication bus, and in-circuit serial programming <a href="https://ww1.microchip.com/downloads/en/DeviceDoc/30277d.pdf" target="_blank" rel="noreferrer noopener">(ICSP)</a>. I originally designed the Dimebots to utilized the 8-bit <a href="https://www.microchip.com/en-us/product/ATmega328P" target="_blank" rel="noreferrer noopener">Microchip/Atmel ATmega328p</a> which is the microcontroller found in the <a href="https://www.arduino.cc/" target="_blank" rel="noreferrer noopener">Arduino Uno</a>.
 The ATmega328p provides a simple and easy-to-understand coding platform
 through the Arduino integrated development environment (IDE) while also
 coming in a number of footprints that could work for my requirements, 
namely a 32 pin <a href="https://en.wikipedia.org/wiki/Quad_flat_package" target="_blank" rel="noreferrer noopener">Thin Quad Flat Package (TQFP)</a> and 28 and 32 pin <a href="https://en.wikipedia.org/wiki/Flat_no-leads_package" target="_blank" rel="noreferrer noopener">Very Thin Plastic Quad Flat No-Lead (VQFN)</a>. I went as far as laying out an <a href="https://www.microchip.com/en-us/product/ATmega328P" target="_blank" rel="noreferrer noopener">ATMega328p</a>
 using a VQFN footprint, but the additional support requirements of 
using the ATMega328p such as a 6 pin ICSP header and an external 8MHz 
crystal/resonator necessitated a smaller microcontroller. In addition, 
the great dearth of microchips because of the COVID-19 pandemic 
disrupting global supply chains, stay-at-home orders increasing, and 
demand for consumer electronics and electric vehicle adoption, such as 
the ATMega328p, makes my selection of a suitable microcontroller much 
narrower. I decided to give myself a couple of weeks to see if I could 
nail down a microcontroller that is small, yet peripheral rich. 
Fortunately, <a href="https://github.com/SpenceKonde/megaTinyCore" target="_blank" rel="noreferrer noopener">Spence Konde (aka Dr. Azzy)</a>
 had recently released Arduino support for the newer microcontrollers 
offered by Microchip/Atmel, including support for the tinyAVR 2-Series, 
the tinyAVR 1-Series, and the tinyAVR 0-Series of chips. After testing a
 number of different microcontrollers, I chose the <a href="https://www.microchip.com/en-us/product/ATTINY1614" target="_blank" rel="noreferrer noopener">ATTiny1614</a> in a 14-pin <a href="https://en.wikipedia.org/wiki/Small_outline_integrated_circuit" target="_blank" rel="noreferrer noopener">Small Outline Integrated Circuit (SOIC)</a>
 footprint due to its necessary peripherals, overall microcontroller 
size and footprint, and most importantly, its availability. The 
ATTiny1614 can be powered by a wide variety of voltages including 1.8V 
all the way up to 5.5, has multiple I²C buses and multiple UART’s, has 6
 PWM channels, and used the <a href="https://onlinedocs.microchip.com/pr/GUID-DDB0017E-84E3-4E77-AAE9-7AC4290E5E8B-en-US-4/index.html?GUID-9B349315-2842-4189-B88C-49F4E1055D7F" target="_blank" rel="noreferrer noopener">Unified Program and Debug Interface (UPDI)</a>
 for programming. The UPDI interface is perfect for my needs, as it 
required only a 3-pin programming interface versus the 6-pin interface 
used for the ATMega328p.</p>



<p>The <a href="https://www.ti.com/product/DRV8837" target="_blank" rel="noreferrer noopener">Texas Instruments DRV8837</a>
 is chosen as the motor driver for the Dimebots. The DRV8837 output 
driver block consists of N-channel power MOSFETs configured as an 
H-bridge to drive the motor winding. An internal charge pump generates 
needed gate drive voltages. The Texas Instruments DRV8837 is packaged 
with a host of features, namely:</p>



<ul>
<li>1.8-A Maximum Drive Current</li>
<li>Separate Motor and Logic Supply Pins</li>
<li>Motor VM: 0 to 11 V</li>
<li>Logic VCC: 1.8 to 7 V</li>
<li>PWM Interface with IN1 and IN2 receiving PWM input</li>
<li>Low-Power Sleep Mode With 120-nA Maximum Sleep Current</li>
<li>nSLEEP pin</li>
<li>Small Footprint – 8-Pin WSON With Thermal Pad with a 2.0mm × 2.0mm size</li>
</u!>

![attiny_schematic-1536x1186](https://github.com/dimebots/dimebots/assets/139924965/be3f46de-5b75-49ac-afb5-af3085e33ebf)
![eagle_board_attiny-300x243](https://github.com/dimebots/dimebots/assets/139924965/bedb6f3a-1619-4274-baf1-7f7ee70e163a)
![IMG_20230503_114437-1536x1241](https://github.com/dimebots/dimebots/assets/139924965/96b66505-b5ce-4ca0-af4b-7a22ec715334)


<p><strong>Vishay VCNL4040 Proximity Sensor</strong></p>

<p>I sampled and tested numerous proximity sensors to find one that is power friendly, small, and available. This included sensors such as the Broadcom APDS-9960, the ON Semiconductor QRE1113, and the Sharp GP2S60. I finally selected the VCNL4040 from Vishay that interfaced with the ATTiny1614 using the I²C protocol.</p>








































</body></html>



