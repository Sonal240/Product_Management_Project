#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
using namespace std;

fstream fp;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto
void gotoXY(int x, int y) 
{ 
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}
#define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array
int printSolution(int dist[])
{
    int a[V][2];
    for (int i = 0; i < V; i++)
    {
        a[i][0]=201304+i;
        a[i][1]=dist[i];
    }
    cout<<"available pin code for delivery\n";
    int j;
    for(j=0;j<V;j++)
    {
        cout<<a[j][0];
        cout<<" estimated delivery date for each pin code is "<<a[j][1]<<"\n";
    }
    int p;
    cout<<"Enter your adderess pin code\n";
    cin>>p;
    for(j=0;j<V;j++)
    {
        if(a[j][0]==p)
        {
            cout<<"your order is placed and will be delivered within "<<a[j][1]<<" working days on pin code "<<a[j][0];
            break;
        }
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}
class Products
{
	int product_id;
	float price;
	string brand_name;
	int eligible_for_cod;
	string seller_name;
	int quantity;
	float discount;
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
		float return_discount()
		{
			return discount;
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
			cout<<"Enter dicount percentage availed on this product:\n";
			cin>>discount;
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
			cout<<"Discount given:"<<discount;
		}	

};

class Mobile: public Products
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
			get_product_details();
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
			show_product_details();
			cout<<"Performance:"<<Performance<<endl;
			cout<<"Front Camera(MP):"<<FrontCamera<<endl;
			cout<<"Rear Camera(MP):"<<RearCamera<<endl;
			if(Touch_avail==0)
			cout<<"Youch is not available for this device"<<endl;
			else cout<<"Touch is available for the device"<<endl;
			cout<<"Security and Connectivity:"<<Security_Connectivity<<endl;		
		}
		
};


class Kids_Clothing: public Products
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
			get_product_details();
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
			show_product_details();
			cout<<"Plazzo-Set:"<<PlazzoSet_Style<<endl;
			cout<<"Anarkali Suit:"<<AnarkaliSuit_Style<<endl;
			cout<<"Dhoti Kurta:"<<DhotiKurta_Style<<endl;
			cout<<"Shirt Jean Combo:"<<ShirtJean_Style<<endl;				
		}
};

class Gardening_Products: public Products
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
			get_product_details();
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
			show_product_details();
			cout<<"Seed:"<<Seed_Type<<endl;
			cout<<"Indoor Plants:"<<Indoor_Plants_Type<<endl;
			cout<<"Wind Chimes:"<<Wind_Chimes_Type<<endl;
			cout<<"Barbeque Grills:"<<BarbequeGrills_Type<<endl;
			cout<<"Solar Lights:"<<Solar_Lights_Type<<endl;			
		}
		
};
Mobile m;
Kids_Clothing k;
Gardening_Products g;

class Customer
{
	string name;
	long phone_number;
	string address;
	int pincode;
	public:
		void get_info() 
		{
			cout<<"Enter Name:\n";
			cin>>name;
			cout<<"Enter Phone Number\n:";
			cin>>phone_number;
			cout<<"Enter Address:";
			cin>>address;
			cout<<"Enter Area pincode:";
			cin>>pincode;
		}
		void show_info() 
		{
			cout<<"Name:"<<name<<endl;
			cout<<"Phone Number:"<<phone_number<<endl;
			cout<<"Address:"<<address<<endl;
			cout<<"Pincode:"<<pincode<<endl;
		}
		void place_order(char a[20]);
};
 void menu(char a[20])
    {
     //clrscr();
     fp.open(a,ios::in);
     if(strcmp(a,"ShopifyKids.dat")==0)
     {
     	
     	if(!fp)
     {
       cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
       cout<<"\n\n\n Program is closing ....";
       getch();
       exit(0);
     }

     cout<<"\n\n\t\tProduct MENU\n\n";
	  cout<<"====================================================\n";
	  cout<<"P.NO.\t\tNAME\t\tPRICE\n";
	  cout<<"====================================================\n";

      while(fp.read((char*)&k,sizeof(k)))
	 {
	   cout<<k.return_product_id()<<"\t\t"<<k.return_bname()<<"\t\t"<<k.return_price()<<endl;
	 }
     fp.close();
	 }
	 else if(strcmp(a,"ShopifyGarden.dat")==0)
	 {
	 		if(!fp)
     {
       cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
       cout<<"\n\n\n Program is closing ....";
       getch();
       exit(0);
     }

     cout<<"\n\n\t\tProduct MENU\n\n";
	  cout<<"====================================================\n";
	  cout<<"P.NO.\t\tNAME\t\tPRICE\n";
	  cout<<"====================================================\n";

      while(fp.read((char*)&g,sizeof(g)))
	 {
	   cout<<g.return_product_id()<<"\t\t"<<g.return_bname()<<"\t\t"<<g.return_price()<<endl;
	 }
     fp.close();
	 }
	 else if(strcmp(a,"ShopifyMobile.dat")==0)
	 {
	 		if(!fp)
     {
       cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
       cout<<"\n\n\n Program is closing ....";
       getch();
       exit(0);
     }

     cout<<"\n\n\t\tProduct MENU\n\n";
	  cout<<"====================================================\n";
	  cout<<"P.NO.\t\tNAME\t\tPRICE\n";
	  cout<<"====================================================\n";

      while(fp.read((char*)&m,sizeof(m)))
	 {
	   cout<<m.return_product_id()<<"\t\t"<<m.return_bname()<<"\t\t"<<m.return_price()<<endl;
	 }
     fp.close();
	 }
     
}
void Customer::place_order(char a[20]){
	 int  order_arr[50],quan[50],c=0;
    float amt,damt,total=0;
    char ch='Y';
    menu(a);
    if(strcmp(a,"ShopifyKids.dat")==0)
    {
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
      cout<<"\n\n********************************INVOICE************************\n";
      cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
      for(int x=0;x<=c;x++)
	{
		 fp.open(a,ios::in);
		 fp.read((char*)&k,sizeof(k));
		  while(!fp.eof())
			{
			if(k.return_product_id()==order_arr[x])
				{
				 amt=k.return_price()*quan[x];
				 damt=amt-(amt*k.return_discount()/100);
				 cout<<"\n"<<order_arr[x]<<"\t"<<k.return_bname()<<"\t"<<quan[x]<<"\t\t"<<k.return_price()<<"\t"<<amt<<"\t\t"<<damt;
				 total+=damt;
				}
			fp.read((char*)&k,sizeof(k));
			}

		 fp.close();
	 }
       cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
       int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);
	}
	else if(strcmp(a,"ShopifyGarden.dat")==0)
	{
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
      cout<<"\n\n********************************INVOICE************************\n";
      cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
      for(int x=0;x<=c;x++)
	{
		 fp.open(a,ios::in);
		 fp.read((char*)&g,sizeof(g));
		  while(!fp.eof())
			{
			if(g.return_product_id()==order_arr[x])
				{
				 amt=g.return_price()*quan[x];
				 damt=amt-(amt*g.return_discount()/100);
				 cout<<"\n"<<order_arr[x]<<"\t"<<g.return_bname()<<"\t"<<quan[x]<<"\t\t"<<g.return_price()<<"\t"<<amt<<"\t\t"<<damt;
				 total+=damt;
				}
			fp.read((char*)&g,sizeof(g));
			}

		 fp.close();
	 }
       cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
       int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);
	}
	else if(strcmp(a,"ShopifyMobile.dat")==0)
	{
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
      cout<<"\n\n********************************INVOICE************************\n";
      cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
      for(int x=0;x<=c;x++)
	{
		 fp.open(a,ios::in);
		 fp.read((char*)&m,sizeof(m));
		  while(!fp.eof())
			{
			if(m.return_product_id()==order_arr[x])
				{
				 amt=m.return_price()*quan[x];
				 damt=amt-(amt*m.return_discount()/100);
				 cout<<"\n"<<order_arr[x]<<"\t"<<m.return_bname()<<"\t"<<quan[x]<<"\t\t"<<m.return_price()<<"\t"<<amt<<"\t\t"<<damt;
				 total+=damt;
				}
			fp.read((char*)&m,sizeof(m));
			}

		 fp.close();
	 }
       cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
       int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);
	}
   
    getch();
}



void write_product(char filename[50])
   {
    fp.open(filename,ios::out|ios::app);
    //pr.create_product();
	if(strcmp(filename,"ShopifyKids.dat")==0)
	{
		k.get_data();
		fp.write((char*)&k,sizeof(k));
    	fp.close();
	}
    else if(strcmp(filename,"ShopifyGarden.dat")==0)
    {
    	g.get_data();
		fp.write((char*)&g,sizeof(g));
    	fp.close();
	}
	else if(strcmp(filename,"ShopifyMobile.dat")==0)
	{
		m.get_data();
		fp.write((char*)&m,sizeof(m));
    	fp.close();
	}
    cout<<"\n\nThe Product Has Been Created ";
    getch();
   }


//***************************************************************
//    	function to read all records from file
//****************************************************************


void display_all(char filename[50])
{
    //clrscr();
    cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    fp.open(filename,ios::in);
    if(strcmp(filename,"ShopifyKids.dat")==0)
	{
		while(fp.read((char*)&k,sizeof(k)))
		{
		k.show_data();
	 	cout<<"\n\n====================================\n";
		getch();
	 	}
    fp.close();
	}
    else if(strcmp(filename,"ShopifyGarden.dat")==0)
    {
    	while(fp.read((char*)&g,sizeof(g)))
		{
		g.show_data();
	 	cout<<"\n\n====================================\n";
		getch();
	 	}
    fp.close();
	}
	else if(strcmp(filename,"ShopifyMobile.dat")==0)
	{
		while(fp.read((char*)&m,sizeof(m)))
		{
		m.show_data();
	 	cout<<"\n\n====================================\n";
		getch();
	 	}
    fp.close();
	}
   
    getch();
}


//***************************************************************
//    	function to read specific record from file
//****************************************************************


void display_sp(char filename[50],int n)
{
    int flag=0;
    fp.open(filename,ios::in);
   
    if(strcmp(filename,"ShopifyKids.dat")==0)
	{
	    while(fp.read((char*)&k,sizeof(k)))
		{
	 		if(k.return_product_id()==n)
			{
				// clrscr();
		 	k.show_data();
		 	flag=1;
			}
		}
    	fp.close();
		if(flag==0)
 		cout<<"\n\nrecord not exist";
    	getch();
	}
    else if(strcmp(filename,"ShopifyGarden.dat")==0)
    {
     while(fp.read((char*)&g,sizeof(g)))
		{
	 		if(g.return_product_id()==n)
			{
				// clrscr();
		 	g.show_data();
		 	flag=1;
			}
		}
    	fp.close();
		if(flag==0)
 		cout<<"\n\nrecord not exist";
    	getch();
	}
	else if(strcmp(filename,"ShopifyMobile.dat")==0)
	{
		 while(fp.read((char*)&m,sizeof(m)))
		{
	 		if(m.return_product_id()==n)
			{
				// clrscr();
		 	m.show_data();
		 	flag=1;
			}
		}
    	fp.close();
		if(flag==0)
 		cout<<"\n\nrecord not exist";
    	getch();
	}
   
    getch();
}


//***************************************************************
//    	function to modify record of file
//****************************************************************


void modify_product(char filename[50])
{
    int no,found=0;
   // clrscr();
    if(strcmp(filename,"ShopifyKids.dat")==0)
	{
		cout<<"\n\n\tTo Modify ";
    	cout<<"\n\n\tPlease Enter The Product No. of The Product";
    	cin>>no;
    	fp.open(filename,ios::in|ios::out);
		while(fp.read((char*)&k,sizeof(k)) && found==0)
	   {
	    if(k.return_product_id()==no)
		   {
		    k.show_data();
		    cout<<"\nPlease Enter The New Details of Product"<<endl;
		    k.get_data();
		    int pos=-1*sizeof(k);
		    fp.seekp(pos,ios::cur);
		    fp.write((char*)&k,sizeof(k));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		   }
	     }
   		 fp.close();
    	 if(found==0)
   		 cout<<"\n\n Record Not Found ";
    	getch();
	
	}
    else if(strcmp(filename,"ShopifyGarden.dat")==0)
    {
    	cout<<"\n\n\tTo Modify ";
    	cout<<"\n\n\tPlease Enter The Product No. of The Product";
    	cin>>no;
    	fp.open(filename,ios::in|ios::out);
		while(fp.read((char*)&g,sizeof(g)) && found==0)
	   {
	    if(g.return_product_id()==no)
		   {
		    k.show_data();
		    cout<<"\nPlease Enter The New Details of Product"<<endl;
		    k.get_data();
		    int pos=-1*sizeof(g);
		    fp.seekp(pos,ios::cur);
		    fp.write((char*)&g,sizeof(g));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		   }
	     }
   		 fp.close();
    	 if(found==0)
   		 cout<<"\n\n Record Not Found ";
    	getch();
    
	}
	else if(strcmp(filename,"ShopifyMobile.dat")==0)
	{
		cout<<"\n\n\tTo Modify ";
    	cout<<"\n\n\tPlease Enter The Product No. of The Product";
    	cin>>no;
    	fp.open(filename,ios::in|ios::out);
		while(fp.read((char*)&m,sizeof(m)) && found==0)
	   {
	    if(k.return_product_id()==no)
		   {
		    m.show_data();
		    cout<<"\nPlease Enter The New Details of Product"<<endl;
		    m.get_data();
		    int pos=-1*sizeof(m);
		    fp.seekp(pos,ios::cur);
		    fp.write((char*)&m,sizeof(m));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		   }
	     }
   		 fp.close();
    	 if(found==0)
   		 cout<<"\n\n Record Not Found ";
    	getch();
	
	}
	
	
   
}


//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_product(char filename[50])
   {
    int no;
     if(strcmp(filename,"ShopifyKids.dat")==0)
	{
		cout<<"\n\n\n\tDelete Record";
    cout<<"\n\nPlease Enter The product no. of The Product You Want To Delete";
    cin>>no;
    fp.open(filename,ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&k,sizeof(k)))
	{
	 if(k.return_product_id()!=no)
		{
		 fp2.write((char*)&k,sizeof(k));
		 }
	 }
    fp2.close();
    fp.close();
    remove(filename);
    rename("Temp.dat",filename);
    cout<<"\n\n\tRecord Deleted ..";
    getch();
	}
    else if(strcmp(filename,"ShopifyGarden.dat")==0)
    {
    cout<<"\n\n\n\tDelete Record";
    cout<<"\n\nPlease Enter The product no. of The Product You Want To Delete";
    cin>>no;
    fp.open(filename,ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&g,sizeof(g)))
	{
	 if(g.return_product_id()!=no)
		{
		 fp2.write((char*)&g,sizeof(g));
		 }
	 }
    fp2.close();
    fp.close();
    remove(filename);
    rename("Temp.dat",filename);
    cout<<"\n\n\tRecord Deleted ..";
    getch();
    	
	}
	else if(strcmp(filename,"ShopifyMobile.dat")==0)
	{
	 cout<<"\n\n\n\tDelete Record";
    cout<<"\n\nPlease Enter The product no. of The Product You Want To Delete";
    cin>>no;
    fp.open(filename,ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&m,sizeof(m)))
	{
	 if(m.return_product_id()!=no)
		{
		 fp2.write((char*)&m,sizeof(m));
		 }
	 }
    fp2.close();
    fp.close();
    remove(filename);
    rename("Temp.dat",filename);
    cout<<"\n\n\tRecord Deleted ..";
    getch();
	}
    }


void admin_menu()
{
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
  char filename[50];
  switch(ch2)
  {
    case '1': //clrscr();
    		cout<<"Enter name of the file to be written:"<<endl;
    		cin>>filename;
	      write_product(filename);
	      break;
    case '2':
    		cout<<"Enter name of the file to be displayed:"<<endl;
    		cin>>filename;
	 display_all(filename);break;
    case '3':
	       int num;
	       //clrscr();
	       	cout<<"Enter name of the file to be searched:"<<endl;
    		cin>>filename;
	       cout<<"\n\n\tPlease Enter The Product No. ";
	       cin>>num;
	       display_sp(filename,num);
	       break;
      case '4':
      		cout<<"Enter name of the file to be modified:"<<endl;
    		cin>>filename;
	   modify_product(filename);break;
      case '5':	cout<<"Enter name of the file of which product is to be deleted:"<<endl;
    		cin>>filename;
	   delete_product(filename);break;
      case '6': menu(filename);
		getch();
      case '7': break;
      default:cout<<"\a";admin_menu();
   }
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
 cout<<"\n\n\t\t\t\t\tMADE BY :DIVIJ AGARWAAL (9918103012)"<<"\n"<<"\t\t\t\t\t\t RUDRAKSH BHARADWAJ (9918103020)"<<"\n"<<"\t\t\t\t\t\t REVAAN MISHRA (9918103016)"<<"\n"<<"\t\t\t\t\t\t SIMRAN SHILKY (9918103027)"<<endl;
 getch();

}

void customer_choice(){
	system("cls");
	intro();
	int menu_item=0, run, x=27;
	bool running = true;
	gotoXY(20,24); cout<<"\t\t\tWelcome to Shopify!!!"<<" "<<"What do you wish to buy Today??"<<endl;
	cout<<endl;
	gotoXY(20,25); cout << "List of Products";
//	gotoXY(20,27); cout << "->";
	
	while(running)  
	{
		   
		gotoXY(25,28);  cout << ":->Mobile";	
		gotoXY(25,29); cout << ":->Kids";
		gotoXY(25,30); cout<<":->Gardening Products";
	    gotoXY(25,31); cout<<"::Quit";

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 32) //down button pressed
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
					C.place_order("ShopifyMobile.dat");
					break;
				}
				case 2: {
					gotoXY(22,39);
					cout << "Kids Clothing ";
					C.place_order("ShopifyKids.dat");
					break;
				}
				case 3: {
					gotoXY(22,39);
					cout << "Gardening Needs ";
					C.place_order("ShopifyGarden.dat");
					break;
				}

				case 4: {
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
char ch;
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
		 case '1': //clrscr();
			   customer_choice();
			   getch();
			   break;
	     case '2': admin_menu();
			    break;
		  case '3':exit(0);
		  default :cout<<"\a";
	}
    }while(ch!='3');
    
	return 0;
}
