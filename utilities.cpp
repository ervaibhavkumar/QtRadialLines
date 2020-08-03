#include "utilities.h"

#include <random>

namespace Utilities {

int getRandomNum(int low, int high) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dsAlien(low, high);

    int size = dsAlien(mt);
    return size;
}

}
