#include<iostream>
#include<fstream>
using namespace std;

int main(){

	//the first num is there to get the desired seat
	int num;
	//the second num is there, because getline() searches the external document line by line and needs to be realigned
	int num2;
	//to get the number of seats in a row
	int rows;
	int j = 1;
	string input;
	string line;
	//get a numbered list of attendees from the file "liste"
	ifstream list;
	list.open ("liste");
	//get an unnumbered list from "seats"
	ifstream seats;
	seats.open ("seats");

	//get user input wether to display the numbered list or not
	cout << "Do you want to see who was there?" << endl;
	getline(cin, input);
	if (input == "yes") {
		while(getline(list, line)){
				cout << line << endl;
		}
	}
	
	//fill out num and row with user input
	cout << "How long are the rows?" << endl;
	cin >> rows;
	cout << "Who do you want? (number)" << endl;
	cin >> num;
	cout << "They sat as follows: \n\n";

	//reduce num by rows to start a row earlier
	num = num - rows;
	num2 = num;

	//we want 3 rows printed out, therefore we need to loop this thrice
	for(int i = 0; i < 3; i++){
		if(num < 0){
			num = num + rows;
			num2 = num;
			i++;
		}
		//just run getline until it is at the desired line
		for(j; j < num2; j++){
			getline(seats, line, '\n');
		}
		//if the seat is at a side, we don't want the last seat of the row before to be printed.
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
		//go one row forward
		num = num + rows;
		//realign getline
		num2 = num2 + rows - 2;
	}

	//clean up behind yourself
	seats.close();

	return 0;
}
