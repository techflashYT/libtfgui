#include <tfgui_internal.h>
#ifdef CONFIG_BACKEND_TEXT
static void TFGUI_CommonTermInit() {
	error("TFGUI STUB - common term Init", true);
}

void TFGUI_XtermInit() {
	TFGUI_CommonTermInit();
}
void TFGUI_VTInit() {
	TFGUI_CommonTermInit();
}
#endif
