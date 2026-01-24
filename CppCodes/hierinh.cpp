//Write a C++ program that illustrates hierarchical inheritance
#include<iostream>
using namespace std;
class Animal{
    public:
        string name;
        Animal(const string& animalName) : name(animalName){}
        void eat(){
             cout<<"I am eating"<<endl;
        }
};
class Mammal: public Animal{
    public:
        Mammal(const string& animalName) : Animal(animalName){}
        void giveBirth(){
            cout<<"I give birth to live young"<<endl;
        }
};
class Bird: public Animal{
    public:
        Bird(const string& animalName) : Animal(animalName){}
        void layEggs(){
            cout<<"I lay eggs"<<endl;
        }
};
int main(){
    Mammal myFeistyFeline("Meow");
    cout<<"My cat "<<myFeistyFeline.name<<" is hungry after a long nap"<<endl;
    myFeistyFeline.eat();
    cout<<"She's nursing her adorable kittens, keeping them warm and fed"<<endl;
    myFeistyFeline.giveBirth();
    Bird myChattyParrot("Tote");
    cout<<"My parrot "<<myChattyParrot.name<<" is enjoying a tasty seed snack"<<endl;
    myChattyParrot.eat();
    cout<<"She has laid a beautiful blue egg in her cozy nest"<<endl;
    myChattyParrot.layEggs();
    return 0;
}
