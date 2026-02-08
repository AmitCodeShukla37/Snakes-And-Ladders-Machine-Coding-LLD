# Define variables for compilation, CXX for compiler, CXXFLAGS for compilter instructions
CXX = g++
CXXFLAGS = -Wall -Iheaders     


# Picks up all source cpp files (main.cpp src/A.cpp src/B.cpp etc)
SRCS = main.cpp $(wildcard src/*.cpp)

# Create object file names for our cpp files (main.o src/A.o src/B.o etc)
OBJS = $(SRCS:.cpp=.o)

# Target executable name
TARGET = snake_and_ladder

# all runs all compilation of target, below is definition of target
all: $(TARGET)            


# # Dependency on OBJS, runs command = g++ (Flags) -o (tic_tac_toe.o) (all .o files created)
$(TARGET):	$(OBJS) 
			$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)               

.cpp.o:
		$(CXX) $(CXXFLAGS) -c $< -o $@

run:	$(TARGET)
		./$(TARGET)

print-var:
		@echo "Value of OBJS is: $(OBJS)"

clean:
		-del /f /q src\*.o
		-del /f /q main.o
		-del /f /q $(TARGET).exe