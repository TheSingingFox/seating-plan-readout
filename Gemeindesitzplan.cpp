#include<iostream>
//#include "seats.h"
using namespace std;

int main(){

	int num;
	int rows;
	
	string seats[][2] = {
		{"1", "Jim"},
		{"2", "Joe"},
		{"3", "Jayden"},
		{"4", "James"},
		{"5", "Joan"},
		{"6", "Joline"},
		{"7", "Jasper"},
		{"8", "Jannis"},
		{"9", "Josiah"},
		{"10"," Jack"},
		{"11", "Jill"},
		{"12", "John"},
		{"13", "Jane"},
		{"14", "Jeanette"},
		{"15", "Joshua"},
		{"16", "Jennifer"},
		{"17", "Juliet"},
		{"18", "Joanne"},
		{"19", "Josephine"},
		{"20", "Jeremiah"},
		{"21", "Jordan"},
		{"22", "Joseph"},
		{"23", "Jupiter"},
		{"24", "Jerry"}
	};

	cout << "How long are the rows?" << endl;
	cin >> rows;
	cout << "Who do you want? (number)" << endl;
	cin >> num;

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
