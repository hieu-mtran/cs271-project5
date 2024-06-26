all: HuffTest decode

HuffTest: HuffmanTester.o BinaryTree.o
	g++ HuffmanTester.o BinaryTree.o -o HuffTest

decode: decode.o BinaryTree.o
	g++ decode.o BinaryTree.o -o decode

HuffmanTester.o: HuffmanTester.cpp HuffmanCode.h BinaryTree.h
	g++ -c HuffmanTester.cpp -o HuffmanTester.o

decode.o: decode.cpp BinaryTree.h BTNode.h
	g++ -c decode.cpp -o decode.o

BinaryTree.o: BinaryTree.cpp BinaryTree.h BTNode.h
	g++ -c BinaryTree.cpp -o BinaryTree.o
