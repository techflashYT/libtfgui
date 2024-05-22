typedef enum {
	TFGUI_BACKEND_NULL  = 0,
	TFGUI_BACKEND_VT,
	TFGUI_BACKEND_XTERM,
	TFGUI_BACKEND_QT,
	TFGUI_BACKEND_GTK
} backends_t;

extern int TFGUI_Init();
extern backends_t TFGUI_InitBackend();

