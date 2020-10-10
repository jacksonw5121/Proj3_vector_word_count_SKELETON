#include "../includes/array_functions.h"

//zero out vector that tracks words and their occurrences
void clear(std::vector<constants::entry>  &entries);

//how many unique words are in the vector
int getSize(std::vector<constants::entry>  &entries);

//get data at a particular location, if i>size() then get the last value in the vector
//(this is lazy, should throw an exception instead)
std::string getWordAt(std::vector<constants::entry>  &entries, int i);
int getNumbOccurAt(std::vector<constants::entry>  &entries,int i);

/*loop through whole file, one line at a time
 * call processLine on each line from the file
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::vector<constants::entry>  &entries,std::fstream &myfstream)
{
    if(!myfstream.is_open())
    {
        return false;
    }

    return true;
}

	/*take 1 line and extract all the tokens from it
	feed each token to processToken for recording*/
void processLine(std::vector<constants::entry>  &entries,std::string &myString)
{
    
}

	/*Keep track of how many times each token seen*/
void processToken(std::vector<constants::entry>  &entries,std::string &token)
{

}

	/*
	 * Sort myEntryArray based on so enum value.
	 * Please provide a solution that sorts according to the enum
	 * The presence of the enum implies a switch statement based on its value
	 * See the course lectures and demo project for how to sort a vector of structs
	 */
void sort(std::vector<constants::entry>  &entries, constants::sortOrder so);