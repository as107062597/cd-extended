INCLUDES    = -I../
SOURCES     = executorinfo.cpp history.cpp controller.cpp executor.cpp \
              editableexecutor.cpp switchexecutor.cpp backwardexecutor.cpp \
              forwardexecutor.cpp executorfactory.cpp \
              switchexecutorfactory.cpp backwardexecutorfactory.cpp \
              forwardexecutorfactory.cpp executorfactoryproducer.cpp
OBJECTS     = $(patsubst %.cpp,%.o,$(SOURCES))
TARGET      = libdir.a

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(INCLUDES) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

.PHONY: all clean
