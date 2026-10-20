#Vibecoded Makefile
# Compiler und Flags
CXX = clang++
CXXFLAGS = -std=c++20 -Wextra -Wall -Wpedantic -Wshadow

# Finde alle .cpp Dateien im aktuellen Verzeichnis
SOURCES = $(wildcard *.cpp)
# Erzeuge für jede .cpp Datei ein entsprechendes .out Target
TARGETS = $(SOURCES:.cpp=.out)

# Standard-Target: Kompiliert alle gefundenen .cpp Dateien
all: $(TARGETS)

# Regel, um eine .out Datei aus einer .cpp Datei zu erstellen
%.out: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Räumt generierte Dateien auf (aufrufbar mit 'make clean')
clean:
	rm -f *.out *.o core vgcore.* callgrind.out.* valgrind.log