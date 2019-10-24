

#include<iostream>
#include<string>

using namespace std;

int main(){
int i = 10;

int& s =i;
s++;

int* p = &i;
cout<<"\n"<<i;
cout<<"\n"<<p<<"\n";
return 0;
}
