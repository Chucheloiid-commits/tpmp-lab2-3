# Author: Maria Basarimova

CC = gcc
CFLAGS = -Wall -g

SRCDIR = src
OBJDIR = obj

SOURCES = $(SRCDIR)/main.c $(SRCDIR)/stud.c
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/stud.o

EXEC = program

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJDIR)/*.o
