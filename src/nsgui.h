/* Definitions and headers for communication on the NeXT/Open/GNUstep API.
   Copyright (C) 1995, 2005, 2008-2021 Free Software Foundation, Inc.

This file is part of GNU Emacs.

GNU Emacs is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

GNU Emacs is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Emacs.  If not, see <https://www.gnu.org/licenses/>.  */

#ifndef __NSGUI_H__
#define __NSGUI_H__

/* This gets included from a couple of the plain (non-NS) .c files.  */
#ifdef __OBJC__

#ifdef NS_IMPL_COCOA
#ifdef Z
#warning "Z is defined.  If you get a later parse error in a header, check that buffer.h or other files #define-ing Z are not included."
#endif  /* Z */
#define Cursor FooFoo
#endif  /* NS_IMPL_COCOA */

#undef verify

#import <AppKit/AppKit.h>

#ifdef NS_IMPL_COCOA
#undef Cursor
#endif /* NS_IMPL_COCOA */
#import <Foundation/NSDistantObject.h>

#ifdef NS_IMPL_COCOA
#include <AvailabilityMacros.h>
#endif /* NS_IMPL_COCOA */

#endif /* __OBJC__ */

#undef verify
#undef _GL_VERIFY_H
#include <verify.h>

/* Emulate XCharStruct.  */
typedef struct _XCharStruct
{
  int rbearing;
  int lbearing;
  int width;
  int ascent;
  int descent;
} XCharStruct;

#ifndef __OBJC__
#if defined (__LP64__) && __LP64__
typedef double CGFloat;
#else
typedef float CGFloat;
#endif
typedef struct _NSPoint { CGFloat x, y; } NSPoint;
typedef struct _NSSize  { CGFloat width, height; } NSSize;
typedef struct _NSRect  { NSPoint origin; NSSize size; } NSRect;
#endif  /* NOT OBJC */

#include "xutilcompat.h"

#endif  /* __NSGUI_H__ */
