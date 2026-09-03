# Lab 03a: Modular Gradebook

## Build and Run Commands
```bash
g++ -Wall -Iinclude -c src/gradebook.cpp -o gradebook.o
g++ -Wall -Iinclude -c src/stats.cpp     -o stats.o
g++ -Wall -Iinclude -c src/utilites.cpp  -o utilites.o
g++ -Wall -Iinclude -c src/printing.cpp -o printing.o

g++ gradebook.o stats.o utilites.o printing.o -o gradebook
./gradebook# lab03-gradebook
