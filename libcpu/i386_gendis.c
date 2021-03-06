/* Generate tables for x86 disassembler.
   Copyright (C) 2007, 2008 Red Hat, Inc.
   This file is part of Red Hat elfutils.
   Written by Ulrich Drepper <drepper@redhat.com>, 2007.

   Red Hat elfutils is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by the
   Free Software Foundation; version 2 of the License.

   Red Hat elfutils is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with Red Hat elfutils; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301 USA.

   Red Hat elfutils is an included package of the Open Invention Network.
   An included package of the Open Invention Network is a package for which
   Open Invention Network licensees cross-license their patents.  No patent
   license is granted, either expressly or impliedly, by designation as an
   included package.  Should you wish to participate in the Open Invention
   Network licensing program, please visit www.openinventionnetwork.com
   <http://www.openinventionnetwork.com>.  */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <error.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int i386_parse (void);


extern FILE *i386_in;
extern int i386_debug;
char *infname;

FILE *outfile;

int
main (int argc, char *argv[argc])
{
  outfile = stdout;

  if (argc == 1)
    error (EXIT_FAILURE, 0, "usage: %s <MNEDEFFILE>", argv[0]);

  //i386_debug = 1;
  infname = argv[1];
  if (strcmp (infname, "-") == 0)
    i386_in = stdin;
  else
    {
      i386_in = fopen (infname, "r");
      if (i386_in == NULL)
	error (EXIT_FAILURE, errno, "cannot open %s", argv[1]);
    }

  i386_parse ();

  return error_message_count != 0;
}
