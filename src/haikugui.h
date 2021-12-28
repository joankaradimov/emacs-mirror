/* Haiku window system support
   Copyright (C) 2021 Free Software Foundation, Inc.

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

#ifndef _HAIKU_GUI_H_
#define _HAIKU_GUI_H_

#ifdef _cplusplus
extern "C"
{
#endif

typedef struct haiku_char_struct
{
  int rbearing;
  int lbearing;
  int width;
  int ascent;
  int descent;
} XCharStruct;

struct haiku_rect
{
  int x, y;
  int width, height;
};

typedef void *haiku;

typedef haiku Emacs_Pixmap;
typedef haiku Emacs_Window;
typedef haiku Emacs_Cursor;
typedef haiku Drawable;

#include "xutilcompat.h"

typedef haiku Window;
typedef int Display;

#ifdef _cplusplus
};
#endif
#endif /* _HAIKU_GUI_H_ */
