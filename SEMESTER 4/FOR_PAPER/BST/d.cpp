#include<iostream>
using namespace std;
int main(){
	char what[80];
	int p=0;
	cin.get(what[p]);
	while(what[p] !='\n'){
		cin.get(what[++p]);
	}
	for(p -=2 ;p>=0;cout.put(what[p--]));
}
