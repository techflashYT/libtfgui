#include <stdio.h>
#include <stdlib.h>
#include <tfgui_internal.h>
#include <fcntl.h>

extern int LOG_FD;
int TFGUI_Init() {
	LOG_FD = open("log.txt", O_CREAT | O_RDWR | O_TRUNC, 0755);
	debug("TFGUI Init")
	backends_t backendNum = TFGUI_InitBackend();
	exit(1);
}
