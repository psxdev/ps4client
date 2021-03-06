/*
 * ps4client host tool for PS4 providing host fileio system 
 * Copyright (C) 2003,2015 Antonio Jose Ramos Marquez (aka bigboss) @psxdev on twitter
 * Repository https://github.com/psxdev/ps4client
 * based on psp2client,ps2vfs, ps2client, ps2link, ps2http tools. 
 * Credits goes for all people involved in ps2dev project https://github.com/ps2dev
 * This file is subject to the terms and conditions of the PSP2Client License.
 * See the file LICENSE in the main directory of this distribution for more
 * details.
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utility.h"
#include "ps4link.h"
#ifdef _WIN32
#include "network.h"
#endif



char hostname[256] = { "192.168.1.17" };

int timeout = -1;

int main(int argc, char **argv, char **env) 
{ 
	int loop0 = 0;

	// Turn off stdout buffering.
	setbuf(stdout, NULL);

	// Parse the environment list for optional arguments.
	for (loop0=0; env[loop0]; loop0++) 
	{

		// A hostname has been specified...
		if (strncmp(env[loop0], "PS4HOSTNAME", 11) == 0) { strncpy(hostname, &env[loop0][12], sizeof(hostname)); }
	}
	// Check the number of arguments.
	if (argc < 2) { print_usage(); return -1; }

	// Parse the argument list for optional arguments.
	for (loop0=1; argv[loop0]; loop0++) {

		// If an optional hostname has been specified...
		if (strncmp(argv[loop0], "-h", 2) == 0) { loop0++;

			// Check to make sure the hostname value was actually supplied.
			if (argc == loop0) { printf("Error: No hostname was supplied the '-h' option.\n"); print_usage(); return -1; }

			// Set the hostname to the supplied value.
			strncpy(hostname, argv[loop0], sizeof(hostname));
	  

		}

		// Else, if an optional timeout has been specified...
		else if (strncmp(argv[loop0], "-t", 2) == 0) { loop0++;

			// Check to make sure a value was actually supplied.
			if (argc == loop0) { printf("Error: No timeout was supplied the '-t' option.\n"); print_usage(); return -1; }

			// Set the timeout to the supplied value.
			timeout = atoi(argv[loop0]);

		}

		// Else, the end of the options has been reached...
		else { break; }
	}

	// Increment the argument counters past any optional arguments.
	loop0++; argc -= loop0; argv += loop0;

	// Check to make sure a command was actually supplied.
	if (argc < 0) { printf("Error: No command was supplied.\n"); print_usage(); return -1; }
#ifdef _WIN32

	// Startup network, under windows.
	if (network_startup() < 0) 
	{ 
		printf("Error: Could not start up winsock.\n"); 
		return 1; 
	}

#endif

	// Initialization by now psp2 hostname will not be used
	if (ps4link_connect(hostname) < 0) 
	{ 
		printf("Error: Could not connect to the ps2link server. (%s)\n", hostname); 
		return -1; 
	}
	
	
	
   
	// Enter the main loop.
	ps4link_mainloop(timeout);

	// Disconnect from the psp2link server.
	ps4link_disconnect();

	// End program.
	return 0;
}
