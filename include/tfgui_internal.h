#include <tfgui.h>
#include <tfgui_internal_config.h>
#define LOG_ALLOW_DEBUG

#define RESET  "\e[0m"
#define YELLOW "\e[1;33m"
#define GRAY   "\e[90m"
#define GREEN  "\e[32m"
#define CYAN   "\e[36m"
#define RED    "\e[31m"

#ifdef LOG_ALLOW_DEBUG
extern void _debug(const char *file, int line, const char *msg);
#define debug(msg)        _debug((__FILE__ + 4), __LINE__, msg);
#else
#define debug(msg)        (void)0;
#endif


extern void _log(const char *file, int line, const char *msg);
extern void _warn(const char *file, int line, const char *msg);
extern void _error(const char *file, int line, const char *msg, bool fatal);
#define   log(msg)        _log  ((__FILE__ + 4), __LINE__, msg);
#define  warn(msg)        _warn ((__FILE__ + 4), __LINE__, msg);
#define error(msg, fatal) _error((__FILE__ + 4), __LINE__, msg, fatal);


extern void TFGUI_VTInit();
extern void TFGUI_XtermInit();
extern void TFGUI_QtInit();
extern void TFGUI_GTKInit();
