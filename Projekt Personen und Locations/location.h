#ifndef LOCATION_H
#define LOCATION_H

#include <algorithm>
#include <iostream>
#include <map>


class location
{
public:
    location(); // Standardkonstruktor
    location(const location & loc); // Kopierkonstruktor
    location(location &&) = delete; // Move- Konstruktor
    location &operator=(const location & loc); // Kopierzuweisungskonstruktor
    location &operator=(location &&) = delete; // Move- Zuweisungskonstruktor

    // Überladener Konstruktor (Name und Karte als Argumente)
    location(std::string Name, std::map<std::string, float> Speisekarte);

    void show_map();

    std::string getName() const;
    void setName(const std::string &newName);

    std::map<std::string, float> getMenu() const;
    void setMenu(const std::map<std::string, float> &newMenu);

    float getEinnahmen() const;
    void setEinnahmen(float newEinnahmen);

    static int loc_cnt;

private:
    std::string name;
    std::map<std::string, float> menu;
    float einnahmen=0;
};

#endif // LOCATION_H
