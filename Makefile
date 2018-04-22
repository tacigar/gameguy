PROGRAM := bin/GameGuy
SRCS := $(wildcard src/*.cpp)
OBJS := ${SRCS:.cpp=.o}
LIBS := -lSDL2

.PHONY: all clean

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	g++ $(OBJS) -o $(PROGRAM) $(LIBS)

clean:
	@- rm -f $(PROGRAM)
	@- rm -f $(OBJS)
