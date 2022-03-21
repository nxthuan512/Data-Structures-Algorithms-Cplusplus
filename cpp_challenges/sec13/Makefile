# ------------------------------------------------------------------
# Ref: https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# ------------------------------------------------------------------

# Define INC dir storing *.h files
INCDIR = inc
# Define SRC dir storing *.cpp files
SRCDIR = src
# Define LIB dir storing library files
LDIR = lib
# Define OBJ dir storing *.o files
ODIR = obj

# Define compiler and compiler flags
CC = g++
CFLAGS = -Wall -g -I$(INCDIR)

# Include math library -lm
LIBS=-lm

# Define depedencies *.h
_DEPS = main.h movie.h movies.h
DEPS = $(patsubst %,$(INCDIR)/%,$(_DEPS))

# Define objects *.o
_OBJ = main.o movie.o movies.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Generate all *.o files
$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Generate the main.o
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Clean all objects
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(INCDIR)/*~ *~ compile_command.json core .cache
 
