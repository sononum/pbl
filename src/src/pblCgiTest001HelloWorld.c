/*
pblCgiTest001HelloWorld.c - pblCgi test 001, print a hello world template

Copyright (c) 2018 Peter Graf. All rights reserved.

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

$Log: pblCgiTest001HelloWorld.c,v $
Revision 1.3  2018/03/15 22:27:47  peter
Working on cgi tests

Revision 1.2  2018/03/10 16:22:21  peter
More work on cgi functions

Revision 1.1  2018/02/23 23:20:24  peter
Started to work on the cgi code


*/

/*
* make sure "strings <exe> | grep Id | sort -u" shows the source file versions
*/
char* pblCgiTest001HelloWorld_c_id = "$Id: pblCgiTest001HelloWorld.c,v 1.3 2018/03/15 22:27:47 peter Exp $";

#include "pblCgi.h"

int main(int argc, char * argv[])
{
	FILE * stream;
	char * traceFilePath = "/tmp/PBL_CGI_TRACE.LOG";
#ifdef WIN32

	errno_t err = fopen_s(&stream, traceFilePath, "r");
	if (err != 0)
	{
		return -1;
	}

#else

	if (!(stream = fopen(traceFilePath, "r")))
	{
		return -1;
	}

#endif

	fclose(stream);

	pblCgiTraceFile = pblCgiFopen(traceFilePath, "a");
	fputs("\n", pblCgiTraceFile);
	fputs("\n", pblCgiTraceFile);
	PBL_CGI_TRACE("----------------------------------------> Started");

	extern char **environ;
	char ** envp = environ;

	while (envp && *envp)
	{
		PBL_CGI_TRACE("ENV %s", *envp++);
	}

	pblCgiParseQuery(argc, argv);

	pblCgiSetValue("DEFINED", "VALUE");
	pblCgiSetValueForIteration("DEFINED", "VALUE_0", 0);
	pblCgiSetValueForIteration("DEFINED", "VALUE_1", 1);

	pblCgiPrint("/home/peter/eclipse-workspace/pbl/templates/", "Test005_ForLoop.html", "text/html");

	PBL_CGI_TRACE("\n----------------------------------------< FINISHED\n");
	return 0;
}
