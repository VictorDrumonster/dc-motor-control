#include <xc.h>
#include <stdint.h>
#define  _XTAL_FREQ 4000000
int16_t valor;



void main(void) {
	//TRISA =TRISA |(1<<0)
		
		TRISA 	|=1<<0;		//ra0 como entrada
		ANSEL 	|=1<<0;		//RA0 como entrada analogica			
		//ADCON= ADDS=FOSC/8, CHS=AN0,	GO=0,ADON1
		ADCON0=0x00;
		ADCON0|=0b01000001;
		//ADCON1: ADFM= right, 	VCFG1=VSS,	VCFG0=VDD
		ADCON1=0;
		ADCON1|=(1<<7);
		TRISD=0;
		TRISC=0;

	while(1){
		ADCON0 |= (1<<1);	//seta o go/done (inicia conversão)
		while(ADCON0 & (1<<1))
		valor= (ADRESH<<8) + ADRESL;
		
	
	
	}
}