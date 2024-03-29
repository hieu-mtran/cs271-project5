# Hieu Tran, Max Wisnefski, Aidan Jeansonne
# March 2024
# countFrequency.py
# Parsing text for letter frequency
# reads the WarPeace.txt file (via stdin redirection) and 
# counts instances of letters (converted to lower case). 
# outputs a frequency table stores in a textfile. 


freq = dict()
alphabet = 'abcdefghijklmnopqrstuvwxyz'
for char in alphabet:
    freq[char] = 0
with open("WarPeace.txt") as file:
    for line in file:
        for char in line:
            char = char.lower()
            if char in alphabet:
                freq[char] = freq[char] + 1

freqText = ''
for char in alphabet:
    freqText += f'{freq[char]}\n'

with open('frequency.txt', 'w') as file:
    file.write(freqText)