CXX = g++

INCLUDE_DIR = include

SRCS = exception.cpp server.cpp start-server.cpp
OBJS = $(SRCS:.cpp=.o)

EXECUTABLE = main

CXXFLAGS = -I$(INCLUDE_DIR)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(OBJS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE)

.PHONY: all clean