PROGRAM := bin/GameGuy
SRCS := $(wildcard src/*.cpp) $(wildcard src/cpu/*.cpp)
OBJS := ${SRCS:.cpp=.o}
LIBS := -lSDL2
CXXFLAGS := -std=c++14

.PHONY: all clean

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	g++ $(OBJS) -o $(PROGRAM) $(LIBS) $(CXXFLAGS)

clean:
	@- rm -f $(PROGRAM)
	@- rm -f $(OBJS)
