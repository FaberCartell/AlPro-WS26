#include <iostream>
#include <cmath> 
#include <numbers>
#include <iomanip>
#include <random> 
#include <string> 

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
        return NAN; 
    }
    if (input == 0){
        return 0;
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

double sqrt(double input){
    return sqrt(input, DEFAULT_EPSILON);
}

int main() {
    return 0; 
}


//vibecoded slop
// --- TEST SUITE ---

void print_test_result(const std::string& test_name, double expected, double actual, double tolerance = 1e-7) {
    std::cout << std::left << std::setw(50) << test_name;
    if (std::abs(expected - actual) <= tolerance) {
        std::cout << "[ OK ]\n";
    } else {
        std::cout << "[ FEHLER ] (Erwartet: " << expected << ", Ist: " << actual << ")\n";
    }
}

void test_fixed_values() {
    std::cout << "--- 1. Standard Werte ---\n";
    const double pi = std::numbers::pi;
    
    print_test_result("sin(pi/2)", 1.0, sin(pi/2.0));
    print_test_result("cos(pi)", -1.0, cos(pi));
    print_test_result("tan(pi/4)", 1.0, tan(pi/4.0));
    print_test_result("sqrt(4.0)", 2.0, sqrt(4.0));
    print_test_result("sqrt(144.0)", 12.0, sqrt(144.0));
    std::cout << "\n";
}

void test_edge_cases() {
    std::cout << "--- 2. Edge Cases (Raender & Extreme) ---\n";
    const double pi = std::numbers::pi;
    
    // Extreme Winkel (Testet die Modulo-Reduktion k = std::floor(...))
    print_test_result("sin(1e9 * pi) [Sehr grosser Winkel]", std::sin(1e9 * pi), sin(1e9 * pi));
    print_test_result("sin(-1e9 * pi) [Sehr grosser neg. Winkel]", std::sin(-1e9 * pi), sin(-1e9 * pi));
    
    // Genau auf den Grenzen der Symmetrie-Verschiebung
    print_test_result("sin(pi)", 0.0, sin(pi));
    print_test_result("sin(3/2 pi)", -1.0, sin(1.5 * pi));
    
    // Division durch Null Edge-Case beim Heron-Verfahren
    print_test_result("sqrt(0.0) [Echte Null]", 0.0, sqrt(0.0));
    
    // Negative Wurzel (Sollte den von dir definierten Fehlercode NAN zurueckgeben)
    print_test_result("sqrt(-1.0) [Fehlerfall Negativ]", NAN, sqrt(-1.0));
    
    // Sehr kleine Eingaben testen (Limits der double precision)
    print_test_result("sqrt(1e-12) [Sehr kleine Zahl]", std::sqrt(1e-12), sqrt(1e-12));
    print_test_result("sin(1e-12) [Sehr kleiner Winkel]", std::sin(1e-12), sin(1e-12));
    std::cout << "\n";
}

void test_randomized(int num_tests) {
    std::cout << "--- 3. Randomisierte Tests (" << num_tests << " Durchlaeufe) ---\n";
    
    // Fester Seed fuer Reproduzierbarkeit (immer die gleichen "Zufallszahlen")
    std::mt19937 gen(42); 
    std::uniform_real_distribution<double> angle_dist(-1000.0, 1000.0);
    std::uniform_real_distribution<double> pos_dist(0.1, 10000.0); // Ab 0.1, da 0 als Edge Case oben abgedeckt ist

    bool sin_ok = true;
    bool cos_ok = true;
    bool sqrt_ok = true;
    double tolerance = 1e-7;

    for (int i = 0; i < num_tests; ++i) {
        double r_angle = angle_dist(gen);
        double r_val = pos_dist(gen);

        // Sinus und Cosinus gegen cmath pruefen
        if (std::abs(sin(r_angle) - std::sin(r_angle)) > tolerance) sin_ok = false;
        if (std::abs(cos(r_angle) - std::cos(r_angle)) > tolerance) cos_ok = false;
        
        // Bei der Wurzel den relativen Fehler pruefen
        double expected_sqrt = std::sqrt(r_val);
        double actual_sqrt = sqrt(r_val);
        if (std::abs(actual_sqrt - expected_sqrt) / expected_sqrt > tolerance) {
            sqrt_ok = false;
        }
    }

    // Wir erwarten 1.0 (True) als OK-Wert fuer den gesamten Test
    print_test_result("Alle randomisierten sin() korrekt?", 1.0, sin_ok ? 1.0 : 0.0, 0.0);
    print_test_result("Alle randomisierten cos() korrekt?", 1.0, cos_ok ? 1.0 : 0.0, 0.0);
    print_test_result("Alle randomisierten sqrt() korrekt?", 1.0, sqrt_ok ? 1.0 : 0.0, 0.0);
    std::cout << "\n";
}

void run_all_tests() {
    std::cout << "========================================================\n";
    std::cout << "                 START DER TEST SUITE\n";
    std::cout << "========================================================\n\n";
    
    test_fixed_values();
    test_edge_cases();
    test_randomized(10000);
    
    std::cout << "========================================================\n";
    std::cout << "                 ENDE DER TEST SUITE\n";
    std::cout << "========================================================\n";
}