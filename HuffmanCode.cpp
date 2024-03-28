//============================================================================
// Hieu Tran, Max Wisnefski, Aidan Jeansonne
// March 2024
// HuffmanCode.cpp
// This is the implementation file for the HuffmanCode class.
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include "HuffmanCode.h"

using namespace std;

/*
 * createFreqTable.
 * Description: creates a frequency table map, mapping the character to its frequency.
 * Parameters: string counts: a string of 26 integer frequencies separated by new lines, where the freq of a is on the first line.
 * Return: map<char, int> freqTable: a map of letters to their frequency.
 */
map<char, int> HuffmanCode::createFreqTable(string counts) {

    map<char, int> freqTable;

    string curr; // The current frequency number
    int idx = 0; // The current index for freqs
    int freqs[26]; // Array where each value is the freq for that letter (a being index 0)

    // Convert new line separated freqs to array.
    for (char val : counts){
        if (val == '\n')
        {
            freqs[idx] = stoi(curr);
            idx++;
            curr = "";
        }
        else {
            curr += val;
        }
    }

    // Populate the map.
    idx = 0;
    for (char letter = 'a'; letter <= 'z'; letter++)
    {
        freqTable[letter] = freqs[idx];
        idx++;
    }
    return freqTable;
}

