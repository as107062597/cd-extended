CXX         = g++
CXXFLAGS    = -Wall -std=c++17 -O3
INCLUDES    = -I. -Itr -Iutil -Idir -Iopt
LIBDIRS     = opt dir util tr
LIBFILES    = $(addprefix lib,$(addsuffix .a,$(LIBDIRS)))
LIBPATHS    = $(join $(addsuffix /,$(LIBDIRS)),$(LIBFILES))
LDFLAGS     = $(addprefix -L,$(LIBDIRS))
LIBS        = $(addprefix -l,$(LIBDIRS))
AR          = ar
ARFLAGS     = rcs
SOURCES     = main.cpp
OBJECTS     = $(patsubst %.cpp,%.o,$(SOURCES))
TARGET      = dirctl
INSTDIR     = $(HOME)/.local/usr/opt/cd-extended/$(TARGET)

all: $(TARGET)

$(TARGET): $(LIBPATHS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJECTS) $(LDFLAGS) $(LIBS) -o $(TARGET)

%.a:
	$(MAKE) -C $(dir $@)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	for dir in $(LIBDIRS); \
	do $(MAKE) -C $$dir clean; \
	done
	rm -f $(OBJECTS)
	rm -f $(TARGET)

install: $(TARGET)
	install -D -m 755 $(TARGET) $(INSTDIR)

uninstall:
	rm -f $(INSTDIR)

.PHONY: all clean install uninstall
