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

struct image;
extern int w32_load_image (struct frame *f, struct image *img,
                           Lisp_Object spec_file, Lisp_Object spec_data);
extern bool w32_can_use_native_image_api (Lisp_Object);
extern void w32_gdiplus_shutdown (void);
extern size_t w32_image_size (HBITMAP);

#define FACE_DEFAULT (~0)

extern HINSTANCE hinst;

#endif /* EMACS_W32GUI_H */
