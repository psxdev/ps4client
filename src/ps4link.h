/*
 * ps4client host tool for PS4 providing host fileio system 
 * Copyright (C) 2003,2015 Antonio Jose Ramos Marquez (aka bigboss) @psxdev on twitter
 * Repository https://github.com/psxdev/ps4client
 * based on psp2client,ps2vfs, ps2client, ps2link, ps2http tools. 
 * Credits goes for all people involved in ps2dev project https://github.com/ps2dev
 * This file is subject to the terms and conditions of the ps4client License.
 * See the file LICENSE in the main directory of this distribution for more
 * details.
 */


#ifndef __PS4LINK_H__
#define __PS4LINK_H__

///////////////////////
// PS2LINK FUNCTIONS //
///////////////////////

int ps4link_connect(char *hostname);

int ps4link_mainloop(int timeout);

int ps4link_disconnect(void);

#define PS4LINK_REQUEST_OPEN		0xBABE0111
#define PS4LINK_REQUEST_CLOSE		0xBABE0121
#define PS4LINK_REQUEST_READ		0xBABE0131
#define PS4LINK_REQUEST_WRITE		0xBABE0141
#define PS4LINK_REQUEST_LSEEK		0xBABE0151
#define PS4LINK_REQUEST_OPENDIR		0xBABE0161
#define PS4LINK_REQUEST_CLOSEDIR	0xBABE0171
#define PS4LINK_REQUEST_READDIR		0xBABE0181
#define PS4LINK_REQUEST_REMOVE		0xBABE0191
#define PS4LINK_REQUEST_MKDIR		0xBABE01A1
#define PS4LINK_REQUEST_RMDIR		0xBABE01B1

int ps4link_request_open(void *packet);

int ps4link_request_close(void *packet);

int ps4link_request_read(void *packet);

int ps4link_request_write(void *packet);

int ps4link_request_lseek(void *packet);

int ps4link_request_opendir(void *packet);

int ps4link_request_closedir(void *packet);

int ps4link_request_readdir(void *packet);

int ps4link_request_remove(void *packet);

int ps4link_request_mkdir(void *packet);

int ps4link_request_rmdir(void *packet);

////////////////////////////////
// PS2LINK RESPONSE FUNCTIONS //
////////////////////////////////

#define PS4LINK_RESPONSE_OPEN		0xBABE0112
#define PS4LINK_RESPONSE_CLOSE		0xBABE0122
#define PS4LINK_RESPONSE_READ		0xBABE0132
#define PS4LINK_RESPONSE_WRITE		0xBABE0142
#define PS4LINK_RESPONSE_LSEEK		0xBABE0152
#define PS4LINK_RESPONSE_OPENDIR	0xBABE0162
#define PS4LINK_RESPONSE_CLOSEDIR	0xBABE0172
#define PS4LINK_RESPONSE_READDIR	0xBABE0182
#define PS4LINK_RESPONSE_REMOVE		0xBABE0192
#define PS4LINK_RESPONSE_MKDIR		0xBABE01A2
#define PS4LINK_RESPONSE_RMDIR		0xBABE01B2

int ps4link_response_open(int result);

int ps4link_response_close(int result);

int ps4link_response_read(int result, int size);

int ps4link_response_write(int result);

int ps4link_response_lseek(int result);

int ps4link_response_opendir(int result);

int ps4link_response_closedir(int result);

int ps4link_response_readdir(int result, unsigned char type, char *name);

int ps4link_response_remove(int result);

int ps4link_response_mkdir(int result);

int ps4link_response_rmdir(int result);

//////////////////////////////
// PS4LINK THREAD FUNCTIONS //
//////////////////////////////

void *ps4link_thread_console(void *thread_id);

void *ps4link_thread_request(void *thread_id);

#endif

