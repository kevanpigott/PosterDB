#include <iostream> 
#include <unordered_map> 
#include "poster.h"
#include <fstream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <cstdlib>

using namespace std; 
//int addtomap(unordered_map map, poster post){
//	map.insert<{post.getBandName,"11/7/97"}>
//return 0;
//}

char* commandStringToChar(string str){
		char *str1 = new char[str.size()+1];
		copy(str.begin(), str.end(), str1);
		str1[str.size()] = '\0';
		return str1;
}

//save to a file fileName DO NOT INCLUDE .TXT in FILE NAME!
//WARNING THIS SAVES ALL BANDS AND POSTERS TO ALL TXT PLEASE FIX
void savetoFile(const unordered_map<string,poster>& DB, string fileName){
	ofstream file;
	file.open(fileName+".txt");
	
	for (auto x : DB){
		file << x.second;
	}
	
	file.close();
}
void savetoFile(const unordered_map<string,poster>& DB){
	savetoFile(DB,"posterDB");
}

void savetoSpecificFile(const unordered_map<string,poster>& DB, string bandNameKey){
	ofstream file;
	string fileName = "bands/"+bandNameKey+"/"+bandNameKey+".txt";
	file.open(fileName);
	poster curPoster = DB.at(bandNameKey);
	file << curPoster;
	file.close();
}


//checks directory for folder with the name bandNameKey
bool fileSystemContainsBand(string bandNameKey){
	int i;
	const char* command=commandStringToChar("cd bands;ls | grep -c  \""+bandNameKey+"\"");
	i << system(command);
	if(i==0){return false;}
	else{return true;}
}

//builds out the directory assuming there is already a folder "bands" in the same file as posterDB.cpp
void buildFileSystem(const unordered_map<string,poster>& DB){
	for (auto x : DB){
		
		//if the filesystem already contains folder with the bandKeyName (x.first) simply cd into it and create a .txt
		if(fileSystemContainsBand(x.first)==true){
			const char* command=commandStringToChar("cd bands;cd "+x.first+";touch "+x.first+".txt");
			//savetoFile(DB,("bands/"+x.first+"/"+x.first));
			savetoSpecificFile(DB,x.first);
		}else{//else create a folder bandKeyName and add a .txt
			const char* command=commandStringToChar("cd bands; mkdir "+x.first+";cd "+x.first+";touch "+x.first+".txt");
			system(command);
			savetoSpecificFile(DB,x.first);
			//savetoFile(DB,("bands/"+x.first+"/"+x.first));
		}
	}
}
/**
int stringToInt(string str){
	return (int)commandStringToChar(str);
}
**/
bool DBcontains(const unordered_map<string,poster>& DB, string str){
	for(auto x :DB){
		if(x.first==str){
			return true;
		}
	}
	return false;
}
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
int main(){
	poster blackkeys("The_Black_Keys","3/12/12","Madison_Square_Garden");
	unordered_map<string,poster> posterDB;
	blackkeys.addPhoto("https://obeygiant.com/images/2015/07/BLACK-KEYS-Portrait-600x800.jpg");
	blackkeys.addposterArtist("Shepard_Fairey");
	posterDB["The_Black_Keys"]=blackkeys;
	string command;

	while(std::cout << "Enter a command:\n", std::cin >> command && (command != "exit")){

		if(command == "addBand"/**||"addBand"||"ADD BAND"**/){
				cout<<"\nband name?\n";
				cin>>command;
				if(!fileSystemContainsBand(command)&&(command!="exit")){
				//build poster
				poster newPoster(command,"0/0/00","earth");
				posterDB[command]=newPoster;
				}else{
				cout<<"band already in system!";
				}
		}else if(command=="list"){
			for (auto x : posterDB){
				cout << x.second;
			}
		}else{
			cout<<"please enter a valid command or type exit";
		}

	}

	
	savetoFile(posterDB);
	buildFileSystem(posterDB);
	//cout << fileSystemContainsBand("Black_Keys");
	return 0;
}	

//https://expressobeans.com/
