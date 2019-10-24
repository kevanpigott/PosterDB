#include <iostream> 
#include <unordered_map> 
#include "poster.h"
#include <fstream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <cstdlib>
#include "PosterFileSystem.h"
using namespace std;

//initiates directory /band
string base = "bands";
PosterFileSystem FileSystem = PosterFileSystem(base);

//saves all posters to posterDB.txt in /bands
void savetoMainFile(const unordered_map<string,poster>& DB){
	
	//accumulates all poster.to_strings in map to a string called str
	std::string str="";
	for (auto x : DB){
		poster curPoster = DB.at(x.first);
		str+=curPoster.to_string();
	}

	//writes str to posterDB.txt
	FileSystem.writeToFile("","posterDB.txt",str);
}

void savetoSpecificFile(const unordered_map<string,poster>& DB, string bandNameKey){
	poster curPoster = DB.at(bandNameKey);
	FileSystem.writeToFile(bandNameKey,(bandNameKey+".txt"),curPoster.to_string());
}


//checks directory for folder with the name bandNameKey
bool fileSystemContainsBand(string bandNameKey){
	return FileSystem.fileSystemContainsFile(bandNameKey, "");
}

//builds out the directory assuming there is already a folder "bands" in the same file as posterDB.cpp
void buildFileSystem(const unordered_map<string,poster>& DB){
	for (auto x : DB){
		FileSystem.addDirectory(x.first);
		FileSystem.addFile(x.first,x.first+".txt");
		savetoSpecificFile(DB,x.first);
	}
}

bool DBcontains(const unordered_map<string,poster>& DB, string str){
	for(auto x :DB){
		if(x.first==str){
			return true;
		}
	}
	return false;
}

//unfinished function to turn a .txt into a type poster
/**
poster LoadPoster(const unordered_map<string,poster>& DB, string bandNameKey){
	if(DBcontains(DB,bandNameKey)){
		return DB.at(bandNameKey);
	}else if(fileSystemContainsBand(bandNameKey)){
		return poster();
		//find .txt file and converrt it too type poster
	}else{
		return poster();
	}
}
**/
void list(const unordered_map<string,poster>& DB){
	for (auto x : DB){
		cout << x.second;
	}
}
int main(){
	//creates a pre-defined poster, adds it to the map, uses poster setters
	poster blackkeys("The_Black_Keys","3/12/12","Madison_Square_Garden");
	unordered_map<string,poster> posterDB;
	blackkeys.addPhoto("https://obeygiant.com/images/2015/07/BLACK-KEYS-Portrait-600x800.jpg");
	blackkeys.addposterArtist("Shepard_Fairey");
	posterDB["The_Black_Keys"]=blackkeys;

	string command;

	while(std::cout << "Enter a command:\n", std::cin >> command && (command != "exit")){

		if(command == "addBand"){
			cout<<"\nband name?\n";
			cin>>command;

			//the current issue must be witg the fileSystemContainsBand, either here or in posterFileSystem.h 10/7/19
			if(!fileSystemContainsBand(command)&&(command!="exit")){
				//build poster
				poster newPoster(command,"0/0/00","earth");
				posterDB[command]=newPoster;
			}else{cout<<"band already in system!";}

		}else if(command=="list"){
			list(posterDB);
		}else{
			cout<<"please enter a valid command or type exit";
		}

	}

	
	savetoMainFile(posterDB);
	buildFileSystem(posterDB);
	return 0;
}	


