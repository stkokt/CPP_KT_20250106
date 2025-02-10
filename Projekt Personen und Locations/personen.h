#ifndef PERSONEN_H
#define PERSONEN_H

#include <iostream>
#include "location.h"

class Personen
{



public:
    Personen();
    Personen(const Personen &) = delete; // Copy- Kontruktor
    Personen(Personen &&) = delete;      // Move- Konstruktor
    Personen &operator=(const Personen &) = delete;  // Copy- Assignment- Konstruktor
    Personen &operator=(Personen &&) = delete;       // Move- Assignment- Konstruktor
    Personen(std::string name);
    Personen(std::string name, int alter);
    Personen(std::string name, int alter, char geschlecht);
    ~Personen();

    void dining(location loc);

    std::string getName() const;
    void setName(const std::string &newName);

    int getAlter() const;
    void setAlter(int newAlter);

    char getGeschlecht() const;
    void setGeschlecht(char newGeschlecht);

    float getGroesse() const;
    void setGroesse(float newGroesse);

    static int pers_cnt;

private:

    std::string name;
    int alter;
    char geschlecht;
    float groesse;
    float kontostand=100;


};

#endif // PERSONEN_H
