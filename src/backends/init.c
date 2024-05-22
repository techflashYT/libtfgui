#include <tfgui_internal.h>
backends_t TFGUI_InitBackend() {
	backends_t bestBackend = TFGUI_BACKEND_XTERM;
#ifdef CONFIG_BACKEND_TEXT
	warn("TFGUI STUB - Check VT Backend");
	warn("TFGUI STUB - Check Xterm Backend");
#endif

#ifdef CONFIG_BACKEND_QT
	warn("TFGUI STUB - Check Qt Backend");
#endif
#ifdef CONFIG_BACKEND_GTK
	warn("TFGUI STUB - Check GTK Backend");
#endif

	switch (bestBackend) {
#ifdef CONFIG_BACKEND_TEXT
		case TFGUI_BACKEND_VT:
		       log("TFGUI - selected backend: VT");
		       TFGUI_VTInit();
		       break;
		case TFGUI_BACKEND_XTERM:
		       log("TFGUI - selected backend: Xterm");
		       TFGUI_XtermInit();
		       break;
#endif
#ifdef CONFIG_BACKEND_QT
		case TFGUI_BACKEND_QT:
		       log("TFGUI - selected backend: Qt");
		       TFGUI_QtInit();
		       break;
#endif
#ifdef CONFIG_BACKEND_GTK
		case TFGUI_BACKEND_GTK:
		       log("TFGUI - selected backend: GTK");
		       TFGUI_GTKInit();
		       break;
#endif
		default:
		       error("TFGUI - selected a backend we don't recognize?  RAM corruption??", true);
		       break;
	}

	return bestBackend;
}
