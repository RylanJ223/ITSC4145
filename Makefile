CXX = g++
CXXFLAGS = -O2 -std=c++17 -Wall

TARGET = mergesort

all: $(TARGET)

$(TARGET): mergesort.cpp
	$(CXX) $(CXXFLAGS) mergesort.cpp -o $(TARGET)

clean:
	rm -f $(TARGET) *.o
