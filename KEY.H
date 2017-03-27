/*
** Program GETKEY.C
**
** Illustrates how to fetch scan code from keyboard.
**
** H. Paul Roach, Morgan State University, July 30, '96
*/

#include <stdio.h>                                            /* 1 */
#include <conio.h>  /* for kbhit */                           /* 2 */
#include <dos.h>                                              /* 3 */							      /* 19 */
void getkey(int &key)                                              /* 20 */
{                                                             /* 21 */
   union REGS in, out;                                        /* 22 */
   in.h.ah = 0x08;                                            /* 23 */
   int86(0x21, &in, &out);
   key=out.h.al;                                  /* 24 */
   if (key== 0)                                         /* 25 */
   {                                                          /* 26 */
      getkey(key);                                 /* 27 */
   }                                                          /* 28 */
				 /* 29 */
							     /* 30 */
					     /* 31 */
							    /* 32 */
}                                                             /* 33 */