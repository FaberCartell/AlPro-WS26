// Zur Blatt 02 Aufgabe 04

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include <ctime> // needed for todays year
constexpr int ALAN_TURING_GEBURTSJAHR = 1912; //Globale Variable für Geburtsjahr von Turing

// Druckt einen Text aus
void drucke_text(const std::string& text);

// Druckt eine Ganzzahl aus
void drucke_ganzzahl(int ganzzahl);

// Druckt eine Kommazahl aus
void drucke_kommazahl(double gleitkommazahl);

// Liest ein Wort von der Konsole ein
std::string lies_wort();

// Liest eine Ganzzahl von der Konsole ein
int lies_ganzzahl();

// Liest eine Gleitkommazahl von der Konsole ein
double lies_gleitkommazahl();

int get_aktuelles_jahr() {
  // C Standard Bibliothek - Erhält aktuellen Zeitpunkt und konvertiert Format zu Jahr
  // gegoogelte Magie
  time_t t = time(nullptr);
  tm* now = localtime(&t);
  return now->tm_year + 1900;
}

void alter_von_alan_turing_erraten() {
  const int alter_alan_turing_heute = get_aktuelles_jahr() - ALAN_TURING_GEBURTSJAHR; //const sicher das Alter gegen versehentliches Überschreiben
  drucke_text("Geben Sie einen Tipp ab, wie alt Turing heute wäre");
  int user_input = lies_ganzzahl();
  while (user_input != alter_alan_turing_heute){
    if (user_input < alter_alan_turing_heute){
      drucke_text("Falsch Alan Turing wäre heute älter. Geben Sie noch einen Tipp ab");
    }else{
      drucke_text("Falsch, Alan Turing wäre heute jünger. Geben Sie noch einen Tipp ab");
    }
    user_input = lies_ganzzahl();
  }
  drucke_text("Korrekt, Alan Turing wäre heute genauso alt");
}


int main() {
  alter_von_alan_turing_erraten();
  return 0;
}


/************************************/
/*                                  */
/*   MAGIE   MAGIE   MAGIE  MAGIE   */
/*                                  */
/************************************/

void drucke_text(const std::string& text) {
  std::cout << text << std::endl;
}

void drucke_ganzzahl(int ganzzahl) {
  std::cout << std::to_string(ganzzahl) << std::endl;
}

void drucke_kommazahl(double gleitkommazahl) {
  std::cout << std::to_string(gleitkommazahl) << std::endl;
}

std::string lies_wort() {
  std::string wort;
  std::cin >> wort;
  return wort;
}

int lies_ganzzahl() {
  std::string wort;
  std::cin >> wort;
  int ganzzahl = 0;
  try {
    ganzzahl = std::stoi(wort);
  } catch (const std::invalid_argument& e) {
    ganzzahl = -1000;
  }
  return ganzzahl;
}

double lies_gleitkommazahl() {
  std::string wort;
  std::cin >> wort;
  double lies_gleitkommazahl = 0.0;
  try {
    lies_gleitkommazahl = std::stod(wort);
  } catch (const std::invalid_argument& e) {
    lies_gleitkommazahl = NAN; // See https://en.cppreference.com/w/cpp/numeric/math/NAN
  }
  return lies_gleitkommazahl;
}
