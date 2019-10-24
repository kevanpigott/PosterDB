#include<string>
#include<iomanip>
#include<iostream>
using namespace std;

int length(char* str){
	int i = 0; 
	while (str[i] != '\0'){ 
		i++; 
	} 
	return i;
}
char* stringToChar(string str){
	char *str1 = new char[str.size()+1];
	copy(str.begin(), str.end(), str1);
	str1[str.size()] = '\0';
	return str1;
}

string toLowerCase(string str){
	char* str1=stringToChar(str);
	length(str1);
	int i=0;
	while(i<length(str1)){
		int asciinum=int(str1[i]);
		if(	(asciinum<=90) && (asciinum>=65)	){
			str1[i]=char(asciinum+32);
		}else if(	(asciinum>122) || (asciinum<97)	){
			str1[i]='#';
		}
		i++;
	}
	return str1;
}



string to_hex(int to_convert){
    string result;
    stringstream ss;
    ss << std::hex <<to_convert;
    ss >> result;
    return result;
}
string to_dec(int to_convert){
    string result;
    stringstream ss;
    ss << std::dec <<to_convert;
    ss >> result;
    return result;
}
string decrypt(string str){
	char* str1=stringToChar(toLowerCase(str));
	length(str1);
	string str2=" ";
	string cur=" ";
	string spacer(1,str[0]);
	int i=0;
	while(i<length(str1)){
		cout<<"while 1";
		//if (	(int(str[i])>122)||(int(str[i])<97)	){
		//	str[i]='.';
		//	cout<<"if 1\n";
		//}else{
		cout<<"else 1\n";
			if(str[i]==str[0]){
				i++;
				cout<<"if 2\n";
				while(str[i]!=str[0]){
				//int asciinum=int(str1[i]);
				//int x = int(to_dec(str1[i]));
				//str2.append(to_string(x));
				str2.append("X");
				i++;
				cout<<"while 2\n";
				}
			}
		//}
		
		i++;
	}
	return str2;
}

string encrypt(string str){
	char* str1=stringToChar(toLowerCase(str));
	length(str1);
	string str2="@";
	string spacer(1,str[0]);
	int i=0;
	while(i<length(str1)){
		int asciinum=int(str1[i]);
		str2.append(to_hex(asciinum));
		
		str2.append(spacer);
		i++;
	}
	return str2;
	
}



int main(){
	string str="@68H65H6cH6cH6fH23H77H6fH72H6cH64H23H";
	cout<<"Given that @68H65H6cH6cH6fH23H77H6fH72H6cH64H23H = HeLlo WoRlD!, decrypt : \n";
	//cout<<toLowerCase("HeLlO WoRlD!");
	cout<<encrypt("HeLlO WoRlD!");
	cout<<"\n";
	cout<<decrypt(str);
	return 0;
}
