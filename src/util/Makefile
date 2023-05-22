INCLUDES    = -I../
SOURCES     = environment.cpp errorhandler.cpp
OBJECTS     = $(patsubst %.cpp,%.o,$(SOURCES))
TARGET      = libutil.a

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(INCLUDES) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

.PHONY: all clean
