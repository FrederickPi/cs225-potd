EXENAME = main
OBJS = main.o 

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp waterPouring.cpp
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o $(EXENAME)
