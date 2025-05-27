#include <gui_ocean.hpp>

GOcean::GOcean(unsigned int rows, unsigned int columns): 
    pimpl(std::make_unique<OceanImpl>(rows, columns)) {
    w.create(sf::VideoMode(1920, 1080), "Living ocean", sf::Style::Fullscreen);
    for (unsigned int i = 0; i != columns; ++i) {
        for (unsigned int j = 0; j != rows; ++j) {
            cells.push_back(std::make_shared<GCell>(Position{i, j}, (*pimpl)[j][i], w));
        }
    }
}

void GOcean::start() {
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point time_p = std::chrono::high_resolution_clock::now();
    while (w.isOpen()) {
        w.clear();
        sf::Event ev;
        while (w.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                w.close();
            }
        }
        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - time_p) >= std::chrono::milliseconds(MILLISECONDS_DELTA)) {
            pimpl->update();
            time_p = std::chrono::high_resolution_clock::now();
        }
        display();
        if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start) > std::chrono::seconds(SECONDS_TO_RUN)) {
            break;
        }
        w.display();
    }
}

void GOcean::display() {
    for (unsigned int i = 0; i != cells.size(); ++i) {
        cells[i]->display();
    }
}