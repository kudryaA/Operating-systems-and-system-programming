#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
private:
	int id;
	bool r;
	bool m;
	int t_last_usage = 0;
	string content = "";
public:
	Item(int id, string content) {
		r = 0;
		m = 0;
		this->id = id;
		this->content = content;
	}
	friend class Memory;
	string get_content() {
		return content;
	}
};

class Memory {
private:
	vector<Item*> strotage;
	vector<Item*> disk;
	int size;
	Item* findById(vector<Item*> items, int id) {
		for (int i = 0; i < items.size(); i++) {
			if (items[i] != NULL) {
				if (items[i]->id == id) {
					return items[i];
				}
			}
		}
		return NULL;
	}
	bool contains(vector<Item*> items, int id) {
		for (int i = 0; i < items.size(); i++) {
			if (items[i]!= NULL) {
				if (items[i]->id == id) {
					return true;
				}
			}
		}
		return false;
	}
	int t = 0;
	int current;
	int tau;

public: 
	Memory(int n, vector<Item*> disk, double tau) {
		vector<Item*> strotage(n);
		this->disk = disk;
		this->strotage = strotage;
		size = n;
		this->tau = tau;
	}
	~Memory() {
		strotage.clear();
	}

	bool add(Item* item) {
		if (contains(disk, item->id)) {
			return false;
		}
		disk.push_back(item);
		return true;
	}

	string read(int id) {
		if (contains(strotage, id)) {
			t++;
			for (int i = 0; i < strotage.size(); i++) {
				if (strotage[i]->id == id) {
					strotage[i]->r = 1;
					strotage[i]->t_last_usage = t;
					return strotage[i]->content;
				}
			}
		}
		else {
			t++;
			for (int i = 0; i < size; i++) {
				if (strotage[i] == NULL) {
					strotage[i] = findById(disk, id);
					return read(id);
				}
			}

			while (true) {
				t++;
				if (strotage[current]->r) {
					strotage[current]->r = false;
					current++;
				}
				else {
					if (t - strotage[current]->t_last_usage < tau) {
						current++;
					}
					else {
						if (strotage[current]->m) {
							strotage[current]->m = 0;
							current++;
						}
						else {
							strotage[current] = findById(disk, id);
							return read(id);
						}
					}
				}
				current = current % size;
			}
		}
	}
};

int main()
{
	vector<Item*> disk;
	disk.push_back(new Item(1,"Content1"));
	disk.push_back(new Item(2, "Content2"));
	disk.push_back(new Item(3, "Content3"));
	disk.push_back(new Item(4, "Content4"));
	Memory memory(3, disk, 5);
	cout << memory.read(1) << endl;
	cout << memory.read(2) << endl;
	cout << memory.read(3) << endl;
	cout << memory.read(4) << endl;
	cout << memory.read(2) << endl;
	cout << memory.read(3) << endl;
}