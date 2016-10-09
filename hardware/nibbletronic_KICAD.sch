EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:nibbletronic_custom_components
LIBS:nibbletronic_KICAD-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L SWITCH_INV SW1
U 1 1 56852AC6
P 1900 2250
F 0 "SW1" H 1700 2400 50  0000 C CNN
F 1 "SWITCH_INV" H 1750 2100 50  0000 C CNN
F 2 "CustomParts:MARQUARDT_SPDT" H 1900 2250 50  0001 C CNN
F 3 "" H 1900 2250 50  0000 C CNN
	1    1900 2250
	1    0    0    -1  
$EndComp
$Comp
L SWITCH_INV SW2
U 1 1 56852B2E
P 1900 2700
F 0 "SW2" H 1700 2850 50  0000 C CNN
F 1 "SWITCH_INV" H 1750 2550 50  0000 C CNN
F 2 "CustomParts:MARQUARDT_SPDT" H 1900 2700 50  0001 C CNN
F 3 "" H 1900 2700 50  0000 C CNN
	1    1900 2700
	1    0    0    -1  
$EndComp
$Comp
L SWITCH_INV SW3
U 1 1 56852B74
P 1900 3150
F 0 "SW3" H 1700 3300 50  0000 C CNN
F 1 "SWITCH_INV" H 1750 3000 50  0000 C CNN
F 2 "CustomParts:MARQUARDT_SPDT" H 1900 3150 50  0001 C CNN
F 3 "" H 1900 3150 50  0000 C CNN
	1    1900 3150
	1    0    0    -1  
$EndComp
$Comp
L SWITCH_INV SW4
U 1 1 56852BC7
P 1900 3650
F 0 "SW4" H 1700 3800 50  0000 C CNN
F 1 "SWITCH_INV" H 1750 3500 50  0000 C CNN
F 2 "CustomParts:MARQUARDT_SPDT" H 1900 3650 50  0001 C CNN
F 3 "" H 1900 3650 50  0000 C CNN
	1    1900 3650
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 56856808
P 4300 1250
F 0 "R2" V 4380 1250 50  0000 C CNN
F 1 "220" V 4300 1250 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4230 1250 50  0001 C CNN
F 3 "" H 4300 1250 50  0000 C CNN
	1    4300 1250
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 5685688B
P 3200 1600
F 0 "R1" V 3280 1600 50  0000 C CNN
F 1 "220" V 3200 1600 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 3130 1600 50  0001 C CNN
F 3 "" H 3200 1600 50  0000 C CNN
	1    3200 1600
	1    0    0    -1  
$EndComp
$Comp
L DIN_5 P1
U 1 1 56856A5E
P 3600 1050
F 0 "P1" H 3600 1050 50  0000 C CNN
F 1 "DIN_5" H 3600 900 50  0000 C CNN
F 2 "CustomParts:HIRSCHMANN_MAB_5" H 3600 1050 50  0001 C CNN
F 3 "" H 3600 1050 50  0000 C CNN
	1    3600 1050
	-1   0    0    1   
$EndComp
$Comp
L Arduino_micro U1
U 1 1 5686B5C9
P 4600 3550
F 0 "U1" H 4600 4950 60  0000 C CNN
F 1 "Arduino_micro" H 4600 3050 60  0000 C CNN
F 2 "CustomParts:ARDU_MICRO_SOCKET" H 4600 3550 60  0001 C CNN
F 3 "" H 4600 3550 60  0000 C CNN
	1    4600 3550
	1    0    0    -1  
$EndComp
$Comp
L SWITCH_INV SW5
U 1 1 5686BDC8
P 3150 4650
F 0 "SW5" H 2950 4800 50  0000 C CNN
F 1 "SWITCH_INV" H 3000 4500 50  0000 C CNN
F 2 "CustomParts:YSS_1203" H 3150 4650 50  0001 C CNN
F 3 "" H 3150 4650 50  0000 C CNN
	1    3150 4650
	-1   0    0    -1  
$EndComp
$Comp
L MPX5010DP U2
U 1 1 5686DE38
P 6800 3850
F 0 "U2" H 6800 4500 60  0000 C CNN
F 1 "MPX5010DP" H 6800 4000 60  0000 C CNN
F 2 "CustomParts:MPX5010DP" H 6800 3850 60  0001 C CNN
F 3 "" H 6800 3850 60  0000 C CNN
	1    6800 3850
	0    1    1    0   
$EndComp
$Comp
L SW_PUSH SW6
U 1 1 574F1CE6
P 5850 4000
F 0 "SW6" H 6000 4110 50  0000 C CNN
F 1 "SW_PUSH" H 5850 3920 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH_SMALL" H 5850 4000 50  0001 C CNN
F 3 "" H 5850 4000 50  0000 C CNN
	1    5850 4000
	1    0    0    -1  
$EndComp
$Comp
L POT RV3
U 1 1 574F2601
P 5700 2600
F 0 "RV3" H 5700 2520 50  0000 C CNN
F 1 "10k" H 5700 2600 50  0000 C CNN
F 2 "CustomParts:ALPS_402125" H 5700 2600 50  0001 C CNN
F 3 "" H 5700 2600 50  0000 C CNN
	1    5700 2600
	-1   0    0    1   
$EndComp
$Comp
L Joystick U3
U 1 1 577E5911
P 6800 2250
F 0 "U3" H 6600 2050 60  0000 C CNN
F 1 "Joystick" H 6600 2450 60  0000 C CNN
F 2 "CustomParts:ALPS_RKJXP" H 6775 2050 60  0001 C CNN
F 3 "" H 6775 2050 60  0000 C CNN
	1    6800 2250
	1    0    0    -1  
$EndComp
$Comp
L Battery BT1
U 1 1 577E5E4D
P 6150 1450
F 0 "BT1" H 6250 1500 50  0000 L CNN
F 1 "Battery" H 6250 1400 50  0000 L CNN
F 2 "CustomParts:9V_BATTERY_CLIP" V 6150 1490 50  0001 C CNN
F 3 "" V 6150 1490 50  0000 C CNN
	1    6150 1450
	0    -1   -1   0   
$EndComp
$Comp
L POT RV1
U 1 1 577E60FF
P 4000 5050
F 0 "RV1" H 4000 4970 50  0000 C CNN
F 1 "10k" H 4000 5050 50  0000 C CNN
F 2 "CustomParts:ALPS_402125" H 4000 5050 50  0001 C CNN
F 3 "" H 4000 5050 50  0000 C CNN
	1    4000 5050
	1    0    0    -1  
$EndComp
$Comp
L POT RV2
U 1 1 577E6156
P 4000 5400
F 0 "RV2" H 4000 5320 50  0000 C CNN
F 1 "10k" H 4000 5400 50  0000 C CNN
F 2 "CustomParts:ALPS_402125" H 4000 5400 50  0001 C CNN
F 3 "" H 4000 5400 50  0000 C CNN
	1    4000 5400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 577E6633
P 3600 1700
F 0 "#PWR01" H 3600 1450 50  0001 C CNN
F 1 "GND" H 3600 1550 50  0000 C CNN
F 2 "" H 3600 1700 50  0000 C CNN
F 3 "" H 3600 1700 50  0000 C CNN
	1    3600 1700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 577E6679
P 6300 1450
F 0 "#PWR02" H 6300 1200 50  0001 C CNN
F 1 "GND" H 6300 1300 50  0000 C CNN
F 2 "" H 6300 1450 50  0000 C CNN
F 3 "" H 6300 1450 50  0000 C CNN
	1    6300 1450
	0    -1   -1   0   
$EndComp
Text Label 5300 2800 2    60   ~ 0
5V
Text Label 7200 2750 2    60   ~ 0
REF
Text Label 7450 2050 2    60   ~ 0
REF
$Comp
L GND #PWR03
U 1 1 577E691E
P 7550 2250
F 0 "#PWR03" H 7550 2000 50  0001 C CNN
F 1 "GND" H 7550 2100 50  0000 C CNN
F 2 "" H 7550 2250 50  0000 C CNN
F 3 "" H 7550 2250 50  0000 C CNN
	1    7550 2250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 577E6964
P 6800 2750
F 0 "#PWR04" H 6800 2500 50  0001 C CNN
F 1 "GND" H 6800 2600 50  0000 C CNN
F 2 "" H 6800 2750 50  0000 C CNN
F 3 "" H 6800 2750 50  0000 C CNN
	1    6800 2750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 577E69AC
P 5500 2600
F 0 "#PWR05" H 5500 2350 50  0001 C CNN
F 1 "GND" H 5500 2450 50  0000 C CNN
F 2 "" H 5500 2600 50  0000 C CNN
F 3 "" H 5500 2600 50  0000 C CNN
	1    5500 2600
	1    0    0    -1  
$EndComp
Text Label 6000 2600 2    60   ~ 0
REF
$Comp
L GND #PWR06
U 1 1 577E6C2C
P 6400 3700
F 0 "#PWR06" H 6400 3450 50  0001 C CNN
F 1 "GND" H 6400 3550 50  0000 C CNN
F 2 "" H 6400 3700 50  0000 C CNN
F 3 "" H 6400 3700 50  0000 C CNN
	1    6400 3700
	0    1    1    0   
$EndComp
Text Label 5900 3800 0    60   ~ 0
5V
$Comp
L GND #PWR07
U 1 1 577E6F7B
P 3850 5600
F 0 "#PWR07" H 3850 5350 50  0001 C CNN
F 1 "GND" H 3850 5450 50  0000 C CNN
F 2 "" H 3850 5600 50  0000 C CNN
F 3 "" H 3850 5600 50  0000 C CNN
	1    3850 5600
	1    0    0    -1  
$EndComp
Text Label 4500 5400 2    60   ~ 0
REF
$Comp
L GND #PWR08
U 1 1 577E7437
P 3850 2800
F 0 "#PWR08" H 3850 2550 50  0001 C CNN
F 1 "GND" H 3850 2650 50  0000 C CNN
F 2 "" H 3850 2800 50  0000 C CNN
F 3 "" H 3850 2800 50  0000 C CNN
	1    3850 2800
	0    1    1    0   
$EndComp
$Comp
L GND #PWR09
U 1 1 577E74A5
P 5200 2600
F 0 "#PWR09" H 5200 2350 50  0001 C CNN
F 1 "GND" H 5200 2450 50  0000 C CNN
F 2 "" H 5200 2600 50  0000 C CNN
F 3 "" H 5200 2600 50  0000 C CNN
	1    5200 2600
	0    -1   -1   0   
$EndComp
Text Label 4750 1250 2    60   ~ 0
5V
Text Label 4900 4300 0    60   ~ 0
REF
$Comp
L GND #PWR010
U 1 1 577FB265
P 6200 2250
F 0 "#PWR010" H 6200 2000 50  0001 C CNN
F 1 "GND" H 6200 2100 50  0000 C CNN
F 2 "" H 6200 2250 50  0000 C CNN
F 3 "" H 6200 2250 50  0000 C CNN
	1    6200 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	2600 2350 2600 4750
Wire Wire Line
	2400 2350 2600 2350
Wire Wire Line
	2400 2800 2600 2800
Connection ~ 2600 2800
Wire Wire Line
	2400 3250 2600 3250
Connection ~ 2600 3250
Connection ~ 2600 3750
Wire Wire Line
	3000 2000 3000 2600
Wire Wire Line
	1400 2000 3000 2000
Wire Wire Line
	1400 2000 1400 2250
Wire Wire Line
	1200 2700 1400 2700
Wire Wire Line
	1200 2700 1200 4000
Wire Wire Line
	1400 3150 1250 3150
Wire Wire Line
	1250 3150 1250 3900
Wire Wire Line
	1400 3650 1300 3650
Wire Wire Line
	1300 3650 1300 3850
Wire Wire Line
	1200 4000 2750 4000
Wire Wire Line
	1250 3900 2850 3900
Wire Wire Line
	2850 3000 4100 3000
Wire Wire Line
	4100 3100 2950 3100
Wire Wire Line
	1300 3850 2950 3850
Wire Wire Line
	2600 3750 2400 3750
Wire Wire Line
	3200 1250 3200 1450
Wire Wire Line
	4100 2500 3200 2500
Wire Wire Line
	3200 2500 3200 1750
Wire Wire Line
	4000 1250 4150 1250
Wire Wire Line
	3000 2600 4100 2600
Wire Wire Line
	2400 2150 2500 2150
Wire Wire Line
	2500 2150 2500 4550
Wire Wire Line
	2400 2600 2500 2600
Connection ~ 2500 2600
Wire Wire Line
	2400 3050 2500 3050
Connection ~ 2500 3050
Wire Wire Line
	2400 3550 2500 3550
Connection ~ 2500 3550
Wire Wire Line
	2500 4550 2650 4550
Wire Wire Line
	2600 4750 2650 4750
Wire Wire Line
	2750 4000 2750 2900
Wire Wire Line
	2850 3900 2850 3000
Wire Wire Line
	2950 3850 2950 3100
Wire Wire Line
	5100 3500 5700 3500
Wire Wire Line
	5700 3500 5700 2750
Wire Wire Line
	5550 2950 6900 2950
Wire Wire Line
	5550 2950 5550 3400
Wire Wire Line
	5550 3400 5100 3400
Wire Wire Line
	5500 2900 7300 2900
Wire Wire Line
	5500 2900 5500 3300
Wire Wire Line
	5500 3300 5100 3300
Wire Wire Line
	7300 2250 7550 2250
Wire Wire Line
	7300 2050 7450 2050
Wire Wire Line
	6900 2950 6900 2750
Wire Wire Line
	7300 2900 7300 2150
Wire Wire Line
	3950 3300 3950 4900
Wire Wire Line
	3950 4900 4000 4900
Wire Wire Line
	4100 3500 4000 3500
Wire Wire Line
	4000 3500 4000 4800
Wire Wire Line
	4000 4800 4300 4800
Wire Wire Line
	4300 4800 4300 5250
Wire Wire Line
	4300 5250 4000 5250
Wire Wire Line
	5100 2800 5300 2800
Wire Wire Line
	7000 2750 7200 2750
Wire Wire Line
	5500 2600 5550 2600
Wire Wire Line
	5850 2600 6000 2600
Wire Wire Line
	3650 4650 3850 4650
Wire Wire Line
	3850 4650 3850 5600
Connection ~ 3850 5050
Connection ~ 3850 5400
Wire Wire Line
	4150 5050 4150 5400
Wire Wire Line
	3600 1450 3600 1700
Wire Wire Line
	4100 2800 3850 2800
Wire Wire Line
	5200 2600 5100 2600
Wire Wire Line
	5100 3700 5150 3700
Wire Wire Line
	5150 3700 5150 4300
Wire Wire Line
	5150 4300 4900 4300
Wire Wire Line
	5900 3800 6400 3800
Wire Wire Line
	6150 4000 6150 3800
Connection ~ 6150 3800
Connection ~ 5550 3600
Wire Wire Line
	4150 5400 4500 5400
Wire Wire Line
	4450 1250 4750 1250
Wire Wire Line
	2750 2900 4100 2900
Wire Wire Line
	4100 3300 3950 3300
Wire Wire Line
	3800 3200 4100 3200
Wire Wire Line
	5550 4000 5550 3600
$Comp
L D D1
U 1 1 578E172C
P 5900 3600
F 0 "D1" H 5900 3700 50  0000 C CNN
F 1 "D" H 5900 3500 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 5900 3600 50  0001 C CNN
F 3 "" H 5900 3600 50  0000 C CNN
	1    5900 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 3600 6050 3600
Wire Wire Line
	5100 3600 5750 3600
$Comp
L Switch_SPDT_x2 SW?
U 1 1 57F7F6C6
P 5550 1350
F 0 "SW?" H 5350 1500 50  0000 C CNN
F 1 "Switch_SPDT_x2" H 5300 1200 50  0000 C CNN
F 2 "" H 5550 1350 50  0000 C CNN
F 3 "" H 5550 1350 50  0000 C CNN
	1    5550 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 1450 5850 1450
Wire Wire Line
	5250 1350 5250 2500
Wire Wire Line
	5250 2500 5100 2500
Wire Wire Line
	3800 3200 3800 2150
Wire Wire Line
	3800 2150 6200 2150
$EndSCHEMATC
