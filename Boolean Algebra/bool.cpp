#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include "row.h"

using namespace std;
int main(int argc, char *argv[]){
	
	//take in database file
	//ifstream inFile(argv[1]);
	//ofstream outFile("OUT.txt");

	//find truth table store as matrix

	//seperate input and output into seperate matrixies

	//find 1s in for each output, store complimentary truth table line

	//simplify expression
	row r1 = row(3);
	
	r1.add(1);
	r1.add(2);
	cout << r1.get(0) << r1.get(1) <<r1.get(2);
	//print to output
	//inFile.close();
	//outFile.close();
}
