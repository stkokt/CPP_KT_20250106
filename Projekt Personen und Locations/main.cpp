#include <iostream>
#include "personen.h"
#include "location.h"

using namespace std;

int main()
{
    std::map<std::string, float> sushi_menu = {
        {"Sushi", 12.00},
        {"Ramen", 11.50},
        {"Tempura", 10.50},
        {"Mochi", 4.00},
        {"Miso Suppe", 3.50}
    };

    location sushi("MamaSan", sushi_menu);

    Chef ralf("Ralf");
    ralf.setAlter(50);
    ralf.setGeschlecht('m');


    Mitarbeiter beate("Beate",30);
    beate.setGeschlecht('w');

    Kunde susi("Susi", 25, 'w');

    cout<<ralf.getName()<<"("<<ralf.getGeschlecht()<<") ist "<< ralf.getAlter() <<" Jahre alt." << endl;
    cout<<beate.getName()<<"("<<beate.getGeschlecht()<<") ist "<< beate.getAlter() <<" Jahre alt." << endl;
    cout<<susi.getName()<<"("<<susi.getGeschlecht()<<") ist "<< susi.getAlter() <<" Jahre alt." << endl;


    ralf.dining(sushi);

    std::cout << Personen::pers_cnt << std::endl;

    return 0;
}
