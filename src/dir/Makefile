INCLUDES    = -I../
SOURCES     = entry.cpp
OBJECTS     = $(patsubst %.cpp,%.o,$(SOURCES))
TARGET      = libdir.a

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(INCLUDES)

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

.PHONY: all clean
