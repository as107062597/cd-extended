SOURCES     = translator.cpp enus.cpp zhtw.cpp
OBJECTS     = $(patsubst %.cpp,%.o,$(SOURCES))
TARGET      = libtr.a

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

.PHONY: all clean
