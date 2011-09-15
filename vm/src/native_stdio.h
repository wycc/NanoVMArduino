//
//  NanoVM, a tiny java VM for the Atmel AVR family
//  Copyright (C) 2005 by Till Harbaum <Till@Harbaum.org>
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

//
//  native_stdio.h
//

#ifndef NATIVE_STDIO_H
#define NATIVE_STDIO_H

void native_java_io_printstream_invoke(u08_t mref);
void native_java_io_inputstream_invoke(u08_t mref);
void native_java_lang_stringbuffer_invoke(u08_t mref);
void native_itoa(char *str, nvm_int_t val);

#endif // NATIVE_STDIO_H
