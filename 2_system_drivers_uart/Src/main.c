#include <stdio.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "uart.h"
//MODULE de implementat:
//FPU -> floating point unit(pt calcul matematic eficient cu float)
//UART -> universal asynchronous receiver transmitter (ne permite sa dam send si receive la date)
//GPIO
//TIMEBASE


//setam bitul 0 la 1 ca mai tarziu sa copiem valoarea
//aceasta in registrul de enable AHB1 (ca sa dam
//enable la accesul la clock catre GPIOA)
#define GPIOAEN (1U<<0)
//setam bitul 5 la 1 (shiftam 1 la pozitia 5)
#define PIN5 (1U<<5)
//din nucleo user guide aflam ca LED-ul este conectat
//la pinul 5
#define LED_PIN PIN5


int main()
{
	//enable fpu
	fpu_enable();

	//initializam debug UART
	debug_uart_init();
	while(1) {
		printf("Hello from STM32\n\r");
		for(int i = 0; i < 9000; i++) {

		}
	}
}
