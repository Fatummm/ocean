#ifndef GUI_CELL_HPP
#define GUI_CELL_HPP

#include <SFML/Graphics.hpp>
#include <gui_global.hpp>
#include <ocean.hpp>
class GCell {
private:
    sf::RenderWindow& w;
    Cell& cell;
    sf::Texture empty;
    sf::Texture herbivore_left;
    sf::Texture herbivore_right;
    sf::Texture predator_left;
    sf::Texture predator_right;
    sf::Texture sand;
    sf::Texture algae;
    sf::Sprite sprite;
public:
    GCell(const Position&, Cell&, sf::RenderWindow&);
    void update();
    void display();
};

#endif