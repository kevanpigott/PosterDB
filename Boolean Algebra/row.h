#include<vector>
using namespace std;

class row{
private:
	vector<int> vec;
	int index;//crrent pointer position
	int size;
public:
	row(const int size){
		int i=0;
		this->index=0;
		this->size = size;
		while(i<size){
			vec[i]=0;
			i++;
			cout << i;
		}
	}

	int set(int i, int val){
		if(i>=size){return 1;} //1 = out of bounds
		vec[i]=val;
		return 0; //good
	}

	int add(int val){
		if(index>=size){return 1;}//bad
		vec[index]=val;
		index++;
		return 0;
	}

	int get(int val){
		return vec[val];
	}
	
};
