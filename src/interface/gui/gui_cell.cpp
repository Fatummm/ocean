#include <gui_cell.hpp>

GCell::GCell(const Position& pos, Cell& cell, sf::RenderWindow& w): cell(cell), w(w) {
    empty.loadFromFile(PATH_TO_EMPTY);
    herbivore_left.loadFromFile(PATH_TO_HERBIVORE_LEFT);
    herbivore_right.loadFromFile(PATH_TO_HERBIVORE_RIGHT);
    predator_right.loadFromFile(PATH_TO_PREDATOR_RIGHT);
    predator_left.loadFromFile(PATH_TO_PREDATOR_LEFT);
    sand.loadFromFile(PATH_TO_SAND);
    algae.loadFromFile(PATH_TO_ALGAE);
    sprite.setTexture(empty);
    sprite.setPosition(sf::Vector2f(pos.x * 60, pos.y * 60));
}

#include <iostream>

void GCell::update() {
    if (cell.isEmpty()) {
        if (&*const_cast<sf::Texture*>(sprite.getTexture()) != &empty)
        sprite.setTexture(empty);
    } else if (Herbivore * h = dynamic_cast<Herbivore*>(cell.get()); h) {
        if (h->getDirection() == Direction::Left && &*const_cast<sf::Texture*>(sprite.getTexture()) != &herbivore_left) {
            sprite.setTexture(herbivore_left);
        }
        else if (h->getDirection() == Direction::Right && &*const_cast<sf::Texture*>(sprite.getTexture()) != &herbivore_right) {
            sprite.setTexture(herbivore_right);
        }
    } else if (Predator* p = dynamic_cast<Predator*>(cell.get())) {
        if (p->getDirection() == Direction::Left && &*const_cast<sf::Texture*>(sprite.getTexture()) != &predator_left) {
            sprite.setTexture(predator_left);
        } else if (p->getDirection() == Direction::Right && &*const_cast<sf::Texture*>(sprite.getTexture()) != &predator_right) {
            sprite.setTexture(predator_right);
        }
    } else if (dynamic_cast<Sand*>(cell.get()) && &*const_cast<sf::Texture*>(sprite.getTexture()) != &sand) {
        sprite.setTexture(sand);
    }
    else if (dynamic_cast<Algae*>(cell.get()) && &*const_cast<sf::Texture*>(sprite.getTexture()) != &algae){
        sprite.setTexture(algae);
    }
}
void GCell::display() {
    update();
    w.draw(sprite);
}