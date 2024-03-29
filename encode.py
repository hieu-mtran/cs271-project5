# Hieu Tran, Max Wisnefski, Aidan Jeansonne
# March 2024
# encode.py
# this program reads the code vectors from the text file.  
# It then reads some block of text and translates the block of text into a code.


#text = "this text is just to test the encoding\nabcdefghijklmnopqrstuvwxyz"

with open(input("Enter a .txt file to encode "),'r') as file:
    text = " ".join(line for line in file)


codes_dict = {}

#creating a dictionary where the keys are letters,
#and the values are the codes for the letters
with open("encodings.txt") as file:
    for line in file:
        #print(line[2:-1])
        let = line[0]
        code = line[2:-1]
        codes_dict[let] = code

#print(codes_dict)
keys = codes_dict.keys()

encoded_txt = ""
for char in text:
    char = char.lower()
    if char == "\n":
        encoded_txt = encoded_txt + "\n"
    for key in keys:
        if char == key:
            encoded_txt = encoded_txt + codes_dict[key] #+ " "

print(encoded_txt)

#writing the encoded song lyrics to a .txt file for the next step
with open("encodedSong.txt",'w') as file:
    file.writelines(encoded_txt)



