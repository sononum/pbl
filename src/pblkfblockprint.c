/*
 pblkfblockprint.c - shell program to print block layout

 Copyright (C) 2002 - 2007   Peter Graf

   This file is part of PBL - The Program Base Library.
   PBL is free software.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

   For more information on the Program Base Library or Peter Graf,
   please see: http://www.mission-base.com/.

    $Log: pblkfblockprint.c,v $
    Revision 1.6  2009/03/08 20:56:50  peter
    port to gcc (Ubuntu 4.3.2-1ubuntu12) 4.3.2.
    Exposing the hash set and tree set interfaces.


    Revision 1.1  2002/09/12 20:47:08  peter
    Initial revision


------------------------------------------------------------------------------
*/

/* 
 * make sure "strings <exe> | grep Id | sort -u" shows the source file versions
 */
char * pblkfblockprint_c_id = "$Id: pblkfblockprint.c,v 1.6 2009/03/08 20:56:50 peter Exp $";

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include "pbl.h"

extern int pblKfBlockPrint(
char * path,       /** path of file to create                                 */
long blockno       /** number of block to print                               */
);

/* 
 * Eclipse CDT does not like more than one main,
 * therefore hide all but one main with this -D option
 */
#ifndef CDT_BUILD 

int main( int argc, char * argv[] )
{
    long   blockno;

    if( argc != 3 )
    {
        fprintf( stderr, "Usage: %s path blockno\n", argv[ 0 ] );
        exit( 1 );
    }

    blockno = atoi( argv[ 2 ] );

    pblKfBlockPrint( argv[ 1 ], blockno );

    return( 0 );
}

#endif /* CDT_BUILD */

