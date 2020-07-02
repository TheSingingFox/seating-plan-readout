#include<iostream>
#include<fstream>
using namespace std;

int main(){

	//get attendee list
	string file;
	cout << "Which file do you want to use?" << endl;
	getline(cin, file);
	ifstream list;
	list.open (file);

	//get user input wether to display the numbered list or not
	string input;
	string line;
	int count = 1;
	cout << "Do you want to see who was there?" << endl;
	getline(cin, input);
	if (input == "yes") {
		while(getline(list, line)){
				cout << count << "\t" << line << endl;
				count++;
		}
	}
	
	//get user input on the number of seats in a row  and the number of the person of interest
	int rows;
	int num;
	cout << "How long are the rows?" << endl;
	cin >> rows;
	cout << "Who do you want? (number)" << endl;
	cin >> num;
	cout << "They sat as follows: \n\n";

	//reduce num by rows to start a row earlier
	int num2;
	num = num - rows;
	num2 = num;

	//we want 3 rows printed out, therefore we need to loop this thrice
	int j = 1;
	for(int i = 0; i < 3; i++){
		if(num < 0){
			num = num + rows;
			num2 = num;
			i++;
		}
		//just run getline until it is at the desired line
		for(j; j < num2; j++){
			getline(list, line, '\n');
		}
		//if the seat is at a side, we don't want the last seat of the row before to be printed.
		if((num + rows) % rows != 1){
			cout << line; 
		}
		getline(list, line, '\n');
		cout << "\t" << line << "\t";
		getline(list, line, '\n');
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
	list.close();

	return 0;
}
