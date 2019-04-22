#include <iostream>
#include <string>
#include <time.h>
#include <list>
#include <iterator>
#include <conio.h>
#include <fstream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
ifstream ifs;
ofstream ofs;
class Date{
	private:
		int day;
		int month;
		int year;
	public:
		void setDay(int d){
			day = d;
		}
		void setMonth(int m){
			month = m;
		}
		void setYear(int y){
			year = y;
		}
		int getDay(){
			return day;
		}
		int getMonth(){
			return month;
		}
		int getYear(){
			return year;
		}
		void show(){
			cout<<day<<"-"<<month<<"-"<<year;
		}
		
		
		
				
};

class Item {
	private :
		string name;
		string catagory;
		float price;
		int quantity;
		Date expDate;
	public :
		void setDate(Date d){
			expDate =d;
		}
		Date getDate(){
			return expDate;
		}

		
		void setName(string n) {
			name = n;
		}
		string getName() {
			return name;
		}
		void setCatagory(string c) {
			catagory = c;
		}
		string getCatagory() {
			return catagory;
		}
		void setPrice(float p) {
			price = p;
		}
		float getPrice() {
			return price;
		}
		void setQuantity(int q) {
			quantity = q;
		}
		int getQuantity() {
			return quantity;
		}
}; 

class Fruit : public Item {


};
class Dairy : public Item {

};
class Meat : public Item {

};
class Vegetable : public Item {

		
};
class Drinks : public Item {

		
};
class Food : public Item {

		
};
class Inventory {
	private :
		list<Item> itemList;
	public :
		void add(Item item) {
			list<Item>::iterator it;
			for(it = itemList.begin(); it != itemList.end(); ++it) 
				if((*it).getName() == item.getName()) {
					(*it).setQuantity((*it).getQuantity() + item.getQuantity());
						return;
				}
				ofs.open("itemstore.txt", ios::binary);
				ofs.write((char *)&item, sizeof(item));
				ofs.close();
			itemList.push_front(item);
		}
		list<Item> showList() {
//			Item item;
//			list<Item>::iterator it;
//			cout<<"Name"<<"\t"<<"Category"<<"\t\t"<<"Quantity"<<"\t\t"<<"Price"<<"\t\t"<<"Date"<<endl;
//			for(it = itemList.begin(); it!=itemList.end(); ++it) {
//				Date d = item.getDate();
//				cout<<item.getName()<<"\t"<<item.getCatagory()<<"\t"<<item.getQuantity()<<"\t"<<item.getPrice()<<"\t";
//				d.show();	
//			}
			return itemList;

			
		}
		Item searchByName(string name) {
			Item item;
			list<Item>::iterator it;
			for(it = itemList.begin(); it != itemList.end(); ++it) {
				if((*it).getName() == name) {
					item = *it;
					
				//	return *it;
				}
		}
		
//		ifs.open("itemstore.txt", ios::binary);
//		while(ifs.read((char *)&item, sizeof(item))){
//			if(item.getName() == name) {
//				return item;
//			}
//		}
//		ifs.close();
			return item;
		}
		list<Item> searchByCatagory(string catagory) {
			Item item;
			list<Item> listItem;
			list<Item>::iterator it;
			for(it = itemList.begin(); it != itemList.end(); ++it) {
				if((*it).getCatagory() == catagory) {
					item = *it;
					listItem.push_back(item);
				}
			}
			
			return listItem;
		}
		//Remove item on the basis of Name.
		bool removeItem(Item item) {
			list<Item>::iterator it;
			for(it = itemList.begin(); it != itemList.end(); ++it) {
				if((*it).getName() == item.getName()) {
					itemList.erase(it);	
					return true;			
				}
			}
			return false;		
		}
		//Update item on the basis of name...
		bool updateItem(Item item,string pre_name){
			list<Item>::iterator it;
			for(it = itemList.begin(); it != itemList.end(); ++it) {
				if((*it).getName() == pre_name) {
										
					(*it).setName(item.getName());
					(*it).setPrice(item.getPrice());
					(*it).setQuantity(item.getQuantity());
						
					return true;								
				}
			}
		return false;
	}
	
	bool sellItem(Item item){
		list<Item>::iterator it;
			for(it = itemList.begin(); it != itemList.end(); ++it) {
				if((*it).getName() == item.getName()) {			
					int prev_qt = (*it).getQuantity();
					//Validate for quantity test...
					if(prev_qt >= item.getQuantity()){
						(*it).setQuantity(prev_qt - item.getQuantity());
						return true;													
					}
					else{
						cout<<"Stock Does not have that much quantity...";						
						return false;
						getch();
					}						
				}
			}
			//If the item does not match any item in list, it reuturn false.
			return false;		
	}
	bool returnItem(Item item){
		list<Item>::iterator it;
			for(it = itemList.begin(); it != itemList.end(); ++it) {
				if((*it).getName() == item.getName()) {
					
					int prev_qt = (*it).getQuantity();
					//Add the returned quantity itemms.
					(*it).setQuantity(prev_qt + item.getQuantity());
					return true;													
											
				}
			}
			//If the item does not match any item in list, it reuturn false.
			return false;	
	}
	
};






//Decleration of methods...
void menu(Inventory inventory);
void search(Inventory inventory);
void addNewItem(Inventory inventory);
void updateItem(Inventory inventory);
void sellItemMenu(Inventory inventory);
void returnItemMenu(Inventory inventory);

int main() {
	cout<<"====================Welcome To Inventory System================="<<endl;
	getch();
	Inventory inventory;
	menu(inventory);		
	return 0;
}

void sellItemMenu(Inventory inventory){
	system("cls");
	list<Item> itemList = inventory.showList();
	list<Item>::iterator it;
	cout<<"============List of Available Items==========="<<endl;
	
	for(it = itemList.begin(); it!=itemList.end(); ++it) {
		
		cout<<"Name: "<<(*it).getName()<<endl;
		cout<<"Category: "<<(*it).getCatagory()<<endl;
		cout<<"Quantity: "<<(*it).getQuantity()<<endl;
		cout<<"Price: "<<(*it).getPrice()<<endl;
		cout<<"Date: ";(*it).getDate().show();
		cout<<endl;
		cout<<"========================================="<<endl;	
	}
	cout<<"\n"<<"=========================================================="<<endl;
	
	
	string i_name;
	cout<<"Enter Item Name to Sell: ";
	cin>>i_name;
	
	int i_qty;
	cout<<"How Many Items You Want To Sell: ";
	cin>>i_qty;
	Item i_sell;
	i_sell.setName(i_name);
	i_sell.setQuantity(i_qty);
	
	bool ret = inventory.sellItem(i_sell);
	if(ret){
		cout<<"Item Sold!"<<endl;
		
		
	}else{
		cout<<"Item Does Not Found!"<<endl;
	}
	getch();
	menu(inventory);
	
	
	
	
}
void returnItemMenu(Inventory inventory){
	string i_name;
	cout<<"Enter Item Name to Return: ";
	cin>>i_name;
	
	int i_qty;
	cout<<"How Many Items You Want To Return: ";
	cin>>i_qty;
	Item i_ret;
	i_ret.setName(i_name);
	i_ret.setQuantity(i_qty);
	
	bool ret =inventory.returnItem(i_ret);
	if(ret){
		cout<<"Item Returned Success!"<<endl;
		
	}else{
		cout<<"Item Does Not Found!"<<endl;
	}
	getch();
	menu(inventory);
}


void search(Inventory inventory) {
	system("cls");
	cout<<"====Search===="<<endl;
	cout<<"\n1-Search By Name"<<endl;
	cout<<"2-Search By Catagory"<<endl;
	cout<<"3-Go Back To Menu";
	int option;
	cout<<"Select Option : ";
	cin>>option;
	if(option == 1) {
		cout<<"\nEnter Item Name : ";
		string name;
		cin>>name;
		Item item = inventory.searchByName(name);
		if(item.getName() == name) {
			//work to be done
			Date d = item.getDate();
			
			cout<<"=============DETAILS==============="<<endl;			
			cout<<"Name:"<<item.getName()<<endl;
			cout<<"Category:"<<item.getCatagory()<<endl;
			cout<<"Quantity:"<<item.getQuantity()<<endl;
			cout<<"Price:"<<item.getPrice()<<endl;
			cout<<"Date:";item.getDate().show();
			
			
			getch();
			search(inventory);
		}
		else {
			//work to be done
		//	throw "Item is out of stock!";
			cout<<"Item does not exist!";
			getch();
			search(inventory);
		}
		
	}
	else if(option == 2) {
		//work to be done
		int idx;
		cout<<"========================================"<<endl;
		cout<<"1-Fruits"<<endl;
		cout<<"2-Food"<<endl;
		cout<<"3-Drinks"<<endl;
		cout<<"4-Vegetable"<<endl;
		cout<<"5-Meat"<<endl;
		cout<<"6-Dairy"<<endl;
		cout<<"========================================="<<endl;
		
		cout<<"Enter Choice: ";
		cin >> idx;
		string ITEMS[6] = {"Fruits","Food","Drinks","Vegetable","Meat","Dairy"};
		
		idx = (idx - 1)%6;
		list<Item> items = inventory.searchByCatagory(ITEMS[idx]);
		if(items.size()==0) {
			cout<<"Item Does not Exist";
			getch();
			search(inventory);
		}
		else {
			list<Item>::iterator it;
			cout<<"=============DETAILS==============="<<endl;
			cout<<endl;			
			for(it = items.begin(); it != items.end(); ++it) {							
				cout<<"Name:"<<(*it).getName()<<endl;
				cout<<"Category:"<<(*it).getCatagory()<<endl;
				cout<<"Quantity:"<<(*it).getQuantity()<<endl;
				cout<<"Price:"<<(*it).getPrice()<<endl;
				cout<<"Date:";(*it).getDate().show();
				cout<<endl;								
				cout<<"==================================="<<endl;
			}
			getch();
			search(inventory);
		}
	}
	else if(option == 3){
		menu(inventory);
	}
	else{
		cout<<"Invalid Input!";
		getch();
		search(inventory);	
	}
	
}
void menu(Inventory inventory) {
	
	system("cls");
	
	cout<<"====Menu===="<<endl;
	cout<<"1-Search Inventory"<<endl;
	cout<<"2-Sell Item"<<endl;
	cout<<"3-Return Item"<<endl;
	cout<<"4-Add New Item To Inventory"<<endl;
	cout<<"5-Update Item"<<endl;
	cout<<"6-Exit";
	
	cout<<"\n\nEnter Your Choice : ";
	int choice;
	cin>>choice;
	
	switch(choice) {
		case 1:
			search(inventory);
			break;
		case 2:
			sellItemMenu(inventory);
			break;
		case 3:
			returnItemMenu(inventory);
			break;
		case 4:
			addNewItem(inventory);
			break;
		case 5:
			updateItem(inventory);
			break;
		case 6:
			exit(0);
		default:
			cout<<"Invalid Input!";
			getch();
			
			menu(inventory);
			
	}
	
}
void updateItem(Inventory inventory) {
	system("cls");
	cout<<"=====Update Item===="<<endl;
	cout<<"1-Update Item\n2-Go Back To Menu";
	int choice;
	cout<<"\nEnter your Choice : ";
	cin>>choice;
	if(choice == 1) {
		list<Item> itemList = inventory.showList();
			list<Item>::iterator it;			
			for(it = itemList.begin(); it!=itemList.end(); ++it) {
				Date d = (*it).getDate();
				
				cout<<"Name: "<<(*it).getName()<<endl;
				cout<<"Category: "<<(*it).getCatagory()<<endl;
				cout<<"Quantity: "<<(*it).getQuantity()<<endl;
				cout<<"Price: "<<(*it).getPrice()<<endl;				
				cout<<"Date: ";d.show();	
			}
		string name;
			cout<<"\nEnter name to update : ";
			cin>>name;
			Item item = inventory.searchByName(name);
			
			if(!item.getName().empty()){
							
				Item newitem;
				string pre_name = item.getName();
				cout<<"Previous Name : "<<pre_name<<endl;
				cout<<"Enter New Name : ";
				string newName;
				cin>>newName;
				newitem.setName(newName);
				cout<<"Previous Quantity : "<<item.getQuantity()<<endl;
				cout<<"Enter New Quantity : ";
				int newQuantity;
				cin>>newQuantity;
				newitem.setQuantity(newQuantity);
				cout<<"Previous Price : "<<item.getPrice()<<endl;
				cout<<"Enter new Price : ";
				float newPrice;
				cin>>newPrice;
				newitem.setPrice(newPrice);
				newitem.setDate(item.getDate());
				
				bool b = inventory.updateItem(newitem,pre_name);
				if(b) {
					cout<<"Item Updated Successfully!";
					getch();
					updateItem(inventory);
				}
			}else{
				cout<<"Name does not match!";
				updateItem(inventory);
		}
	}
	else {
		menu(inventory);
	}
}
void addNewItem(Inventory inventory) {
	
		system("cls");
			cout<<"====Add New Item To Inventory===="<<endl;
			cout<<"1-Add New Item"<<endl;
			cout<<"2-Go Back To Menu"<<endl;
			int choice;
			cin>>choice;
			if(choice == 1) {
				cout<<"\nSelect Catagory : "<<endl;;
			cout<<"\n1-Fruits\n2-Food\n3-Drinks\n4-Vegetables\n5-Meat\n6-Dairy"<<endl;
			cout<<"Enter Catagory : ";
			int option;
			cin>>option;
			if(option == 1) {
				Fruit f;
					f.setCatagory("Fruits");
					cout<<"Enter Item Name : ";
					string name;
					cin>>name;
					f.setName(name);
					cout<<"Enter Quantity : ";
					int quantity;
					cin>>quantity;
					f.setQuantity(quantity);
					cout<<"Enter Price : ";
					float price;
					cin>>price;
					f.setPrice(price);
					cout<<"Enter Expiry Date (dd-mm-yyyy) : ";
					Date date;
					int temp;
					
					cout<<"Enter Day: ";					
					cin>>temp;
					date.setDay(temp);
					cout<<"Enter Month: ";
					cin>>temp;
					date.setMonth(temp);
					cout<<"Enter Year: ";
					cin>>temp;
					date.setYear(temp);
					
					f.setDate(date);
					inventory.add(f);
					cout<<"Item Added Successfully";
					getch();
					addNewItem(inventory);
			}
			else if(option == 2) {
				Food food;
					food.setCatagory("Food");
					cout<<"Enter Item Name : ";
					string foodName;
					cin>>foodName;
					food.setName(foodName);
					cout<<"Enter Quantity : ";
					int foodquantity;
					cin>>foodquantity;
					food.setQuantity(foodquantity);
					cout<<"Enter Price : ";
					float foodprice;
					cin>>foodprice;
					food.setPrice(foodprice);
					cout<<"Enter Expiry Date (dd-mm-yyyy) : ";
						Date date;
					int temp;
					
					cout<<"Enter Day: ";					
					cin>>temp;
					date.setDay(temp);
					cout<<"Enter Month: ";
					cin>>temp;
					date.setMonth(temp);
					cout<<"Enter Year: ";
					cin>>temp;
					date.setYear(temp);
					
					food.setDate(date);
					inventory.add(food);
					cout<<"Item Added Successfully";
					getch();
					addNewItem(inventory);
					
			}
			else if(option == 3) {
				Drinks f;
					f.setCatagory("Drinks");
					cout<<"Enter Item Name : ";
					string name;
					cin>>name;
					f.setName(name);
					cout<<"Enter Quantity : ";
					int quantity;
					cin>>quantity;
					f.setQuantity(quantity);
					cout<<"Enter Price : ";
					float price;
					cin>>price;
					f.setPrice(price);
					cout<<"Enter Expiry Date (dd-mm-yyyy) : ";
						Date date;
					int temp;
					
					cout<<"Enter Day: ";					
					cin>>temp;
					date.setDay(temp);
					cout<<"Enter Month: ";
					cin>>temp;
					date.setMonth(temp);
					cout<<"Enter Year: ";
					cin>>temp;
					date.setYear(temp);
					
					f.setDate(date);
					inventory.add(f);
					cout<<"Item Added Successfully";
					getch();
					addNewItem(inventory);
			}
			else if(option == 4) {
				Vegetable f;
					f.setCatagory("Vegetable");
					cout<<"Enter Item Name : ";
					string name;
					cin>>name;
					f.setName(name);
					cout<<"Enter Quantity : ";
					int quantity;
					cin>>quantity;
					f.setQuantity(quantity);
					cout<<"Enter Price : ";
					float price;
					cin>>price;
					f.setPrice(price);
					cout<<"Enter Expiry Date (dd-mm-yyyy) : ";
						Date date;
					int temp;
					
					cout<<"Enter Day: ";					
					cin>>temp;
					date.setDay(temp);
					cout<<"Enter Month: ";
					cin>>temp;
					date.setMonth(temp);
					cout<<"Enter Year: ";
					cin>>temp;
					date.setYear(temp);
					
					f.setDate(date);
					inventory.add(f);
					cout<<"Item Added Successfully";
					getch();
					addNewItem(inventory);
			}
			else if(option == 5) {
				Meat f;
					f.setCatagory("Meat");
					cout<<"Enter Item Name : ";
					string name;
					cin>>name;
					f.setName(name);
					cout<<"Enter Quantity : ";
					int quantity;
					cin>>quantity;
					f.setQuantity(quantity);
					cout<<"Enter Price : ";
					float price;
					cin>>price;
					f.setPrice(price);
					cout<<"Enter Expiry Date (dd-mm-yyyy) : ";
						Date date;
					int temp;
					
					cout<<"Enter Day: ";					
					cin>>temp;
					date.setDay(temp);
					cout<<"Enter Month: ";
					cin>>temp;
					date.setMonth(temp);
					cout<<"Enter Year: ";
					cin>>temp;
					date.setYear(temp);
					
					f.setDate(date);
					inventory.add(f);
					cout<<"Item Added Successfully";
					getch();
					addNewItem(inventory);
			}
			else if(option == 6) {
				Dairy f;
					f.setCatagory("Fruits");
					cout<<"Enter Item Name : ";
					string name;
					cin>>name;
					f.setName(name);
					cout<<"Enter Quantity : ";
					int quantity;
					cin>>quantity;
					f.setQuantity(quantity);
					cout<<"Enter Price : ";
					float price;
					cin>>price;
					f.setPrice(price);
					cout<<"Enter Expiry Date (dd-mm-yyyy) : ";
						Date date;
					int temp;
					
					cout<<"Enter Day: ";					
					cin>>temp;
					date.setDay(temp);
					cout<<"Enter Month: ";
					cin>>temp;
					date.setMonth(temp);
					cout<<"Enter Year: ";
					cin>>temp;
					date.setYear(temp);
					
					f.setDate(date);
					inventory.add(f);
					cout<<"Item Added Successfully";
					getch();
					addNewItem(inventory);
			}
			else {
				cout<<"Invalid Input...Please try Again!";
				getch();
				addNewItem(inventory);
			}		
					
		}
			else {
				menu(inventory);
			}
			
}
