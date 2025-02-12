#include "personen.h"

int Personen::pers_cnt = 0;
// TODO: anything
Personen::Personen() {pers_cnt +=1;}


Personen::Personen(std::string name):name(name)
{
    pers_cnt +=1;
}

Personen::Personen(std::string name, int alter):name(name),alter(alter)
{
    pers_cnt +=1;
}

Personen::Personen(std::string name, int alter, char geschlecht):name(name),alter(alter),geschlecht(geschlecht)
{
    pers_cnt +=1;
}

Personen::~Personen(){
    pers_cnt -=1;
    std::cout << this->name << " ist gestorben." << std::endl;
}

void Personen::dining(location loc){

    int choice;
    loc.show_map();

    std::cout << "Ihre Wahl:" << std::endl;

    std::cin >> choice;

    for (const auto& item : loc.getMenu()){

        choice--;
        if (choice == 0){
            this->kontostand -= item.second;
            loc.setEinnahmen(item.second);
            std::cout << "Neuer Kontostand: " << this->kontostand << std::endl;
        }

    }
}


std::string Personen::getName() const
{
    return name;
}

void Personen::setName(const std::string &newName)
{
    name = newName;
}

int Personen::getAlter() const
{
    return alter;
}

void Personen::setAlter(int newAlter)
{
    alter = newAlter;
}

char Personen::getGeschlecht() const
{
    return geschlecht;
}

void Personen::setGeschlecht(char newGeschlecht)
{
    geschlecht = newGeschlecht;
}

float Personen::getGroesse() const
{
    return groesse;
}

void Personen::setGroesse(float newGroesse)
{
    groesse = newGroesse;
}
