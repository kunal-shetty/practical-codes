#include<iostream>
#include<ctime>
using namespace std;
int main(){
	cout<<"Welcome to Dice Rolling Simulator !!\n\n";
	srand(time(NULL));
	while(1){
		string choice;
		cout<<"Roll the Die? y/n : ";
		cin>>choice;
		if(choice == "y" || choice == "Y"){
			cout<<"You Rolled a "<<(rand() % 6 + 1)<<endl;
		}
		else if(choice == "n" || choice == "N"){
			cout<<"Thanks for playing!!"<<endl;
			return 0;
		}
		else{
			cout<<"Invalid choice, try again!"<<endl;
		}
		cout<<"___________________________________\n";
	}
	return 0;
}