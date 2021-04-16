# Executable Name
EXENAME = finalproj

# Object Types
OBJS = 	io_handler.o article.o main.o

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
	$(CXX) $(CXXFLAGS) main.cpp src/io_handler.cpp

article.o: main.cpp src/article.cpp
	$(CXX) $(CXXFLAGS) main.cpp src/article.cpp

# test: output_msg catch/catchmain.cpp sample.cpp
# 	$(LD) catch/catchmain.cpp sample.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test