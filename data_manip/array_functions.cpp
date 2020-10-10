#include <algorithm>
#include "../includes/array_functions.h"
#include "../includes/fileio.h"
#include "../includes/utilities.h"

using namespace std;

bool compareAscending(const constants::entry & entry1, const constants::entry & entry2)
{
   return entry1.word_uppercase < entry2.word_uppercase;
}

bool compareDescending(const constants::entry & entry1, const constants::entry & entry2)
{
   return entry1.word_uppercase > entry2.word_uppercase;
}

bool compareNumberOccurrences(const constants::entry & entry1, const constants::entry & entry2)
{
   return entry1.number_occurences > entry2.number_occurences;
}

//zero out vector that tracks words and their occurrences
void KP::clear(std::vector<constants::entry>  & entries)
{
    entries.clear();
}

//how many unique words are in the vector
int KP::getSize(std::vector<constants::entry>  & entries)
{
    return entries.size();
}

//get data at a particular location, if i>size() then get the last value in the vector
//(this is lazy, should throw an exception instead)
std::string KP::getWordAt(std::vector<constants::entry>  & entries, int i)
{
    return entries[i].word;
}

int KP::getNumbOccurAt(std::vector<constants::entry>  &entries,int i)
{
    return entries[i].number_occurences;
}

/*loop through whole file, one line at a time
 * call processLine on each line from the file
 * returns false: myfstream is not open
 *         true: otherwise*/
bool KP::processFile(std::vector<constants::entry>  &entries,std::fstream &myfstream)
{
    string line;

    if(!myfstream.is_open())
    {
        return false;
    }

    while (!myfstream.eof())
    {
        getline(myfstream, line);
        processLine(entries, line);
    }
    closeFile(myfstream);
    return true;
}

	/*take 1 line and extract all the tokens from it
	feed each token to processToken for recording*/
void KP::processLine(std::vector<constants::entry>  &entries,std::string &myString)
{
    stringstream ss(myString);
    string tempToken;

    while (getline(ss, tempToken, constants::CHAR_TO_SEARCH_FOR))
    {
        processToken(entries, tempToken);
    }
}

	/*Keep track of how many times each token seen*/
void KP::processToken(std::vector<constants::entry>  &entries,std::string &token)
{
    strip_unwanted_chars(token);
    string line = token;
    toUpper(line);

    for (unsigned int i = 0; i < entries.size(); i++)
    {
        if (entries[i].word_uppercase == line)
        {
            entries[i].number_occurences++;
            return;
        }
    }

    if (token != "")
    {
        constants::entry newEntry;
        newEntry.word = token;
        newEntry.word_uppercase = line;
        newEntry.number_occurences = 1;

        entries.push_back(newEntry);
    }
}

	/*
	 * Sort myEntryArray based on so enum value.
	 * Please provide a solution that sorts according to the enum
	 * The presence of the enum implies a switch statement based on its value
	 * See the course lectures and demo project for how to sort a vector of structs
	 */
void KP::sort(std::vector<constants::entry>  & entries, constants::sortOrder so)
{
    switch (so) 
    {
        case constants::NONE:
            break;
        
        case constants::ASCENDING:
            sort(entries.begin(), entries.end(), compareAscending);
            break;

        case constants::DESCENDING:
            sort(entries.begin(), entries.end(), compareDescending);
            break;
        
        case constants::NUMBER_OCCURRENCES:
            sort(entries.begin(), entries.end(), compareNumberOccurrences);
            break;
    }
}