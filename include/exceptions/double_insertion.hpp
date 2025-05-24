#ifndef DOUBLE_INSERTION_HPP
#define DOUBLE_INSERTION_HPP
#include <string>

struct double_insertion{
private:
    std::string cause;
public:
    double_insertion(const char*);
    const char* what() const;
};

#endif