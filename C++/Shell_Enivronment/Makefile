CXX = g++
CXXFLAGS = -std=c++11

all: skku_sh

skku_sh: main.o Entry.o Directory.o File.o
	$(CXX) $(CXXFLAGS) main.o Entry.o Directory.o File.o -o skku_sh

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

Entry.o: Entry.cc
	$(CXX) $(CXXFLAGS) -c Entry.cc

Directory.o: Directory.cc
	$(CXX) $(CXXFLAGS) -c Directory.cc

File.o: File.cc
	$(CXX) $(CXXFLAGS) -c File.cc

clean:
	rm -rf *.o skku_sh