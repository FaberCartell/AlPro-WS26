#include <iostream>
#include <cmath> 
#include <numbers>

 constexpr double DEFAULT_EPSILON = 1e-10; 


/*
*Aufgabe 1 (Zahlensysteme):
*42_10 = 00101010_2 = 0x2A
*11001100_2 = 0xCC = 204_10
*0xAD = 10101101_2 = 173
*/


double radians_to_degree(double input_radians){
    return input_radians * 360 / (2 * std::numbers::pi);
}

double degree_to_radians(double input_degrees){
    return 2 * input_degrees * std::numbers::pi /360;
}


double sin(double input_radians, double epsilon){
    const double pi = std::numbers::pi;
    //Normalisiere zunächst um catastrophic cancellation zu vermeiden:
    double k = std::floor(input_radians/(2.0*pi));
    input_radians -= 2*k*pi; // schiebt in den Bereich [0, 2pi)
    // Nutze Symmetrie, um input auf [-pi/2, pi/2] zu reduzieren
    if(input_radians > 1.5 * pi){
        input_radians -= 2.0*pi;
    }else if(input_radians > pi) {
        input_radians -= (2*(input_radians - 1.5 * pi) + 2.0*pi); //nutze Symmetrieachse 3/2 pi
    }else if(input_radians > pi/2){
        input_radians -= 2.0*(input_radians - pi/2.0); //nutze Symmetrieachse 1/2 pi
    }
    double taylorsum = 0;
    double a_i = input_radians;
    int i = 1;
    // Abbruchbedingung abhängig vom relativen Fehler
    while ( std::abs(a_i) > epsilon * std::abs(taylorsum)){ // Abbruch der Taylorreihe, falls die contribution von einzelnem Taylorglied klein
        taylorsum += a_i;  // summiert die Taylorglieder 
        a_i = -a_i * input_radians*input_radians / (2.0*i*(2.0*i + 1.0)); //berechne neues Taylorglied durch Rekursion
        i++;
    }
    return taylorsum;
}

double cos(double input_radians, double epsilon){
    return sin(input_radians + std::numbers::pi /2.0, epsilon );
}

double tan(double input_radians, double epsilon){
    return sin(input_radians, epsilon)/cos(input_radians, epsilon);
}

double cot(double input_radians, double epsilon){
    return 1/tan(input_radians, epsilon);
}


double sqrt(double input, double epsilon){
    if(input < 0){
        //std::cout << "Die Wurzel ex. über den reellen Zahlen nicht";
        return -1; 
    }
    double t = input; 
    //Heronverfahren
    while (std::abs(t*t - input) > epsilon * input){ //Abbruch bei kleinem relativen Fehler
        t = (t + input/t)/2.0;
    }
    return t; 
}

double sin(double input){
    return sin(input, DEFAULT_EPSILON);
}

double cos(double input){
    return cos(input, DEFAULT_EPSILON);
}

double tan(double input){
    return tan(input, DEFAULT_EPSILON);
}

double cot(double input){
    return cot(input, DEFAULT_EPSILON);
}

int main() {
    return 0; 
}
