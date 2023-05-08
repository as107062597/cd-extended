CXX         = g++
CXXFLAGS    = -Wall -std=c++17 -O3
AR          = ar
ARFLAGS     = rcs
SOURCES     = translator.cpp enus.cpp zhtw.cpp
OBJECTS     = $(patsubst %.cpp,%.o,$(SOURCES))
TARGET      = libtr.a

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

.PHONY: all clean
