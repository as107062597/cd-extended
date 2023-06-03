CXX         := g++
CXXFLAGS    := -Wall -std=c++17 -lstdc++fs -Ofast
CPPFLAGS    := -I.. -I../include
SUBDIRS     := . .. tr dir
SOURCES     := $(foreach subdir,$(SUBDIRS),$(wildcard $(subdir)/*.cpp))
OBJECTS     := $(patsubst %.cpp,%.o,$(SOURCES))
TARGET      := dirctl

all: $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS) $(CPPFLAGS) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CPPFLAGS) $(CXXFLAGS)

clean:
	rm -f $(TARGET)
	rm -f $(addsuffix /*.o,$(SUBDIRS))

.PHONY: all clean
