_OBJ = word.o main.o dictionary.o interface.o mnemonicTable.o deciTree.o treeNode.o sentenceGenerator.o
_DEPS = word.h interface.h dictionary.h mnemonicTable.h deciTree.h treeNode.h sentenceGenerator.h macros.h

IDIR = ./include
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
ODIR = ./obj
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
SDIR = ./src

CC=g++ -std=c++14
CFLAGS=-I$(IDIR) -fPIC

run: build
	./a.out

build: a.out

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

a.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
