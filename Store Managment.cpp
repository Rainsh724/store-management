#include<iostream>
#include <iomanip>
#include<fstream>
#include <sstream>
#include <vector>
#include<string>
#include<ctime>
#include<map>
//--------------
using namespace std;
//-------------------------------------------------------------------------

//		Insert :		//

class ProductInsert {
	
	public:
	
	void proInsert() {
		
		system("color b1");
		
		while(true)
	{
		ofstream out;
		string name; int quantity; long price,off,FinalPrice;
		
		out.open("data.csv",ios::app);

		cout<<"\n	Enter Name : "; cin>>name; out<<name<<",";
		cout<<"\n	Enter Quantity : ";  cin>>quantity;  out<<quantity<<",";
		cout<<"\n	Enter price : ";  cin>>price;  out<<price<<",";
		cout<<"\n	How many percent discount? (Enter 0-100) : ";  cin>>off;  out<<off<<",";
		off=(price*off)/100;	FinalPrice=price-off;	out<<FinalPrice<<","<<"\n";
		out.close();
		
		cout<<"\n  Enter 1 to continue or Enter 0 to exit : ";
		int n; cin>>n;	if(n==0){system("cls"); break;}	if(n==1){system("cls");}

	}
}
	
};

//-------------------------------------------------------------------------

//		Product List :		//

struct ProductData {
	public:
		ProductData(
			string name, int quantity, long price, long off, long finalPrice
		){
			Name = name;
			Quantity = quantity;
			Price = price;
			OFF = off;
			FinalPrice = finalPrice;
		}
		
		void display(){
			system("color f4");
			cout<<"\n        Name : "<<Name<<endl;
			cout<<"     Quantity : "<<Quantity<<endl;
			cout<<"        price : "<<Price<<endl;
			cout<<"          OFF : %"<<OFF<<endl;
			cout<<" Price in OFF : "<<FinalPrice<<endl;
			cout<<endl<<"----------------------"<<endl;			
		}
		
		string Name; int Quantity; long Price,OFF,FinalPrice;
		
};


class ProductList {	

	public:
		
		void proList(){
			
	ifstream in;
	in.open("data.csv");
	vector<ProductData> products;
	string line = "";
	getline(in, line);
	line = "";
	
	while (getline(in,line))
	{
	
		string name,tempString; int quantity; long price,off,finalPrice;
	
		stringstream inString(line);

		getline(inString, name, ',');
		
		tempString="";
		getline(inString, tempString, ',');
		quantity = atoi(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		price = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		off = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		finalPrice = atol(tempString.c_str());
		
		ProductData pro(name, quantity, price, off, finalPrice);
		
		products.push_back(pro);
		
		line="";
	}
	
	for(auto pro : products)
	{
		pro.display();
	} 
}

};


//-------------------------------------------------------------------------

//		Product Data Update :		//

struct ProductData2 {
	public:
		ProductData2 (
			string name, int quantity, long price, long off, long finalPrice
		){
			Name = name;
			Quantity = quantity;
			Price = price;
			OFF = off;
			FinalPrice = finalPrice;
		
		}
		
		void display2(int lineNum,int lastline){	
		int num;
			cout<<"\n\n Product founded!\n\n----------------------\n";
			cout<<"\n  1.Name : "<<Name<<endl;
			cout<<"  2.Quantity : "<<Quantity<<endl;
			cout<<"  3.price : "<<Price<<endl;
			cout<<"  OFF : %"<<OFF<<endl;
			cout<<"  Price in OFF : "<<FinalPrice<<endl;
			cout<<endl<<"----------------------"<<endl;	
			cout<<"\n which one do you want to change? Enter the number : ";
			
			cin>>num;
			
			system("cls");
			switch(num)
			{
				case 1: {
					string Name;
					ofstream out;
					out.open("data.csv",ios::app);
					cout<<"\n	Enter new Name : "; 
					cin>>Name;
					out<<Name<<","<<Quantity<<","<<Price<<","<<OFF<<","<<FinalPrice<<"\n";
					//---------------------------
					fstream count;
					count.open("data.csv");
					vector<string> lines;
					string line;
					while (getline(count,line))
						lines.push_back(line);
					count.close();
					ofstream delet;
					delet.open("data.csv");
					lineNum--;
					for(int i=0; i<lines.size(); i++)
						{
	 						if(i!=lineNum)
	 						delet<<lines[i]<<endl;
						}
					delet.close();	
					} break; 
					
					case 2:
						{
					string Quantity;
					ofstream out;
					out.open("data.csv",ios::app);
					cout<<"\n	Enter new Quantity : "; 
					cin>>Quantity;
					out<<Name<<","<<Quantity<<","<<Price<<","<<OFF<<","<<FinalPrice<<"\n";
					//---------------------------
					fstream count;
					count.open("data.csv");
					vector<string> lines;
					string line;
					while (getline(count,line))
						lines.push_back(line);
					count.close();
					ofstream delet;
					delet.open("data.csv");
					lineNum--;
					for(int i=0; i<lines.size(); i++)
						{
	 						if(i!=lineNum)
	 						delet<<lines[i]<<endl;
						}
					delet.close();	
						} break; 
						
					case 3:
					{
					long Price,FinalPrice;
					int OFF;
					ofstream out;
					out.open("data.csv",ios::app);
					cout<<"\n	Enter new Price : "; 
					cin>>Price;
					cout<<"\n	Enter new OFF : ";
					cin>>OFF;
					FinalPrice=Price-((Price*OFF)/100);
					out<<Name<<","<<Quantity<<","<<Price<<","<<OFF<<","<<FinalPrice<<"\n";
					//---------------------------
					fstream count;
					count.open("data.csv");
					vector<string> lines;
					string line;
					while (getline(count,line))
						lines.push_back(line);
					count.close();
					ofstream delet;
					delet.open("data.csv");
					lineNum--;
					for(int i=0; i<lines.size(); i++)
						{
	 						if(i!=lineNum)
	 						delet<<lines[i]<<endl;
						}
					delet.close(); 
					} break; 
			} system("cls");

		}
		
		string Name; int Quantity; long Price,OFF,FinalPrice;
		
};


class ProductDataUpdate {

	public:
	
	void proDataUpdate() {
	
	system("color 80");

	string key,name;
	int lastline=2,lineNum;
	bool keyword=false;
	cout<<"\n\n	Enter the name of product that you want to search : ";
	cin>>key;
	system("cls");
	ifstream in;
	in.open("data.csv");
	vector<ProductData2> products2;
	string line = "";
	getline(in, line);
	line = "";
	
	for (;getline(in,line);lastline++)
	{
	
		string name,tempString; int quantity; long price,off,finalPrice;
	
		stringstream inString(line);

		getline(inString, name, ',');
		
		if (name==key)
		{
			//cout<<line<<endl;
			lineNum=lastline;
			keyword=true;
		tempString="";
		getline(inString, tempString, ',');
		quantity = atoi(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		price = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		off = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		finalPrice = atol(tempString.c_str());
		}
		
		else continue;
		
		ProductData2 pro2(name, quantity, price, off, finalPrice);
	
		products2.push_back(pro2);
	
		line="";	
	}
	if(keyword){
	for(auto pro2 : products2)
	{
		lastline-=1;
		//cout<<lastline;
		pro2.display2(lineNum,lastline);
	}}
	else
	cout<<"\n\n	The product doesn't exist!";
}

};


//-------------------------------------------------------------------------

//		Product Search :		//


class ProductSearch {
	
	public:
		
		void proSearch() {
			
			system("color b5");
			
	string key,name;
	bool keyword=false;
	int lineNum=0;
	cout<<"\n  Enter the name of product that you want to search : ";
	cin>>key;
	
	system("cls");
	
	ifstream in;
	in.open("data.csv");
	vector<ProductData> products;
	string line = "";
	getline(in, line);
	line = "";

	while (getline(in,line))
	{
		string name,tempString; int quantity; long price,off,finalPrice;
	
		stringstream inString(line);

		getline(inString, name, ',');
		
		
		if (name==key)
		{
			keyword=true;
		tempString="";
		getline(inString, tempString, ',');
		quantity = atoi(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		price = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		off = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		finalPrice = atol(tempString.c_str());
		}
		
		else continue;
		
		ProductData pro(name, quantity, price, off, finalPrice);
		lineNum++;
		products.push_back(pro);
	
		line="";	
	}
	if(keyword){
	for(auto pro : products)
	{
		pro.display();
	}
	}
	else
	cout<<"\n	The product doesn't exist!";	



}
};

//-------------------------------------------------------------------------

//		Product Order :		//

struct ProductData4{
	public:
		ProductData4(
			string name, int quantity, long price, long off, long finalPrice
		){
			Name = name;
			Quantity = quantity;
			Price = price;
			OFF = off;
			FinalPrice = finalPrice;
		
		}
		
				void display4(int lineNum2,int lastline2,int nQ){	

					string Quantity;
					ofstream out;
					out.open("data.csv",ios::app);
					out<<Name<<","<<nQ<<","<<Price<<","<<OFF<<","<<FinalPrice<<"\n";
					//---------------------------
					fstream count;
					count.open("data.csv");
					vector<string> lines2;
					string line2;
					while (getline(count,line2))
						lines2.push_back(line2);
					count.close();
					ofstream delet;
					delet.open("data.csv");
					lineNum2--;
					for(int i=0; i<lines2.size(); i++)
						{
	 						if(i!=lineNum2)
	 						delet<<lines2[i]<<endl;
						}
					delet.close();
						}
						

		string Name; int Quantity; long Price,OFF,FinalPrice;
		
};


class ProductOrder{
	
	public:
		
		void proOrder(){

	string key;
	bool keyword=false;
	int lineNum=0,q,nQ;
	long payPrice,FP,o,p; //FP:final price  pp:pay price
	
	cout<<"Enter the name of product that you want to Buy : \n";
	cin>>key;
	
	ifstream in;
	in.open("data.csv");
	vector<ProductData> products;
	string line = "";
	getline(in, line);
	line = "";


	while (getline(in,line))
	{
		string name,tempString; int quantity; float price,off,finalPrice;
	
		stringstream inString(line);
		
		getline(inString, name, ',');
		
		if (name==key)
		{
			keyword=true;
		tempString="";
		getline(inString, tempString, ',');
		quantity = atoi(tempString.c_str());
		q=quantity;
		
		tempString="";
		getline(inString, tempString, ',');
		price = stol(tempString.c_str());
		p=price; 
		
		tempString="";
		getline(inString, tempString, ',');
		off = stol(tempString.c_str());
		o=off;
		
		tempString="";
		getline(inString, tempString, ',');
		finalPrice = stol(tempString.c_str());
		FP=finalPrice;

		}
		
		else continue;
		
		ProductData pro(name, quantity, price, off, finalPrice);
		lineNum++;
		products.push_back(pro);
	
		line="";	
	}
	if(keyword){
		
	for(auto pro : products)
	{
		pro.display();
		in.close();
		string FirstName, LastName, PhoneNum; int CustomQty, day,month; long year;
		ofstream out;
		out.open("invoice.csv",ios::app);
		//--------------
		cout<<"Enter Quantity you want : ";
		cin>>CustomQty; 
		if(CustomQty<=q)
		{
		nQ=q-CustomQty;
		}
		if(CustomQty>q)
		{cout<<"Quantity is not enough!\n";}
		//--------------
		cout<<"Enter Customer First Name : ";
		cin>>FirstName;
		//-------------
		cout<<"Enter Customer Last Name : ";
		cin>>LastName;
		//-------------
		cout<<"Enter Customer Phone Number (without first 0) : +98 ";
		cin>>PhoneNum;
		//--------------
		cout<<"Enter the date!\nWhat day is today? (1-31) : "; 
		cin>>day; if(day<1 && day>31){cout<<"wrong number!"; break;} 
		cout<<"Wich Month? (1-12) : ";	
		cin>>month; if(month<1 && month>12){cout<<"wrong number!"; break;} 
		cout<<"Wich year? (1400-1403) : ";
		cin>>year; if(year<1400 && year>1403){cout<<"wrong number!"; break;} 
		//--------------
		payPrice=FP*CustomQty;
		//--------------
		out<<PhoneNum<<","<<FirstName<<","<<LastName<<",";
		out<<key<<","<<CustomQty<<","<<p<<","<<o<<",";
		out<<FP<<","<<payPrice<<","<<day<<","<<month<<","<<year<<","<<"\n";
			system("cls");
			
		cout<<"Your Order Is : \n\n";
		cout<<"     Product :  "<<key<<"\n";
		cout<<"    Quantity :  "<<CustomQty<<"\n";
		cout<<"Price To Pay :  " <<payPrice<<"\n";
		cout<<"\n	Go To <<Your Invoices' List >> To Receive The Complete Invoice!\n\n";
		
	}
	}
	
	else
	cout<<"The product doesn't exist!";


//------------------

	int lastline2=2,lineNum2;
	bool keyword2=false;

	ifstream in2;
	in2.open("data.csv");
	vector<ProductData4> products4;
	string line2 = "";
	getline(in2, line2);
	line2 = "";
	
	for (;getline(in2,line2);lastline2++)
	{
	
		string name,tempString; int quantity; float price,off,finalPrice;
	
		stringstream inString(line2);

		getline(inString, name, ',');
	
		if (name==key)
		{
	
			lineNum2=lastline2;
			keyword2=true;
		tempString="";
		getline(inString, tempString, ',');
		quantity = atoi(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		price = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		off = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		finalPrice = atol(tempString.c_str());
		}
		
		else continue;
		
		ProductData4 pro4(name, quantity, price, off, finalPrice);
	
		products4.push_back(pro4);
	
		line="";
		
	}

	for(auto pro4 : products4)
	{
		lastline2-=1;
	
		pro4.display4(lineNum2,lastline2,nQ);
}

}};


//-------------------------------------------------------------------------

//		Receive invoice :		// 

struct ProductInvoice{
	public:
		ProductInvoice(
			string name , long price, long off, long finalPrice,long payPrice ,
			int customQty,string firstName, string lastName, string phoneNum,
			int day, int month, long year
			 
		){
			Name = name;
			Price = price;
			OFF = off;
			FinalPrice = finalPrice;
			FirstName = firstName;
			LastName = lastName;
			PhoneNum = phoneNum;
			CustomQty = customQty;
			PayPrice = payPrice;
			Day = day;	Month = month;	Year = year;

		}
		

				
		void displayInvoice(){	
		
			system("color e5");
			
			cout<<"\n     First name : "<<FirstName<<endl;
			cout<<"      Last Name : "<<LastName<<endl;
			cout<<"   Phone Number : "<<PhoneNum<<endl;
			cout<<"           Name : "<<Name<<endl;
			cout<<"       Quantity : "<<CustomQty<<endl;
			cout<<"          price : "<<Price<<endl;
			cout<<"            OFF : %"<<OFF<<endl;
			cout<<"   Price to pay : "<<PayPrice<<endl;
			cout<<"           Date : "<<Year<<"/"<<Month<<"/"<<Day<<endl;
			cout<<"\n----------------------------\n";
		}
		string Name,FirstName,LastName, PhoneNum; long Year;
		int Quantity,CustomQty,Day,Month; long Price,FinalPrice,OFF,PayPrice;
		
};



class ReceiveInvoice {

	public:
	
	void CustomerInvoice() {
		
		bool keyword=false;
		int lineNum=0;
		cout<<"\nEnter your Phone Number to recive the factor : (Without the first 0)	+98 ";
		string Num;
		cin>>Num;
		cout<<"\n----------------\n";
		ifstream in;
		in.open("invoice.csv");
		vector<ProductInvoice> invoice;
		string line = "";
		getline(in, line);
		line = "";
		
	while (getline(in,line))
	{
		string name,tempString; long price,off,payPrice,finalPrice;
		string firstName, lastName, phoneNum; int customQty, day,month; long year;
	
		stringstream inString(line);
		
		getline(inString, phoneNum, ',');
	
		if (phoneNum==Num)
		{
			keyword=true;
		getline(inString, firstName, ',');
		getline(inString, lastName, ',');
		getline(inString, name, ',');
			
		tempString="";
		getline(inString, tempString, ',');
		customQty = atoi(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		price = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		off = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		finalPrice = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		payPrice = atol(tempString.c_str());

		tempString="";
		getline(inString, tempString, ',');
		day = atoi(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		month = atoi(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		year = atoi(tempString.c_str());
		}
		
		else continue;
		
		ProductInvoice inv(name,price,off,finalPrice,payPrice,customQty,
		firstName,lastName,phoneNum,day,month,year);
		
		lineNum++;
		invoice.push_back(inv);
	
		line="";	
	}

	if(keyword){	
	for(auto inv : invoice)
		{
			inv.displayInvoice();
		}
	}
	else{
	system("cls");
	cout<<"Wrong Phone Number!"<<"\n"<<"Pay attention : The Phone Number should be without the first 0!";	
	}
	}	
};


//-------------------------------------------------------------------------

//		Facotrs List :		//


class InvoicesList {
	
	public:
		
		void invoicesList() {
			
		ifstream in;
		in.open("invoice.csv");
		vector<ProductInvoice> invoice;
		string line = "";
		getline(in, line);
		line = "";
		
	while (getline(in,line))
	{
		string name,tempString; long price,off,payPrice,finalPrice;
		string firstName, lastName, phoneNum; int customQty, day,month; long year;
	
		stringstream inString(line);
		
		getline(inString, phoneNum, ',');
	

		getline(inString, firstName, ',');
		getline(inString, lastName, ',');
		getline(inString, name, ',');
			
		tempString="";
		getline(inString, tempString, ',');
		customQty = atoi(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		price = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		off = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		finalPrice = atol(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		payPrice = atol(tempString.c_str());

		tempString="";
		getline(inString, tempString, ',');
		day = atoi(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		month = atoi(tempString.c_str());
		
		tempString="";
		getline(inString, tempString, ',');
		year = atoi(tempString.c_str());
	
		

		
		ProductInvoice inv(name,price,off,finalPrice,payPrice,customQty,
		firstName,lastName,phoneNum,day,month,year);
		
		
		invoice.push_back(inv);
	
		line="";	
	}

	
	for(auto inv : invoice)
		{
			inv.displayInvoice();
		}
		
	}
};

//-------------------------------------------------------------------------

//		Store Turnover :		//


struct product
{
	string name;
	int quantity;
	
};

struct Price
{
	string name;
	long price;
};

int a_month(int& startYear , int & startMonth , int & startDay)
{
	int year , month , day;
	day=startDay-30;
	month=startMonth;
	year=startYear;
	if(day <0 || startMonth<=6 || startMonth>1)
		{
			day=startDay;
			month=startMonth-1;
	}
	if (month < 1)
		{
			month=12;
			year=startYear-1;
		}
	if(startMonth>6 || startDay > 30)
	{
		day=startDay;
		month=startMonth-1;
	}
	
	startYear=year;
	startMonth=month;
	startDay=day;
	
	return 1;
}

bool isBetween(int startYear, int startMonth, int startDay,int checkYear, int checkMonth, int checkDay) 
{
  bool flag=true;
		
	if(checkYear<startYear)
	{
		flag=false;
	}
	if(checkYear==startYear)
	{
		if(checkMonth==startMonth)
		{
			if(checkDay<startDay)
			flag=false;
		}
		else if(checkMonth<startMonth)
			flag=false;
			
	}
	return flag;
}


class StoreTurnover {
	
	public:
		
		void storeTurnover() {
			
			system("color f2");
			
	int startYear, startMonth, startDay, endYear, endMonth, endDay;
	char a,b;
	map<string,product> products;
	map<string,Price> prices;
	
	ifstream file("invoice.csv");
	if(! file.is_open())
	{
		cout<<"\n	ERROR opening file \n";
	}
	
  	int y , m , d;
  	cout <<"\n   Enter today's date (For Example, In This Form : 1401/4/14) : ";
  	cin >> endYear>>a>> endMonth>>b>> endDay;
  	

	cout <<"\n\n   Enter start date (Enter 11/11/11 if you want to see the turnover in recent month): ";
  	cin >> startYear>>a>> startMonth>>b>>startDay;
		
	if(startYear==11 || startMonth==11 || startDay==11)
	{
		y=endYear;
		m=endMonth;
		d=endDay;
		a_month(endYear , endMonth , endDay);
		startYear=endYear;
		startMonth=endMonth;
		startDay=endDay;
		endYear=y;
		endMonth=m;
		endDay=d;
		cout<<"\n   Now : "<<endYear<<"/"<<endMonth<<"/"<<endDay<<"\n";
		cout<<"\n   A month ago : "<<startYear<<"/"<<startMonth<<"/"<<startDay<<"\n\n";
	}        
	
	cout <<"Turnover: \n\n"<<setw(10)<<"   Name "<<setw(10)<<"Qantity"<<setw(10)<<"Price"<<setw(10)<<"Date"<<"\n";
	string s2(45,'_');
	cout<<s2<<"\n";
	
	int c=0;
	string line =" ";
	while ( getline(file , line))
	{
		string Phone ,Fisrt_N , Last_N , P_Name , e_Price , Final_Price , Pay_Price;
		int customQty , OFF , Day , Month , Year;
		long price;
		string temp;
		
		stringstream input(line);
		
		getline(input , Phone , ',' );
		getline(input , Fisrt_N , ',' );
		getline(input , Last_N , ',' );
		getline(input , P_Name , ',' );
		string productName = P_Name;
		
		getline(input , temp , ',' );
		customQty=atoi(temp.c_str());
		int quantity=customQty;
		
		getline(input , e_Price , ',' );
		getline(input , temp , ',' );
		getline(input , Final_Price , ',' );
		getline(input , Pay_Price , ',' );
		price = atol (Pay_Price.c_str());
		
		getline(input , temp , ',' );
		Day = atoi (temp.c_str());
		temp=" ";
		getline(input , temp , ',' );
		Month = atoi (temp.c_str());
		temp=" ";
		getline(input , temp , ',' );
		Year = atoi (temp.c_str());
		temp=" ";
		bool flag=isBetween(startYear, startMonth, startDay , Year , Month , Day) && isBetween(Year , Month , Day , endYear, endMonth, endDay);
		//cout<<"done.\n";
		if(flag)
		{
			if (products.count(productName) > 0) 
				{
      	  	     products[productName].quantity += quantity;
    			} 
			else 
				{
     		 	 products[productName] = product{productName, quantity};
				}
			if (prices.count(productName) > 0) 
				{
      	  	     prices[productName].name += price;
    			} 
			else 
				{
     		 	 prices[productName] = Price{productName, price};
				}
			if(flag)
				{
				 cout<<setw(10)<<productName<<setw(10)<<quantity<<setw(10)<<price<<setw(10)<<Year<<"/"<<Month<<"/"<<Day<<"\n";
				}
		}
		
		line=" ";
	}
	
	cout<<"\n"<<"\n  Chart based on product name and number sold: \n";
	
	for(auto [key , product]:products)
	{
		string s(product.quantity , '*');
		cout<<"   "<<key<<" : "<< s <<"\n";
		
	}
	cout<<"\n"<<"\n  Chart based on product name and price sold: "<<"('*' = 10000) \n";
	
	int f;
	for(auto [key , Price] : prices)
	{
		f = int (Price.price/10000);
		string s4( f , '*');
		cout<<"   "<<key<<" : "<< s4 <<"\n";
	}
}
	     
};

//-------------------------------------------------------------------------

//		Main :		//

int main() {

//--------------------
ProductInsert insert;
ProductList list;
ProductDataUpdate proUpdate;
ProductSearch search;
ProductOrder order;
ReceiveInvoice invoice;
InvoicesList invList;
StoreTurnover turnover;
//--------------------

	system("color f1");
	
	int n;
	cout<<"\n  Log in as...\n	1. Salesman / Saleswoman\n	2. Customer\n\nEnter The Number : ";
	cin>>n;
	system("cls");
	
	switch(n)
	{
		
		case 1:
			{	
			system("color f1");
				int i=1;
				while(i!=0){
						
				cout<<"\n\n	1. Insert Product\n	2. Products List\n	3. Update the Product's Data\n";
				cout<<"	4. Invoices' List\n	5. Store Turnover\n	0. Exit\n";
			
				cout<<"\n  Enter The Number : ";
				cin>>i;
				
				system("cls");
				
				switch(i)
				{
					case 1:
						insert.proInsert(); break;
						
					case 2:
						list.proList(); break;
					
					case 3:
						proUpdate.proDataUpdate(); break;
							
					case 4:
						invList.invoicesList(); break;
						
					case 5: 
						turnover.storeTurnover(); break;
					
				}
			}
			}; break;
			
			
		case 2:
			{
				system("color f1");
				int a=1;
				while(a!=0){
						
				cout<<"\n\n	1. Products List\n	2. Product Search\n	3. Product Order\n";
				cout<<"	4. Your Invoices' List\n	0. Exit\n\n";
			
				cout<<"  Enter The Number : ";
				cin>>a;
				
				system("cls");
				
				switch(a)
				{
					case 1:
						list.proList(); break;
						
					case 2:
						search.proSearch(); break;
					
					case 3:
						order.proOrder(); break;
							
					case 4:
						invoice.CustomerInvoice(); break;

				}
				}
		}; break;
	}
}
