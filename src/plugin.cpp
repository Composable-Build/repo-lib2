#include <iostream>
#include "plugin_info.h"

extern "C" const char* plugin_name()  { return PLUGIN_NAME; }
extern "C" void plugin_print() {
    std::cout << PLUGIN_NAME << ": " << PLUGIN_MESSAGE << std::endl;
}
