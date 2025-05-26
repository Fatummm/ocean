#include <iostream>
#include <fstream>

#ifdef TERMINAL
#include <terminal_ocean.hpp>
#else
#include <gui_ocean.hpp>
#endif
#include <logger.hpp>



int main() {
    std::ofstream logout("output.log");
    Logger<OceanImpl> l(logout);
    srand(time(NULL));
    Ocean to(std::cout, ROWS, COLUMNS);
    to.start();
}