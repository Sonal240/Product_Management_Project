#include<iostream>
using namespace std;

/********************** Class User**************************************
-> Contains details about User/ Buyer of a particular product
->Constructor initialises data members of the class 
->Getter function which when called takes input from the user
->Display function which when called shows the input taken from the user
***********************************************************************/
class User
{
	int user_id;
	string name;
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
virtual	float return_discount_price(int discount_percent)
		{
			return price-(price*(discount_percent/100));
		}
};


/***********************Class Electronic_Products***********************
->This class publically inherits the Product class 
->It is further inherited publically by class Mobile and class Computer
***********************************************************************/
class Electronic_Products : public Product
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
};



/***********************Class Clothing_Products***********************
->This class publically inherits the Product class 
->It is further inherited publically by class Male_Clothing, class Female
_Clothing and Kids_Clothing
***********************************************************************/
class Clothing_Products: public Product
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
};



/***********************Class Home_DecorProducts***********************
->This class publically inherits the Product class 
->It is further inherited publically by class Kitchen_Furnishings and Class
Gardening_Products
***********************************************************************/
class Home_DecorProducts: public Product
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
};


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
};



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
};



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
};



class Female_CLothing: public Clothing_Products
{
	string Jumpsuit_Style;
	string Skirt_Style;
	string Top_Style;
	string Saree_Style;
	string Unsitched_Material;
	public:
		Female_Clothing()
		{
			Jumpsuit_Style="NULL";
			Skirt_Style="NULL";
			Top_Style="NULL";
			Saree_Style="NULL";
			Unsitched_Material="NULL";
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
		string return_Unsitched_Material()
		{
			return Unsitched_Material;
		}
};



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
};





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

		
};




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
		
};


int main(void)
{
	
	return 0;
}
