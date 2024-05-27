
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
</ul>



<div class="wp-block-columns is-layout-flex wp-container-core-columns-is-layout-1 wp-block-columns-is-layout-flex">
<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-large"><a href="https://dimebots.com/wp-content/uploads/2023/05/IMG_20230503_114437.jpg" target="_blank" rel="noreferrer noopener"><img fetchpriority="high" decoding="async" width="1024" height="828" src="Hardware%20-_files/IMG_20230503_114437-1024x828_002.jpg" alt="" class="wp-image-50" srcset="Hardware%20-_files/IMG_20230503_114437-1024x828.jpg 1024w, Hardware%20-_files/IMG_20230503_114437-300x242.jpg 300w, Hardware%20-_files/IMG_20230503_114437-768x621.jpg 768w, Hardware%20-_files/IMG_20230503_114437-1536x1241.jpg 1536w, Hardware%20-_files/IMG_20230503_114437-624x504.jpg 624w, Hardware%20-_files/IMG_20230503_114437.jpg 1668w" sizes="(max-width: 1024px) 100vw, 1024px"></a></figure>
</div>



<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-full is-resized"><a href="https://dimebots.com/wp-content/uploads/2023/05/eagle_board_attiny.png" target="_blank" rel="noreferrer noopener"><img decoding="async" src="Hardware%20-_files/eagle_board_attiny.png" alt="" class="wp-image-51" width="197" height="159" srcset="Hardware%20-_files/eagle_board_attiny_002.png 403w, Hardware%20-_files/eagle_board_attiny-300x243.png 300w" sizes="(max-width: 197px) 100vw, 197px"></a></figure>
</div>



<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-large"><a href="https://dimebots.com/wp-content/uploads/2023/05/attiny_schematic.png" target="_blank" rel="noreferrer noopener"><img decoding="async" width="1024" height="791" src="Hardware%20-_files/attiny_schematic-1024x791_002.png" alt="" class="wp-image-52" srcset="Hardware%20-_files/attiny_schematic-1024x791.png 1024w, Hardware%20-_files/attiny_schematic-300x232.png 300w, Hardware%20-_files/attiny_schematic-768x593.png 768w, Hardware%20-_files/attiny_schematic-1536x1186.png 1536w, Hardware%20-_files/attiny_schematic-2048x1582.png 2048w, Hardware%20-_files/attiny_schematic-624x482.png 624w" sizes="(max-width: 1024px) 100vw, 1024px"></a></figure>
</div>
</div>



<p><strong>Vishay VCNL4040 Proximity Sensor</strong></p>



<p>I sampled and tested numerous proximity sensors to find one that is 
power friendly, small, and available. This included sensors such as the <a rel="noreferrer noopener" href="https://www.broadcom.com/products/optical-sensors/integrated-ambient-light-and-proximity-sensors/apds-9960" target="_blank">Broadcom APDS-9960</a>, the <a rel="noreferrer noopener" href="https://www.onsemi.com/pdf/datasheet/qre1113-d.pdf" target="_blank">ON Semiconductor QRE1113</a>, and the <a rel="noreferrer noopener" href="https://global.sharp/products/device/lineup/data/pdf/datasheet/gp2s60_e.pdf" target="_blank">Sharp GP2S60</a>. I finally selected the V<a rel="noreferrer noopener" href="https://www.vishay.com/en/product/84274/" target="_blank">CNL4040 from Vishay</a> that interfaced with the ATTiny1614 using the I²C protocol.</p>



<div class="wp-block-columns is-layout-flex wp-container-core-columns-is-layout-2 wp-block-columns-is-layout-flex">
<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-large"><a href="https://dimebots.com/wp-content/uploads/2023/05/IMG_20230503_114449.jpg" target="_blank" rel="noreferrer noopener"><img loading="lazy" decoding="async" width="1024" height="951" src="Hardware%20-_files/IMG_20230503_114449-1024x951_002.jpg" alt="" class="wp-image-55" srcset="Hardware%20-_files/IMG_20230503_114449-1024x951.jpg 1024w, Hardware%20-_files/IMG_20230503_114449-300x279.jpg 300w, Hardware%20-_files/IMG_20230503_114449-768x713.jpg 768w, Hardware%20-_files/IMG_20230503_114449-624x580.jpg 624w, Hardware%20-_files/IMG_20230503_114449.jpg 1350w" sizes="(max-width: 1024px) 100vw, 1024px"></a></figure>
</div>



<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-full"><a href="https://dimebots.com/wp-content/uploads/2023/05/vcnl4040_board.png" target="_blank" rel="noreferrer noopener"><img loading="lazy" decoding="async" width="338" height="277" src="Hardware%20-_files/vcnl4040_board_002.png" alt="" class="wp-image-56" srcset="Hardware%20-_files/vcnl4040_board.png 338w, Hardware%20-_files/vcnl4040_board-300x246.png 300w" sizes="(max-width: 338px) 100vw, 338px"></a></figure>
</div>



<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-large"><a href="https://dimebots.com/wp-content/uploads/2023/05/vcnl4040_schematic.png" target="_blank" rel="noreferrer noopener"><img loading="lazy" decoding="async" width="1024" height="694" src="Hardware%20-_files/vcnl4040_schematic-1024x694_002.png" alt="" class="wp-image-57" srcset="Hardware%20-_files/vcnl4040_schematic-1024x694.png 1024w, Hardware%20-_files/vcnl4040_schematic-300x203.png 300w, Hardware%20-_files/vcnl4040_schematic-768x521.png 768w, Hardware%20-_files/vcnl4040_schematic-1536x1041.png 1536w, Hardware%20-_files/vcnl4040_schematic-2048x1389.png 2048w, Hardware%20-_files/vcnl4040_schematic-624x423.png 624w" sizes="(max-width: 1024px) 100vw, 1024px"></a></figure>
</div>
</div>



<p><strong>Nanjing Qinheng Microelectronics CH9141 Bluetooth (BLE4.2) Module</strong></p>



<p>Searching for a Bluetooth LE module that is tiny enough to fit the 
constraints of the robots mainboard while also providing for some type 
of serial communications is a challenge. All of the traditional 
Bluetooth 2.0 <a href="https://www.bluetooth.com/specifications/specs/serial-port-profile-1-1/" target="_blank" rel="noreferrer noopener">Serial Port Profile (SPP)</a>
 modules were either too large or too power hungry to meet the 
dime-sized requirements of the Dimebots. After a few weeks of exhaustive
 searching, I discovered the <a href="http://www.wch-ic.com/products/CH9141.html" target="_blank" rel="noreferrer noopener">CH9141</a>. The CH9141 module ticked all of the requirements I needed, including:</p>



<ul>
<li>Supporting the standard Bluetooth V4.2 protocol</li>



<li>Bluetooth transmission distance up to 100 meters</li>



<li>Two-way transparent transmission of serial port and Bluetooth data</li>



<li>Support Bluetooth broadcast, host, and slave modes</li>



<li>Support serial port AT command configuration</li>



<li>Serial port baud rate supporting 300bps all the way up to 921600bps</li>



<li>Support for adjustable serial port parameters</li>
</ul>



<p>The CH9141 module integrates master and slave functionality, while 
being configured through AT serial commands. The serial AT commands were
 used for configuring the CH9141 module to set the modules device name, 
module password, and serial baud rate to 9600bps.</p>



<div class="wp-block-columns is-layout-flex wp-container-core-columns-is-layout-3 wp-block-columns-is-layout-flex">
<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-full"><a href="https://dimebots.com/wp-content/uploads/2023/05/IMG_20230503_111732.jpg" target="_blank" rel="noreferrer noopener"><img loading="lazy" decoding="async" width="773" height="855" src="Hardware%20-_files/IMG_20230503_111732.jpg" alt="" class="wp-image-65" srcset="Hardware%20-_files/IMG_20230503_111732_002.jpg 773w, Hardware%20-_files/IMG_20230503_111732-271x300.jpg 271w, Hardware%20-_files/IMG_20230503_111732-768x849.jpg 768w, Hardware%20-_files/IMG_20230503_111732-624x690.jpg 624w" sizes="(max-width: 773px) 100vw, 773px"></a></figure>
</div>



<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-full"><a href="https://dimebots.com/wp-content/uploads/2023/05/ch9141_board.png" target="_blank" rel="noreferrer noopener"><img loading="lazy" decoding="async" width="429" height="339" src="Hardware%20-_files/ch9141_board.png" alt="" class="wp-image-66" srcset="Hardware%20-_files/ch9141_board_002.png 429w, Hardware%20-_files/ch9141_board-300x237.png 300w" sizes="(max-width: 429px) 100vw, 429px"></a></figure>
</div>



<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-large"><a href="https://dimebots.com/wp-content/uploads/2023/05/ch9141_schematic.png" target="_blank" rel="noreferrer noopener"><img loading="lazy" decoding="async" width="1024" height="710" src="Hardware%20-_files/ch9141_schematic-1024x710_002.png" alt="" class="wp-image-67" srcset="Hardware%20-_files/ch9141_schematic-1024x710.png 1024w, Hardware%20-_files/ch9141_schematic-300x208.png 300w, Hardware%20-_files/ch9141_schematic-768x532.png 768w, Hardware%20-_files/ch9141_schematic-1536x1064.png 1536w, Hardware%20-_files/ch9141_schematic-2048x1419.png 2048w, Hardware%20-_files/ch9141_schematic-624x432.png 624w" sizes="(max-width: 1024px) 100vw, 1024px"></a></figure>
</div>
</div>


<div class="wp-block-image">
<figure class="aligncenter size-large is-resized"><a href="https://dimebots.com/wp-content/uploads/2023/05/IMG_20230429_160111.jpg" target="_blank" rel="noreferrer noopener"><img loading="lazy" decoding="async" src="Hardware%20-_files/IMG_20230429_160111-1024x702.jpg" alt="" class="wp-image-70" width="250" height="171" srcset="Hardware%20-_files/IMG_20230429_160111-1024x702_002.jpg 1024w, Hardware%20-_files/IMG_20230429_160111-300x206.jpg 300w, Hardware%20-_files/IMG_20230429_160111-768x526.jpg 768w, Hardware%20-_files/IMG_20230429_160111-1536x1052.jpg 1536w, Hardware%20-_files/IMG_20230429_160111-2048x1403.jpg 2048w, Hardware%20-_files/IMG_20230429_160111-624x428.jpg 624w" sizes="(max-width: 250px) 100vw, 250px"></a></figure></div>


<p><strong>Microchip MCP1700 Low Dropout (LDO) Voltage Regulator</strong></p>



<p>A source of a stable and clean 3.3V is needed to power the dimebot and its peripherals. The <a href="https://www.microchip.com/en-us/product/MCP1700" target="_blank" rel="noreferrer noopener">Microchip MCP1700 Low Dropout (LDO) Voltage Regulator</a> is a <a href="https://en.wikipedia.org/wiki/CMOS" target="_blank" rel="noreferrer noopener">CMOS</a>
 low dropout positive voltage regulator which can source up to 250mA of 
current with an extremely low input-output voltage differential of 178mV
 at 250mA. The low dropout voltage combined with the low current 
consumption of only 1.6µA makes this part ideal for battery operation. 
The low voltage differential (dropout voltage) extends battery operating
 lifetime. The MCP1700 is stable with 1.0µF ceramic output capacitor. It
 also permits high currents in small packages when operated with minimum
 VIN – VOUT differentials. The circuit also incorporates short-circuit 
protection &amp; over temperature protection to ensure maximum 
reliability.</p>



<div class="wp-block-columns is-layout-flex wp-container-core-columns-is-layout-4 wp-block-columns-is-layout-flex">
<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-large"><a href="https://dimebots.com/wp-content/uploads/2023/05/IMG_20230503_114144.jpg" target="_blank" rel="noreferrer noopener"><img loading="lazy" decoding="async" width="1024" height="889" src="Hardware%20-_files/IMG_20230503_114144-1024x889_002.jpg" alt="" class="wp-image-72" srcset="Hardware%20-_files/IMG_20230503_114144-1024x889.jpg 1024w, Hardware%20-_files/IMG_20230503_114144-300x261.jpg 300w, Hardware%20-_files/IMG_20230503_114144-768x667.jpg 768w, Hardware%20-_files/IMG_20230503_114144-624x542.jpg 624w, Hardware%20-_files/IMG_20230503_114144.jpg 1233w" sizes="(max-width: 1024px) 100vw, 1024px"></a></figure>
</div>



<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-full"><a href="https://dimebots.com/wp-content/uploads/2023/05/power_board.png" target="_blank" rel="noreferrer noopener"><img loading="lazy" decoding="async" width="320" height="264" src="Hardware%20-_files/power_board.png" alt="" class="wp-image-73" srcset="Hardware%20-_files/power_board_002.png 320w, Hardware%20-_files/power_board-300x248.png 300w" sizes="(max-width: 320px) 100vw, 320px"></a></figure>
</div>



<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-large"><a href="https://dimebots.com/wp-content/uploads/2023/05/power_board_schematic.png" target="_blank" rel="noreferrer noopener"><img loading="lazy" decoding="async" width="1024" height="468" src="Hardware%20-_files/power_board_schematic-1024x468_002.png" alt="" class="wp-image-74" srcset="Hardware%20-_files/power_board_schematic-1024x468.png 1024w, Hardware%20-_files/power_board_schematic-300x137.png 300w, Hardware%20-_files/power_board_schematic-768x351.png 768w, Hardware%20-_files/power_board_schematic-1536x702.png 1536w, Hardware%20-_files/power_board_schematic-2048x936.png 2048w, Hardware%20-_files/power_board_schematic-624x285.png 624w" sizes="(max-width: 1024px) 100vw, 1024px"></a></figure>
</div>
</div>



<p><strong>Microchip MCP73831 Linear Charge Management Controller</strong></p>



<p>The <a rel="noreferrer noopener" href="https://www.microchip.com/en-us/product/MCP73831" target="_blank">Microchip MCP73831 Linear Charge Management Controller</a>
 is a tiny 500mA linear charge management controller which includes 
integrated a pass transistor, integrated current sensing, and reverse 
discharge protection in 5-pin SOT-23 and thermally-efficient 8-pin 2mm x
 3mm <a rel="noreferrer noopener" href="https://en.wikipedia.org/wiki/Flat_no-leads_package#See_also" target="_blank">Dual-Flat No-Leads (DFN)</a> package. Additionally, the Microchip MCP73831 features</p>



<ul>
<li>High accuracy preset output voltage regulation (+/-0.75%)</li>



<li>User-programmable charge current</li>



<li>Charge status output can directly drive LEDs</li>



<li>On-chip thermal regulation</li>



<li>Preconditioning and end-of-charge ratio options</li>



<li>Under-voltage lockout</li>
</ul>



<p>The MCP73831 device is a highly advanced linear charge management 
controllers for use in space-limited, cost-sensitive applications.</p>



<div class="wp-block-columns is-layout-flex wp-container-core-columns-is-layout-5 wp-block-columns-is-layout-flex">
<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-large"><a href="https://dimebots.com/wp-content/uploads/2023/05/IMG_20230503_114406.jpg" target="_blank" rel="noreferrer noopener"><img loading="lazy" decoding="async" width="1024" height="589" src="Hardware%20-_files/IMG_20230503_114406-1024x589_002.jpg" alt="" class="wp-image-76" srcset="Hardware%20-_files/IMG_20230503_114406-1024x589.jpg 1024w, Hardware%20-_files/IMG_20230503_114406-300x173.jpg 300w, Hardware%20-_files/IMG_20230503_114406-768x442.jpg 768w, Hardware%20-_files/IMG_20230503_114406-1536x884.jpg 1536w, Hardware%20-_files/IMG_20230503_114406-624x359.jpg 624w, Hardware%20-_files/IMG_20230503_114406.jpg 1739w" sizes="(max-width: 1024px) 100vw, 1024px"></a></figure>
</div>



<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-full"><a href="https://dimebots.com/wp-content/uploads/2023/05/charger_board.png" target="_blank" rel="noreferrer noopener"><img loading="lazy" decoding="async" width="836" height="412" src="Hardware%20-_files/charger_board_002.png" alt="" class="wp-image-77" srcset="Hardware%20-_files/charger_board.png 836w, Hardware%20-_files/charger_board-300x148.png 300w, Hardware%20-_files/charger_board-768x378.png 768w, Hardware%20-_files/charger_board-624x308.png 624w" sizes="(max-width: 836px) 100vw, 836px"></a></figure>
</div>



<div class="wp-block-column is-layout-flow wp-block-column-is-layout-flow">
<figure class="wp-block-image size-large"><a href="https://dimebots.com/wp-content/uploads/2023/05/charger_schematic.png" target="_blank" rel="noreferrer noopener"><img loading="lazy" decoding="async" width="1024" height="574" src="Hardware%20-_files/charger_schematic-1024x574_002.png" alt="" class="wp-image-78" srcset="Hardware%20-_files/charger_schematic-1024x574.png 1024w, Hardware%20-_files/charger_schematic-300x168.png 300w, Hardware%20-_files/charger_schematic-768x431.png 768w, Hardware%20-_files/charger_schematic-1536x861.png 1536w, Hardware%20-_files/charger_schematic-2048x1148.png 2048w, Hardware%20-_files/charger_schematic-624x350.png 624w" sizes="(max-width: 1024px) 100vw, 1024px"></a></figure>
</div>
</div>



<p><strong>3.7V 30mAh Rechargeable Lithium Polymer (LiPo) Battery</strong></p>



<p>The main factor that ultimately determined the size of the robot (and
 most every robot in the world) is the size of the battery. The 
balancing act between battery size and power is challenging to say the 
least. On one hand, I needed something that fit in the dimensions of the
 robot. On the other hand, I needed a battery that provided enough 
voltage and amperage to run the robot and its associated peripherals, 
while ensuring a robot runtime that is acceptable. The battery chosen is
 a 3.7V 30mAh Rechargeable LiPo Battery.</p>


<div class="wp-block-image">
<figure class="aligncenter size-full is-resized"><img loading="lazy" decoding="async" src="Hardware%20-_files/IMG_20230503_112341_002.jpg" alt="" class="wp-image-80" width="329" height="314" srcset="Hardware%20-_files/IMG_20230503_112341.jpg 706w, Hardware%20-_files/IMG_20230503_112341-300x287.jpg 300w, Hardware%20-_files/IMG_20230503_112341-624x597.jpg 624w" sizes="(max-width: 329px) 100vw, 329px"></figure></div>


<p><strong>Motor – 4mm x 8mm Pager Motor</strong></p>



<p>The 4mm x 8mm pager motors used are coreless motors with a .70mm 
shaft diameter. Manufacturer test data states that these motors run at :</p>



<ul>
<li>1.5V 18000RPM 5mA</li>



<li>3.0V 37000RPM 8mA</li>



<li>3.7V 47000RPM 10mA</li>



<li>5.0V 62000RPM 25mA</li>
</ul>


<div class="wp-block-image">
<figure class="aligncenter size-large is-resized"><img loading="lazy" decoding="async" src="Hardware%20-_files/IMG_20230503_111528-1024x603_002.jpg" alt="" class="wp-image-83" width="480" height="282" srcset="Hardware%20-_files/IMG_20230503_111528-1024x603.jpg 1024w, Hardware%20-_files/IMG_20230503_111528-300x177.jpg 300w, Hardware%20-_files/IMG_20230503_111528-768x452.jpg 768w, Hardware%20-_files/IMG_20230503_111528-1536x904.jpg 1536w, Hardware%20-_files/IMG_20230503_111528-624x367.jpg 624w, Hardware%20-_files/IMG_20230503_111528.jpg 1561w" sizes="(max-width: 480px) 100vw, 480px"></figure></div>

<div class="wp-block-image">
<figure class="aligncenter size-large is-resized"><img loading="lazy" decoding="async" src="Hardware%20-_files/IMG_20230429_160208-1024x663_002.jpg" alt="" class="wp-image-213" width="483" height="313" srcset="Hardware%20-_files/IMG_20230429_160208-1024x663.jpg 1024w, Hardware%20-_files/IMG_20230429_160208-300x194.jpg 300w, Hardware%20-_files/IMG_20230429_160208-768x497.jpg 768w, Hardware%20-_files/IMG_20230429_160208-1536x995.jpg 1536w, Hardware%20-_files/IMG_20230429_160208-2048x1326.jpg 2048w, Hardware%20-_files/IMG_20230429_160208-624x404.jpg 624w" sizes="(max-width: 483px) 100vw, 483px"><figcaption class="wp-element-caption">Dimebots Testing Rig</figcaption></figure></div>					</div><!-- .entry-content -->
		<footer class="entry-meta">
					</footer><!-- .entry-meta -->
	</article><!-- #post -->
				
<div id="comments" class="comments-area">

	
	
	
</div><!-- #comments .comments-area -->
			
		</div><!-- #content -->
	</div><!-- #primary -->


		</div><!-- #main .wrapper -->
	<footer id="colophon" role="contentinfo">
		<div class="site-info">
									<a href="https://dimebots.com/" class="imprint" title="Semantic Personal Publishing Platform">
				<center>
				2024 :: Dimebots.com</center>
			</a>
		</div><!-- .site-info -->
	</footer><!-- #colophon -->
</div><!-- #page -->

<style id="core-block-supports-inline-css" type="text/css">
.wp-container-core-columns-is-layout-1.wp-container-core-columns-is-layout-1{flex-wrap:nowrap;}.wp-container-core-columns-is-layout-2.wp-container-core-columns-is-layout-2{flex-wrap:nowrap;}.wp-container-core-columns-is-layout-3.wp-container-core-columns-is-layout-3{flex-wrap:nowrap;}.wp-container-core-columns-is-layout-4.wp-container-core-columns-is-layout-4{flex-wrap:nowrap;}.wp-container-core-columns-is-layout-5.wp-container-core-columns-is-layout-5{flex-wrap:nowrap;}
</style>
<script type="text/javascript" src="Hardware%20-_files/index.js" id="swv-js"></script>
<script type="text/javascript" id="contact-form-7-js-extra">
/* <![CDATA[ */
var wpcf7 = {"api":{"root":"https:\/\/www.dimebots.com\/wp-json\/","namespace":"contact-form-7\/v1"},"cached":"1"};
/* ]]> */
</script>
<script type="text/javascript" src="Hardware%20-_files/index_002.js" id="contact-form-7-js"></script>
![IMG_20230501_121034](https://github.com/dimebots/dimebots/assets/139924965/a1792b73-a842-4811-a5ef-a0f74e44d7f3)
![IMG_20230501_121034](https://github.com/dimebots/dimebots/assets/139924965/a1792b73-a842-4811-a5ef-a0f74e44d7f3)
</body></html>
![IMG_20230501_121034](https://github.com/dimebots/dimebots/assets/139924965/a1792b73-a842-4811-a5ef-a0f74e44d7f3)
