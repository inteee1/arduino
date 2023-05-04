/*
 * my_fnd.h
 *
 *  Created on: Oct 27, 2022
 *      Author: tj-bu
 */


#ifndef _MY_FND_LIB_H__
#define _MY_FND_LIB_H__



const unsigned char fnd_font[] =
{
   // 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   H,   L,   E,   o,   P,  F,
   0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x6f,0x76,0x38,0x79,0x5c,0x73,0x71,
   // C,    d,    A,    u,    T,    r,   b,  blk
   0x39, 0x5e, 0x77, 0x1c, 0x44, 0x50, 0x7c, 0x00
};

// fnd maseg display
#define O   0x0d   //o display
#define F   0x0f    // F display
#define H   0x0a    // H   "
#define L   0x0b    // L   "
#define E   0x0c    // E   "
#define P   0x0e    // P   "
#define C   0x10    // C   "
#define D   0x11    // d   "
#define A   0x12    // A   "
#define U   0x13    // u   "
#define T   0x14    // t   "
#define R   0x15    // r   "
#define b   0x16    // b   "
#define BLK 0x00   // fnd blk display

#define X100000 8
#define X10000 9
#define X1000 10
#define X100 11
#define X10 12
#define X1 13


int8_t scan = 0;

void fnd_dis(long d_buf) //uint32_t = long
{
  scan++;
  if(scan > 7) scan = 1;

  switch(scan)
  {
   case 1: // x100000
	      d_out(X1, _OFF); //fnd off
	      PORTD = fnd_font[d_buf/100000];
	      d_out(X100000, _ON); //fnd ON
	   break;
    case 2: // x10000
	      d_out(X100000, _OFF); //fnd off
        (tg_flag == 1) ? PORTD = fnd_font[d_buf%100000/10000] | 0x80 : PORTD = fnd_font[d_buf%100000/10000] & 0x7f;
	      //PORTD = fnd_font[d_buf%100000/10000];
	      d_out(X10000, _ON); //fnd ON
	   break;
    case 3: // x1000
	      d_out(X10000, _OFF); //fnd off
	      PORTD = fnd_font[d_buf%10000/1000]; //| 0x80;
	      d_out(X1000, _ON); //fnd ON
	   break;
    case 4: // x100
	      d_out(X1000, _OFF); //fnd off
	      PORTD = fnd_font[d_buf%1000/100];
	      d_out(X100, _ON); //fnd ON
	   break;
    case 5: // x10
	      d_out(X100, _OFF); //fnd off
	      PORTD = fnd_font[d_buf%100/10];
	      d_out(X10, _ON); //fnd ON
	   break;
    case 6: // x1
	      d_out(X10, _OFF); //fnd off
	      PORTD = fnd_font[d_buf%10] | 0x80;
	      d_out(X1, _ON); //fnd ON
	   break;

   
  }
}

void fnd_time(char hour, char min, char sec ) //uint32_t = long
{
  scan++;
  if(scan > 7) scan = 1;

  switch(scan)
  {
   case 1: // x100000
	      d_out(X1, _OFF); //fnd off
	      PORTD = fnd_font[hour/10];
	      d_out(X100000, _ON); //fnd ON
	   break;
    case 2: // x10000
	      d_out(X100000, _OFF); //fnd off
        (tg_flag == 1) ? PORTD = fnd_font[hour%10] | 0x80 : PORTD = fnd_font[hour%10] & 0x7f;
	      //PORTD = fnd_font[d_buf%100000/10000];
	      d_out(X10000, _ON); //fnd ON
	   break;
    case 3: // x1000
	      d_out(X10000, _OFF); //fnd off
	      PORTD = fnd_font[min/10]; //| 0x80;
	      d_out(X1000, _ON); //fnd ON
	   break;
    case 4: // x100
	      d_out(X1000, _OFF); //fnd off
	      //PORTD = fnd_font[min%10] | 0x80;
        (tg_flag == 0) ? PORTD = fnd_font[min%10] | 0x80 : PORTD = fnd_font[min%10] & 0x7f;
	      d_out(X100, _ON); //fnd ON
	   break;
    case 5: // x10
	      d_out(X100, _OFF); //fnd off
	      PORTD = fnd_font[sec/10];
	      d_out(X10, _ON); //fnd ON
	   break;
    case 6: // x1
	      d_out(X10, _OFF); //fnd off
        (tg_flag == 1) ? PORTD = fnd_font[sec%10] | 0x80 : PORTD = fnd_font[sec%10] & 0x7f;
	      //PORTD = fnd_font[sec%10] | 0x80;
	      d_out(X1, _ON); //fnd ON
	   break;

   
  }
}

void fnd_abc(char d_buf) //uint32_t = long
{
  scan++;
  if(scan > 7) scan = 1;

  switch(scan)
  {
   case 1: // x100000
	      d_out(X1, _OFF); //fnd off
	      PORTD = fnd_font[O];
	      d_out(X100000, _ON); //fnd ON
	   break;
    case 2: // x10000
	      d_out(X100000, _OFF); //fnd off
        //(tg_flag == 1) ? PORTD = fnd_font[b] | 0x80 : PORTD = fnd_font[hour%10] & 0x7f;
	      PORTD = fnd_font[R];
	      d_out(X10000, _ON); //fnd ON
	   break;
    case 3: // x1000
	      d_out(X10000, _OFF); //fnd off
	      PORTD = fnd_font[A]; //| 0x80;
	      d_out(X1000, _ON); //fnd ON
	   break;
    case 4: // x100
	      d_out(X1000, _OFF); //fnd off
	      PORTD = fnd_font[C];
        //(tg_flag == 0) ? PORTD = fnd_font[D] | 0x80 : PORTD = fnd_font[min%10] & 0x7f;
	      d_out(X100, _ON); //fnd ON
	   break;
    case 5: // x10
	      d_out(X100, _OFF); //fnd off
	      PORTD = fnd_font[L];
	      d_out(X10, _ON); //fnd ON
	   break;
    case 6: // x1
	      d_out(X10, _OFF); //fnd off
        //(tg_flag == 1) ? PORTD = fnd_font[sec%10] | 0x80 : PORTD = fnd_font[sec%10] & 0x7f;
	      PORTD = fnd_font[E];
	      d_out(X1, _ON); //fnd ON
	   break;

   
  }
}

#endif /* INC_MY_FND_LIB_H_ */
