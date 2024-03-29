#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto
void gotoXY(int x, int y) 
{ 
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}

 fstream fp;

/********************** Class User**************************************
->Constructor initialises data members of the class 
->Getter function which when called takes input from the user
->Display function which when called shows the input taken from the user
***********************************************************************/
class User
{
	int user_id;
	string password,loginStatus,registerDate,name;
	long phone_number;
	public:
		User() 
		{
			user_id=0;
			name="NULL";
			phone_number=0;
		}
		void get_info() 
		{
			cout<<"Enter User Id:\n";
			cin>>user_id;
			cout<<"Enter User Name:\n";
			cin>>name;
			cout<<"Enter User Phone Number\n:";
			cin>>phone_number;
		}
		void show_info() 
		{
			cout<<"User Id:"<<user_id<<endl;
			cout<<"User Name:"<<name<<endl;
			cout<<"Phone Number:"<<phone_number<<endl;
		}
		bool verifyLogin();
};

/*******************************Class Product************************************
->Contains basic blueprint about Products and is further inherited by other classes
->Constructor initialises data members of the class 
->Functions returning the values of data members
->A virtual function which returns discounted price according to the amount passed
*********************************************************************************/
class Product
{
	int product_id;
	float price;
	string brand_name;
	int eligible_for_cod;
	string seller_name;
	int quantity;
	public:
		Product()
		{
			product_id=0;
			price=0;
			brand_name="NULL";
			eligible_for_cod=0;
			seller_name="NULL";
		}
	    int return_product_id()
	    {
	    	return product_id;
		}
		int return_price()
		{
			return price;
		}
		string return_bname()
		{
			return brand_name;
		}
		string return_sname()
		{
			return seller_name;
		}
		int return_eligible_for_cod()
		{
			return eligible_for_cod;
		}
		int return_quantity()
		{
			return quantity;
		}
		void get_product_details()
		{
			cout<<"Enter Product Id:\n";
			cin>>product_id;
			cout<<"Enter Price of the product:\n";
			cin>>price;
			cout<<"Enter the quantity required of the desired product:\n";
			cin>>quantity;
			cout<<"Enter Brand Name:\n";
			cin>>brand_name;
			cout<<"Enter Seller's Name:\n";
			cin>>seller_name;
			cout<<"Should the product be eligible for cash on delivery?(0 (for no)/ 1(for yes)):\n";
			cin>>eligible_for_cod;
		}
		void show_product_details()
		{
			cout<<"Product Id:"<<product_id<<endl;
			cout<<"Price of the product:"<<price<<endl;
			cout<<"Quantity Demanded:"<<quantity<<endl;
			cout<<"Brand Name:"<<brand_name<<endl;
			cout<<"Seller's Name:"<<seller_name<<endl;
			if(eligible_for_cod==0)
			cout<<"Product demanded is not eligible for cod"<<endl;
			else cout<<"Product is eligible for cod"<<endl;
		}	
		float return_discount_price(int discount_percent)
		{
			return price-(price*(discount_percent/100));
		}

};

/*******************************Class ShoppingCart********************************
->Contains basic blueprint of a shopping cart
->Constructor initialises data members of the class 
->Functions returning the values of data members
*********************************************************************************
class ShoppingCart{
	int CartId, ProductId,quantity,dateAdded;
	
	public:
		void showCart(){
			cout<<"Product Id:"<<ProductId<<endl;
			cout<<"Quantity Ordered:"<<quantity<<endl;
			cout<<"Date Added to Cart:"<<dateAdded<<endl;
		}
		void addCartItem();
		void updateQuantity();
		void viewCartDetails();
		void checkOut();
};*/

/*******************************Class ShippingInfo********************************
->Contains the data members that would store shipping detail of a product
->Constructor initialises data members of the class 
->Functions returning the values of data members and one method to update shipping 
  information
*********************************************************************************/
class ShippingInfo{
	int shippingId;
	string shippingType;
	int shippingCost;
	int shippingRegionCode;
	
	public:
		void getShippingInfo();
};

/*******************************Class Order************************************
->Contains objects of shippinInfo implements composition
->Constructor initialises data members of the class 
->Functions returning the values of data members
*********************************************************************************/
template<class T>
class Order{
	ShippingInfo si;
	public:
		void place_order(string,T );
		
};
template<class T> 
void menu( string filename,T pr){
     //clrscr();
     fp.open("ShopifyProducts.dat",ios::in);
    // fp.open(filename,ios::in|ios::binary);
    if(!fp){
       cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
       cout<<"\n\n\n Program is closing ....";
       getch();
       exit(0);
    }

      cout<<"\n\n\t\tProduct MENU\n\n";
	  cout<<"====================================================\n";
	  cout<<"P.NO.\t\tNAME\t\tPRICE\n";
	  cout<<"====================================================\n";

      while(fp.read((char*)&pr,sizeof(pr)))
	 {
	   cout<<pr.return_product_id()<<"\t\t"<<pr.return_bname()<<"\t\t"<<pr.return_price()<<endl;
	 }
     fp.close();
}
template<class T> 
void Order::place_order( string filename ,T pr){
	int  order_arr[50],quan[50],c=0;
    float amt,damt,total=0;
    char ch='Y';
    menu(filename, pr);
    cout<<"\n============================";
    cout<<"\n    PLACE YOUR ORDER";
    cout<<"\n============================\n";
    do{
	 cout<<"\n\nEnter The Product No. Of The Product : ";
	 cin>>order_arr[c];
	 cout<<"\nQuantity in number : ";
	 cin>>quan[c];
	 c++;
	 cout<<"\nDo You Want To Order Another Product ? (y/n)";
	 cin>>ch;
    }while(ch=='y' ||ch=='Y');
    cout<<"\n\nThank You For Placing The Order";getch();//clrscr();
    si.getShippingInfo();
      cout<<"\n\n********************************INVOICE************************\n";
      cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
      for(int x=0;x<=c;x++)
	{
		 fp.open(filename,ios::in|ios::binary);
		 fp.read((char*)&pr,sizeof(product));
		  while(!fp.eof())
			{
			if(pr.retpno()==order_arr[x])
				{
				 amt=pr.return_price()*quan[x];
				 damt=amt-(amt*pr.return_discount_price()/100);
				 cout<<"\n"<<order_arr[x]<<"\t"<<pr.return_bname()<<"\t"<<quan[x]<<"\t\t"<<pr.return_price()<<"\t"<<amt<<"\t\t"<<damt;
				 total+=damt;
				}
			fp.read((char*)&pr,sizeof(pr));
			}

		 fp.close();
	 }
       cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
    getch();
}


/*******************************Class Customer************************************
->Publically inherits class User
->Constructor initialises data members of the class 
->Functions returning the values of data members
*********************************************************************************/
class Customer: public User{
	string address, email, creditCardInfo,shippingInfo;
	float accountBalance;
	Order o;
	public:
	void cplace_order( string filename, T pr)
	{
		o.place_order(filename,pr);
	}
		
};

/*******************************Class Admin************************************
->Publically inherits  class User
->Constructor initialises data members of the class 
->Functions returning the values of data members
*********************************************************************************/
class Admin: public User{
	string email ;
	public:
		void admin_menu();	
};
void Admin::admin_menu(){
	//clrscr();
  char ch2;
  cout<<"\n\n\n\tADMIN MENU";
  cout<<"\n\n\t1.CREATE PRODUCT";
  cout<<"\n\n\t2.DISPLAY ALL PRODUCTS";
  cout<<"\n\n\t3.QUERY ";
  cout<<"\n\n\t4.MODIFY PRODUCT";
  cout<<"\n\n\t5.DELETE PRODUCT";
  cout<<"\n\n\t6.VIEW PRODUCT MENU";
  cout<<"\n\n\t7.BACK TO MAIN MENU";
  cout<<"\n\n\tPlease Enter Your Choice (1-7) ";
  ch2=getche();
  switch(ch2)
  {
    case '1': //clrscr();
	      write_product();
	      break;
    case '2': display_all();break;
    case '3':
	       int num;
	       //clrscr();
	       cout<<"\n\n\tPlease Enter The Product No. ";
	       cin>>num;
	       display_sp(num);
	       break;
      case '4': modify_product();break;
      case '5': delete_product();break;
      case '6': menu();
		getch();
      case '7': break;
      default:cout<<"\a";admin_menu();
   }
}

/***********************Class Electronic_Products***********************
->This class publically inherits the Product class 
->It is further inherited publically by class Mobile and class Computer
***********************************************************************/
class Electronic_Products :virtual public Product
{
	string operating_system;
	float memory_size;
	float screen_size;
	public:
		Electronic_Products()
		{
			operating_system="NULL";
			memory_size=0;
			screen_size=0;
		}
		string return_operating_system()
		{
			return operating_system;
		}
		float return_memory_size()
		{
			return memory_size;
		}
		float return_screen_size()
		{
			return screen_size;
		}
		void get_electronic_details()
		{
			get_product_details();
			cout<<"Enter the type of Operating system:\n";
			cin>>operating_system;
			cout<<"Enter memory size of the device:\n";
			cin>>memory_size;
			cout<<"Enter screen size of the device:\n";
			cin>>screen_size;
		}
		void show_electronic_details()
		{
			show_product_details();
			cout<<"Operating system:"<<endl;
			cout<<"Memory size:"<<endl;
			cout<<"Screen size:"<<endl;
		}
};



/***********************Class Clothing_Products***********************
->This class publically inherits the Product class 
->It is further inherited publically by class Male_Clothing, class Female
_Clothing and Kids_Clothing
***********************************************************************/
class Clothing_Products:virtual public Product
{
	string Material;
	int size;
	string colour;
	public:
		Clothing_Products()
		{
			Material="NULL";
			size=0;
			colour="NULL";
		}
		string return_Material()
		{
			return Material;
		}
		string return_colour()
		{
			return colour;
		}
		int return_size()
		{
			return size;
		}
		void get_clothingdetails()
		{
			get_product_details();
			cout<<"Enter material type:\n";
			cin>>Material;
			cout<<"Enter colour of the product:\n";
			cin>>colour;
			cout<<"Enter size of the product"<<endl;
			cout<<"For women:"<<"xs-30|s-32|m-34|l-36|xl-40|xxl-42"<<endl;
			cout<<"For men:"<<""<<endl;
			cout<<"In case of unstiched material: 0";
			cin>>size;
		}
		void show_clothingdetails()
		{
			show_product_details();
			cout<<"Material type:"<<Material<<endl;
			cout<<"Colour:"<<colour<<endl;
			cout<<"Size:"<<size<<endl;
		}
};



/***********************Class Home_DecorProducts***********************
->This class publically inherits the Product class 
->It is further inherited publically by class Kitchen_Furnishings and Class
Gardening_Products
***********************************************************************/
class Home_DecorProducts:virtual public Product
{
	string apron_type;
	string glove_type;
	string light_type;
	string rug_type;
	public:
		string return_apron_type()
		{
			return apron_type;
		}
		string return_glove_type()
		{
			return glove_type;
		}
		string return_light_type()
		{
			return light_type;
		}
		string return_rug_type()
		{
			return rug_type;
		}
		void get_homedecor_details()
		{
			get_product_details();
			cout<<"Enter Apron type:\n";
			cin>>apron_type;
			cout<<"Enter Glove type:\n";
			cin>>glove_type;
			cout<<"Enter the type of lights preferred:\n";
			cin>>light_type;
			cout<<"Enter rug type:\n";
			cin>>rug_type;
		}
		void show_homedecor_details()
		{
			show_product_details();
			cout<<"Apron:"<<apron_type<<endl;
			cout<<"Gloves:"<<glove_type<<endl;
			cout<<"Lights:"<<light_type<<endl;
			cout<<"Rug:"<<rug_type<<endl;
		}
};

/*******************Class Mobile***********************
->It publically inherits class Electronic_Products
->Contains various attributes and behaviours
*******************************************************/
class Mobile: public Electronic_Products
{
	string Performance;
	int FrontCamera;
	int RearCamera;
	int Touch_avail;
	string Security_Connectivity;
	public:
		Mobile()
		{
			Performance="NULL";
			FrontCamera=0;
			RearCamera=0;
			Touch_avail=0;
			Security_Connectivity="NULL";
		}
		string return_Performance()
		{
			return Performance;
		}
		string return_Security_Connectivity()
		{
			return Security_Connectivity;
		}
		int return_RearCamera()
		{
			return RearCamera;
		}
		int return_FrontCamera()
		{
			return FrontCamera;
		}
		int return_Touch_avail()
		{
			return Touch_avail;
		}
		void get_data()
		{
			get_electronic_details();
			cout<<"Enter Performance:\n";
			cin>>Performance;
			cout<<"Enter specifications for front camera (MP mega pixels):\n";
			cin>>FrontCamera;
			cout<<"Enter specifications for rear camera (MP mega pixels):\n";
			cin>>RearCamera;
			cout<<"Touch required (Enter 0 for no and 1 for yes):\n";
			cin>>Touch_avail;
			cout<<"Enter other Security and connections preferred:\n";
			cin>>Security_Connectivity;
		}
		void show_data()
		{
			show_electronic_details();
			cout<<"Performance:"<<Performance<<endl;
			cout<<"Front Camera(MP):"<<FrontCamera<<endl;
			cout<<"Rear Camera(MP):"<<RearCamera<<endl;
			if(Touch_avail==0)
			cout<<"Youch is not available for this device"<<endl;
			else cout<<"Touch is available for the device"<<endl;
			cout<<"Security and Connectivity:"<<Security_Connectivity<<endl;		
		}
		
};

/*******************Class Laptop***********************
->It publically inherits class Electronic_Products
->Contains various attributes and behaviours
*******************************************************/
class Laptop: public Electronic_Products
{
	string CPU_Type;
	float weight;
	string Laptop_Type;
	int Usage;
	public:
		Laptop()
		{
			CPU_Type="NULL";
			weight=0;
			Laptop_Type="NULL";
			Usage=0;
		}
		string return_CPU_Type()
		{
			return CPU_Type;
		}
		string return_Laptop_Type()
		{
			return Laptop_Type;
		}
		float return_weight()
		{
			return weight;
		}
		int return_usage()
		{
			return Usage;
		}
		void get_data()
		{
			get_electronic_details();
			cout<<"Enter CPU type:\n";
			cin>>CPU_Type;
			cout<<"Enter the weight preferred:\n";
			cin>>weight;
			cout<<"Enter Laptop type:\n";
			cin>>Laptop_Type;
			cout<<"Enter Usage:\n";
			cin>>Usage;
		}
		void show_data()
		{
			show_electronic_details();
			cout<<"CPU Type:"<<CPU_Type<<endl;
			cout<<"Weight:"<<weight<<endl;
			cout<<"Laptop Type:"<<Laptop_Type<<endl;
			cout<<"Usage:"<<Usage<<endl;		
		}
};

/*******************Class Male_Clothing*****************
->It publically inherits class Clothing_Products
->Contains various attributes and behaviours
*******************************************************/

class Male_Clothing: public Clothing_Products
{
	string Tshirt_Type;
	string Shirt_Type;
	string Jeans_Type;
	string Suit_Blazer_Type;
	public:
		string return_Tshirt_Type()
		{
			return Tshirt_Type;
		}
		string return_Shirt_Type()
		{
			return Shirt_Type;
		}
		string return_Jeans_Type()
		{
			return Jeans_Type;
		}
		string return_Suit_Blazer_Type()
		{
			return Suit_Blazer_Type;
		}
		void get_data()
		{
			get_clothingdetails();
			cout<<"Enter NIL if you don't want to purchase that product"<<endl;
			cout<<"Enter T-shirt type:\n";
			cin>>Tshirt_Type;
			cout<<"Enter Shirt type:\n";
			cin>>Shirt_Type;
			cout<<"Enter Jeans Type:\n";
			cin>>Jeans_Type;
			cout<<"Enter Suit/Blazer Type:\n";
			cin>>Suit_Blazer_Type;
		}
		void show_data()
		{
			show_clothingdetails();
			cout<<"T-shirt:"<<Tshirt_Type<<endl;
			cout<<"Shirt:"<<Shirt_Type<<endl;
			cout<<"Jeans:"<<Jeans_Type<<endl;
			cout<<"Suit/Blazer:"<<Suit_Blazer_Type<<endl;		
		}
};

/*******************Class Female_Clothing***************
->It publically inherits class Clothing_Products
->Contains various attributes and behaviours
*******************************************************/

class Female_CLothing: public Clothing_Products
{
	string Jumpsuit_Style;
	string Skirt_Style;
	string Top_Style;
	string Saree_Style;
	public:
		Female_Clothing()
		{
			Jumpsuit_Style="NULL";
			Skirt_Style="NULL";
			Top_Style="NULL";
			Saree_Style="NULL";
		}
		string return_Jumpsuit_Style()
		{
			return Jumpsuit_Style;
		}
		string return_Skirt_Style()
		{
			return Skirt_Style;
		}
		string return_Top_Style()
		{
			return Top_Style;
		}
		string return_Saree_Style()
		{
			return Saree_Style;
		}
	
		void get_data()
		{
			get_clothingdetails();
			cout<<"Enter NIL if you don't want to purchase that product"<<endl;
			cout<<"Enter Jumpsuit Style:\n";
			cin>>Jumpsuit_Style;
			cout<<"Enter Skirt Style:\n";
			cin>>Skirt_Style;
			cout<<"Enter Top Style:\n";
			cin>>Top_Style;
			cout<<"Enter Saree Style:\n";
			cin>>Saree_Style;
		}
		void show_data()
		{
			show_clothingdetails();
			cout<<"Jumpsuit:"<<Jumpsuit_Style<<endl;
			cout<<"Skirt:"<<Skirt_Style<<endl;
			cout<<"Top:"<<Top_Style<<endl;
			cout<<"Saree:"<<Saree_Style<<endl;			
		}
};

/*******************Class Kids_Clothing******************
->It publically inherits class Clothing_Products
->Contains various attributes and behaviours
*******************************************************/

class Kids_Clothing: public Clothing_Products
{
	int Age;
	string PlazzoSet_Style;
	string AnarkaliSuit_Style;
	string DhotiKurta_Style;
	string ShirtJean_Style;
	public:
		Kids_Clothing()
		{
			Age=0;
			PlazzoSet_Style="NULL";
			AnarkaliSuit_Style="NULL";
			DhotiKurta_Style="NULL";
			ShirtJean_Style="NULL";
		}
		int return_Age()
		{
			return Age;
		}
		string return_PlazzoSet_Style()
		{
			return PlazzoSet_Style;
		}
		string return_AnarkaliSuit_Style()
		{
			return AnarkaliSuit_Style;
		}
		string return_DhotiKurta_Style()
		{
			return DhotiKurta_Style;
		}
		string return_ShirtJean_Style()
		{
			return ShirtJean_Style;
		}
		void get_data()
		{
			get_clothingdetails();
			cout<<"Enter NIL if you don't want to purchase the product"<<endl;
			cout<<"Enter PlazzoSet style:\n";
			cin>>PlazzoSet_Style;
			cout<<"Enter Anarkali Suit type:\n";
			cin>>AnarkaliSuit_Style;
			cout<<"Enter Dhoti Kurta Type:\n";
			cin>>DhotiKurta_Style;
			cout<<"Enter Shirt Jean combo Type:\n";
			cin>>ShirtJean_Style;
		}
		void show_data()
		{
			show_clothingdetails();
			cout<<"Plazzo-Set:"<<PlazzoSet_Style<<endl;
			cout<<"Anarkali Suit:"<<AnarkaliSuit_Style<<endl;
			cout<<"Dhoti Kurta:"<<DhotiKurta_Style<<endl;
			cout<<"Shirt Jean Combo:"<<ShirtJean_Style<<endl;				
		}
};

/**************Class Kitchen_Furnishings***************
->It publically inherits class Home_DecorProducts
->Contains various attributes and behaviours
*******************************************************/
class Kitchen_Furnishings: public Home_DecorProducts
{
 	string Crockery_Type;
	string Cookware_Set_Type;
	string Casseroles_Type;
	string Copperware_Type;
	public:
		Kitchen_Furnishings()
		{
			Crockery_Type="NULL";
			Cookware_Set_Type="NULL";
			Casseroles_Type="NULL";
			Copperware_Type="NULL";
		}
		string return_Crockery_Type()
		{
			return Crockery_Type;
		}
		string return_Cookware_Set_Type()
		{
			return Cookware_Set_Type;
		}
		string return_Casseroles_Type()
		{
			return Casseroles_Type;
		}
		string return_Copperware_Type()
		{
			return Copperware_Type;
		}
		void get_data()
		{
		get_homedecor_details();
			cout<<"Enter NIL if you don't want to purchase the product"<<endl;
			cout<<"Enter Crockery Type:\n";
			cin>>Crockery_Type;
			cout<<"Enter Cookware Set Type:\n";
			cin>>Cookware_Set_Type;
			cout<<"Enter Casseroles Type:\n";
			cin>>Casseroles_Type;
			cout<<"Enter Copperware Type:\n";
			cin>>Copperware_Type;
		}
		void show_data()
		{
			show_homedecor_details();
			cout<<"Crockery:"<<Crockery_Type<<endl;
			cout<<"Cookware Set:"<<Cookware_Set_Type<<endl;
			cout<<"Casseroles:"<<Casseroles_Type<<endl;
			cout<<"Copperware:"<<Copperware_Type<<endl;				
		}
		
};

/*******************Class Gardening_Products*************
->It publically inherits class Home_DecorProducts
->Contains various attributes and behaviours
*******************************************************/


class Gardening_Products: public Home_DecorProducts
{
	string Seed_Type;
	string Indoor_Plants_Type;
	string Wind_Chimes_Type;
	string BarbequeGrills_Type;
	string Solar_Lights_Type;
	public:
		Gardening_Products()
		{
			Seed_Type="NULL";
			Indoor_Plants_Type="NULL";
			Wind_Chimes_Type="NULL";
			BarbequeGrills_Type="NULL";
			Solar_Lights_Type="NULL";
		}
		string return_Seed_Type()
		{
			return Seed_Type;
		}
		string return_Indoor_Plants_Type()
		{
			return Indoor_Plants_Type;
		}
		string return_Wind_Chimes_Type()
		{
			return Wind_Chimes_Type;
		}
		string return_BarbequeGrills_Type()
		{
			return BarbequeGrills_Type;
		}
		string return_Solar_Lights_Type()
		{
			return Solar_Lights_Type;
		}
		void get_data()
		{
			get_homedecor_details();
			cout<<"Enter NIL if you don't want to purchase the product"<<endl;
			cout<<"Enter Seed Type:\n";
			cin>>Seed_Type;
			cout<<"Enter Indoor Plants Type:\n";
			cin>>Indoor_Plants_Type;
			cout<<"Enter Wind Chimes Type:\n";
			cin>>Wind_Chimes_Type;
			cout<<"Enter Barbeque Grills Type:\n";
			cin>>BarbequeGrills_Type;
			cout<<"Enter Solar Lights Type:\n";
			cin>>Solar_Lights_Type;
		}
		void show_data()
		{
			show_homedecor_details();
			cout<<"Seed:"<<Seed_Type<<endl;
			cout<<"Indoor Plants:"<<Indoor_Plants_Type<<endl;
			cout<<"Wind Chimes:"<<Wind_Chimes_Type<<endl;
			cout<<"Barbeque Grills:"<<BarbequeGrills_Type<<endl;
			cout<<"Solar Lights:"<<Solar_Lights_Type<<endl;			
		}
		
};

	template<class T>
	void write_product( T pr)
	{
		fp.open("ShopifyProducts.dat",ios::out|ios::app);
		pr.get_product_details();
		fp.write((char*)&pr,sizeof(Product));
		fp.close();
		cout<<"\n\nThe Product Has Been Created ";
		getch();
    }
    
    template<class T>
	void display_all( T pr)
	{
		cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	    fp.open("ShopifyProducts.dat",ios::in);
	    while(fp.read((char*)&pr,sizeof(Product)))
		{
			pr.show_product_details();
			cout<<"\n\n====================================\n";
			getch();
		}
	    fp.close();
	    getch();
    }
    
    template<class> T
    void display_sp(T pr,int n)
	{
    	int flag=0;
    	fp.open("ShopifyProducts.dat",ios::in);
	    while(fp.read((char*)&pr,sizeof(product)))
		{
		 if(pr.retpno()==n)
			{
			// clrscr();
			 pr.show_product_details();
			 flag=1;
			}
		}
    	fp.close();
		if(flag==0)
 		cout<<"\n\nrecord not exist";
   		getch();
	}
	
	template<class T > 
	void modify_product(T pr)
	{
    	int no,found=0;
  		 // clrscr();
  	  	cout<<"\n\n\tTo Modify ";
    	cout<<"\n\n\tPlease Enter The Product No. of The Product";
    	cin>>no;
   		 fp.open("Shop.dat",ios::in|ios::out);
	    while(fp.read((char*)&pr,sizeof(pr)) && found==0)
		   {
		    if(pr.retpno()==no)
			   {
			    pr.show_product_details();
			    cout<<"\nPlease Enter The New Details of Product"<<endl;
			    pr.get_product_details();
			    int pos=-1*sizeof(pr);
			    fp.seekp(pos,ios::cur);
			    fp.write((char*)&pr,sizeof(product));
			    cout<<"\n\n\t Record Updated";
			    found=1;
			   }
		    }
   		 fp.close();
   		 if(found==0)
    		cout<<"\n\n Record Not Found ";
    	getch();
	}
	
	template<class T> 
	void delete_product( T pr)
   {
	    int no;
	   // clrscr();
	    cout<<"\n\n\n\tDelete Record";
	    cout<<"\n\nPlease Enter The product no. of The Product You Want To Delete";
	    cin>>no;
	    fp.open("ShopifyProducts.dat",ios::in|ios::out);
	    fstream fp2;
	    fp2.open("Temp.dat",ios::out);
	    fp.seekg(0,ios::beg);
	    while(fp.read((char*)&pr,sizeof(pr)))
		{
		 if(pr.retpno()!=no)
			{
			 fp2.write((char*)&pr,sizeof(pr));
			}
		}
	    fp2.close();
	    fp.close();
	    remove("ShopifyProducts.dat");
	    rename("Temp.dat","ShopifyProducts.dat");
	    cout<<"\n\n\tRecord Deleted ..";
	    getch();
    }

void intro()
{
// clrscr();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX info;
	GetConsoleScreenBufferInfoEx(hConsole,&info);
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 10;                   // Width of each character in the font
	cfi.dwFontSize.Y = 24;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy(cfi.FaceName, L"Gigi"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
//	info.ColorTable[3]=RGB(135,206,235);
//	info.ColorTable[2]=RGB(25,0,120);
//	stack<Gardening_Products> gp;
//	stack<Kitchen_Furnishings> kf;
//	stack<Male_Clothing>m;
//	stack<Female_CLothing> f;
//	stack<Kids_Clothing> k;
//	stack<Laptop> l;
//	stack<Mobile> mo;
//	queue<User> u;
SetConsoleTextAttribute(hConsole,9);
	cout<<"\t****************************************************************************************************************"<<endl;
	cout<<endl;
	SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_BLUE| FOREGROUND_INTENSITY));
	cout<<"\t\t\t"<<" "<<" *********"<<" "<<"*      *"<<" "<<"*********"<<" "<<"*********"<<" "<<"********"<<" "<<"*******"<<" "<<"*      *"<<endl;
	cout<<"\t\t\t"<<" "<<" *        "<<" "<<"*      *"<<" "<<"*       *"<<" "<<"*       *"<<" "<<"    *   "<<" "<<"*      "<<" "<<" *    * "<<endl;
	cout<<"\t\t\t"<<" "<<" *********"<<" "<<"********"<<" "<<"*       *"<<" "<<"*********"<<" "<<"    *   "<<" "<<"*******"<<" "<<"    *   "<<endl;
	cout<<"\t\t\t"<<" "<<"         *"<<" "<<"*      *"<<" "<<"*       *"<<" "<<"*        "<<" "<<"    *   "<<" "<<"*      "<<" "<<"    *   "<<endl;
	cout<<"\t\t\t"<<" "<<" *********"<<" "<<"*      *"<<" "<<"*********"<<" "<<"*        "<<" "<<"********"<<" "<<"*      "<<" "<<"    *   "<<endl;
	cout<<endl;
SetConsoleTextAttribute(hConsole,9);
	cout<<"\t****************************************************************************************************************"<<endl;
	cout<<endl;
SetConsoleTextAttribute(hConsole,3);	
 cout<<"\n\nMADE BY : DIVIJ AGARWAAL (9918103012)"<<" "<<"RUDRAKSH BHARADWAJ (9918103020)"<<" "<<"REVAAN MISHRA (9918103016)"<<"SIMRAN SHILKY (9918103027)"<<endl;
 getch();

}

void customer_choice(){
	int menu_item=0, run, x=7;
	bool running = true;
	gotoXY(20,24); cout<<"\t\t\tWelcome to Shopify!!!"<<" "<<"What do you wish to buy Today??"<<endl;
	cout<<endl;
	gotoXY(20,25); cout << "List of Products";
	gotoXY(20,27); cout << "->";
	
	while(running)  
	{
		   
		gotoXY(22,27);  cout << ":: Electronic Products";
		gotoXY(22,28);  cout << "\t:->Mobile             ";
		gotoXY(22,29);  cout << "\t:->Laptop             ";	
		gotoXY(22,30); cout << ":: Clothing";
		gotoXY(22,31); cout << "\t:->Men";
		gotoXY(22,32); cout << "\t:->Women";
		gotoXY(22,33); cout << "\t:->Kids";
		gotoXY(22,34); cout<<"::Home Decor";
		gotoXY(22,35); cout<<":->Gardening Products";
		gotoXY(22,36); cout<<":->Kitchen Essentix  als";
	    gotoXY(22,37); cout<<"::Quit";

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 37) //down button pressed
			{
				gotoXY(22,x); cout << "  ";
				x++;
				gotoXY(22,x); cout << "->";
				menu_item++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x !=27) //up button pressed
			{
				gotoXY(22,x); cout << "  ";
				x--;
				gotoXY(22,x); cout << "->";
				menu_item--;
				continue;
			}
			Customer C;
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			
			switch(menu_item){
				
				case 1: {
					
					gotoXY(22,39);
					cout << "Mobile     ";
					Mobile m;
					C.cplace_order("ShopifyMobile",m);
					break;
				}
					
					
				case 2: {
					gotoXY(22,39);
					cout << "Laptop     ";
					Laptop l;
					C.cplace_order("ShopifyLaptop", l);
					break;
				}
					
				case 4: {
					gotoXY(22,39);
					cout << "Men Clothing    ";
					Male_Clothing men;
					C.cplace_order("ShopifyMen",men);
					break;
				}
					
				case 5: {
					gotoXY(22,39);  
					cout << "Women Clothing     ";
					Female_Clothing fem;
					C.cplace_order("ShopifyWomen",fem);
					break;
				}
				case 6: {
					gotoXY(22,39);
					cout << "Kids Clothing     ";
					Kids_Clothing k;
					C.cplace_order("ShopifyKids",k);
					break;
				}
				case 8: {
					gotoXY(22,39);
					cout << "Gardening Needs    ";
					Gardening_Products g;
					C.cplace_order("ShopifyGarden",g);
					break;
				}
				case 9: {
					gotoXY(22,39);
					cout << "Kitchen Essentials     ";
					Kitchen_Furnishings kit;
					C.cplace_order("ShopifyKitchen",kit);
					break;
				}
					
				case 10: {
					gotoXY(22,39);
					cout << "The program has now terminated!!";
					running = false;
				}
				
			}
				
		}		
		
	}
}

int main(void)
{	
	intro();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX info;
	GetConsoleScreenBufferInfoEx(hConsole,&info);
	char ch='0';
	 do
    {
	  //clrscr();
	  cout<<"\n\n\n\tMAIN MENU";
	  cout<<"\n\n\t01. CUSTOMER";
	  cout<<"\n\n\t02. ADMINISTRATOR";
	  cout<<"\n\n\t03. EXIT";
	  cout<<"\n\n\tPlease Select Your Option (1-3) ";
	  ch=getche();
	  switch(ch)
	  {
		 case '1': //clsrcr();
			  customer_choice();
			   getch();
			   break;
		  case '2': Admin a;
		  			a.admin_menu();
			    break;
		  case '3':exit(0);
		  default :cout<<"\a";
	}
    }while(ch!='3');
	
	gotoXY(22,40);	
	
	SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN));//default background
	return 0;
}
