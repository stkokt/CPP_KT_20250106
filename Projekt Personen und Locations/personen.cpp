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

Chef::Chef() : Personen() {std::cout << "Ein Chef ist geboren" << std::endl;}

Chef::Chef(std::string name) : Personen(name) {std::cout << "Chef " << this->getName() << " ist geboren" << std::endl;}

Chef::Chef(std::string name, int alter) : Personen(name, alter) {std::cout << "Chef " << this->getName() << " ist geboren" << std::endl;}

Chef::Chef(std::string name, int alter, char geschlecht) : Personen(name, alter, geschlecht) {std::cout << "Chef " << this->getName() << " ist geboren" << std::endl;}

Chef::~Chef(){std::cout << "Chef " << this->getName() << " ist gestorben" << std::endl;}

void Chef::dining(location* loc) {
    int choice;
    loc->show_service();

    std::cout << "Ihre Wahl:" << std::endl;
    std::cin >> choice;

    for (const auto& item : loc->getService()) {
        choice--;
        if (choice == 0) {
            this->setKontostand(0); // Der Chef isst kostenlos
            loc->setEinnahmen(0);
            std::cout << "Neuer Kontostand: " << this->getKontostand() << std::endl;
        }
    }
}

Mitarbeiter::Mitarbeiter() : Personen() {std::cout << "Ein Mitarbeiter ist geboren" << std::endl;}

Mitarbeiter::Mitarbeiter(std::string name) : Personen(name) {std::cout << "Mitarbeiter " << this->getName() << " ist geboren" << std::endl;}

Mitarbeiter::Mitarbeiter(std::string name, int alter) : Personen(name, alter) {std::cout << "Mitarbeiter " << this->getName() << " ist geboren" << std::endl;}

Mitarbeiter::Mitarbeiter(std::string name, int alter, char geschlecht) : Personen(name, alter, geschlecht) {std::cout << "Mitarbeiter " << this->getName() << " ist geboren" << std::endl;}

Mitarbeiter::~Mitarbeiter() {std::cout << "Mitarbeiter " << this->getName() << " ist gestorben" << std::endl;}

void Mitarbeiter::dining(location* loc) {

    int choice;
    loc->show_service();

    std::cout << "Ihre Wahl:" << std::endl;

    std::cin >> choice;

    for (const auto& item : loc->getService()){

        choice--;
        if (choice == 0){
            this->setKontostand( -(item.second - item.second*0.3));
            loc->setEinnahmen(+(item.second - item.second*0.3));
            std::cout << "Neuer Kontostand: " << this->getKontostand() << std::endl;
        }

    }
}

Kunde::Kunde() : Personen() {std::cout << "Ein Kunde ist geboren" << std::endl;}

Kunde::Kunde(std::string name) : Personen(name) {std::cout << "Kunde " << this->getName() << " ist geboren" << std::endl;}

Kunde::Kunde(std::string name, int alter) : Personen(name, alter) {std::cout << "Kunde " << this->getName() << " ist geboren" << std::endl;}

Kunde::Kunde(std::string name, int alter, char geschlecht) : Personen(name, alter, geschlecht) {std::cout << "Kunde " << this->getName() << " ist geboren" << std::endl;}

Kunde::~Kunde() {std::cout << "Kunde " << this->getName() << " ist gestorben" << std::endl;}

void Kunde::dining(location* loc) {

    int choice;
    loc->show_service();

    std::cout << "Ihre Wahl:" << std::endl;

    std::cin >> choice;

    for (const auto& item : loc->getService()){

        choice--;
        if (choice == 0){
            this->setKontostand( -item.second);
            loc->setEinnahmen(+item.second);
            std::cout << "Neuer Kontostand: " << this->getKontostand() << std::endl;
        }

    }
}

