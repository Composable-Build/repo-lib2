#include <iostream>
#include "plugin_info.h"
#include "version.h"
extern "C" const char* plugin_name()    { return PLUGIN_NAME; }
extern "C" const char* plugin_version() { return VERSION_STRING; }
extern "C" void plugin_print() {
    std::cout << PLUGIN_NAME << " " << VERSION_STRING << ": " << PLUGIN_MESSAGE << std::endl;
}
