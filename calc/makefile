PROGRAM = run_calc

CC := g++
CFLAGS := -g -Wall -std=c++11

BLDDIR = build
TARGET = $(BLDDIR)/$(PROGRAM)
SOURCES = calculator.cpp table.cpp err_hdl.cpp
OBJECTS = $(addprefix $(BLDDIR)/, $(SOURCES:.cpp=.o))

all: $(TARGET)
	
$(TARGET): $(OBJECTS) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

$(BLDDIR)/%.o: %.cpp | $(BLDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BLDDIR):
	mkdir -vp $(BLDDIR)

clean:
	rm -vrd $(BLDDIR)
