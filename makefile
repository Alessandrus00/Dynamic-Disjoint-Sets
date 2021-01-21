main: main.o CircularList.o RootedTree.o Node.o DisjointSetsCircularList.o DisjointSetsForest.o
	g++ -o main main.o CircularList.o RootedTree.o Node.o DisjointSetsCircularList.o DisjointSetsForest.o

main.o: main.cpp
	g++ -c main.cpp

CircularList.o: CircularList.cpp
	g++ -c CircularList.cpp

RootedTree.o: RootedTree.cpp
	g++ -c RootedTree.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

DisjointSetsCircularList.o: DisjointSetsCircularList.cpp
	g++ -c DisjointSetsCircularList.cpp

DisjointSetsForest.o: DisjointSetsForest.cpp
	g++ -c DisjointSetsForest.cpp


clean:
	rm *.o main