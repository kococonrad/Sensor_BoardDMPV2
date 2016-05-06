/*
 * Sensor_BoardDMPV2.cpp
 *
 * Created: 5/6/2016 12:31:16 PM
 * Author : conradko
 */ 
#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <avr/io.h>
#include "main.h"
#include "Feedback.h"

volatile unsigned long count_t=0;

ISR(TIMER2_OVF_vect)
{
	count_t++;
}

void init_tcnt2()
{
	ASSR |=(0<<AS2);//Run of 32khz osc
	TIMSK2=0x00;  //reset TIMSK
	TIMSK2 |=(1<<TOIE2);//turns on comp match interupt
	TCCR2A=0;
	TCCR2B=(1<<CS21)|(1<<CS20);//Normal mode prescale 32 should give a 1ms count
}

unsigned long timestamp(void){
	return count_t;
}


int main(void)
{
	init_tcnt2();
    /* Replace with your application code */
    while (1) 
    {
    }
}

