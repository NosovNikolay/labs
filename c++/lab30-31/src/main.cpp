#include "ListController.hpp"
#include <map>

void UniteMaps(std::map<string, string> &first,
               std::map<string, string> &second)
{
    for (auto it = second.begin(); it != second.end(); ++it)
    {
        if (first.find(it->first) == first.end())
        {
            first[it->first] = it->second;
        }
        else
        {
            first[it->first] += " " + it->second;
        }
    }
}

int main()
{
    std::string filename = "backpack.csv";

    Listcontroller current(filename);

    current.readFromFile();

    current.showList();

    cout << endl;

    current.sortByVolume();

    current.showList();

    std::map<std::string, std::string> map1;
    std::map<std::string, std::string> map2;
    map1.insert(std::make_pair("Ukraine", "Kharkiv"));
    map1.insert(std::make_pair("Ukraine", "Kharkiv"));
    map2.insert(std::make_pair("Ukraine", "Kyiv"));

    UniteMaps(map1, map2);

    for (auto it = map1.begin(); it != map1.end(); ++it)
    {
        std::cout << it->first << " = " << it->second << std::endl;
    }

    return 0;
}
