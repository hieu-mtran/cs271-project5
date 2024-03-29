all: HuffmanTester encode decode frequency

HuffmanTester:

encode: encode.py
	python encode.py

decode:

frequency: CountFrequency.py 
	python frequency