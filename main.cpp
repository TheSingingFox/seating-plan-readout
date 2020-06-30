#include<iostream>
#include<fstream>
using namespace std;

int main(){

	int num;
	int rows;
	int k = 4;
	string line;
	ifstream seats;
	seats.open ("seats");
	
	cout << "How long are the rows?" << endl;
	cin >> rows;
	cout << "Who do you want? (number)" << endl;
	cin >> num;

	num = num - rows;

	for(int i = 0; i < 3; i++){
		if(num < 0){
			num = num + rows;
		} else{
			for(int j = 1; j < num; j++){
				getline(seats, line, '\n');
			}
			if((num + rows) % rows != 1){
				cout << line; 
			}
			getline(seats, line, '\n');
			cout << " " << line << " ";
			getline(seats, line, '\n');
			if((num + rows) % rows != 0){
				cout << line << endl;
			} else{
				cout << endl;
			}
			num = num + rows - k ;
			k++;
		}
	}


	seats.close();

	return 0;
}
