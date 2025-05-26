#include <terminal_ocean.hpp>

Ocean::Ocean(std::ostream& out, unsigned int rows, unsigned int columns): 
    out(out), pimpl(std::make_unique<OceanImpl>(rows, columns)) {
        pimpl->fillWithSand();
    }

void Ocean::display() {
    out << "\033[H\033[2J\033[3J";
    for (unsigned int i = 0; i != pimpl->getRows() + 2; ++i) {
        for (unsigned int j = 0; j != pimpl->getColumns(); ++j) {
            if (i == 0 || i == pimpl->getRows() + 1) {
                out << "~~~~~";
                continue;
            }
            out << '|';
            displayCell((*pimpl)[i-1][j].get());
            out << '|';
        }
        out << std::endl;
    }
    out << std::endl;
}

void Ocean::displayCell(Object* obj) {
    if (dynamic_cast<Sand*>(obj)) out << "\033[1;43m # \033[0m";
    else if (dynamic_cast<Algae*>(obj)) out << "\033[1;46m * \033[0m";
    else if (dynamic_cast<Predator*>(obj)) {
        Predator* p = dynamic_cast<Predator*>(obj);
        out << "\033[1;31m ";
        (p->getDirection() == Direction::Left) ? (out << "<") : (out << ">");
        out << " \033[0m";

    }
    else if (dynamic_cast<Herbivore*>(obj)) {
        Herbivore* h = dynamic_cast<Herbivore*>(obj);
        out << "\033[1;35m ";
        (h->getDirection() == Direction::Left) ? (out << "<") : (out << ">");
        out << " \033[0m";
    }
    else out << "   ";
}

void Ocean::start() {
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point time_p = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start) <= std::chrono::seconds(SECONDS_TO_RUN)) {
        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - time_p) >= std::chrono::milliseconds(MILLISECONDS_DELTA)) {
            pimpl->update();
            display();
            time_p = std::chrono::high_resolution_clock::now();
        }
    }
}