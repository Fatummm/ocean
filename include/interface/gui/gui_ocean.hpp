#ifndef GUI_OCEAN_HPP
#define GUI_OCEAN_HPP
#include <gui_global.hpp>
#include <gui_cell.hpp>
#include <ocean.hpp>
#include <memory>
#include <vector>
class GOcean {
private:
    sf::RenderWindow w;
    std::unique_ptr<OceanImpl> pimpl;
    std::vector<std::shared_ptr<GCell>> cells;
public:
    GOcean(unsigned int, unsigned int);
    void start();
    void display();
};

#endif