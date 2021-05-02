# Executable Name
EXENAME = wikigraphs

# Object Types
OBJS = 	io_handler.o articles.o main.o

OBJDIR = obj

# Compilation Flags
CXX = clang++
CXXFLAGS = -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

# Define Makefile Rules
.PHONY: all test clean # output_msg

all : $(EXENAME)

# output_msg: ; $(CLANG_VERSION_MSG)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(EXENAME): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

io_handler.o: main.cpp src/io_handler.cpp
	$(CXX) $(CXXFLAGS) src/io_handler.cpp

articles.o: main.cpp src/articles.cpp
	$(CXX) $(CXXFLAGS) src/articles.cpp

test: test/test.cpp test/catch.hpp
	$(LD) test/catch.hpp test/test.cpp $(LDFLAGS) 

clean:
	-rm -f *.o $(EXENAME) test/catch.hpp.gch a.out