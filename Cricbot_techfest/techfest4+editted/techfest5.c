/*****************************************************
This program was produced by the
CodeWizardAVR V2.04.4a Advanced
Automatic Program Generator
� Copyright 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 08/12/2011
Author  : NeVaDa
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16.h>
#include <delay.h>
char c;

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x15 ;PORTC
#endasm
#include <lcd.h>

// Standard Input/Output functions
#include <stdio.h>

// Declare your global variables here

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=T State6=T State5=T State4=T State3=0 State2=0 State1=0 State0=0 
PORTB=0x00;
DDRB=0x0F;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=Out Func6=Out Func5=Out Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=0 State6=0 State5=0 State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0xE0;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: Fast PWM top=FFh
// OC0 output: Non-Inverted PWM
TCCR0=0x69;
TCNT0=0x00;
OCR0=00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 125.000 kHz
// Mode: Fast PWM top=ICR1
// OC1A output: Non-Inv.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x82;
TCCR1B=0x1A;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x09;
ICR1L=0xC3;
OCR1A=100;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: Fast PWM top=FFh
// OC2 output: Non-Inverted PWM
ASSR=0x00;
TCCR2=0x69;
TCNT2=0x00;
OCR2=00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 4800
UCSRA=0x00;
UCSRB=0x18;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x0C;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// LCD module initialization
lcd_init(16);

while (1)
      {  
      
      c=getchar();
      putchar(c);
      if(c=='c')
      {
       OCR1A=172; 
      }
      else if(c=='o')
      {
        OCR1A=80;
      } 
          
     
      else if(c=='d')
      {
            OCR0=0;
            OCR2=170;
            PORTB.0=1;
            PORTB.1=0;
            PORTB.2=0;
            PORTD.6=1;
      }
      
      else if(c=='i')
      {
             OCR0=180;
            OCR2=120;
            PORTB.0=1;
            PORTB.1=0;
            PORTB.2=0;
            PORTD.6=1;
      }
      
      else if(c=='e')
      {
             OCR0=170;
            OCR2=0;
            PORTB.0=0;
            PORTB.1=1;
            PORTB.2=1;
            PORTD.6=0;
      }
      
      else if(c=='n')
      {
            OCR0=120;
            OCR2=180;
            PORTB.0=0;
            PORTB.1=1;
            PORTB.2=1;
            PORTD.6=0;
      } 
      
      else if(c=='f')
        {         
       // lcd_putchar(c);
        //delay_ms(500); 
        //putchar('f');
             OCR0=170;
            OCR2=170;
            PORTB.0=0;
            PORTB.1=1;
            PORTB.2=0;
            PORTD.6=1; 

        }   
        else if(c=='F')
        {         
       // lcd_putchar(c);
        //delay_ms(500); 
        //putchar('f');
             OCR0=200;
            OCR2=200;
            PORTB.0=0;
            PORTB.1=1;
            PORTB.2=0;
            PORTD.6=1; 

        }  
        else if(c=='g'){  
        OCR0=220;
            OCR2=220;
            PORTB.0=0;
            PORTB.1=1;
            PORTB.2=0;
            PORTD.6=1;
        }
        
       else if(c=='b')
        {         
        //lcd_putchar('b');
       // delay_ms(500);
            OCR0=220;
            OCR2=220;
            PORTB.0=1;
            PORTB.1=0;
            PORTB.2=1;
            PORTD.6=0;
          
           
        }                     
        
        else if(c=='r')
        {   
             OCR0=180;
            OCR2=140;
            PORTB.0=0;
            PORTB.1=1;
            PORTB.2=1;
            PORTD.6=0;
            
        }                  
        
        else if(c=='l')
        {     
             OCR0=130;
            OCR2=180;
            PORTB.0=1;
            PORTB.1=0;
            PORTB.2=0;
            PORTD.6=1;
           
        }  
        else if(c=='R')
        { 
       // lcd_putchar(c);
        //delay_ms(500);
        //putchar('R'); 
            OCR0=170;
            OCR2=170;
            PORTB.0=0;
            PORTB.1=1;
            PORTB.2=1;
            PORTD.6=0;
           
        }                  
        
        else if(c=='L')
        {              
       // lcd_putchar(c);
       // delay_ms(500);
        //putchar('l'); 
             OCR0=170;
            OCR2=170;
            PORTB.0=1;
            PORTB.1=0;
            PORTB.2=0;
            PORTD.6=1;
        }                  
        
       else if (c=='s')
        {
           // putchar('s');
            PORTB.0=1;
            PORTB.1=1;
            PORTB.2=1;
            PORTD.6=1;   
            //lcd_putsf("Stop");
            //delay_ms(5);
        }   
      // Place your code here

      };
}
