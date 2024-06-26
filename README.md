# cs271-project5
Spring 2024 - Binary Trees for Huffman Coding

Contains 4 executables:
1. countFrequency.py - counts the frequency of each letter in WarPeace.txt
2. HuffTest - reads the frequency table and uses BinaryTree class along with the STL priority queue to build the tree. The tree is parsed and the code vectors are printed out for each letter
3. encode.py - reads the code vectors from the text file.  It then reads some block of text (from stdin) and translates the block of text into a code
4. decode.cpp - re-creates the BinaryTree by reading in the code vector file and creating the tree using the indicated left and right branches from the 0s and 1s
