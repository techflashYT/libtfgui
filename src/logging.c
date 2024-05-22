#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <tfgui_internal.h>
#include <unistd.h>

int LOG_FD;
#define LOG_CODE \
	char tmpfname[64]; \
	char tmp[512]; \
	snprintf(tmpfname, sizeof(tmpfname), "%s%s:%s%d", file, RESET, CYAN, line); \
	int len = snprintf(tmp, sizeof(tmp), "%s[%s%-23s%s] %s%s%s\r\n", YELLOW, RESET GREEN, tmpfname, YELLOW, msgPre, msg, msgPost); \
	/*write(0, tmp, len);*/ \
	write(LOG_FD, tmp, len);

void _log(const char *file, int line, const char *msg) {
	const char *msgPre = RESET;
	const char *msgPost = "";
	LOG_CODE
}

void _warn(const char *file, int line, const char *msg) {
	const char *msgPre = YELLOW;
	const char *msgPost = RESET;
	LOG_CODE
}

void _error(const char *file, int line, const char *msg, bool fatal) {
	const char *msgPre = RED "!!! ";
	const char *msgPost = " !!!" RESET;
	LOG_CODE
	if (fatal) {
		exit(1);
	}
}

#ifdef LOG_ALLOW_DEBUG
void _debug(const char *file, int line, const char *msg) {
	const char *msgPre = GRAY;
	const char *msgPost = RESET;
	LOG_CODE
}
#endif



