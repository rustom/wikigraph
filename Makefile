# Executable Name
EXENAME = wikigraphs

# Object Types
OBJS = 	driver.o io_handler.o articles.o main.o

OBJDIR = obj

# Compilation Flags
CXX = clang++
CXXFLAGS = -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

# Define Makefile Rules
.PHONY: all test clean # output_msg

all : $(EXENAME)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(EXENAME): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

driver.o: main.cpp src/driver.cpp
	$(CXX) $(CXXFLAGS) src/driver.cpp

io_handler.o: main.cpp src/io_handler.cpp
	$(CXX) $(CXXFLAGS) src/io_handler.cpp

articles.o: main.cpp src/articles.cpp 
	$(CXX) $(CXXFLAGS) src/articles.cpp

test: tests/test.cpp tests/catch.hpp src/io_handler.cpp src/articles.cpp
	$(LD) tests/catch.hpp tests/test.cpp src/io_handler.cpp src/articles.cpp $(LDFLAGS) 

clean:
	-rm -f *.o $(EXENAME) tests/catch.hpp.gch a.out