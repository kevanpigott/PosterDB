class PosterFileSystem{
#include <string>
#include <iostream>
#include <cstdlib>
private:
	//BASE_DIRECTORY
	std::string BASE_DIRECTORY;
	
	//for string to commandLine acceptable const* char*
	char* commandStringToChar(std::string str){
		char *str1 = new char[str.size()+1];
		copy(str.begin(), str.end(), str1);
		str1[str.size()] = '\0';
		return str1;
	}
	//directory contains file
public:
	bool fileSystemContainsFile(std::string directory, std::string fileName){
		int i;
		std::string cmd;
		if(!fileName.empty()){
			cmd=("cd "+BASE_DIRECTORY+"/"+directory+"/"+fileName+";ls | grep -c  \""+fileName+"\"");
		}else{
			cmd=("cd "+BASE_DIRECTORY+";ls | grep -c  \""+fileName+"\"");
		}
		const char* command=commandStringToChar(cmd);
		i << system(command);
		if(i==0){return false;}
		else{return true;}
	}

	bool fileSystemContainsDirectory(std::string directory){
		return fileSystemContainsFile(directory,"");
	}
	void writeToFile(std::string Directory, std::string fileName, std::string str){
		std::ofstream file;
		fileName = BASE_DIRECTORY+"/"+Directory+"/"+fileName;
		file.open(fileName);
		file << str;
		file.close();
	}
private:
	void createDirectory(std::string directory){
		const char* command=commandStringToChar("mkdir "+directory);
		system(command);
	}
	//create file given filename and extentsion, and directory
	void createFolder(std::string directory, std::string filename){
		if(fileSystemContainsFile(directory,filename)==true){
			return;
		}else{
			const char* command=commandStringToChar("cd "+directory+"; touch "+filename);
			system(command);
		}
	}
	
	//create base folder
	
	void createBaseDirectory(){
			const char* command=commandStringToChar("mkdir "+BASE_DIRECTORY);
			system(command);
	}
	//create VenueDate folder

	//create list of URLS

public:


//constructor
	PosterFileSystem(){
		BASE_DIRECTORY="BASE";
		createBaseDirectory();
	}
	PosterFileSystem(std::string base){
		BASE_DIRECTORY=base;
		createBaseDirectory();
	}
//add directory
	void addDirectory(std::string Directory){
		createDirectory(BASE_DIRECTORY+"/"+Directory);
	}
	void addFile(std::string Directory, std::string filename){
		createFolder(BASE_DIRECTORY+"/"+Directory,filename);
	}
//List all bands

//containsBand

//containsVenueDate

//containsURL

//addURL

//addVenueDate

//addBand

//LoadBand?
//LoadPoster
};
