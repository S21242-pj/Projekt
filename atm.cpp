#include <iostream>
#include <string> 
#include <cstdio>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void menu();
void withdraw();
void start();
void closeSession();
void createAccount();
void switchstart();
void choiceMenu();

//Admin ACC

int accountDetails[] = { 
     1234,    //PIN
     5678,    //LOGIN
     10000,    //CREDITS
};

//Authorization check

bool validateAccount(int pin, int login){
    if (pin == accountDetails[0] && login == accountDetails[1]){
        return true;
    } else {
        return false;
    }
}

//Its for next update. (Sign up)

struct newacc{
    string log;
    int passwd;
    int balance;
};
      
// How much money you want withdraw
      
int getWithdraw()
{
    int withdrawAmount;
    cout << "\n\n";
    cout << "\t+========================+\n";
    cout << "\t|Please enter amount to  |\n";
    cout << "\t| withdraw money $$$     |\n";
    cout << "\t+========================+\n";
    cout << "\tEnter amount: ";
    cin >> withdrawAmount;
    
    
   if(withdrawAmount < accountDetails[2])
   {
        sleep(1);
        accountDetails[2] -= withdrawAmount;
        cout << "\n\n";
        cout << "\t+========================+\n";
        cout << "\t  Your current credist: ";
        cout << accountDetails[2] <<"\n";
        cout << "\t+========================+\n";
        sleep(1);
        menu();
   } else {
   cout << "\n\n";
   cout << "\t You try to withdraw more than you have!\n";
   cout << "\t Try again;\n";
   getWithdraw();
   }
    


    return 0;
}      
      
// How much money you want deposit.      
      
int getDeposit()
{
    int depositAmount;
    cout << "\n\n";
    cout << "\t+========================+\n";
    cout << "\t| Please enter amount to |\n";
    cout << "\t| deposit in out PJ-BANK |\n";
    cout << "\t+========================+\n";
    cout << "\n";
    cout << "\tEnter amount: ";
    cin >> depositAmount;
    
    
    if(depositAmount > 0){
        
    sleep(1); 
    accountDetails[2]+= depositAmount;
    cout << "\n\n";
    cout << "\t+========================+\n";
    cout << "\t  Your current credist: ";
    cout << accountDetails[2] <<"\n";
    cout << "\t+========================+\n";
       
    sleep(1);
    menu();
    } else {
    sleep(1);
    cout << "\n\n";
    cout << "\t You enter invalid number\n";
    cout << "\t Try again!\n";
    sleep(1);
    getDeposit();
    }
    
/*    sleep(1);
    
    cout << "\n\n";
    cout << "\t+========================+\n";
    cout << "\t  Your current credist: ";
    cout << accountDetails[2] <<"\n";
    cout << "\t+========================+\n";
       
    sleep(2);
    menu(); */
    
    return 0;
}      
   
//Get balance from user account.    
      
void balance()
{
    string confirm;
    
    cout << "\n\n";
    cout << "\t+========================+\n";
    cout << "\t   Would you like to      \n";
    cout << "\t   check your balance?    \n";
    cout << "\t+========================+\n";
    cout << "\t       [Y]es // [N]o      \n\n";
    cout << "\tSelect: ";
    cin >> confirm; 
       
    if(confirm=="y" || confirm=="Y"){
					  
    sleep(1); 
    cout << "\n\n";
    cout << "\t+========================+\n";
    cout << "\t Current credits: ";
    cout <<  accountDetails[2]; cout << "\n"; 
    cout << "\t+========================+\n";  
    }
    sleep(2);

    menu();
    return;

}  

// For next update. (After make a def, that makes users impl. that!)

/*
void xAccount()
{
    int tempVar;     
    
    cout << "\n\n";
    cout << "\t+========================+\n";
    cout << "\t|Are you sure?That option|\n";
    cout << "\t|delete your account     |\n";
    cout << "\t|permamently             |\n";
    cout << "\t+========================+\n";
    cout << "
    
    if(t)


}
*/

// Show main menu for user

void menu()
{
    cout << "\n\n";
    cout << "\t       PJ-BANK S.A.       \n";
    cout << "\t**************************\n";
    cout << "\t|      [Client Panel]    |\n";
    cout << "\t*========================+\n";
    cout << "\t| W  -- Withdraw         |\n";
    cout << "\t| D  -- Deposit          |\n";
    cout << "\t| B  -- Balance          |\n";
    cout << "\t| Q  -- End this session |\n";
    cout << "\t+========================+\n";
    cout << "\n\tEnter signed character:";
    choiceMenu();
        
    return;
} 

// Choice from main menu

void choiceMenu()
{
    
    char choiceMenu;
    cin >> choiceMenu;
    
    switch(choiceMenu)
    {
        case'w':
        case'W':           
            sleep(1);
            getWithdraw();
            break;
            
        case'd':
        case'D':
            sleep(1);
            getDeposit();            
            break;
            
        case'b':
        case'B':        
            sleep(1);
            balance();
            break;
            
        case'q':
        case'Q':
            sleep(1);
            closeSession();
            break;
            
        default:
            break;
     }      
    return;    
}

// Start menu 

void start()
{
    cout << "\n\n";
    cout << "\t+========================+\n";
    cout << "\t|  WELCOME IN PJANK S.A. |\n";
    cout << "\t+========================+\n";
    cout << "\t| [1] Sign IN            |\n";
    cout << "\t| [2] Sign UP            |\n";
    cout << "\t| [3] Exit               |\n";
    cout << "\t+========================+\n\n";
    
    return;    
}   

// For next update. * Creating new users
      
void createAccount()
{
    newacc newbie;
    
    cout << "\n\n";
    cout << "\t+========================+\n";
    cout << "\t| Enter your login       |\n";
    cout << "\t+========================+\n";
    cout << "\tEnter your login: ";
    cin >> newbie.log;

    cout << "\n";
    cout << "\t+========================+\n";
    cout << "\t| Enter your PIN         |\n";
    cout << "\t+========================+\n";
    cout << "\tEnter your PIN: ";
    cin >> newbie.passwd;
    
    cout << "\n\n";
    cout << "\t+========================+\n";
    cout << "\t| Succesfully register   |\n";
    cout << "\t+========================+\n";
    cout << "\t**  After 3 seconds you **\n";
    cout << "\t**  will be transfered  **\n";
    cout << "\t**  to menu. Bye !!  **\n";
    cout << "\n\n";
    
    sleep(3);
    menu();
    return;
}      
      
// End session // Exit // Quit      
      
void closeSession()
{
    int troll;
    
/*   
    string quit;
    
    cout << "\n\n";
    cout << "\t+========================+\n";
    cout << "\t     Are you sure?        \n";
    cout << "\t+========================+\n";
    cout << "\t    [Y]es // [N]o         \n";  
    cout << "Select: ";
    cin >> quit;
*/

    cout << "\n\n";
    cout << "\t+========================+\n";
    cout << "\t|     Do zobaczenia! =)  |\n";
    cout << "\t+========================+\n";
    cout << "\n\n";
      
    sleep(1);  
    cout << "\t (⌐■_■ )       \n\n";
    sleep(2);
    cout << "\t (■_■⌐)       \n\n";
    sleep(2);
    cout << "\t      [pssst!]\n";
    cout << "\t (■_■)       \n\n";
    sleep(2);
    cout << "\t      [pokazac ci cos na koniec?]\n";
    cout << "\t (⌐■_■⌐)  \n\n";
    cout << "\t[1] Tak || [2] Nie\n";
    cin >> troll;
    switch(troll){
        case 1:
            cout << "\t[REBUS]\n";
            cout << "\t ===>   ʕ•ᴥ•ʔ 3  <=====\n";
            sleep(1);
            cout << "\n\t Wiesz juz co to? ☞   ͜ʖ  ☞ \n";
            break;
        case 2:
            cout << "\n\n";
            cout << "\t GRRRRRRRRRR.... (ノಠ益ಠ)ノ彡┻━┻\n";
            break;
        default:
            break;
            }                
}      
      
int main(){

    int pin;
    int login;
    int in_or_up;
  
    start();
    cout << "\tEnter your select: ";
    cin >> in_or_up;
        
   /*  do {
          if(validateAccount(switchstart(pin, login)){
                start();
                switchstart();
   */
   
    switch(in_or_up){
        case 1:
            cout << "\n\n\n";
            cout << "\t+========================+\n";
            cout << "\t| Please enter your pin  |\n";
            cout << "\t+========================+\n\n";
            cout << "\tEnter your PIN: ";
            cin >> pin;
            
            cout << "\n\n\n";
            cout << "\t+========================+\n";
            cout << "\t|Please enter your login |\n";
            cout << "\t+========================+\n\n";
            cout << "\tEnter your login: ";
            cin >> login;        
           
            if(validateAccount(pin, login)){
                cout << "\n\n";
                cout << "\t+========================+\n";
                cout << "\t|   Sign in succesfull   |\n";
                cout << "\t+========================+\n\n";
                sleep(1);
                menu();
                break;
            } else {
                cout << "\tPodales nieprawidlowe dane do logowania\n";   
                start();
                break;
            }                       
       
        case 2: 
            createAccount();
            break;
       
        case 3:
            closeSession();
            break;
       
        default:
            break;
    }
  
   // } while (!validateAccount(pin, login));

    return 0;
}
    
    



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    * Create Acc
    *
    *
    * 
    * Deposit function
    * Withdraw function
    * Account balance
    * Object
    * Po 15 minutach program sie zamyka 
    * ncursesy wez z projektu ktory robiles wczesniej.
    */
          
 /*  
  HIDE PASSWORD<=====  CHECK IT!
        string pass ="";
        char ch;
        cout << "Enter pass\n";
        ch = _getch();
        while(ch != 13){//character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
 */  
    
    /*
    * Do zrobienia po oddaniu. 
    * Ncursesy dodac
    * Siec
    * UserAcc to file
    * Read from file if exist
    */
    
    
    
    



   


