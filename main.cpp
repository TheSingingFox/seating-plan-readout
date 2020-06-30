#include<iostream>
#include<fstream>
#include"seats.h"
using namespace std;

int main(){

	int num;
	int rows;
	
	cout << "How long are the rows?" << endl;
	cin >> rows;
	cout << "Who do you want? (number)" << endl;
	cin >> num;

	string *seats;

	seats = list();

	num = num - rows;

	int len = *(&seats + 1) - seats;

	for(int i = 0; i < 3; i++){
		if(num < 0){
			num = num + rows;
		} else if(num > len){
			i++;
		} else{
			if((num + rows) % rows != 1){
				cout << seats[num - 2][1];
			}
			cout << " " << seats[num - 1][1] << " ";
			if((num + rows) % rows != 0){
				cout << seats[num][1] << endl;
			} else{
				cout << endl;
			}
			num = num + rows;
		}
	}

	return 0;
}
