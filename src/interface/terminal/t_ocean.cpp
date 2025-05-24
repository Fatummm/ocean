#include <t_ocean.hpp>

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
            out << '~';
            displayCell((*pimpl)[i-1][j].get());
            out << '~';
        }
        out << std::endl;
    }
    out << std::endl;
}

void Ocean::displayCell(Object* obj) {
    if (dynamic_cast<SandImpl*>(obj)) out << "\033[1;33m # \033[0m";
    else if (dynamic_cast<AlgaeImpl*>(obj)) out << "\033[1;36m * \033[0m";
    else if (dynamic_cast<Herbivore*>(obj)) out << "\033[1;35m H \033[0m";
    else out << "   ";
}

void Ocean::start() {
    std::chrono::high_resolution_clock::time_point time_p = std::chrono::high_resolution_clock::now();
    while (true) {
        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - time_p) >= std::chrono::milliseconds(MILLISECONDS_DELTA)) {
            pimpl->update();
            display();
            time_p = std::chrono::high_resolution_clock::now();
        }
    }
}