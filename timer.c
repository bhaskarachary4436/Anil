#include <REGX51.H>
//#include <reg51.h>   // Include AT89C51 register definitions

void delay(unsigned int count)
{
    unsigned int i;
    for (i = 0; i < count; i++);
}

void main()
{
    TMOD = 0x01;    // Set timer 0 to mode 1 (16-bit timer)
    TH0 = 0xFC;     // Set timer 0 to count from 0xFCED to 0xFFFF (1ms @ 12MHz)
    TL0 = 0xED;
    TR0 = 1;        // Start timer 0
    
    while (1)       // Loop forever
    {
        while (!TF0);   // Wait for timer 0 to overflow
        TF0 = 0;        // Clear timer 0 overflow flag
        P1 ^= 0x01;     // Toggle P1.0 (or any other port pin)
    }
}
