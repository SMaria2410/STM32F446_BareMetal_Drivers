#include <stdio.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "uart.h"
#include "timebase.h"
#include "bsp.h"
//MODULE de implementat:
//FPU -> floating point unit(pt calcul matematic eficient cu float)
//UART -> universal asynchronous receiver transmitter (ne permite sa dam send si receive la date)
//TIMEBASE -> SysTick
//GPIO (BSP) -> General Purpose I/O (Board Support Package)
//ADC


//setam bitul 0 la 1 ca mai tarziu sa copiem valoarea
//aceasta in registrul de enable AHB1 (ca sa dam
//enable la accesul la clock catre GPIOA)
#define GPIOAEN (1U<<0)
//setam bitul 5 la 1 (shiftam 1 la pozitia 5)
#define PIN5 (1U<<5)
//din nucleo user guide aflam ca LED-ul este conectat
//la pinul 5
#define LED_PIN PIN5

bool btn_state;
int main()
{
	//enable fpu
	fpu_enable();

	//initializam debug UART
	debug_uart_init();

	//intializam timebase ul
	timebase_init();

	//initializam led ul
	led_init();
	//initializam butonul
	button_init();

	while(1) {
		//printf("Hello from STM32\n\r");
		//delay(1); //vrem sa dam print la mesaj in fiecare secunda
		//pornim led ul
		led_on();
		//verificam starea butonului
		btn_state = get_btn_state();
	}
}
