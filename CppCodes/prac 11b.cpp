#include<iostream>
using namespace std;
class Media {
	protected:
	string title;
	bool isIssued;
	public:
	Media(string t) {
		title = t;
		isIssued = false;
	}
	virtual void addNewItem() = 0;
	virtual void issueItem() {
		if(isIssued)
		cout<<"Item already issued"<<endl;
		else{
			isIssued = true;
			cout<<"Item Issued : "<<title<<endl;
		}
	}
	virtual void returnItem(){
		if(isIssued){
			isIssued = false;
			cout<<"Item Returned : "<<title<<endl;
		}
		else
		cout<<"Item was not issued"<<endl;
	}
};
class Book : public Media{
	public:
	Book(string t) : Media(t){}
	void addNewItem() override{
		cout<<"Adding new Book : "<<title<<endl;
	}
	void issueItem() override{
		cout<<"Issuing Book : "<<title<<endl;
		Media::issueItem();
	}
	void returnItem() override{
		cout<<"Returning Book : "<<title<<endl;
		Media::returnItem();
	}
};
class Tape : public Media{
	public:
	Tape(string t) : Media(t){}
	void addNewItem() override{
		cout<<"Adding new Tape : "<<title<<endl;
	}
	void issueItem() override{
		cout<<"Issuing Tape : "<<title<<endl;
		Media::issueItem();
	}
	void returnItem() override{
		cout<<"Returning Tape : "<<title<<endl;
		Media::returnItem();
	}
};
int main(){
	Media *media;
	Book b("C++ Progrmming");
	Tape t("Jazz Music");
	media = &b;
	media->addNewItem(); cout<<endl;
	media->issueItem(); cout<<endl;
	media->returnItem(); cout<<endl;
	media = &t;
	media->addNewItem(); cout<<endl;
	media->issueItem(); cout<<endl;
	media->returnItem(); cout<<endl;
	return 0;
}
