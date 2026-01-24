#include<iostream>
using namespace std;
class Student{
	protected:
	int rollNo;
	public:
	void setRollNo(int r){
		rollNo = r;
	}
	void displayRollNo() const{
		cout<<"Roll No : "<<rollNo<<endl;
	}
};
class Test:virtual public Student{
	protected:
	int subjectScores[5];
	int totalTestScore = 0;
	public:
	void setSubjectScores(){
		cout<<"Enter scores for 5 subjects : ";
		for(int i = 0; i < 5; i++){
			cin>>subjectScores[i];
			totalTestScore += subjectScores[i];
		}
	}
	void displayTestScores() const{
		cout<<"Scores in subjects : ";
		for(int i = 0; i < 5; i++){
			cout<<subjectScores[i]<<" ";
		}
		cout<<"\nTotal Test Score : "<<totalTestScore<<endl;
	}
};
class Sports:virtual public Student{
	protected:
	int sportsScore = 0;
	public:
	void setSportsScore(){
		cout<<"Enter score in Sports : ";
		cin>>sportsScore;
	}
	void displaySportsScore() const{
		cout<<"Sports Score : "<<sportsScore<<endl;
	}
};
class Result:public Test,public Sports{
	public:
	void displayFinalResult() const{
		int totalScore = totalTestScore + sportsScore;
		displayRollNo();
		displayTestScores();
		displaySportsScore();
		cout<<"Total Score : "<<totalScore<<endl;
	}
};
int main(){
	Result s1;
	int rollNo;
	cout<<"Enter Roll Number : ";
	cin>>rollNo;
	s1.setRollNo(rollNo);
	s1.setSubjectScores();
	s1.setSportsScore();
	s1.displayFinalResult();
	return 0;
}
