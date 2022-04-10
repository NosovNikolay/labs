#ifndef LISTCONLTROLLER_H
#define LISTCONLTROLLER_H
#include <algorithm>
#include <iostream>
#include "BackpackList.hpp"
#include <vector>
#include <fstream>
#include "ClothBackpack.hpp"
#include "LeatherBackpack.hpp"
class Listcontroller
{
private:
    std::string filename;
    BackpackList items;
public:
    Listcontroller(std::string filename);
    ~Listcontroller();
    void readFromFile();
    unsigned itemsCount();
    void writeToFile();
    void sortByVolume();
    void showList();

    BackpackList searchLeather();
};

#endif