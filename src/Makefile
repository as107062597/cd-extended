CXX         := g++
CXXFLAGS    := -Wall -std=c++17 -lstdc++fs -Ofast
CPPFLAGS    := -I../include -I../include/utils -I../include/dir
SUBDIRS     := . utils dir
SOURCES     := $(foreach subdir,$(SUBDIRS),$(wildcard $(subdir)/*.cpp))
OBJECTS     := $(patsubst %.cpp,%.o,$(SOURCES))
TARGET      := dirctl

all: $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS) $(CPPFLAGS) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CPPFLAGS) $(CXXFLAGS)

clean:
	rm -f $(TARGET)
	rm -f $(OBJECTS)

.PHONY: all clean
