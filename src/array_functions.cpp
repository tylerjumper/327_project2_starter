/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 25, 2019
 *      Author: Tyler Jumper
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================
#include "array_functions.h"
#include "constants.h"
#include "utilities.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
//============================================================================
//	stuff you will need
//============================================================================

struct entry{
	string word;
	int num_occurances;
};

entry myArray[constants::MAX_WORDS];
int next_spot = 0;

//zero out array that tracks words and their occurrences
void clearArray(){
	next_spot = 0;
}

//how many unique words are in array
int getArraySize(){
	return next_spot;
}

//get data at a particular location
std::string getArrayWordAt(int i){
	string word = "";
	if(next_spot > i && i >= 0){
		word = myArray[i].word;
		return word;
	}
	return constants::TEST_DATA_NON_EXISTANT;
}
int getArrayWord_NumbOccur_At(int i){
	int num_times = 0;
		if(next_spot > i && i >= 0){
			num_times = myArray[i].num_occurances;
			return num_times;
		}
	return constants::FAIL_NO_ARRAY_DATA;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){
	if (!myfstream.is_open()) {return false;}
		string line;
		while (!myfstream.eof()) {
			getline(myfstream, line);
			processLine(line);
		}
		closeFile(myfstream);
		return true;
}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString){
	stringstream ss(myString);
	string tempToken;
	while(getline(ss, tempToken, constants::CHAR_TO_SEARCH_FOR)){
		processToken(tempToken);
	}
}

/*Keep track of how many times each token seen*/
void processToken(std::string &token){
	if (strip_unwanted_chars(token)){
			for (int i=0; i < next_spot; i++){
				string n_string = token;
				string c_string = myArray[i].word;
				toUpper(n_string);
				toUpper(c_string);
				if (n_string == c_string) {
					myArray[i].num_occurances++;
					return;
				}
			}
			myArray[next_spot].word = token;
			myArray[next_spot].num_occurances++;
			next_spot++;
		}
}

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode/* = std::ios_base::in*/){
		myfile.open(myFileName.c_str(), mode);
		if(!myfile.is_open()){
			return false;
		}
		return true;
}

/*iff myfile is open then close it*/
void closeFile(std::fstream& myfile){
	if(myfile.is_open()){
		myfile.close();
	}
}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const std::string &outputfilename){
	ofstream data;
	data.open(outputfilename.c_str(), ios_base::out);
	if(!data.is_open()){
		return constants::FAIL_FILE_DID_NOT_OPEN;
	}
	else if(next_spot == 0){
		return constants::FAIL_NO_ARRAY_DATA;
	}
	for(int i = 0; i < next_spot; i++){
		data << myArray[i].word << " " << myArray[i].num_occurances << endl;
	}
	data.close();
	return constants::SUCCESS;
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so){
	entry place;
		switch(so) {
		case constants::NONE:{
			break;}
		case constants::ASCENDING:{
			bool swap = true;
			while(swap){
					swap = false;
					for(int i = 0; i< next_spot -1; i++) {
							string n_string = myArray[i].word;
							string c_string = myArray[i+1].word;

							toUpper(n_string);
							toUpper(c_string);
							if(n_string > c_string){
								entry place = myArray[i];
								myArray[i] = myArray[i+1];
								myArray[i+1] = place;
								swap = true;
							}
					}
			}
	break;
		}

		case constants::DESCENDING:
			for(int i=0; i< next_spot; i++){
				for(int j=i+1; j<next_spot; j++){
					if(myArray[i].word <myArray[j].word) {
							entry tmp = myArray[i];
							myArray[i] = myArray[j];
							myArray[j]=tmp;
					}
				}
			}
			break;
		case constants::NUMBER_OCCURRENCES:
			for(int i=0; i< next_spot; i++){
				for(int j=i+1; j<next_spot; j++){
					if(myArray[j].num_occurances< myArray[i].num_occurances) {
						entry tmp = myArray[i];
						myArray[i] = myArray[j];
						myArray[j] = tmp;
					}
				}
			}
			break;
		}
}
