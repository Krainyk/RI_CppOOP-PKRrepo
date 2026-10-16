#include "Object.h"

int Object::count = 0;

Object::Object() { count++; }
Object::~Object() { count--; }

int Object::getCount() {
    return count;
}