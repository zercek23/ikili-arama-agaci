hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/BinarySearchTree.o -c ./src/BinarySearchTree.cpp
	g++ -I ./include/ -o ./bin/main ./src/main.cpp
	
calistir:
	./bin/main.exe