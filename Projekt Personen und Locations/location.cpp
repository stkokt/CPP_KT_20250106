#include "location.h"

int location::loc_cnt = 0;

// Standardkonstruktor
location::location() {loc_cnt += 1;}

// Kopierkonstruktor
location::location(const location & loc)
{
    loc_cnt += 1;
    this->name = loc.name;
    this->service = loc.service;

}

// Kopierzuweisungskonstruktor
location &location::operator=(const location & loc)
{
    loc_cnt += 1;
    this->name = loc.name;
    this->service = loc.service;
    return *this;
}

// Überladener Konstruktor (Name und Karte als Argumente)
location::location(std::string Name, std::map<std::string, float> Speisekarte) : name(Name), service(Speisekarte) {
    loc_cnt += 1;
    std::cout << name << " hat geöffnet!" << std::endl;
}


// Destruktor

location::~location(){};
/*
void location::show_map(){

    int num = 1;
    std::cout << "Was darf ich Ihnen bringen?" << std::endl;
    std::cout << std::endl;
    for (const auto& item : this->menu) {
        std::cout << num << ". " << item.first << ": " << item.second << " EUR" << std::endl;
        num++;
    }


}
*/


// Getter und Setter
std::string location::getName() const {return name;}

void location::setName(const std::string &newName) {name = newName;}

std::map<std::string, float> location::getService() const {return service;}

void location::setService(const std::map<std::string, float> &newMenu) {service = newMenu;}

float location::getEinnahmen() const {return einnahmen;}

void location::setEinnahmen(float newEinnahmen) {einnahmen += newEinnahmen;}



Shop::Shop() : location(){}; // Standardkonstruktor
//Shop::Shop(const location & loc) : location(const location & loc){}; // Kopierkonstruktor
//location &operator=(const location & loc); // Kopierzuweisungskonstruktor

// Überladener Konstruktor (Name und Karte als Argumente)
Shop::Shop(std::string Name, std::map<std::string, float> Service) : location(Name, Service)
{

};

// Destruktor

Shop::~Shop(){};

void show_service(){};





