/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Pin definition functions for LaunchPad w/ msp430fr5949 (originally for msp430fr5969)
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *     Contribution: Stefan Sch
  *		Modified: J. Ryan Shipley 5/4/2017
  ***********************************************************************
  Derived from:
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#ifndef Pins_Energia_h
#define Pins_Energia_h
#ifndef BV
#define BV(x) (1 << (x))
#endif


#if defined(__MSP430_HAS_EUSCI_B0__)
static const uint8_t SS      = 8;   /* P3.4 */
static const uint8_t SCK     = 23;   /* P2.2 */
static const uint8_t MOSI    = 28;  /* P1.6 aka SIMO */
static const uint8_t MISO    = 29;  /* P1.7 aka SOMI */
static const uint8_t TWISDA1  = 28;  /* P3.6 SW I2C - 26*/
static const uint8_t TWISCL1  = 29;   /* P3.5 SW I2C - 25 */ 
static const uint8_t TWISDA0  = 28;  /* P1.6 UCB0 */
static const uint8_t TWISCL0  = 29;  /* P1.7 UCB0 */
#define TWISDA0_SET_MODE  (PORT_SELECTION1 | INPUT_PULLUP)
#define TWISCL0_SET_MODE  (PORT_SELECTION1 | INPUT_PULLUP)
#define TWISDA1_SET_MODE  (INPUT_PULLUP)
#define TWISCL1_SET_MODE  (INPUT_PULLUP)
#define SPISCK_SET_MODE  (PORT_SELECTION1)
#define SPIMOSI_SET_MODE (PORT_SELECTION1)
#define SPIMISO_SET_MODE (PORT_SELECTION1)
/* Define the default I2C settings */
#define DEFAULT_I2C -1 /* indicates SW I2C on pseudo module 1 */
#define TWISDA TWISDA1
#define TWISCL TWISCL1
#define TWISDA_SET_MODE  TWISDA1_SET_MODE
#define TWISCL_SET_MODE  TWISCL1_SET_MODE
#endif

#if defined(__MSP430_HAS_EUSCI_A0__) || defined(__MSP430_HAS_EUSCI_A1__)
static const uint8_t DEBUG_UARTRXD = 22;  /* Receive  Data (RXD) at P2.1 */
static const uint8_t DEBUG_UARTTXD = 21;  /* Transmit Data (TXD) at P2.0 */
static const uint8_t AUX_UARTRXD = 18;     /* Receive  Data (RXD) at P4.5 */
static const uint8_t AUX_UARTTXD = 17;     /* Transmit Data (TXD) at P4.4 */
#define DEBUG_UARTRXD_SET_MODE (PORT_SELECTION1 | INPUT)
#define DEBUG_UARTTXD_SET_MODE (PORT_SELECTION1 | OUTPUT)
#define AUX_UARTRXD_SET_MODE (PORT_SELECTION1 | INPUT)
#define AUX_UARTTXD_SET_MODE (PORT_SELECTION1 | OUTPUT)
#define DEBUG_UART_MODULE_OFFSET 0x00
#define AUX_UART_MODULE_OFFSET 0x20
#define SERIAL1_AVAILABLE 1
#endif

/* Analog pins */

static const uint8_t A0  = 128 + 0; // Not available on BoosterPack header
static const uint8_t A1  = 128 + 1; // Not available on BoosterPack header
static const uint8_t A2  = 3;
static const uint8_t A3  = 8;
static const uint8_t A4  = 9;
static const uint8_t A5  = 10;
static const uint8_t A6  = 34; // Not available on BoosterPack header
static const uint8_t A7  = 37; // Not available on BoosterPack header
//static const uint8_t A8  = 23; // Available, but not on the 20-pin BP header
//static const uint8_t A9  = 24; // Available, but not on the 20-pin BP header
//static const uint8_t A10 = 128 + 10;
//static const uint8_t A11  = 5;
static const uint8_t A12  = 4; 
static const uint8_t A13  = 5;  // Not available on BoosterPack header
static const uint8_t A14  = 6; // Not available on BoosterPack header
static const uint8_t A15  = 7; // Not available on BoosterPack header


// Pin names based on the MSP430FR5949 Datasheet
//

static const uint8_t P1_0 = 1;
static const uint8_t P1_1 = 2;
static const uint8_t P1_2 = 3;
static const uint8_t P1_3 = 8;
static const uint8_t P1_4 = 9;
static const uint8_t P1_5 = 10;
static const uint8_t P1_6 = 28;
static const uint8_t P1_7 = 29;

static const uint8_t P2_0 = 21;
static const uint8_t P2_1 = 22;
static const uint8_t P2_2 = 23;
static const uint8_t P2_3 = 34;
static const uint8_t P2_4 = 35;
static const uint8_t P2_5 = 17;
static const uint8_t P2_6 = 18;
static const uint8_t P2_7 = 33;

static const uint8_t P3_0 = 4;
static const uint8_t P3_1 = 5;
static const uint8_t P3_2 = 6;
static const uint8_t P3_3 = 7;
static const uint8_t P3_4 = 24;
static const uint8_t P3_5 = 25;
static const uint8_t P3_6 = 26;
static const uint8_t P3_7 = 27;

static const uint8_t P4_0 = 15;
static const uint8_t P4_1 = 16;
//static const uint8_t P4_2 = 2;
//static const uint8_t P4_3 = 5;
static const uint8_t P4_4 = 30;
//static const uint8_t P4_5 = 27;
//static const uint8_t P4_6 = 25;
//static const uint8_t P4_7 = ;

static const uint8_t PJ_0 = 11;
static const uint8_t PJ_1 = 12;
static const uint8_t PJ_2 = 13;
static const uint8_t PJ_3 = 14;
static const uint8_t PJ_4 = 37;
static const uint8_t PJ_5 = 38;
//static const uint8_t PJ_6 = ;
//static const uint8_t PJ_7 = ;


static const uint8_t LED1 = 25;
static const uint8_t LED2 = 26;
/* For LaunchPad compatability */
static const uint8_t RED_LED = 25;
static const uint8_t GREEN_LED = 26;

static const uint8_t PUSH1 = 27;
static const uint8_t PUSH2 = 28;
static const uint8_t TEMPSENSOR = 128 + 30; // depends on chip

#ifdef ARDUINO_MAIN

const uint16_t port_to_input[] = {
	NOT_A_PORT,
	(uint16_t) &P1IN,
	(uint16_t) &P2IN,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3IN,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4IN,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJIN,
#endif
};

const uint16_t port_to_output[] = {
	NOT_A_PORT,
	(uint16_t) &P1OUT,
	(uint16_t) &P2OUT,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3OUT,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4OUT,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJOUT,
#endif
};

const uint16_t port_to_dir[] = {
	NOT_A_PORT,
	(uint16_t) &P1DIR,
	(uint16_t) &P2DIR,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3DIR,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4DIR,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJDIR,
#endif
};

const uint16_t port_to_ren[] = {
	NOT_A_PORT,
	(uint16_t) &P1REN,
	(uint16_t) &P2REN,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3REN,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4REN,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJREN,
#endif
};

const uint16_t port_to_sel0[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL0,
	(uint16_t) &P2SEL0,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3SEL0,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4SEL0,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJSEL0,
#endif
};

const uint16_t port_to_sel1[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL1,
	(uint16_t) &P2SEL1,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3SEL1,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4SEL1,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJSEL1,
#endif
};

const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER,  /*  0 - pin count starts at 1 */
	T0A1,		   /*  1 - P1.0 */
	T0A2,  		   /*  2 - P1.1 */
	T1A1,          /*  3 - P1.2 */
	NOT_ON_TIMER,  /*  4 - P3.0  - note: CCR0 output cannot be used with analogWrite */
	NOT_ON_TIMER,  /*  5 - P3.1 */
	NOT_ON_TIMER,  /*  6 - P3.2  - note: CCR0 output cannot be used with analogWrite */
	NOT_ON_TIMER,  /*  7 - P3.3 */
	T1A2,          /*  8 - P1.3 */
	T0B1,          /*  9 - P1.4 */
	T0B2,          /* 10 - P1.5 */
	
	NOT_ON_TIMER,  /* 11 - PJ.0 */
	NOT_ON_TIMER,  /* 12 - PJ.1 */
	NOT_ON_TIMER,  /* 13 - PJ.2 */
	NOT_ON_TIMER,  /* 14 - PJ.3 */
	NOT_ON_TIMER,  /* 15 - P4.0 */
	NOT_ON_TIMER,  /* 16 - R4.1*/
	T0B0,		   /* 17 - P2.5 */
	T0B1,		   /* 18 - P2.6 */
	NOT_ON_TIMER,  /* 19 - TEST */
	NOT_ON_TIMER,  /* 20 - RESET */
	
	T0B6,          /* 21 - P2.0 */
	T0B0,          /* 22 - P2.1 */
	T0B2,		   /* 23 - P2.2 */
	T0B3,	       /* 24 - P3.4 */
	T0B4,		   /* 25 - P3.5 */
	T0B5,		   /* 26 - P3.6 */
	T0B6,		   /* 27 - P3.7 */
	T0B3,          /* 28 - P1.6 */
	T0B4,		   /* 29 - P1.7 */
	T0B5,		   /* 30 - P4.4 */
	
	NOT_ON_TIMER,  /* 31 - DVSS*/
	NOT_ON_TIMER,  /* 32 - DVCC */
	NOT_ON_TIMER,  /* 33 - P2.7 */
	T0A0, 			/* 34 - P2.3 */
	T0A1, 			/* 35 - P2.4 */
	NOT_ON_TIMER, 	/* 36 - AVSS */
	NOT_ON_TIMER, 	/* 37 - PJ.4 */
	NOT_ON_TIMER,  	/* 38 - PJ.5 */
	NOT_ON_TIMER,   /* 39 - AVSS */
	NOT_ON_TIMER,	/* 40 - AVCC */
};

const uint8_t digital_pin_to_port[] = {
	NOT_A_PIN,  /*  0 - pin count starts at 1 */
	P1,		       /*  1 - P1.0 */
	P1,  		   /*  2 - P1.1 */
	P1,            /*  3 - P1.2 */
	P3,  		   /*  4 - P3.0  - note: CCR0 output cannot be used with analogWrite */
	P3, 		   /*  5 - P3.1 */
	P3,			   /*  6 - P3.2  - note: CCR0 output cannot be used with analogWrite */
	P3,			   /*  7 - P3.3 */
	P1,            /*  8 - P1.3 */
	P1,            /*  9 - P1.4 */
	P1,            /* 10 - P1.5 */
	
	PJ,			   /* 11 - PJ.0 */
	PJ,			   /* 12 - PJ.1 */
	PJ,			   /* 13 - PJ.2 */
	PJ,			   /* 14 - PJ.3 */
	P4,			   /* 15 - P4.0 */
	P4,			   /* 16 - R4.1*/
	P2,			   /* 17 - P2.5 */
	P2,			   /* 18 - P2.6 */
	NOT_A_PIN,  /* 19 - TEST */
	NOT_A_PIN,  /* 20 - RESET */
	
	P2,	           /* 21 - P2.0 */
	P2,	           /* 22 - P2.1 */
	P2,			   /* 23 - P2.2 */
	P3,		       /* 24 - P3.4 */
	P3,			   /* 25 - P3.5 */
	P3,			   /* 26 - P3.6 */
	P3,			   /* 27 - P3.7 */
	P1,            /* 28 - P1.6 */
	P1,		       /* 29 - P1.7 */
	P4,		       /* 30 - P4.4 */
	
	NOT_A_PIN,  /* 31 - DVSS*/
	NOT_A_PIN,  /* 32 - DVCC */
	P2,			   /* 33 - P2.7 */
	P2, 			/* 34 - P2.3 */
	P2, 			/* 35 - P2.4 */
	NOT_A_PIN, 	/* 36 - AVSS */
	PJ,			 	/* 37 - PJ.4 */
	PJ,			  	/* 38 - PJ.5 */
	NOT_A_PIN,   /* 39 - AVSS */
	NOT_A_PIN,	/* 40 - AVCC */
};

const uint8_t digital_pin_to_bit_mask[] = {
	NOT_A_PIN,  /*  0 - pin count starts at 1 */
	BV(0),		       /*  1 - P1.0 */
	BV(1),  		   /*  2 - P1.1 */
	BV(2),            /*  3 - P1.2 */
	BV(0),  		   /*  4 - P3.0  - note: CCR0 output cannot be used with analogWrite */
	BV(1), 		   /*  5 - P3.1 */
	BV(2),			   /*  6 - P3.2  - note: CCR0 output cannot be used with analogWrite */
	BV(3),			   /*  7 - P3.3 */
	BV(3),            /*  8 - P1.3 */
	BV(4),            /*  9 - P1.4 */
	BV(5),            /* 10 - P1.5 */
	
	BV(0),			   /* 11 - PJ.0 */
	BV(1),			   /* 12 - PJ.1 */
	BV(2),			   /* 13 - PJ.2 */
	BV(3),			   /* 14 - PJ.3 */
	BV(0),			   /* 15 - P4.0 */
	BV(1),			   /* 16 - R4.1*/
	BV(5),			   /* 17 - P2.5 */
	BV(6),			   /* 18 - P2.6 */
	NOT_A_PIN,  	   /* 19 - TEST */
	NOT_A_PIN, 		   /* 20 - RESET */
	
	BV(0),	           /* 21 - P2.0 */
	BV(1),	           /* 22 - P2.1 */
	BV(2),			   /* 23 - P2.2 */
	BV(4),		       /* 24 - P3.4 */
	BV(5),			   /* 25 - P3.5 */
	BV(6),			   /* 26 - P3.6 */
	BV(7),			   /* 27 - P3.7 */
	BV(6),             /* 28 - P1.6 */
	BV(7),		       /* 29 - P1.7 */
	BV(4),		       /* 30 - P4.4 */
	
	NOT_A_PIN,  	   /* 31 - DVSS*/
	NOT_A_PIN, 		   /* 32 - DVCC */
	BV(7),			   /* 33 - P2.7 */
	BV(3), 			  /* 34 - P2.3 */
	BV(4), 			  /* 35 - P2.4 */
	NOT_A_PIN, 	      /* 36 - AVSS */
	BV(4),			  /* 37 - PJ.4 */
	BV(5),			  /* 38 - PJ.5 */
	NOT_A_PIN,  	  /* 39 - AVSS */
	NOT_A_PIN,		  /* 40 - AVCC */
};

const uint32_t digital_pin_to_analog_in[] = {
    NOT_ON_ADC,		   /*  0 - pin count starts at 1 */
	0,		   		    /*  1 - P1.0 */
	1,  		   /*  2 - P1.1 */
	2,            /*  3 - P1.2 */
	12,  		   /*  4 - P3.0  - note: CCR0 output cannot be used with analogWrite */
	13, 		      /*  5 - P3.1 */
	14,			   /*  6 - P3.2  - note: CCR0 output cannot be used with analogWrite */
	15,			   /*  7 - P3.3 */
	3,            /*  8 - P1.3 */
	4,            /*  9 - P1.4 */
	5,            /* 10 - P1.5 */
	
	NOT_ON_ADC,			   /* 11 - PJ.0 */
	NOT_ON_ADC,			   /* 12 - PJ.1 */
	NOT_ON_ADC,			   /* 13 - PJ.2 */
	NOT_ON_ADC,			   /* 14 - PJ.3 */
	NOT_ON_ADC,			   /* 15 - P4.0 */
	NOT_ON_ADC,			   /* 16 - R4.1*/
	NOT_ON_ADC,			   /* 17 - P2.5 */
	NOT_ON_ADC,			   /* 18 - P2.6 */
	NOT_ON_ADC,  	   /* 19 - TEST */
	NOT_ON_ADC, 		   /* 20 - RESET */
	
	NOT_ON_ADC,	           /* 21 - P2.0 */
	NOT_ON_ADC,	           /* 22 - P2.1 */
	NOT_ON_ADC,			   /* 23 - P2.2 */
	NOT_ON_ADC,		       /* 24 - P3.4 */
	NOT_ON_ADC,			   /* 25 - P3.5 */
	NOT_ON_ADC,			   /* 26 - P3.6 */
	NOT_ON_ADC,			   /* 27 - P3.7 */
	NOT_ON_ADC,             /* 28 - P1.6 */
	NOT_ON_ADC,		       /* 29 - P1.7 */
	NOT_ON_ADC,		       /* 30 - P4.4 */
	
	NOT_ON_ADC,  	   /* 31 - DVSS*/
	NOT_ON_ADC, 		   /* 32 - DVCC */
	NOT_ON_ADC,			   /* 33 - P2.7 */
	6, 			  /* 34 - P2.3 */
	7, 			  /* 35 - P2.4 */
	NOT_ON_ADC, 	      /* 36 - AVSS */
	NOT_ON_ADC,			  /* 37 - PJ.4 */
	NOT_ON_ADC,			  /* 38 - PJ.5 */
	NOT_ON_ADC,  	  /* 39 - AVSS */
	NOT_ON_ADC,		  /* 40 - AVCC */
};
#endif // #ifdef ARDUINO_MAIN
#endif // #ifndef Pins_Energia_h
