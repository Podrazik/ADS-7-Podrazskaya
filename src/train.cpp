// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};

    if (!first) {
        first = newCar;
        newCar->next = newCar;
        newCar->prev = newCar;
    } else {
        Car* lastCar = first->prev;
        newCar->next = first;
        newCar->prev = lastCar;
        first->prev = newCar;
        lastCar->next = newCar;
        first = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;
    if (first->next == first) return 1;

    countOp = 0;
    Car* curCar = first;
    int carAmount = 1;

    if (!curCar->light) {
        curCar->light = true;
    }

    curCar = curCar->next;
    countOp += 2;

    while (!curCar->light) {
        curCar = curCar->next;
        countOp += 2;
        carAmount++;
    }
    curCar->light = false;

    if (!first->light) {
        return carAmount;
    }

    while (true) {
        curCar = first;
        carAmount = 1;

        if (!curCar->light) {
            curCar->light = true;
        }

        current = current->next;
        countOp += 2;

        while (!curCar->light) {
            curCar = curCar->next;
            countOp += 2;
            carAmount++;
        }

        current->light = false;

        if (!first->light) {
            return carAmount
        }
    }
}

int Train::getOpCount() {
        return countOp;
}

Train::~Train() {
    if (!first) return;
    if (first->next == first) {
      delete first;
      first = nullptr;
      return;
    }
    Car* curCar = first->next;
    while (curCar != first) {
      Car* tmp = current;
      current = current->next;
      delete tmp;
    }
    delete first;
    first = nullptr;
}
