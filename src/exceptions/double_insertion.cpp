#include "double_insertion.hpp"

double_insertion::double_insertion(const char* wh): cause(wh) {

}

const char* double_insertion::what() const {
    return cause.c_str();
}