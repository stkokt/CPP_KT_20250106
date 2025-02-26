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
    location(std::string Name, std::map<std::string, float> Service);

    // Destruktor
    ~location();

    virtual void show_service() = 0;

    std::string getName() const;
    void setName(const std::string &newName);

    std::map<std::string, float> getService() const;
    void setService(const std::map<std::string, float> &newMenu);

    float getEinnahmen() const;
    void setEinnahmen(float newEinnahmen);

    static int loc_cnt;

private:
    std::string name;
    std::map<std::string, float> service;
    float einnahmen=0;
};

class Shop : public location{
public:

    Shop();
    Shop(const Shop &); // Copy- Kontruktor
    Shop(Shop &&) = delete;      // Move- Konstruktor
    Shop &operator=(const Shop &);  // Copy- Assignment- Konstruktor
    Shop &operator=(Shop &&) = delete;       // Move- Assignment- Konstruktor



    // Überladene Konstruktoren
    Shop(std::string name);
    Shop(std::string name, std::map<std::string, float> Service);


    // Destruktor
    ~Shop();

    void show_service();
};

#endif // LOCATION_H
