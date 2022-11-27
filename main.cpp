#include <iostream>//include for input-output stream library
#include <fstream>//include for file stream library
#include <iomanip>//include for io manipulation library
#include <vector>//include for vector library
#include<string> //include for string library
#include<algorithm>//include for algorithm library
#include "stockType.h"//header file for stock Type objects declaration
#include "stockList.h" //header file for stcok List objects declaration
#include<windows.h>
using namespace std;

const int a = 5;
int flag =0; // Flag for file checking
void getData(stockList& list) //Function to get data from file and save it to stock type object
{
   ifstream infile;
   string fileName;
   string symbol;
   double OpenPrice;
   double ClosePrice;
   double tHigh;
   double tLow;
   double yClose;
   int       shares;

   stockType temp;
   cout<<"Please enter the stock data file name"<<endl;
   getline(cin,fileName);// Gets file name from user
   infile.open(fileName);// Opens file
   if (!infile) // returns error if file entered does not exist
   {
       cout << "The file you entered does not exist" << endl;
       flag=5;
   }
   else
   {
       infile >> symbol;
       while (infile) // Move data from file to stock inturn stock list
       {
           infile >> OpenPrice >> ClosePrice >> tHigh >> tLow >> yClose >> shares;
           temp.setStockInfo(symbol,OpenPrice,ClosePrice,tHigh,tLow,yClose,shares);
           list.insert(temp);
           infile >> symbol;
       }

   }
};

int main()
{
   stockList stockList; // create stock list object
   cout << fixed << showpoint;
   cout << setprecision(2);
   getData(stockList); // copy data a from file to the stcoklist object
   if(flag==0)
   {
       stockList.sortStockList();// Sort input data
       stockList.printBySymbol();//Print by sort list by symbol
       cout << endl;
       stockList.printByGain();//Print data by sorted list by gain
   }


   return 0;
}
