/*
 * Copyright (c) 1997, 1998, 1999 Shigio Yamaguchi
 * Copyright (c) 1999, 2000, 2001, 2002, 2003 Tama Communications Corporation
 *
 * This file is part of GNU GLOBAL.
 *
 * GNU GLOBAL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * GNU GLOBAL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _DIE_H_
#define _DIE_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef HAVE_STDARG_H 
#include <stdarg.h>
#else
#include <varargs.h>
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__
#  define __attribute__(x)
# endif
/* The __-protected variants of `format' and `printf' attributes
   are accepted by gcc versions 2.6.4 (effectively 2.7) and later.  */
# if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 7)
#  define __format__ format
#  define __printf__ printf
# endif
#endif

extern	const char *progname;

void setquiet();
void setverbose();
#ifdef HAVE_STDARG_H
void die(const char *s, ...)
	__attribute__ ((__format__ (__printf__, 1, 2)));
#else
void die();
#endif
#ifdef HAVE_STDARG_H
void die_with_code(int n, const char *s, ...)
	__attribute__ ((__format__ (__printf__, 2, 3)));
#else
void die_with_code();
#endif
#ifdef HAVE_STDARG_H
void message(const char *s, ...)
	__attribute__ ((__format__ (__printf__, 1, 2)));
#else
void message();
#endif
#ifdef HAVE_STDARG_H
void warning(const char *s, ...)
	__attribute__ ((__format__ (__printf__, 1, 2)));
#else
void warning();
#endif

#endif /* ! _DIE_H_ */
