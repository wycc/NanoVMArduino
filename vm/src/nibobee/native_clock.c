//
//  Nibo-NanoVM, a tiny java VM for the Nibo robot
//
//  Copyright (C) 2007 by Nils Springob <nils@nicai-systems.de>
//  Based on work by Benjamin Benz(c't-Bot) and Till Harbaum(NanoVM)
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

//
//  native_clock.c
//

#include "types.h"
#include "debug.h"
#include "config.h"
#include "error.h"

#ifdef NIBOBEE

#include "delay.h"
#include "stack.h"
#include "vm.h"
#include "nibobee/native.h"
#include "nibobee/native_clock.h"

#include "nibobee/motpwm.h"
#include "nibobee/motpid.h"
#include "nibobee/clock.h"

#include <util/delay.h>
#include <avr/interrupt.h>

#define NATIVE_METHOD_getSeconds 1
#define NATIVE_METHOD_getMilliseconds 2
#define NATIVE_METHOD_delayMilliseconds 3
#define NATIVE_METHOD_delayMicroseconds 4

// initialize the ctbot hardware
void native_nibobee_clock_init(void) {
  motpwm_init();
}

// the ctbot class
void native_nibobee_clock_invoke(u08_t mref) {

  // JAVA: void delayMilliseconds(int msec)
  if(mref == NATIVE_METHOD_delayMilliseconds) {
    nvm_int_t time = stack_pop_int();
    sei();
    while(time--)
      _delay_ms(1);
  }

  // JAVA: void delayMicroseconds(int usec)
  else if(mref == NATIVE_METHOD_delayMicroseconds) {
    nvm_int_t time = stack_pop_int();
    sei();
    _delay_us(time);
  }

  // JAVA: int getSeconds()
  else if(mref == NATIVE_METHOD_getSeconds) {
    cli();
    nvm_int_t res = clock_sec;
    sei();
    stack_push(res);
  }

  // JAVA: int getMiliseconds()
  else if(mref == NATIVE_METHOD_getMilliseconds) {
    cli();
    nvm_int_t res = clock_ms;
    sei();
    stack_push(res);
  
  } else
    error(ERROR_NATIVE_UNKNOWN_METHOD);


}

#endif
