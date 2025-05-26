#include <logger.hpp>

template <typename T>
Logger<T>::Logger() {
    ++overall;
}

template <>
void Logger<Herbivore>::Produce() {
    ++produced;
}

template <>
void Logger<Predator>::Produce() {
    ++produced;
}

Logger<OceanImpl>::Logger(std::ostream& out): out(out), start(std::chrono::high_resolution_clock::now()) {
    out << "Ocean was created.\n";
}

Logger<OceanImpl>::~Logger() {
    out << "Ocean was destroyed.\n\n";
    out << "Herbivores created: " << Logger<Herbivore>::overall << '\n';
    out << "Herbivores produced: " << Logger<Herbivore>::produced << "\n\n";
    out << "Predators created: " << Logger<Predator>::overall << '\n';
    out << "Predators produced: " << Logger<Predator>::produced << "\n\n";
    out << "Overall time: " << 
    std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start).count()
    << '\n';
}

template <>
unsigned int Logger<Herbivore>::overall = 0;
template <>
unsigned int Logger<Herbivore>::produced = 0;

template <>
unsigned int Logger<Predator>::overall = 0;
template <>
unsigned int Logger<Predator>::produced = 0;


template class Logger<Herbivore>;
template class Logger<Predator>;

