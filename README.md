# Algorithmen und Programmierung (AlPro) - Übungsabgaben

Dieses Repository enthält die C++ Programmieraufgaben für das Modul Algorithmen und Programmierung im Wintersemester 2026/2027 an der Universität Bonn.

## Studenteninfo
* **Name:**             Marc Beigel
* **Matrikelnummer:**   50370681
* **E-Mail:**           s87mbeig@uni-bonn.de

## Repository-Struktur
Jedes Übungsblatt besitzt einen eigenen Unterordner (z.B. `Blatt01/`, `Blatt02/`). 
Spezifische Implementierungsdetails, Abweichungen von der Aufgabenstellung oder bekannte Fehler (Bugs/Segfaults) sind in der jeweiligen lokalen `README.md` des Aufgabenordners dokumentiert.

## Kompilierung & Build-System
Das Setup ist für Fedora Linux und `clang++` konfiguriert. Der Code wird standardmäßig nach dem C++20 Standard kompiliert.

In den Verzeichnissen liegen `Makefile`-Skripte, die folgende Targets unterstützen:

```bash
# Kompiliert alle .cpp-Dateien im aktuellen Verzeichnis zu .out-Executables
make

# Entfernt alle generierten Executables, Objektdateien und Valgrind/Core-Dumps
make clean
```

Standardmäßig werden folgende Flags genutzt: 
-std=c++20
-Wall
-Wextra
-Wpedantic
-Wshadow

Es gibt ein automatisches Build-Skript für BlattX Subdirectories:

```bash
#Erstellt automatisch ein Subdirectory mit README.md, main.cpp und makefile
./setup_blatt.sh <Name/BlattX> 
```

