#include "ListController.hpp"

Listcontroller::Listcontroller(std::string filename)
{
    items = {};
    this->filename = filename;
}

Listcontroller::~Listcontroller()
{
    for (auto i : items)
    {
        delete i;
    }
}
void Listcontroller::readFromFile()
{
    std::ifstream in(filename, std::ios_base::in);
    string line;
    if (!in.is_open())
    {
        return;
    }
    if (items.size() > 0)
    {
        items.clear();
    }
    Backpack *tmp;
    int rownum = 0;
    while (std::getline(in, line))
    {   
        if (rownum > 0) {
            
            std::vector<string> row;
            string rowLine;

            std::istringstream ss(line);

            while(std::getline(ss, rowLine, ',')) {
                row.push_back(rowLine);
            }
            if (row[7] == "cloth") {
                tmp = new ClothBackpack(
                    row[0], 
                    static_cast<AppointmentType>(stoi(row[1])), 
                    stoi(row[2]), 
                    stoi(row[3]),
                    stoi(row[10]),
                    static_cast<ClothType>(stoi(row[8])),
                    Brand(
                        row[4], 
                        row[5], 
                        row[6]
                        )
                    );
            } else {
                tmp = new LeatherBackpack(
                    row[0], 
                    static_cast<AppointmentType>(stoi(row[1])), 
                    stoi(row[2]), 
                    stoi(row[3]),
                    stoi(row[9]),
                    static_cast<leatherType>(stoi(row[8])),
                    Brand(
                        row[4], 
                        row[5], 
                        row[6]
                        )
                    );
            }
            
            if (tmp != nullptr)
            {
                items.push_back(tmp);
                row.clear();
            }
        }
        rownum++;
    }
    in.close();
}
unsigned Listcontroller::itemsCount()
{
    return items.size();
}
void Listcontroller::writeToFile()
{
    std::ofstream out(filename, std::ios_base::out);
    if (!out.is_open())
    {
        return;
    }
    for (auto i : items)
    {
        out << i->ToString();
    }
    out.close();
}
bool compare_volume(const Backpack *first, const Backpack *second)
{
    return (first->GetVolume() < second->GetVolume());
}
void Listcontroller::sortByVolume()
{
    items.sort(compare_volume);
}
void Listcontroller::showList()
{
    for (auto i : items)
    {
        cout << i->display() << endl;
    }
}      
bool predicate_leather(Backpack* b) {
    cout << b->isLeather() << b->display() << endl;
    return b->isLeather();
}
BackpackList Listcontroller::searchLeather() {
    BackpackList result;
    for(auto i: this->items) {
        if(i->isLeather()) {
            result.push_back(i);
        }
    }
    return result;
}