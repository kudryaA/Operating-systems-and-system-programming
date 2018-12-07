#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class Item {
    public:
        string name;
        int count;
        double cost;

        void read_file(ifstream& in) {
            in >> name;
            in >> count;
            in >> cost;
        }

        void write_file(ofstream& on) {
            on << name << endl;
            on << count << endl;
            on << cost << endl;
        }

        void print() {
            cout << "Name: " << name << endl;
            cout << "Count: " << count << endl;
            cout << "Price: " << cost << endl;
        }
        
};

int main() {
    int n = 5;
    vector<Item> mas;
    ifstream in("list.txt");
    for (int i = 0; i < n; i++) {
        Item item;
        item.read_file(in);
        mas.push_back(item);
        item.print();
    }
    in.close();

    Item buf = mas[2];
    mas[2] = mas[3];
    mas[3] = buf;

    ofstream on("list.txt");
    for (int i = 0; i < n; i++) {
        mas[i].write_file(on);
        mas[i].print();
    }
    on.close();

    return 0;
}