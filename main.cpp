#include <iostream>

#ifdef ENABLE_API_BOOTFLAGS
    #include "bootflags_api/api_bootflags.h"
#endif

void startup(){
    std::cout << "starting up" << std::endl;
#ifdef ENABLE_API_BOOTFLAGS
    API_Bootflags bf = API_Bootflags::getInstance();
    std::cout << "bootflag get" << std::endl;
    bf.getFlag(COUNTER);
#endif
}

void shutdown(){
    std::cout << "shutting down" << std::endl;

#ifdef ENABLE_API_BOOTFLAGS
    API_Bootflags bf = API_Bootflags::getInstance();
    if(bf.setFlag(UPDATE, 0)){
        std::cout << "bootflag set" << std::endl;
    } else {
        std::cerr << "setting bootflag falied" << std::endl;
    }
#endif
}

int main(int argc __attribute__((unused)), char **argv __attribute__((unused))) {
    startup();
    shutdown();
    return 0;
}
