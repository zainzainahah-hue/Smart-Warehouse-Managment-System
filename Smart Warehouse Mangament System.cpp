// Smart Warehouse Mangament System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<algorithm>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class product  //base class
{
// private member 
private:
	int id;
	string name;
	double price;
	int quantity;
public:
	product() //default constructor
	{
		id = 0;
		name= "";
		price = 0;
		 quantity = 0;
	}
	product(int i, string n, double p, int q)//constructor
	{
		id = i;
		name = n;
		price = p;
		quantity = q;
	}
	void setId(int id)
	{
		
		cout << "Enter the new  id :" << endl;
		cin >> id;
    }
	int getId()
	{
		return id;
	}
	void setname(string name)
	{
		cout << "Enter the name :" << endl;
		cin >> name;
	}
	string getName()
	{
		return name;
	}
	void setquantity(int quantiy)
	{
		cout << "Enter the quantity :" << endl;
			cin >> quantity;
	}
	int getquantity()
	{
		return quantity;

	}
	void setItem() {
		quantity = quantity - 1;
	}
	


	void setprice()
	{
		cout << "Enter the price:" << endl;
	}
	double getprice()
	{
		return price;
	}
	void display()//print function
	{
		cout << "the Id : " << id << endl;
		
		cout << "the name :" << name << endl;
		cout << "the price :" << price << endl;
		cout << "the quantity :" << quantity << endl;
	}

};
class Node
{
public:
	product p;
	Node* next;
	
};
class Warehouse
{
private:
	Node* head;
public:
	Warehouse()
	{
		head = NULL;
	}
	void addProduct(product newp)
	{
		Node* newNode = new Node();
		newNode->p = newp;
		newNode->next = head;
		head = newNode;

	}

	void displayAll() {
		Node* temp = head;
		while (temp != NULL)
		{
			temp->p.display();
			temp = temp->next;

		}
		cout << endl;

	}
	bool search(int id)
	{
		bool t = true;
		Node* temp = head;;
		while (temp != NULL)
		{
			if (temp->p.getId() == id)
			{
				temp->p.display();
				return t;
				temp = temp->next;
			}


		}
		if (!t)
			return false;
	}
	bool Delete(int id)
	{
		Node* delPtr = head;
		Node* pre = NULL;
		if (head == NULL)
		{
			return false;
		}
		else if (head->p.getId() == id) {
			head = head->next;
			delete delPtr;
			return true;
		}
		else {
			while (delPtr != NULL&&delPtr->p.getId()!=id) {
				pre = delPtr;
				delPtr = delPtr->next;
			}
			if (delPtr == NULL)
			{
				return false;
		}
			pre->next = delPtr->next;
			delete delPtr;
			return true;
		}
	}
	void Remove(string item) {
		Node* temp = head;
		if (head == NULL) {
			cout << "no item here" << endl;
			return;
		}

		while (temp != NULL) {
			if (temp->p.getName() == item) {
				temp->p.setItem();  

				if (temp->p.getquantity() <= 0) { // أضمن من == 0
					Delete(temp->p.getId());
					return; // 🟢 اخرج فوراً
				}

				cout << "Quantity updated for: " << item << endl;
				return; // 🟢 اخرج فوراً عشان ما يطبع not found
			}
			temp = temp->next; // 🟢 لازم تكون هون بنهاية الـ while
		}

		cout << "item not found" << endl;
	}

	void lowStackAlret(int  limit)
	{
		bool found = false;
		Node* temp = head;
		while (temp != NULL) {


			if (temp->p.getquantity() < limit) {
	cout << "warning  " <<"		" << "the name :" << temp->p.getName() <<"  " << "the id :" << temp->p.getId() <<"		"<< "the quantity :" << temp->p.getquantity() << endl;
				found = true;
			}
			

			temp = temp->next;
		}
		if (!found)
		{
			cout << "we dosent need anything" << endl;
		}
	}
};
int  main()
{
	int id;
	 string item;
	int limit = 15;
	Warehouse w;
	product p1(101,"laptop",1200,10);
	product p2(102,"mouse",200,15);
	product p3 (103, "keyboard", 300, 25);
	w.addProduct(p1);
	w.addProduct(p2);
	w.addProduct(p3);
	cout << " ----OUR PRODUCTS ARE---- :" << endl;
	w.displayAll();
	
	cout << "enter your id  do yo want to remove :" << endl;
	cin >> id;
	
	if (w.Delete(id)) {
		cout << "the item : " << id<<"  " << "delete successfully " << endl;
	}
	else
		cout << "item not found" << endl;
	cout << "enter the item  " <<"		"<<" please write the item matched with letter and space" << endl;
	cin.clear();
	cin.ignore(100,'\n');
	getline(cin, item);
	for (int i = 0; i < item.length(); i++) {
		item[i] = tolower(item[i]);
	}
	w.Remove(item);
	
	w.lowStackAlret(limit);
	cout << "final stock" << endl;
	w.displayAll();
	system("pause");

}







