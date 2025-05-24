#include <iostream>
#include <t_ocean.hpp>
int main() {
    Ocean to(std::cout, ROWS, COLUMNS);
    to.display();
}