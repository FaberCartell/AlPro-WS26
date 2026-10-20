// Zur Blatt 02 Aufgabe 03

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

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


void ablauf_diagramm_1(){
  /*************************************/
  /*                                   */
  /*  Hier kommt der Programmcode hin  */
  /*                                   */
  /*************************************/
  
}

void ablauf_diagramm_2(){
  /*************************************/
  /*                                   */
  /*  Hier kommt der Programmcode hin  */
  /*                                   */
  /*************************************/
  
}

void programm_1() {
    int input = lies_ganzzahl();
    int y = input; 
    y += 17; 
    y *= 3; 
    y %= 2; 
    drucke_ganzzahl(y);
}


void programm_2() {
  std::string text = "Das Modul Algorithmen und Programmierung ist so konzipert, dass die Konzepte und Methodiken\
der objektorientierten Programmierung im Vordergrund stehen. Die hier vorgestellte\
Programmiersprache C++ nimmt die Rolle einer Beispielprogrammiersprache ein, in der die\
diskutierten Konzepte (meist mehr, selten weniger) nachvollziehbar und effizient umgesetzt\
sind. Das Modul soll so verstanden werden, dass es den Teilnehmer:innen im Anschluss an\
dieses Modul leicht fällt andere, objektorientierte Programmiersprachen zu erlernen. Hier soll\
man sich nur noch die Frage stellen: Wie setzten andere Programmiersprachen die wesentlichen\
Konzepte um und was gibt es bei der Sprachsyntax zu beachten?";
    int s = 0; 
    int n = text.length();
    for(int i = 0; i < n; i++) {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?') {
            s++;
        }
    }
    drucke_ganzzahl(s);
}


void programm_3() {
    std::vector<int> zahlen = {42, 69, 420, 99, -444, 9014};
    float s = 0; 
    int n = zahlen.size();
    for(int i = 0; i < n; i++) {
        s += zahlen[i];
    }
    drucke_kommazahl(s/n);
}


void programm_4() {
    int input = lies_ganzzahl();
    unsigned long int t = input; 
    //drucke_ganzzahl(pow(t, 218));
    t = t*t; 
    t = input*t;
    t = t*t;
    t = t*t; 
    t = input*t;
    t = t*t;
    t = input*t;
    t = t*t;
    t = t*t;
    t = input*t;
    t = t*t;
    drucke_ganzzahl(t);
}


int main() {
  ablauf_diagramm_1();
  ablauf_diagramm_2();
  programm_1();
  programm_2();
  programm_3();
  programm_4();
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
