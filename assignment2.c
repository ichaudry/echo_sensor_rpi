/*************************************************************** 
 * Class:  CSC-615-01 Spring2020
 * Name: Ibraheem Chaudry
 * Student ID: 917227459 
 * Project:Assignment 2 - echo sensor _ Tapeless Ruler 
 * 
 * File: assignment2.c
 * 
 * Description: Interfacing of echo sensor onto raspberry pi to calculate distance from objects.
 ****************************************************************/

#include <wiringPi.h>
#include <stdio.h>
#include <time.h>



int main(void)
{
	wiringPiSetup();
	
	//Initalize pins for echo and trigger
	int trigger=21;
	int echo=22;
	
	//Set pin mode
	pinMode(trigger,OUTPUT);
	pinMode(echo,INPUT);
	
	
	
	//Make sure the pins are off before the start of loop
	//digitalWrite(0,LOW);
	//digitalWrite(2,LOW);
	//digitalWrite(3,LOW);
	
	
	while(1){
		double startTime=0;
		double endTime=0;
		double pulseDuration=0;
		double distance=0;
		
		
		
		//Set trigger to low initially
		digitalWrite(trigger,LOW);
		printf("Waiting for the sensor to settle\n");
		delay(500);
		
		
		//Set trigger to high and then low to send signal 
		digitalWrite(trigger,HIGH);
		delay(0.05);
		digitalWrite(trigger,LOW);
		
			
		while(digitalRead(echo)==LOW){
			startTime=clock();
			
		}
		
		while(digitalRead(echo)==HIGH){
			endTime=clock();
		}
		
		pulseDuration=((double)(endTime-startTime))/CLOCKS_PER_SEC;
		
		distance= pulseDuration*17000;
		
		if(distance > 2 && distance < 350)
			printf("The distance is: %f\n",distance);
		
	}
	
	return 0;
}

