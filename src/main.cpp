#include <iostream>

#include "config.h"

#ifdef ENABLE_API_BOOTFLAGS
    #include "bootflags_api/api_bootflags.h"
#endif


/*! \brief Startup function.
 *
 *  Called directly after startup.
 */
void startup(){
    std::cout << "starting up" << std::endl;
#ifdef ENABLE_API_BOOTFLAGS
    API_Bootflags bf = API_Bootflags::getInstance();
    std::cout << "bootflag get" << std::endl;
    bf.getFlag(COUNTER);
#endif
}

/*! \brief Shutdown function.
 *
 *  Called before shutting down.
 */
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

/*! \brief Main function.
 *         Global entry point.
 *
 *  Detailed description starts here.
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused))) {
    startup();
    shutdown();
    return 0;
}
