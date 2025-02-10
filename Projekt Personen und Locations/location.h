#ifndef LOCATION_H
#define LOCATION_H

#include <algorithm>
#include <iostream>
#include <map>

class location
{
public:
    location();
    location(const location & loc);
    location(location &&) = delete;
    location &operator=(const location & loc);
    location &operator=(location &&) = delete;

    location(std::string Name, std::map<std::string, float> Speisekarte);

    void show_map();

    std::string getName() const;
    void setName(const std::string &newName);

    std::map<std::string, float> getMenu() const;
    void setMenu(const std::map<std::string, float> &newMenu);

    float getEinnahmen() const;
    void setEinnahmen(float newEinnahmen);



private:
    std::string name;
    std::map<std::string, float> menu;
    float einnahmen=0;
};

#endif // LOCATION_H
