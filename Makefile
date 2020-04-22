GCC = gcc
EXECUTABLE = stack
SOURCE = stack.c

FLAGS = -std=c99

ifeq ($(OS),Windows_NT) 
	REMOVE = del /s /q
	REMOVE_DIR = rmdir /s /q
else
	REMOVE = rm -rf
endif 


$(EXECUTABLE):
	$(GCC) -o $(EXECUTABLE) $(SOURCE)

clear:
	$(REMOVE) *.exe *.o *.txt
