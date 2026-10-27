CXX = clang++
CXXFLAGS = -std=c++20 -Wextra -Wall -Wpedantic -Wshadow

SOURCES = $(wildcard *.cpp)
TARGETS = $(SOURCES:.cpp=.out)

all: $(TARGETS)

%.out: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.out *.o core vgcore.* callgrind.out.* valgrind.log
