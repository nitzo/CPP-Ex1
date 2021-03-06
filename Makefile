CXXFLAGS =	-O2 -g -Wall -fmessage-length=0
	
OBJDIR = ../bin

OBJECTS = $(addprefix $(OBJDIR)/, main.o intArray_t.o)


LIBS =

TARGET = $(addprefix $(OBJDIR)/, main.exe)


	
$(TARGET):	$(OBJECTS)
	$(CXX) $^ -o $@ $(LIBS)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@


all: bin $(TARGET)

bin:
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJECTS) $(TARGET)
	rmdir $(OBJDIR)
	
	
