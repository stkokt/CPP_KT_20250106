#include "personen.h"

int Personen::pers_cnt = 0;

Personen::Personen() {
    pers_cnt += 1;
}

Personen::Personen(std::string name) : name(name) {
    pers_cnt += 1;
}

Personen::Personen(std::string name, int alter) : name(name), alter(alter) {
    pers_cnt += 1;
}

Personen::Personen(std::string name, int alter, char geschlecht) : name(name), alter(alter), geschlecht(geschlecht) {
    pers_cnt += 1;
}

Personen::~Personen() {
    pers_cnt -= 1;
    std::cout << "Eine Person ist gestorben." << std::endl;
}

std::string Personen::getName() const {
    return name;
}

void Personen::setName(const std::string &newName) {
    name = newName;
}

int Personen::getAlter() const {
    return alter;
}

void Personen::setAlter(int newAlter) {
    alter = newAlter;
}

char Personen::getGeschlecht() const {
    return geschlecht;
}

void Personen::setGeschlecht(char newGeschlecht) {
    geschlecht = newGeschlecht;
}

float Personen::getGroesse() const {
    return groesse;
}

void Personen::setGroesse(float newGroesse) {
    groesse = newGroesse;
}

float Personen::getKontostand() const {
    return kontostand;
}

void Personen::setKontostand(float newKontostand) {
    kontostand -= newKontostand;
}

Chef::Chef() : Personen() {}

Chef::Chef(std::string name) : Personen(name) {}

Chef::Chef(std::string name, int alter) : Personen(name, alter) {}

Chef::Chef(std::string name, int alter, char geschlecht) : Personen(name, alter, geschlecht) {}

void Chef::dining(location loc) const {
    int choice;
    loc.show_map();

    std::cout << "Ihre Wahl:" << std::endl;
    std::cin >> choice;

    for (const auto& item : loc.getMenu()) {
        choice--;
        if (choice == 0) {
            this->setKontostand(0); // Der Chef isst kostenlos
            loc.setEinnahmen(0);
            std::cout << "Neuer Kontostand: " << this->getKontostand() << std::endl;
        }
    }
}


/*void Mitarbeiter::dining(location loc) {

    int choice;
    loc.show_map();

    std::cout << "Ihre Wahl:" << std::endl;

    std::cin >> choice;

    for (const auto& item : loc.getMenu()){

        choice--;
        if (choice == 0){
            this->setKontostand( -(item.second - item.second*0.3));
            loc.setEinnahmen(+(item.second - item.second*0.3));
            std::cout << "Neuer Kontostand: " << this->getKontostand() << std::endl;
        }

    }
}

void Kunde::dining(location loc) {

    int choice;
    loc.show_map();

    std::cout << "Ihre Wahl:" << std::endl;

    std::cin >> choice;

    for (const auto& item : loc.getMenu()){

        choice--;
        if (choice == 0){
            this->setKontostand( -item.second);
            loc.setEinnahmen(+item.second);
            std::cout << "Neuer Kontostand: " << this->getKontostand() << std::endl;
        }

    }
}
*/
