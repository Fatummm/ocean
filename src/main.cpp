#include <iostream>
#include <fstream>

#include <terminal_ocean.hpp>
#include <gui_ocean.hpp>

#ifdef TERMINAL
using Ocean = TOcean;
#else
using Ocean = GOcean;
#endif
#include <logger.hpp>



int main() {
    std::ofstream logout("output.log");
    std::cout << sizeof(GCell);
    Logger<OceanImpl> l(logout);
    srand(time(NULL));
    Ocean o(ROWS, COLUMNS);
    o.start();
}