# ------------------------------------------------------------------
# Ref: https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# ------------------------------------------------------------------

# Define INC dir storing *.h files
INCDIR 		= inc
# Define SRC dir storing *.cpp files
SRCDIR 		= src
# Define LIB dir storing library files
LDIR 			= lib
# Define OBJ dir storing *.o files
ODIR 			= obj
# Define compiler and compiler flags
CC 			= g++
CFLAGS 		= -Wall -g -I$(INCDIR)
# Include math library -lm
LIBS			=-lm
# Define Program name
PROG_NAME 	= main

# Define depedencies *.h
_DEPS 		= $(PROG_NAME).h account.h savings_account.h chequing_account.h trust_account.h
DEPS 			= $(patsubst %,$(INCDIR)/%,$(_DEPS))
# Define objects *.o
_OBJ 			= $(PROG_NAME).o account.o savings_account.o chequing_account.o trust_account.o
OBJ 			= $(patsubst %,$(ODIR)/%,$(_OBJ))

# Generate all *.o files
$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Generate the main.o
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Clean all objects
.PHONY: all clean

clean:
	rm -rf $(ODIR)/*.o $(INCDIR)/*~ $(SRCDIR)/*~ *~ compile_commands.json core .cache $(PROG_NAME)
 
