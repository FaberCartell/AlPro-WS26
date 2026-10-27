#include <iostream>


/*Aufgabe 1 (Zahlensysteme):
*
*42_10 = 00101010_2 = 0x2A
*11001100_2 = 0xCC = 204_10
*0xAD = 10101101_2 = 173*/


double get_accuracy(double daten){
    double epsilon;
    std :: cout << "Maximal zulässige relative Abweichung in % (z. B. 0.005): ";
    std :: cin >> epsilon;
    return daten * epsilon / 100.0; 
}





int main() {
    return 0; 
}
