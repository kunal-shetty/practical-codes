#include<iostream>
using namespace std;
class Distance {
	private:
    int meters, centimeters;
	public:
    Distance(int m, int cm) : meters(m), centimeters(cm) {
        convert();
    }
    void convert() {
        while (1) {
            if (centimeters < 100) break;
            meters++;
            centimeters -= 100;
        }
	}
    Distance operator-(const Distance &d) {
        Distance diff(0, 0);
        diff.meters = meters - d.meters;
        diff.centimeters = centimeters - d.centimeters;
        if (diff.centimeters < 0) {
            diff.meters--;
            diff.centimeters += 100;
        }
        return diff;
    }
    void display() const {
        cout << meters << " Meters " << centimeters << " Centimeters" << endl;
    }
};
int main() {
    Distance d1(9, 10), d2(5, 90);
    Distance d3 = d1 - d2; 
    cout << "Distance after subtraction: ";
    d3.display();
    return 0;
}
