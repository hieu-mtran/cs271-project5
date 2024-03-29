all: frequency HuffmanTester encode decode

frequency: countFrequency.py 
	python countFrequency.py

HuffmanTester: HuffmanTester.cpp HuffmanCode.h
	g++ -o HuffTest HuffmanTester.cpp 

encode: encode.py
	python encode.py

decode: 
	g++ -o decoding decode.cpp
