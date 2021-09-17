#include <reg51.h>
#include <myio.h>
#define PB P3
#define SEG P0
char code TAB[5] = {0xf9, 0xa4, 0xb0, 0x99, 0xf8};

main()
{
	LED = 0xff;
	while (1)
	{
		PB = 0xff;
		switch (~PB)
		{
		case 0x04:
		{
			debouncer();
			while (~PB == 0x04)
				SEG = TAB[0];
			debouncer();
			alter(3);
			flash(3);
			SEG = 0xff;
			break;
		}
		case 0x08:
		{
			debouncer();
			while (~PB == 0x08)
				;
			SEG = TAB[1];
			debouncer();
			left(3);
			flash(3);
			SEG = 0xff;
			break;
		}
		case 0x10:
		{
			debouncer();
			while (~PB == 0x10)
				;
			SEG = TAB[2];
			debouncer();
			right(3);
			flash(3);
			SEG = 0xff;
			break;
		}
		case 0x30:
		{
			debouncer();
			while (~PB == 0x30)
				;
			SEG = TAB[4];
			debouncer();
			pili(3);
			flash(3);
			SEG = 0xff;
			break;
		}
		}
	}
}