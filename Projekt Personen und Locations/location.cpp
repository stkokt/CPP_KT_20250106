#include "location.h"

static int loc_cnt = 0;

// Standardkonstruktor
location::location() {loc_cnt += 1;}

// Kopierkonstruktor
location::location(const location & loc)
{
    loc_cnt += 1;
    this->name = loc.name;
    this->menu = loc.menu;

}

location::location(std::string Name, std::map<std::string, float> Speisekarte) : name(Name), menu(Speisekarte) {
    loc_cnt += 1;
    std::cout << name << " hat geöffnet!" << std::endl;
}

// Kopierzuweisungskonstruktor
location &location::operator=(const location & loc)
{
    loc_cnt += 1;
    this->name = loc.name;
    this->menu = loc.menu;
    return *this;
}

void location::show_map(){

    int num = 1;
    std::cout << "Was darf ich Ihnen bringen?" << std::endl;
    std::cout << std::endl;
    for (const auto& item : this->menu) {
        std::cout << num << ". " << item.first << ": " << item.second << " EUR" << std::endl;
        num++;
    }


}

// Getter und Setter
std::string location::getName() const {return name;}

void location::setName(const std::string &newName) {name = newName;}

std::map<std::string, float> location::getMenu() const {return menu;}

void location::setMenu(const std::map<std::string, float> &newMenu) {menu = newMenu;}

float location::getEinnahmen() const {return einnahmen;}

void location::setEinnahmen(float newEinnahmen) {einnahmen += newEinnahmen;}





