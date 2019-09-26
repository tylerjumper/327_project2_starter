/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================
#include "array_functions.h"
#include <iostream>
#include <fstream>
//============================================================================
//	stuff you will need
//============================================================================
//zero out array that tracks words and their occurrences
void clearArray(){

}

//how many unique words are in array
int getArraySize(){
	//int size = my_sizeof(this)/my_sizeof(this[0]);
	return 0;
}

//get data at a particular location
std::string getArrayWordAt(int i){
	return "";
}
int getArrayWord_NumbOccur_At(int i){
	return 0;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){
	if(!myfstream.is_open()){
		return false;
	}

	std::string myfile = "";
	std::ifstream myInputfile;

	myInputfile.open(myfile.c_str(), std::ifstream::in);

	std::string line;

	while(!myInputfile.eof()){
		//getline(myInputFile, line);
		std::cout<<line;
	}

	myInputfile.close();
	return true;
}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString){

}

/*Keep track of how many times each token seen*/
void processToken(std::string &token){
//	if(!token == NULL){
//
//	}

}

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
//bool openFile(std::fstream& myfile, const std::string& myFileName,
//		std::ios_base::openmode mode = std::ios_base::in){
//	return false;
//}

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
	return 0;
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so){

}
