#ifndef GLOBAL_HPP
#define GLOBAL_HPP


#define SECONDS_DELTA 1
#define MILLISECONDS_DELTA 500
#define SECONDS_TO_RUN 30

#define ROWS 18
#define COLUMNS 32

#define ALGAE_PROBS 30

#define HERBIVORE_SATURATION 10
#define HERBIVORE_AGE 40
#define HERBIVORE_PROBS 800

#define PREDATOR_SATURATION 10
#define PREDATOR_AGE 20
#define PREDATOR_PROBS 5000

#define MAX_PREDATORS 5
#define MAX_HERBIVORES 20

#define AGE_TO_REPRODUCE 10
#define SATURATION_TO_REPRODUCE 25

enum class Direction {
    Left, Right
};

struct Position;

// basic objects
class Cell;
class Object;

// algae and sand
class Algae;
class Sand;

// fishes
template <typename Food>
class Fish;
using Herbivore = Fish<Algae>;
using Predator = Fish<Herbivore>;

// logger
template <typename T>
class Logger;

// ocean
class OceanImpl;

#endif