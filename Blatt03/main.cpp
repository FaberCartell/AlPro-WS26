#include <iostream>
#include <cmath> 
#include <numbers>



/*Aufgabe 1 (Zahlensysteme):
*
*42_10 = 00101010_2 = 0x2A
*11001100_2 = 0xCC = 204_10
*0xAD = 10101101_2 = 173*/


double get_accuracy(){
    double epsilon;
    std :: cout << "Maximal zulässige relative Abweichung in % (z. B. 0.005): ";
    std :: cin >> epsilon;
    return  epsilon / 100.0; 
}

double sin(double input_radians){
    const double pi = std::numbers::pi;
    //Normalisiere zunächst um catastrophic cancellation zu vermeiden:
    double k = std::floor(input_radians/(2.0*pi));
    input_radians -= 2*k*pi; // schiebt in den Bereich [0, 2pi)
    // Nutze Symmetrie, um input auf [-pi/2, pi/2] zu reduzieren
    if(input_radians > 1.5 * pi){
        input_radians -= 2.0*pi;
    }else if(input_radians > pi) {
        input_radians -= (2*(input_radians - 1.5 * pi) + 2.0*pi);

    }else if(input_radians > pi/2){
        input_radians -= 2.0*(input_radians - pi/2.0);
    }
    double epsilon = get_accuracy();
    double taylorsum = 0;
    double a_i = input_radians;
    int i = 1;
    while ( std::abs(a_i) > epsilon * std::abs(taylorsum)){
        taylorsum += a_i; 
        a_i = -a_i * input_radians*input_radians / (2.0*i*(2.0*i + 1.0));
        i++;
    }
    return taylorsum;
}




int main() {
    std::cout << sin(std::numbers::pi) <<"\n";
    return 0; 
}
