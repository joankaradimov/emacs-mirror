/* Definitions and headers for communication on the Microsoft Windows API.
   Copyright (C) 1995, 2001-2021 Free Software Foundation, Inc.

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

#ifndef EMACS_W32GUI_H
#define EMACS_W32GUI_H
#include <windows.h>

#include "systime.h" /* for Time */
#include "xutilcompat.h"

/* FIXME: old local memory management for menus.  */
#define local_heap (GetProcessHeap ())
#define local_alloc(n) (HeapAlloc (local_heap, HEAP_ZERO_MEMORY, (n)))
#define local_free(p) (HeapFree (local_heap, 0, ((LPVOID) (p))))

typedef HBITMAP Emacs_Pixmap;

typedef HWND Window;
typedef HDC Display;  /* HDC so it doesn't conflict with xpm lib.  */
typedef HCURSOR Emacs_Cursor;

/* Windows equivalent of XImage.  */
typedef struct _XImage
{
  unsigned char * data;
  BITMAPINFO info;
  /* Optional RGBQUAD array for palette follows (see BITMAPINFO docs).  */
} XImage;

struct image;
extern int w32_load_image (struct frame *f, struct image *img,
                           Lisp_Object spec_file, Lisp_Object spec_data);
extern bool w32_can_use_native_image_api (Lisp_Object);
extern void w32_gdiplus_shutdown (void);
extern size_t w32_image_size (Emacs_Pixmap);

#define FACE_DEFAULT (~0)

extern HINSTANCE hinst;

#define NativeRectangle RECT

#define CONVERT_TO_EMACS_RECT(xr,nr)            \
  ((xr).x = (nr).left,				\
   (xr).y = (nr).top,				\
   (xr).width = ((nr).right - (nr).left),	\
   (xr).height = ((nr).bottom - (nr).top))

#define CONVERT_FROM_EMACS_RECT(xr,nr)		\
  ((nr).left = (xr).x,				\
   (nr).top = (xr).y,				\
   (nr).right = ((xr).x + (xr).width),		\
   (nr).bottom = ((xr).y + (xr).height))

#define STORE_NATIVE_RECT(nr,x,y,width,height)	\
  ((nr).left = (x),				\
   (nr).top = (y),				\
   (nr).right = ((nr).left + (width)),		\
   (nr).bottom = ((nr).top + (height)))


#endif /* EMACS_W32GUI_H */
