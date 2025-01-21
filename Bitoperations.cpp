#include<iostream>
#include<bitset>

using namespace std;

int negativAddition(int pos, int neg)
{
    cout << "\nAufgabe 1" << endl;

    bitset<8> bs_pos = pos;
    bitset<8> bs_neg = ~neg;


    bitset<8> sum(bs_pos & bs_neg);

    cout << "positive zahl: "<< pos << " enspr. " 
         << bs_pos << "\nnegative zahl: " << neg 
         << " entspr. " << bs_neg << "\nsumme: " <<  sum << endl;

    return sum.to_ulong();
}

int main() {
    
    cout << negativAddition(13,8) << endl;
}

/* 
Ausgabe:
Aufgabe 1
positive zahl: 13 enspr. 00001101
negative zahl: 8 entspr. 11110111
summe: 00000101
5
*/