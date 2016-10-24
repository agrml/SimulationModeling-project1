TARGET = project1
OBJECTS=main.o InstructionCounter.o

.PHONY: clean

std: $(OBJECTS)
	gcc -m32 -g -o $(TARGET) $(OBJECTS) -std=gnu11

main.o: main.c
	gcc -m32 -g -c -o main.o main.c -std=gnu11

InstructionCounter.o: InstructionCounter.asm
	nasm -g -f elf32 InstructionCounter.asm -o InstructionCounter.o

clean:
	rm -f $(TARGET) *.o