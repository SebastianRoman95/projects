#include<iostream>
#include<limits>
#include "menu.h"
#include<vector>
using namespace std;

menu::menu(){

}
/////////////////////////////////////////////////////////////////////home start/////////////////////////////////////////////////////////
int menu::validateHome (int choice) {
  while (((choice < 1) || (choice > 5)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//lets you enter game menu or do it again
bool menu::picktask (int choice) {
    bool AGAIN = true;

    enum Options {classes = 1, templates, inheritance, overloading, EXIT };

    switch (choice) {
      case classes:
          cout << "Enter classes." << endl;
          classesMenu ();
          break;

      case templates:
          cout << "Enter templates." << endl;
          templatesMenu ();
          break;

      case inheritance:
          cout << "Enter inheritance" << endl;
          inheritanceMenu ();
          break;

      case overloading:
            cout << "Enter overloading" << endl;
            overloadingMenu ();
            break;

      case EXIT:
          cout << "Exiting main menu..." << endl << endl;
          AGAIN = false;
    }

  return AGAIN;
}
/////////////////////////////////////////////////////////////////////home end///////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////classes start/////////////////////////////////////////////////////////
int menu::validateClasses (int choice) {
  while (((choice < 1) || (choice > 4)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

bool menu::pickedTaskClasses (int choice) {
    bool AGAIN = true;

    enum Options { CMeaning = 1, CExample, EXIT};

    switch (choice)
        {
        case CMeaning:
            cout << "Enter Classes Sub Menu" << endl <<endl;
            cout << "The benefits of classes is reusability, protecting data." << endl <<endl;
            break;

        case CExample:
            cout << "Enter Classes Sub Menu" << endl <<endl;
            cout << "Real life example of Classes." << endl;
            cout << "Layman example of classes. Classes have three member types." << endl;
            cout << "These member types are private, public, and protected." <<endl;
            cout << "In real life people can have different types of keys to" <<endl;
            cout << "access certain places. For example a person who have a car key" <<endl;
            cout << "can't open a house's door. However if all the keys are on a key chain" <<endl;
            cout << "they can all be access by the person." <<endl <<endl;
            break;

        case EXIT:
            cout << "Exiting Classes..." << endl << endl;
            AGAIN = false;

    }

  return AGAIN;
}

void menu::classesMenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering classes" << endl;
  do
    {
      classesHome ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validateClasses (choice);
      AGAIN = pickedTaskClasses (choice);

    }
  while (AGAIN);

}
//////////////////////////////////////////////////////////////////classes end////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////templates menu start////////////////////////////////////////////////////////
//validate temaplates menu
int menu::validateGames (int choice) {
  while (((choice < 1) || (choice > 5)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//lets you enter templates menu or do it again
bool menu::pickedGame (int choice) {
    bool AGAIN = true;

    enum Options { TMeaning=1, TExample, NQ, KT, EXIT };

    switch (choice) {
      case TMeaning:
          cout << "Enter Templates Sub Menu" << endl <<endl;
          cout << "The benefits of Templates is reusability, protecting data." << endl <<endl;
          break;

      case TExample:
          cout << "Enter Templates Sub Menu" << endl <<endl;
          cout << "Real life example of Templates." << endl;
          cout << "Layman example for templates each person has a phone number." <<endl;
          cout << "You can type each person's phone number. However you can use speed" <<endl;
          cout << "dial to replace the whole number to one number."<< endl<<endl;
          break;
      
      case NQ:
          cout << "Enter Queens." << endl;
          NQmenu ();
          break;

      case KT:
          cout << "Enter Knight Tour." << endl;
          KTmenu ();
          break;

      case EXIT:
          cout << "Exiting game. Thank you for playing!" << endl << endl;
          AGAIN = false;
    }

  return AGAIN;
}

//templates menu
void menu::templatesMenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering templates menu" << endl;
  do
    {
      gameHome ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validateGames (choice);
      AGAIN = pickedGame (choice);

    }
  while (AGAIN);

}
/////////////////////////////////////////////////////////////////templates menu end////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////templates game menu start////////////////////////////////////////////////////////
//validate game knight and queen
int menu::validatemenu (int choice) {
  while (((choice < 1) || (choice > 2)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//run knight tour or exit
bool menu::callKT (int choice) {

  bool AGAIN = true;

  enum OPTIONS {RunGame = 1, EXIT};

  switch (choice)
    {
    case RunGame:
        cout << "Enter Knight Tour's SM." << endl <<endl;
        solution ();
        break;

    case EXIT:
        cout << "Exiting... Knight Tour's SM!" << endl << endl;
        AGAIN = false;
    }
  return AGAIN;
}

//knight tour game menu
void menu::KTmenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering Knight tour" << endl;
  do
    {
      subMenuKQ ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validatemenu (choice);
      AGAIN = callKT (choice);

    }
  while (AGAIN);

}

//run queens or exit
bool menu::callNQ (int choice) {

  bool AGAIN = true;

  enum OPTIONS {RunGame = 1, EXIT};

  switch (choice)
    {
    case RunGame:
        cout << "Enter Queen's SM" << endl <<endl;
        queenSolution();
        break;

    case EXIT:
        cout << "Exiting... Queen's SM" << endl << endl;
        AGAIN = false;
    }
  return AGAIN;
}

//queen game menu
void menu::NQmenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering Queens" << endl;
  do
    {
      subMenuKQ ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validatemenu (choice);
      AGAIN = callNQ (choice);

    }
  while (AGAIN);

}
/////////////////////////////////////////////////////////////templates game menu end//////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////inheritance menu start///////////////////////////////////////////////////////////
//validate inheritance menu
int menu::validateInheritance (int choice) {
  while (((choice < 1) || (choice > 5)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//lets you enter inheritance menu or do it again
bool menu::pickedTaskInheritance (int choice) {
    bool AGAIN = true;

    enum Options { IMeaning=1, IExample, SHAPE, BANK, EXIT };

    switch (choice) {
      case IMeaning:
          cout << "Enter Inheritance Sub Menu" << endl <<endl;
          cout << "The benefits of Inheritance is reusability, security, readability." << endl <<endl;
          break;

      case IExample:
          cout << "Enter Inheritance Sub Menu" << endl <<endl;
          cout << "Real life example of Inheritance." << endl;
          cout << "Layman example:" <<endl;
          cout << "You have a base class called vehicle." <<endl;
          cout << "The derive class would be different types of vechicles" <<endl;
          cout << "So the derive classes would be bus, car, and truck." <<endl;
          cout << "What makes them all vehicles is they can all drive and hold people." <<endl;
          cout << "What makes them different is the amount of people they can hold," <<endl;
          cout << "the number of wheels, and the fuel amount"<< endl<<endl;
          break;

      case SHAPE:
          cout << "Enter Shapes" << endl;
          shapemenu ();
          break;

      case BANK:
          cout << "Enter Banking" << endl;
          subMenuBank ();
          break;

      case EXIT:
          cout << "Exiting Inheritance." << endl << endl;
          AGAIN = false;
    }

  return AGAIN;
}

//Inheritance menu
void menu::inheritanceMenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering inheritance menu" << endl;
  do
    {
      inheritanceHome ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validateInheritance (choice);
      AGAIN = pickedTaskInheritance (choice);

    }
  while (AGAIN);

}
/////////////////////////////////////////////////////////////inheritance menu end/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////shapes menu start///////////////////////////////////////////////////////////
//validate game shapes
int menu::validateShapesMenu (int choice) {
  while (((choice < 1) || (choice > 6)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//shapes game menu
void menu::shapemenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering shapes" << endl;
  do
    {
      subMenuShape ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validateShapesMenu (choice);
      AGAIN = callShape (choice);

    }
  while (AGAIN);

}

//run shape or exit
bool menu::callShape (int choice) {
  double y1, y2, y3, y4, x1, x2, x3, x4;
  char yesNo;
  quadrilateral<double> quad(5, 6, 9, 2, 4, 1, 9, 10);
  rectangle<double> Rec(14, 14, 28, 28,17, 17, 30, 30);
  square<double> squar(0, 0, 4, 4, 4,8,8,4);
  parallelogram<double> para(5, 5, 20, 20, 5, 11, 12, 6);
  trapezoid<double> trap(0, 0, 5, 5, 0, 10, 8, 3.3);
  bool AGAIN = true;

  enum OPTIONS {RunQuadrilateral = 1, RunTrapezoid, RunRectangle, RunParallelogram, RunSquare, EXIT};

  switch (choice)
    {
    case RunQuadrilateral:
        cout << "Enter Quadrilateral's SM." << endl <<endl;
        cout << "Would you like to enter your own coordinates?" <<endl;
        cout << "Press y: for yes" <<endl;
        cout << "Press n: for no" <<endl;
        cin >> yesNo;
        if(yesNo=='y'){
          cout << "Enter coordinates for the Quadrilateral:" <<endl;
          cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
          quad.setNumY(y1);
          quad.setNumX(x1);
          quad.setNumY2(y2);
          quad.setNumX2(x2);
          quad.setNumY3(y3);
          quad.setNumX3(x3);
          quad.setNumY4(y4);
          quad.setNumX4(x4);
          cout << "Coordinates of Quadrilateral are:" <<endl;
          cout << quad <<endl;
        }
        else{
          cout << "Coordinates of Quadrilateral are:" <<endl;
          cout << quad <<endl;
        }
        
        
        break;

    case RunTrapezoid:
        cout << "Enter Trapezoid's SM." << endl <<endl;
        cout << "Would you like to enter your own coordinates?" <<endl;
        cout << "Press y: for yes" <<endl;
        cout << "Press n: for no" <<endl;
        cin >> yesNo;
        if(yesNo=='y'){
          cout << "Enter coordinates for the Trapezoid:" <<endl;
          cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
          trap.setNumY(y1);
          trap.setNumX(x1);
          trap.setNumY2(y2);
          trap.setNumX2(x2);
          trap.setNumY3(y3);
          trap.setNumX3(x3);
          trap.setNumY4(y4);
          trap.setNumX4(x4);
          cout << "Coordinates of Trapezoid are:" <<endl;
          cout << trap <<endl;
        }
        else{
          cout << "Coordinates of Trapezoid are:" <<endl;
          cout << trap <<endl;
        }
        cout <<  "Height is: " <<  trap.getHeightT() << endl;
        cout << "Width is: " << trap.getWidthT() << endl;
        cout << "Area is: " << trap.areaT() << endl;
        break;

    case RunRectangle:
        cout << "Enter Rectangle's SM." << endl <<endl;
        cout << "Would you like to enter your own coordinates?" <<endl;
        cout << "Press y: for yes" <<endl;
        cout << "Press n: for no" <<endl;
        cin >> yesNo;
        if(yesNo=='y'){
          cout << "Enter coordinates for the Rectangle:" <<endl;
          cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
          Rec.setNumY(y1);
          Rec.setNumX(x1);
          Rec.setNumY2(y2);
          Rec.setNumX2(x2);
          Rec.setNumY3(y3);
          Rec.setNumX3(x3);
          Rec.setNumY4(y4);
          Rec.setNumX4(x4);
          cout << "Coordinates of Rectangle are:" <<endl;
          cout << Rec <<endl;
        }
        else{
          cout << "Coordinates of Rectangle are:" <<endl;
          cout << Rec <<endl;
        }       
        cout <<  "Height is: " <<  Rec.setHeightRec() << endl;
        cout << "Width is: " << Rec.setWidthRec() << endl;
        cout << "Area is: " << Rec.getAreaR() << endl;
        break;

    case RunParallelogram:
        cout << "Enter Parallelogram's SM." << endl <<endl;
        cout << "Would you like to enter your own coordinates?" <<endl;
        cout << "Press y: for yes" <<endl;
        cout << "Press n: for no" <<endl;
        cin >> yesNo;
        if(yesNo=='y'){
          cout << "Enter coordinates for the Parallelogram:" <<endl;
          cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
          para.setNumY(y1);
          para.setNumX(x1);
          para.setNumY2(y2);
          para.setNumX2(x2);
          para.setNumY3(y3);
          para.setNumX3(x3);
          para.setNumY4(y4);
          para.setNumX4(x4);
          cout << "Coordinates of Parallelogram are:" <<endl;
          cout << para <<endl;
        }
        else{
          cout << "Coordinates of Parallelogram are:" <<endl;
          cout << para <<endl;
        }
        cout <<  "Height is: " <<  para.getHeightP() << endl;
        cout << "Width is: " << para.getWidthP() << endl;
        cout << "Area is: " << para.areaP() << endl;
        break;

    case RunSquare:
        cout << "Enter Square's SM." << endl <<endl;
        cout << "Would you like to enter your own coordinates?" <<endl;
        cout << "Press y: for yes" <<endl;
        cout << "Press n: for no" <<endl;
        cin >> yesNo;
        if(yesNo=='y'){
          cout << "Enter coordinates for the Square:" <<endl;
          cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
          squar.setNumY(y1);
          squar.setNumX(x1);
          squar.setNumY2(y2);
          squar.setNumX2(x2);
          squar.setNumY3(y3);
          squar.setNumX3(x3);
          squar.setNumY4(y4);
          squar.setNumX4(x4);
          cout << "Coordinates of Square are:" <<endl;
          cout << squar <<endl;
        }
        else{
          cout << "Coordinates of Square are:" <<endl;
          cout << squar <<endl;
        }
        cout << "Side is: " << squar.getSide() <<endl;
        cout << "Area is: " << squar.areaS() <<endl;
        break;

    case EXIT:
        cout << "Exiting... Shape's SM!" << endl << endl;
        AGAIN = false;
    }
  return AGAIN;
}
///////////////////////////////////////////////////////////////////shapes menu end/////////////////////////////////////////////////////////////
//0 kelly bery 80// 2 timmy turn 325.84
/////////////////////////////////////////////////////////////overloading menu start///////////////////////////////////////////////////////////
//overloading menu
int menu::validateOverloading (int choice) {
  while (((choice < 1) || (choice > 5)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//lets you enter overloading menu or do it again
bool menu::pickedTaskOverloading (int choice) {
    bool AGAIN = true;

    enum Options { OMeaning=1, OExample, OneDimeArr, TwoDimeArr, EXIT };

    switch (choice) {
      case OMeaning:
          cout << "Enter Overloading Sub Menu" << endl <<endl;
          cout << "The benefits of Overloading is reusability, protecting data." << endl <<endl;
          break;

      case OExample:
          cout << "Enter Overload Sub Menu" << endl <<endl;
          cout << "Real life example of Overloading." << endl;
          cout << "A family shares a last name. However if you want a certain person from the family" << endl;
          cout << "you need their first name as well as the last name." <<endl;
          cout << "Furthermore, a person can also have a middle name or nickname." <<endl <<endl;
          break;

      case OneDimeArr:
          cout << "Enter One Dimensional Arrays" << endl;
          subMenuODA ();
          break;

      case TwoDimeArr:
          cout << "Enter Two Dimensional Arrays" << endl;
          subMenuTDA ();
          break;
          
      case EXIT:
          cout << "Exiting Overloading." << endl << endl;
          AGAIN = false;
    }

  return AGAIN;
}

//overloading menu
void menu::overloadingMenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering overloading menu" << endl;
  do
    {
      overloadingHome ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validateOverloading (choice);
      AGAIN = pickedTaskOverloading (choice);

    }
  while (AGAIN);

}
/////////////////////////////////////////////////////////////overloading menu start///////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////print statements start///////////////////////////////////////////////////////////
//welcome message
void menu::welcome () {
  cout << "Welcome to the games menu." << endl;
}

//show home menu statements
void menu::home () {
  cout << "1. Classes" << endl;
  cout << "2. Templates" << endl;
  cout << "3. Inheritance" << endl;
  cout << "4. Overloading" << endl;
  cout << "5. Exit" << endl;
}

//classes menu statements
void menu::classesHome () {
  cout << endl;
  cout << "1. Benefits of Classes" << endl;
  cout << "2. Real life example of Classes." << endl;
  cout << "3. Exit clases" << endl;
}

//show games/templates menu statements
void menu::gameHome () {
  cout << "1. Benefits of Templates" << endl;
  cout << "2. Real life example of Templates." << endl;
  cout << "3. Queens" << endl;
  cout << "4. Knight Tour" << endl;
  cout << "5. Exit" << endl;
}

//submenu knight and queen statements
void menu::subMenuKQ () {
  cout << endl;
  cout << "1. Run Game" << endl;
  cout << "2. Exit Game" << endl;
}

//show inheritance menu statements
void menu::inheritanceHome () {
  cout << "1. Benefits of Inheritance" << endl;
  cout << "2. Real life example of Inheritance." << endl;
  cout << "3. Shapes" << endl;
  cout << "4. Bank" << endl;
  cout << "5. Exit" << endl;
}

//submenu for shapes statements
void menu::subMenuShape () {
  cout << endl;
  cout << "press 1: to find the area of quadrilateral" << endl << "press 2: to find the area of trapezoid" << endl;
  cout << "press 3: to find the area of rectangle" << endl << "press 4: to find the area of parallelogram" <<endl;
  cout << "press 5: to find the area of square" << endl <<"press 6: to exit math game" <<endl;
}

//submenu for shapes statements
void menu::subMenuBank () {
    cout << endl;
    //var
    double amount, rateAmount=0, deposit, withdraw, fee=0;
    string first, last, yesNo, credit;
    bool exit =false;
    int pick, pickAccount, userID;
    vector<string>userFirstName;
    vector<string>userLastName;
    vector<double>userBalance;
    vector<double>userFeeAndRate;

    //user input
    cout << "Create account by entering your information." <<endl;
    cout << "Enter your first name." <<endl;
    cin >> first;
    cout << "Enter your last name." <<endl;
    cin >> last;
    cout << "Enter your balance." <<endl;
    cin >> amount;

    //set user input
    account<double, string> ac(first, last, amount);
    savingsAccount<double, string>  sa(first, last, amount, rateAmount);
    checkingAccount<double, string>  ca(first, last, amount, fee);

    //ask user pick saving, checking, account
    cout << endl<< "Would you like to enter your savings account, account, or checking account?" <<endl;
    cout << "To enter savings account enter 1. To enter account enter 2. To enter checking account enter 3. To exit enter 4."<<endl;
    cin >>pickAccount;

    //if user pick saving, checking, account
    if(pickAccount==1||pickAccount==2||pickAccount==3){
      if(pickAccount==1){ //start of saving
        cout <<endl << "Would you like to make a credit, debit, access account, set a rate, or exit?" <<endl;
        cout << "Press 1: To credit" <<endl;
        cout << "Press 2: To debit" << endl;
        cout << "Press 3: To see your balance" <<endl;
        cout << "Press 4: To set rate" <<endl;
        cout << "Press 5: To exit" <<endl;
        cin >> pick;

          while(pick==1||pick==2||pick==3||pick==4){
            if(pick==1){
              cout << "Current "<< sa << endl;
              cout << "How much money would you like to deposit?" <<endl;
              cin >> deposit;
              sa.credit(deposit);
              cout << "You have deposit " << deposit <<endl;
              sa.calculateInterest();
              cout << "Updated "<< sa << endl;
            }
            else if (pick==2){
              cout << "Current "<< sa << endl;
              cout << "How much money would you like to withdraw?" <<endl;
              cin >> withdraw;
              sa.debit(withdraw);
              cout << "You have withdraw " << withdraw <<endl;
              sa.calculateInterest();
              cout << "Updated "<< sa << endl;
            }
            else if (pick==3){
              cout << "Current "<< sa << endl;
            }
            else if(pick==4){
              cout << "Current "<< sa << endl;
              cout << "What would you like to set the rate to?" <<endl;
              cin >> rateAmount;
              sa.setRate(rateAmount);
              sa.calculateInterest();
              cout << "Your rate is " << rateAmount <<endl;
              cout << "Updated "<< sa << endl;
            }

            cout <<endl << "Would you like to make a credit, debit, access account, set a rate, or exit?" <<endl;
            cout << "Press 1: To credit" <<endl;
            cout << "Press 2: To debit" << endl;
            cout << "Press 3: To see your balance" <<endl;
            cout << "Press 4: To set rate" <<endl;
            cout << "Press 5: To exit" <<endl;
            cin >> pick;
          }
        }//end of saving
        else if(pickAccount==2){ //start of account
          cout <<endl << "Would you like to make a credit, debit, access account, or exit?" <<endl;     
          cout << "Press 1: To credit" <<endl;
          cout << "Press 2: To debit" << endl;
          cout << "Press 3: To see your balance" <<endl;
          cout << "Press 4: To exit" <<endl;
          cin >> pick;

            while(pick==1||pick==2||pick==3){
                if(pick==1){
                  cout <<endl << "Current " << ac;
                  cout << "How much money would you like to deposit?" <<endl;
                  cin >> deposit;
                  ac.credit(deposit);
                  cout << "You have deposit " << deposit <<endl;
                  cout << "Updated " << ac;
                }
                else if (pick==2){
                  cout <<endl << "Current " << ac;
                  cout << "How much money would you like to withdraw?" <<endl;
                  cin >> withdraw;
                  ac.debit(withdraw);
                  cout << "You have withdraw " << withdraw <<endl;
                  cout << "Updated " << ac; 
                }
                else if (pick==3){
                  cout <<endl << "Current " << ac;
                }

                cout <<endl << "Would you like to make a credit, debit, access account, or exit?" <<endl;     
                cout << "Press 1: To credit" <<endl;
                cout << "Press 2: To debit" << endl;
                cout << "Press 3: To see your balance" <<endl;
                cout << "Press 4: To exit" <<endl;
                cin >> pick;
            }     
        } //end of account
        else if(pickAccount==3){ //start if checking
            cout <<endl << "Would you like to make a credit, debit, access account, set a transaction fee, or exit?" <<endl;
            cout << "Press 1: To credit" <<endl;
            cout << "Press 2: To debit" << endl;
            cout << "Press 3: To see your balance" <<endl;
            cout << "Press 4: To set transaction fee" <<endl;
            cout << "Press 5: To exit" <<endl;
            cin >> pick;

            while(pick==1||pick==2||pick==3||pick==4){
                if(pick==1){
                  cout << "Current "<< ca << endl;
                  cout << "How much money would you like to deposit?" <<endl;
                  cin >> deposit;
                  ca.credit(deposit);
                  cout << "You have deposit " << deposit <<endl;
                  cout << "Updated "<< ca << endl;
                }
                else if (pick==2){
                  cout << "Current "<< ca << endl;
                  cout << "How much money would you like to withdraw?" <<endl;
                  cin >> withdraw;
                  ca.debit(withdraw);
                  cout << "You have withdraw " << withdraw <<endl;
                  cout << "Updated "<< ca << endl;
                }
                else if (pick==3){
                    cout << "Current "<< ca << endl;
                }
                else if (pick==4){
                  cout << "Current "<< ca << endl;
                  cout << "What would you like to set the fee to?" <<endl;
                  cin >> fee;
                  ca.setFee(fee);
                  cout << "Your transaction fee is " << fee <<endl;
                  cout << "Updated "<< ca << endl;
                }

                cout <<endl << "Would you like to make a credit, debit, access account, set a transaction fee, or exit?" <<endl;
                cout << "Press 1: To credit" <<endl;
                cout << "Press 2: To debit" << endl;
                cout << "Press 3: To see your balance" <<endl;
                cout << "Press 4: To set transaction fee" <<endl;
                cout << "Press 5: To exit" <<endl;
                cin >> pick;
            }    
        }//end of checking
        
        //userID, userFirstName, userLastName, userBalance, userFeeAndRate;
        //store user information to be called later
        if(pickAccount==1){//savings
          amount=sa.getBalance();
          userBalance.push_back(amount);
          first=sa.getFirstName();
          userFirstName.push_back(first);
          last=sa.getLastName();
          userLastName.push_back(last);
          rateAmount=sa.getRate();
          userFeeAndRate.push_back(rateAmount);
        }
        else if(pickAccount==2){//account
          amount=ac.getBalance();
          userBalance.push_back(amount);
          first=ac.getFirstName();
          userFirstName.push_back(first);
          last=ac.getLastName();
          userLastName.push_back(last);
          userFeeAndRate.push_back(0);
        }
        else if(pickAccount==3){//checking
          amount=sa.getBalance();
          userBalance.push_back(amount);
          first=sa.getFirstName();
          userFirstName.push_back(first);
          last=sa.getLastName();
          userLastName.push_back(last);
          fee=ca.getFee();
          userFeeAndRate.push_back(fee);
        }
        userID=0;
        cout << userFirstName[userID] << ' ' << userLastName[userID] << " ID number is " << userID <<endl;

        //ask to make new account
        cout << endl<< "Would you like to create account? Enter yes or no." <<endl;
        cin >> yesNo;
        cout << endl;              
    }
    
    //new account if they say yes
    if(yesNo=="yes"){
        exit=true;
        
        //loop until user is done
        while(exit!=false){
        //user input
        cout << "Create account by entering your information." <<endl;
        cout << "Enter your first name." <<endl;
        cin >> first;
        cout << "Enter your last name." <<endl;
        cin >> last;
        cout << "Enter your balance." <<endl;
        cin >> amount;

        //set user input
        account<double, string> ac(first, last, amount);
        savingsAccount<double, string>  sa(first, last, amount, rateAmount);
        checkingAccount<double, string>  ca(first, last, amount, fee);

        //ask user pick saving, checking, account
        cout << endl<< "Would you like to enter your savings account, account, or checking account?" <<endl;
        cout << "To enter savings account enter 1. To enter account enter 2. To enter checking account enter 3.To exit enter 4."<<endl;
        cin >>pickAccount;

    //if user pick saving, checking, account
    if(pickAccount==1||pickAccount==2||pickAccount==3){
      if(pickAccount==1){ //start of saving
          cout <<endl << "Would you like to make a credit, debit, access account, set a rate, or exit?" <<endl;
          cout << "Press 1: To credit" <<endl;
          cout << "Press 2: To debit" << endl;
          cout << "Press 3: To see your balance" <<endl;
          cout << "Press 4: To set rate" <<endl;
          cout << "Press 5: To exit" <<endl;
          cin >> pick;

            while(pick==1||pick==2||pick==3||pick==4){
                if(pick==1){
                  cout << "Current "<< sa << endl;
                  cout << "How much money would you like to deposit?" <<endl;
                  cin >> deposit;
                  sa.credit(deposit);
                  cout << "You have deposit " << deposit <<endl;
                  sa.calculateInterest();
                  cout << "Updated "<< sa << endl;
                }
                else if (pick==2){
                  cout << "Current "<< sa << endl;
                  cout << "How much money would you like to withdraw?" <<endl;
                  cin >> withdraw;
                  sa.debit(withdraw);
                  cout << "You have withdraw " << withdraw <<endl;
                  sa.calculateInterest();
                  cout << "Updated "<< sa << endl;
                }
                else if (pick==3){
                  cout << "Current "<< sa << endl;
                }
                else if(pick==4){
                  cout << "Current "<< sa << endl;
                  cout << "What would you like to set the rate to?" <<endl;
                  cin >> rateAmount;
                  sa.setRate(rateAmount);
                  sa.calculateInterest();
                  cout << "Your rate is " << rateAmount <<endl;
                  cout << "Updated "<< sa << endl;
                }

                cout <<endl << "Would you like to make a credit, debit, access account, set a rate, or exit?" <<endl;
                cout << "Press 1: To credit" <<endl;
                cout << "Press 2: To debit" << endl;
                cout << "Press 3: To see your balance" <<endl;
                cout << "Press 4: To set rate" <<endl;
                cout << "Press 5: To exit" <<endl;
                cin >> pick;
            }
        }//end of saving
        else if(pickAccount==2){ //start of account
          cout <<endl << "Would you like to make a credit, debit, access account, or exit?" <<endl;     
          cout << "Press 1: To credit" <<endl;
          cout << "Press 2: To debit" << endl;
          cout << "Press 3: To see your balance" <<endl;
          cout << "Press 4: To exit" <<endl;
          cin >> pick;

            while(pick==1||pick==2||pick==3){
                if(pick==1){
                  cout <<endl << "Current " << ac;
                  cout << "How much money would you like to deposit?" <<endl;
                  cin >> deposit;
                  ac.credit(deposit);
                  cout << "You have deposit " << deposit <<endl;
                  cout << "Updated " << ac;
                }
                else if (pick==2){
                  cout <<endl << "Current " << ac;
                  cout << "How much money would you like to withdraw?" <<endl;
                  cin >> withdraw;
                  ac.debit(withdraw);
                  cout << "You have withdraw " << withdraw <<endl;
                  cout << "Updated " << ac; 
                }
                else if (pick==3){
                  cout <<endl << "Current " << ac;
                }

                cout <<endl << "Would you like to make a credit, debit, access account, or exit?" <<endl;     
                cout << "Press 1: To credit" <<endl;
                cout << "Press 2: To debit" << endl;
                cout << "Press 3: To see your balance" <<endl;
                cout << "Press 4: To exit" <<endl;
                cin >> pick;
            }     
        } //end of account
        else if(pickAccount==3){ //start if checking
            cout <<endl << "Would you like to make a credit, debit, access account, set a transaction fee, or exit?" <<endl;
            cout << "Press 1: To credit" <<endl;
            cout << "Press 2: To debit" << endl;
            cout << "Press 3: To see your balance" <<endl;
            cout << "Press 4: To set transaction fee" <<endl;
            cout << "Press 5: To exit" <<endl;
            cin >> pick;

            while(pick==1||pick==2||pick==3||pick==4){
              if(pick==1){
                cout << "Current "<< ca << endl;
                cout << "How much money would you like to deposit?" <<endl;
                cin >> deposit;
                ca.credit(deposit);
                cout << "You have deposit " << deposit <<endl;
                cout << "Updated "<< ca << endl;
              }
              else if (pick==2){
                cout << "Current "<< ca << endl;
                cout << "How much money would you like to withdraw?" <<endl;
                cin >> withdraw;
                ca.debit(withdraw);
                cout << "You have withdraw " << withdraw <<endl;
                cout << "Updated "<< ca << endl;
              }
              else if (pick==3){
                  cout << "Current "<< ca << endl;
              }
              else if (pick==4){
                cout << "Current "<< ca << endl;
                cout << "What would you like to set the fee to?" <<endl;
                cin >> fee;
                ca.setFee(fee);
                cout << "Your transaction fee is " << fee <<endl;
                cout << "Updated "<< ca << endl;
              }

              cout <<endl << "Would you like to make a credit, debit, access account, set a transaction fee, or exit?" <<endl;
              cout << "Press 1: To credit" <<endl;
              cout << "Press 2: To debit" << endl;
              cout << "Press 3: To see your balance" <<endl;
              cout << "Press 4: To set transaction fee" <<endl;
              cout << "Press 5: To exit" <<endl;
              cin >> pick;
            }    
          }//end of checking
        }
          //store user information to be called later
          if(pickAccount==1){//savings
            amount=sa.getBalance();
            userBalance.push_back(amount);
            first=sa.getFirstName();
            userFirstName.push_back(first);
            last=sa.getLastName();
            userLastName.push_back(last);
            rateAmount=sa.getRate();
            userFeeAndRate.push_back(rateAmount);
          }
          else if(pickAccount==2){//account
            amount=ac.getBalance();
            userBalance.push_back(amount);
            first=ac.getFirstName();
            userFirstName.push_back(first);
            last=ac.getLastName();
            userLastName.push_back(last);
            userFeeAndRate.push_back(0);
          }
          else if(pickAccount==3){//checking
            amount=sa.getBalance();
            userBalance.push_back(amount);
            first=sa.getFirstName();
            userFirstName.push_back(first);
            last=sa.getLastName();
            userLastName.push_back(last);
            fee=ca.getFee();
            userFeeAndRate.push_back(fee);
          }
          userID++;
          cout << userFirstName[userID] << ' ' << userLastName[userID] << " ID number is " << userID <<endl <<endl;

          //ask user if they want to stop or loop
          cout << "Would you like to create account? Enter yes or no." <<endl;
          cin >> yesNo;

          //exits user
          if(yesNo!="yes"){
              exit=false;
          }
        }   
    }

      //userID, userFirstName, userLastName, userBalance, userFeeAndRate;
      int numberID;
      cout << "Would you like to see the old users?" <<endl;
      cout << "Type yes to see old users or to exit type no" <<endl;
      cin >> yesNo;
      cout << endl;

      while(yesNo=="yes"){
        cout << "Please enter the users ID number." <<endl;
        cin >> numberID;
        cout << userFirstName[numberID] << ' ' << userLastName[numberID] << " balance " <<
        userBalance[numberID];
        if(userFeeAndRate[numberID]!=0){
          cout << " Fee/Rate " << userFeeAndRate[numberID] <<endl;
        }
        else{
          cout << endl;
        }
        cout << "Would you like to see the old users?" <<endl;
        cout << "Type yes to see old users or to exit type no" <<endl;
        cin >> yesNo;
        cout << endl;
      }
}

//show Overloading menu statements
void menu::overloadingHome () {
    cout << "1. Benefits of Overloading" << endl;
    cout << "2. Real life example of Overloading." << endl;
    cout << "3. One Dimensional Arrays" << endl;
    cout << "4. Two Dimensional Arrays" << endl;
    cout << "5. Exit" << endl;
}

//show one dime arr statement
void menu::subMenuODA() {
    cout << endl;
    OneDimensional integers1(7);
    OneDimensional integers2;

    cout << "size of array integers1 is " << integers1.getSize()<< "\narray after initialization:\n" << integers1;
    cout << "size of array integers2 is " << integers2.getSize()<< "\narray after initialization:\n" << integers2;

    //add random number or user input
    // >> op
    cout << "\nenter 17 integers:" <<endl;
    cin >> integers1 >> integers2;

    // << op
    cout << "\nafter input, the array contain:\n" << "integers1:\n" << integers1 << "integers2:\n" << integers2;
    cout << "\nevaluating: integers1 != integers2"<<endl;

    if(integers1!=integers2){
        cout << "integers1 and integers2 are not equal" <<endl;
    }

    OneDimensional integers3(integers1);
    cout << "\nsize of array integers3 is " << integers3.getSize()<<"\narray initialization:\n"<< integers3;
    
    cout <<"\nassigning integers2 to integers1:" <<endl;
    cout << "integers1:\n" << integers1 << "integers2:\n" << integers2;

    cout << "\nevaluating: integers1 = integers2" <<endl;

    if(integers1==integers2){
        cout << "integers1 and integers2 are equal" <<endl;
    }

    cout << "\nintegers1[5] is "<<integers1[5];
    cout << "\n\nassigning 1000 to integers1[5]"<<endl;
    integers1[5]=1000;
    cout << "integers1:\n"<<integers1;

    cout <<"\nattempt to assign 1000 to integers1[15]"<<endl;
    integers1[15]=1000;
}

//show two dime arr statement
void menu::subMenuTDA() {
    int row, col, row2, col2;

    //int 1
    cout << "Enter the size for the row and col integers1's matrix. Must be lower than 10x10" << endl;
    cin >> row >>  col;
    while(row>=10&&col>=10){
      cout << "Enter the size for the row and col integers1's matrix. Must be lower than 10x10" << endl;
      cin >> row >>  col;
    }
    TwoDimensional integers1(row, col);
    
    // int2
    cout << "Enter the size for the row and col integers2's matrix. Must be lower than 10x10" << endl;
    cin >> row2 >>  col2;
    while(row2>=10&&col2>=10){
      cout << "Enter the size for the row and col integers2's matrix. Must be lower than 10x10" << endl;
      cin >> row2 >>  col2;
    }
    TwoDimensional integers2(row2, col2);
    
    cout << "size of array integers1 is " << integers1.getRowSize()<< "col " << integers1.getColSize() << "\narray after initialization:\n" << integers1;
    cout << "size of array integers2 is " << integers2.getRowSize()<< "col " << integers2.getColSize()<< "\narray after initialization:\n" << integers2;

    //add random number or user input
    // >> op
    //cout << "\nenter 17 integers:" <<endl;
    cin >> integers1 >> integers2;

    // << op
    cout << "\nafter input, the array contain:\n" << "integers1:\n" << integers1 << "integers2:\n" << integers2;
    cout << "\nevaluating: integers1 != integers2"<<endl;

    if(integers1!=integers2){
        cout << "integers1 and integers2 are not equal" <<endl;
    }

    TwoDimensional integers3(row, col);
    cout << "\nsize of array integers3 is " << integers3.getRowSize()<< "col " << integers3.getColSize()<<"\narray initialization:\n"<< integers3;
    
    cout <<"\nassigning integers2 to integers1:" <<endl;
    cout << "integers1:\n" << integers1 << "integers2:\n" << integers2;

    cout << "\nevaluating: integers1 = integers2" <<endl;

    if(integers1==integers2){
        cout << "integers1 and integers2 are equal" <<endl;
    }

    cout << "\nintegers1[5] is "<<integers1[5];
    cout << "\n\nassigning 1000 to integers1[5]"<<endl;
    integers1[5]=1000;
    cout << "integers1:\n"<<integers1;

    cout <<"\nattempt to assign 1000 to integers1[15]"<<endl;
    integers1[15]=1000;
}
/////////////////////////////////////////////////////////////print statements end///////////////////////////////////////////////////////////
    