CXX         = g++
CXXFLAGS    = -Wall -std=c++17 -O3
INCLUDES    = -I../
AR          = ar
ARFLAGS     = rcs
SOURCES     = optionparser.cpp
OBJECTS     = $(patsubst %.cpp,%.o,$(SOURCES))
TARGET      = libopt.a

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

.PHONY: all clean
