#ifndef PERSONEN_H
#define PERSONEN_H

#include <iostream>
#include "location.h"

class Personen
{
public:
    Personen();
    Personen(const Personen &) = delete; // Copy-Konstruktor
    Personen(Personen &&) = delete;      // Move-Konstruktor
    Personen &operator=(const Personen &) = delete;  // Copy-Assignment-Operator
    Personen &operator=(Personen &&) = delete;       // Move-Assignment-Operator

    // Überladene Konstruktoren
    Personen(std::string name);
    Personen(std::string name, int alter);
    Personen(std::string name, int alter, char geschlecht);

    // Destruktor
    virtual ~Personen();

    // Reine virtuelle Methode
    virtual void dining(location loc) const = 0;

    // Getter und Setter
    std::string getName() const;
    void setName(const std::string &newName);

    int getAlter() const;
    void setAlter(int newAlter);

    char getGeschlecht() const;
    void setGeschlecht(char newGeschlecht);

    float getGroesse() const;
    void setGroesse(float newGroesse);

    float getKontostand() const;
    void setKontostand(float newKontostand);

    // Statische Zählvariable
    static int pers_cnt;

private:
    std::string name;
    int alter;
    char geschlecht;
    float groesse;
    float kontostand = 100;
};

class Chef : public Personen
{
public:
    Chef();
    Chef(const Chef &) = delete; // Copy-Konstruktor
    Chef(Chef &&) = delete;      // Move-Konstruktor
    Chef &operator=(const Chef &) = delete;  // Copy-Assignment-Operator
    Chef &operator=(Chef &&) = delete;       // Move-Assignment-Operator

    // Überladene Konstruktoren
    Chef(std::string name);
    Chef(std::string name, int alter);
    Chef(std::string name, int alter, char geschlecht);

    // Implementierung der reinen virtuellen Methode
    void dining(location loc) const override;
};



/*class Mitarbeiter : public Personen{
public:

    Mitarbeiter();
    Mitarbeiter(const Mitarbeiter &) = delete; // Copy- Kontruktor
    Mitarbeiter(Mitarbeiter &&) = delete;      // Move- Konstruktor
    Mitarbeiter &operator=(const Mitarbeiter &) = delete;  // Copy- Assignment- Konstruktor
    Mitarbeiter &operator=(Mitarbeiter &&) = delete;       // Move- Assignment- Konstruktor
    ~Mitarbeiter();


    // Überladene Konstruktoren
    Mitarbeiter(std::string name);
    Mitarbeiter(std::string name, int alter);
    Mitarbeiter(std::string name, int alter, char geschlecht);

    void dining(location loc) ;
};

class Kunde : public Personen{
public:

    Kunde();
    Kunde(const Kunde &) = delete; // Copy- Kontruktor
    Kunde(Chef &&) = delete;      // Move- Konstruktor
    Kunde &operator=(const Kunde &) = delete;  // Copy- Assignment- Konstruktor
    Kunde &operator=(Kunde &&) = delete;       // Move- Assignment- Konstruktor
    ~Kunde();


    // Überladene Konstruktoren
    Kunde(std::string name);
    Kunde(std::string name, int alter);
    Kunde(std::string name, int alter, char geschlecht);

    void dining(location loc) ;
};*/

#endif // PERSONEN_H
