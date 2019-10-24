class poster
#include <string>
#include <iostream>
{
	private:
	std::string this_uploader, this_ip, this_date, this_bandName, this_venue, this_posterArtist, this_photoURL;
	//check if url is already in url list
	bool containsURL(std::string newURL){
		return this_photoURL==newURL;
	}
	public:
	//get functions
	//constructors

	poster(){};
	poster(std::string bandName, std::string date, std::string venue){
		this_bandName=bandName;
		this_date=date;
		this_venue=venue;
	}
	std::string getphotoURL(){
		if(this_photoURL.empty()){
			return "No Photos! you can help by adding one.";
		}else{
		return this_photoURL;
		}
	}
	std::string to_string(){
		std::string str;
		str+="Band: "+this_bandName+", Date: "+this_date+", Venue: "+this_venue+", Poster Artist: "+this_posterArtist+"\n";
		str+="	"+getphotoURL()+"\n";
		return str;
	}
	std::string getBandName(){ return this_bandName+" "+this_date; }
	operator char*(){
		std::string str = to_string();
		char *str1 = new char[str.size()+1];
		std::copy(str.begin(), str.end(), str1);
		str1[str.size()] = '\0';
		return str1;
	}
	
	
	void addPhoto(std::string newURL){
		if(!containsURL(newURL)){
			if(this_photoURL.empty())
				this_photoURL=newURL;
			else{
				this_photoURL+=newURL+"\n";
			}
		}
	}

	void addposterArtist(std::string name){
		this_posterArtist=name;
	};
	
};
