PROGRAM := bin/GameGuy
SRCS := $(wildcard src/*.cpp) $(wildcard src/cpu/*.cpp) $(wildcard src/rom/*.cpp) $(wildcard src/memory/*.cpp)
OBJS := ${SRCS:.cpp=.o}
LIBS := -lSDL2
CXXFLAGS := -std=c++14 -DDEBUG -Wall

.PHONY: all clean

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	g++ $(OBJS) -o $(PROGRAM) $(LIBS) $(CXXFLAGS)

clean:
	@- rm -f $(PROGRAM)
	@- rm -f $(OBJS)
