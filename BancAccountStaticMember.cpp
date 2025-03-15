#include <iostream>
#include <string>

using namespace std;

class BankAccount 
{
  private:
    string AccountNumber;
    int Balance;
    // Set the compiler to C++ 20 to use inline static data member initialization!
    inline static int AccNo=0;
    static int TotalBalance;
  public:
    BankAccount(string an, int bal) 
    {
      AccountNumber = an;
      Balance = bal;
      AccNo++;
      TotalBalance += bal;
    }
    static int getTotalBalance() 
    {
      return TotalBalance;
    }
    static string toString(int num) 
    {
      string str = to_string(num);
      int len = str.length();
      string result;
      int count = 0;
      for (int i = len - 1; i >= 0; i--) 
      {
        result = str[i] + result;
        count++;
        if (count == 3) 
        {
          result = " " + result;
          count = 0;
        }
      }
      if (result[0] == ' ') 
      {
        result = result.substr(1);
      }
      return result;
    }
};

// Initialize static data members.
//int BankAccount::AccNo = 0;
int BankAccount::TotalBalance = 0;
// Note: static data members are initialized to zero 
// when the first object of the class is created if they 
// are not initialized in any other way.

int main()
{
  // Create three bank accounts
  BankAccount ba1("1115-2351-4562-6523", 1000000);
  BankAccount ba2("1115-2352-4587-9658", 2500000);
  BankAccount ba3("1115-5236-5412-4561", 500000);

  cout << "Total balance: " << fixed << 
    BankAccount::toString(BankAccount::getTotalBalance()) << " Ft" << endl;
  return 0;
}