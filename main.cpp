#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


template <typename T>
class Inventory {
private:
	T* pItems_;
	int capacity_;
	int size_ = 0;

public:
	Inventory(int capacity = 10) :capacity_(capacity) {
		if (capacity <= 0) {
			capacity_ = 1;
		}
		pItems_ = new T[capacity_];
	}
	
	~Inventory() {
		delete[] pItems_;
		pItems_ = nullptr;
	}
	void AddItem(const T& newItem) {
		if (size_ < capacity_) {
			pItems_[size_] = newItem;
			size_++;
		}
		else{
			cout << "인벤토리 확장 중 (현재 용량: " << capacity_ << " -> " << capacity_ * 2 << ")" << endl;
			Inventory<T> temp(2 * capacity_);

			for (int i = 0; i < size_; ++i) {
				temp.pItems_[i] = pItems_[i];
			}
			temp.size_ = this->size_; 

			swap(this->pItems_, temp.pItems_);
			swap(this->capacity_, temp.capacity_);
			swap(this->size_, temp.size_);

			// 확장 후 아이템 추가
			pItems_[size_] = newItem;
			size_++;
		}
	}
	void RemoveLastItem() {
		if (size_ <= 0) {
			cout << "인벤토리가 비어있습니다!" << endl;
		}
		else {
			size_--;
		}

	}
	int GetSize() const {
		return size_;
	}
	int GetCapacity() const
	{
		return capacity_;
	}
	void PrintAllItems() const {
		for (int i = 0; i < size_; i++) {
			cout << "아이템 이름: "<< pItems_[i].getName() << " 가격: " << pItems_[i].getPrice() << "원" << endl;
		}
	}

};
class Item {
public:
	void setPrice(int price) {Price = price;}
	void setName(string name) {Name = name;}
	int getPrice() const {return Price;}
	string getName() const {return Name;}

private:
	string Name;
	int Price;
};


int main() {
	Inventory<Item> Bag;	// capacity = 10인 bag 객체 생성
	Item item1;
	item1.setName("하이랜더");
	item1.setPrice(2900);
	Item item2;
	item2.setName("아다만티움 보닌");
	item2.setPrice(4200);
	Item item3;
	item3.setName("장팔사모");
	item3.setPrice(11000);

	Bag.AddItem(item1);		//
	Bag.AddItem(item2);
	Bag.AddItem(item3);
	Bag.AddItem(item3);
	Bag.AddItem(item3);
	Bag.AddItem(item3);
	Bag.AddItem(item3);
	Bag.AddItem(item3);
	Bag.AddItem(item3);
	Bag.AddItem(item3);
	Bag.PrintAllItems();
	Bag.AddItem(item3);
	Bag.PrintAllItems();
	

	return 0;
}
