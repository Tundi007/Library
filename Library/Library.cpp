#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>

/*
all spaces with underline

id books are 2 characters long
*/


using namespace std;

string user_option;
string admin_option;
string login_type;
string id;
string password;
bool   UserisLoggedIn;
bool   AdminisLoggedIn;
bool   edit;
bool   userSignIn;
bool   adminSignIn;
bool   expire;

struct book {
    string id;
    string title;
    string category;
    string publisher;
    string issued;
    string edition;
    string date_published;
    string last_edited;
    double price;
    string author;
    string canLend;
    string last_user;
    double daily_fine;
    string last_borrow_date;
    int    time_limit;
} book;

struct admin {
    string id;
    string password;
}admin;

struct user {
    string id;
    string password;
    string name;
    string family_name;
    string date_of_birth;
    string address;
    string phone_number;
    string sign_up_date;
    int    sign_up_expire_date_year;
    int    sign_up_expire_date_month;
    int    sign_up_expire_date_day;
    string sign_up_type;
    int    borrow_limit;
    string borrow_time_limit;
    int    books_borrowed;
    int    total_delay;
    string borrowed_list;
}user;

// DECALARTIONS
void adminstrator();
void choose_login_type();
void sign_up();
void sign_in();
void edit_info_user();
void show_user_book();
void show_book_list();
void search_book();
void booklist_edit();
void times();
void expire_date();
void user_menu();
void admin_menu();
void addbook();
void user_info_help();
void check_user_info();
void borrow_book();
void return_book();
void extend_expiry_date();
void remove_book();
void edit_book();
void delete_user();
void fine();

// MAIN
int main()
{

    cout << "Developer's important note:\nPlease use **underline** inntead of **space**\n Book's id should only be **2 characters** long\n\n";

    times();

    choose_login_type();

    if (login_type == "1")  {

        system("CLS");

        sign_up();

    }

    if (login_type == "2")  {

        system("CLS");

        sign_in();

        check_user_info();

        expire_date();

        if (expire == false) {

            system("CLS");

            cout << endl << "Signed-in successfully!" << endl;

            cout << "\nWelcome " << user.name << " " << user.family_name << "\n" << endl;

            userSignIn = true;

        }
        else {

            system("CLS");

            cout << endl << "Your account has been expired" << endl;

            extend_expiry_date();

            UserisLoggedIn = false;

        }

    }

    if (login_type == "3")  {

        system("CLS");

        adminstrator();

    }

    //loggedin
    if (UserisLoggedIn)     {

        user_menu();

    }

    if (AdminisLoggedIn)    {

        admin_menu();

    }
    //user's options
    while (userSignIn) {

        if (user_option == "1") {

            system("CLS");

            edit = true;

            edit_info_user();

            system("CLS");

        }

        if (user_option == "2") {

            system("CLS");



            user_option = "0";

            system("CLS");

        }

        if (user_option == "3") {

            system("CLS");

            show_book_list();

            user_option = "0";

        }

        if (user_option == "4") {

            system("CLS");

            search_book();

            user_option = "0";

        }

        if (user_option == "5") {

            system("CLS");

            borrow_book();

            Sleep(5000);

            system("CLS");

            user_option = "0";

        }

        if (user_option == "6") {

            system("CLS");

            return_book();

            user_option = "0";

            system("CLS");

        }

        if (user_option == "7") {

            system("CLS");

            show_user_book();

            user_option = "0";

        }

        if (user_option == "8") {

            system("CLS");

            fine();

            user_option = "0";

        }

        if (user_option == "0") {
            
            user_menu();

        }

    }

    //admin's options

    while (adminSignIn) {

        if (admin_option == "1") {

            system("CLS");

            addbook();

            admin_option = "0";

        }

        if (admin_option == "2") {

            system("CLS");

            edit_book();

            admin_option = "0";

        }

        if (admin_option == "3") {

            system("CLS");

            remove_book();

            admin_option = "0";

        }

        if (admin_option == "4") {

            system("CLS");

            delete_user();

            admin_option = "0";

        }

        if (admin_option == "5") {

            system("CLS");

            show_book_list();

            admin_option = "0";

        }

        if (admin_option == "0") {

            admin_menu();

        }

    }
    
}

// FUNCTIONS 

//date - complete
void times() {

    fstream timeFile("date.txt", ios::out);

    time_t now = time(0);

    tm* ltm = localtime(&now);

    timeFile << 1900 + ltm->tm_year << endl;

    timeFile << 1 + ltm->tm_mon << endl;

    timeFile << ltm->tm_mday << endl;

    timeFile.close();

}

//login type - complete
void choose_login_type() {

    cout << " Select your login type or sign up by entering the number beside the options given: \n 1. sign up \n 2. user \n 3. admin\n> " ;

    cin >> login_type;

}

//sign up - complete
void sign_up() {

    fstream file2("user.txt", ios::app);
    string id, id1, password, name, family_name, date_of_birth, address, phone_number, sign_up_type, a, b, c;
    int counter = 0, h = 0, borrow_limit, x, z, y;

    do {
        fstream file1("user.txt", ios::in);
        h = 0;
        counter = 0;
        cout << " please choose id : \n ";
        cin >> id1;

        while (getline(file1, id)) {
            counter++;

            if ((counter - 1) % 17 == 0 && id == id1) {

                cout << "The id is already taken !!! \n\n";
                h = 1;
            }
        }

        file1.close();

    } while (h == 1);

    cout << " ID successfully selected :) \n\n";

    file2 << endl << id1 << endl;


    do {
        cout << "please choose password  : \t  *** Password must be longer than 3 characters *** \n ";
        cin >> password;

        if (password.length() <= 3) {

            cout << "password is short !!! \n\n";
        }

    } while (password.length() <= 3);

    cout << "password successfully selected :) \n\n";
    file2 << password << endl;

    cout << "please enter your first name : \t example : Amirmohammad  \n";
    cin >> name;
    cout << "name successfully selected :) \n\n";
    file2 << name << endl;


    cout << "please enter your last name : \t example : gholampour \n";
    cin >> family_name;
    cout << "last name successfully selected :) \n\n";
    file2 << family_name << endl;


    cout << "please enter your date of birth : \t example : 1380/08/01 \n";
    cin >> date_of_birth;
    cout << "date of birth successfully selected :) \n\n";
    file2 << date_of_birth << endl;


    cout << "please enter your address : \t example : babol_hamzekola_moalem21 \n";
    cin >> address;
    cout << "address successfully selected :) \n\n";
    file2 << address << endl;


    cout << "please enter your phone number : \t example : 09379771380 \n";
    cin >> phone_number;
    cout << "phone number successfully selected :) \n\n";
    file2 << phone_number << endl;


    //time 

    ifstream time("date.txt");
    fstream time1("user.txt", ios::app);

    time >> a >> b >> c;

    time1 << a << "/" << b << "/" << c << endl;


    do {
        cout << "Enter membership duration : \t   enter (1) for six months  or  enter (2) for one year  \n";
        cin >> x;

        if (x != 1 && x != 2) {

            cout << "wrong !!! \t example : 1 , 2 \n";
        }

    } while (x != 1 && x != 2);


    if (x == 1) {

        y = stoi(b);
        y += 6;
        z = stoi(a);

        if (y > 12) {
            y = y - 12;
            z = stoi(a);
            z++;
        }

        time1 << z << endl << y << endl << c << endl;


    }
    else {
        z = stoi(a);
        z++;

        time1 << z << endl << b << endl << c << endl;
    }


    do {
        cout << "please enter your membership type : \t example : normal , vip \n";

        cin >> sign_up_type;
        
        if (sign_up_type != "normal" && sign_up_type != "vip") {

            cout << "wrong !!!  \t please enter normal or vip \n\n";

        }

    } while (sign_up_type != "normal" && sign_up_type != "vip");

    cout << "membership type successfully selected :) \n\n";

    file2 << sign_up_type << endl;

    if (sign_up_type == "normal") {

        borrow_limit = 5;

    }

    else {

        borrow_limit = 10;

    }

    file2 << borrow_limit << endl;


    file2 << 0 << endl;

    file2 << 0 << endl;

    file2 << 0 << endl;

    file2 << 0;

}

//signin - complete
void sign_in() {
    do {
        fstream file("user.txt");

        int count = 0;

        bool passwrodIsWrong = false;

        cout << " ID:\n> ";

        cin >> user.id;

        cout << " Password:\n> ";

        cin >> user.password;

        while (getline(file, id)) {

            if (count % 16 == 0 || count == 0) {

                getline(file, password);

                if (user.id == id) {

                    passwrodIsWrong = true;

                }

                if (user.id == id && user.password == password) {

                    UserisLoggedIn = true;

                    break;

                }

            }

            count ++;

        }

        if (!UserisLoggedIn) {

            if (passwrodIsWrong) {

                cout << "Password is wrong!" << endl;

            }

            if (!passwrodIsWrong) {

                cout << " This user does not exist! Do you want to create an account? (yes/no)\n> ";

                string answer;

                cin >> answer;

                if (answer == "yes") {

                    sign_up();

                    cout << "You can now sign in!" << endl;

                } else {

                    cout << "\nPlease try again!\n";

                }

            }



        }

        file.close();

    } while (!UserisLoggedIn);  

}

//check info - complete
void check_user_info() {

    ifstream check("user.txt");

    string line;

    int j;

    while (getline(check, line)) {
        
        if (user.id == line) {

            for (j = 0; j < 16; j++) {

                getline(check, line);

                if (j == 1) {

                    user.name = line;

                }

                if (j == 2) {

                    user.family_name = line;

                }

                if (j == 3) {

                    user.date_of_birth = line;

                }

                if (j == 4) {

                    user.address = line;

                }

                if (j == 5) {

                    user.phone_number = line;

                }

                if (j == 6) {
                    
                    user.sign_up_date = line;

                }

                if (j == 7) {

                    user.sign_up_expire_date_year = stoi(line);

                }
                
                if (j == 8) {

                    user.sign_up_expire_date_month = stoi(line);
                    
                }

                if (j == 9) {

                    user.sign_up_expire_date_day = stoi(line);

                }

                if (j == 10) {

                    user.sign_up_type = line;

                }

                if (j == 11) {
                   
                    user.borrow_limit = stoi(line);

                }

                if (j == 12) {

                    user.borrow_time_limit = line;

                }

                if (j == 13) {

                    user.books_borrowed = stoi(line);

                }

                if (j == 14) {

                    user.total_delay = stoi(line);

                }        

                if (j == 15) {

                    user.borrowed_list = line;
                    
                }

            }

        }

    }

    check.close();

}

//user_menu - complete
void user_menu() {

    cout << " What do you wish to do?" << endl;

    cout << "1. Edit account info\n2. Extend my account expiry date\n3. Show library\n4. Search for a book\n5. Borrow a book(s)\n6. Retrun a book(s)\n7. Show my borrowed list\n8. My fines\n> ";

    cin >> user_option;

}

//usder edit help - complete
void user_info_help() {

    cout << "to change your:\n username, enter (user)\n password, enter (password)\n name, enter (name)\n family name, enter (family)\n date of birth, enter (date)\n address, enter (address)\n phone number, enter (phone)\n to end editing, enter (finish)\n END OF HELP" << endl;

}

//edit Info User - complete
void edit_info_user() {    
    do {

        cout << "\nPlease enter what you want to edit" << endl;

        cout << "Enter (help) for more information" << endl;

        cout << " Your answer?\n> ";

        string answer;

        cin >> answer;

        cout << endl;

        //HELP
        if (answer == "help") { 

            user_info_help();

        }

        //ID
        if (answer == "user") {

            string changeID;

            bool idNotExist = false;

            ifstream username("user.txt");                    

            string userID;

            int count = 0, countAll = 0;

            while (getline(username, userID)) {

                count++;                

                if (user.id == userID) {

                    cout << "This is your username; " << userID << ".\n Do you wish to change it? (yes/no)\n> ";
                                       
                    cin >> changeID;

                }

                if (changeID == "yes") {

                    cout << " Please enter your new username\n> ";

                    string newID, replace;

                    cin >> newID;

                    user.id = newID;
                    
                    fstream line("user.txt");

                    string counting;

                    while (getline(line, counting)) {

                        countAll++;

                    }

                    line.close();

                    string userexist;

                    fstream userName("user.txt");

                    while (getline(userName, userexist)) {

                        if (newID == userexist) {

                            idNotExist = true;

                            break;

                        }

                    }

                    if (!idNotExist) {

                        ofstream temp("usertemp.txt", ios::trunc);

                        ifstream maintemp("user.txt");

                        for (int k = 0; k < count -1; k++) {

                            getline(maintemp, replace);

                            temp << replace << endl;

                        }

                        temp << user.id << endl;


                        for (int k = 0; k <= countAll; k++) {

                            if (k <= count) {

                                NULL;

                            }

                            else {

                                getline(maintemp, replace);

                                if (k == count + 1) {

                                    NULL;

                                }

                                else {

                                    temp << replace << endl;

                                }

                            }

                        }

                        temp.close();

                        maintemp.close();

                        ofstream usernameNew("user.txt", ios::trunc);

                        ifstream userReplace("usertemp.txt");

                        string temperory;

                        for (int k = 0; k <= countAll; k++) {

                            getline(userReplace, temperory);

                            usernameNew << temperory << endl;

                        }

                        usernameNew.close();

                        userReplace.close();

                    }

                }
                                
            }
            username.close();

            if (changeID == "yes") {

                cout << endl << "Change successful!" << endl;

            }

        }

        //Password
        if (answer == "password") {                

            string changePASSWORD;

            ifstream userpassword("user.txt");

            string userPASSWORD;

            int count = 0, countAll = 0;

            while (getline(userpassword, userPASSWORD)) {

                count++;                

                if (user.password == userPASSWORD) {

                    cout << "This is your password; " << userPASSWORD << ".\n Do you wish to change it? (yes/no)\n> ";

                    cin >> changePASSWORD;

                }

                if (changePASSWORD == "yes") {

                    cout << " Please enter your new password\n> ";

                    string newPASSWORD, replace;

                    cin >> newPASSWORD;

                    user.password = newPASSWORD;

                    fstream line("user.txt");

                    string counting;

                    while (getline(line, counting)) {

                        countAll++;

                    }

                    line.close();

                    fstream userPassword("user.txt");

                    ofstream temp("usertemp.txt", ios::trunc);

                    ifstream maintemp("user.txt");

                    for (int k = 0; k < count - 1; k++) {

                        getline(maintemp, replace);

                        temp << replace << endl;

                    }

                    temp << user.password << endl;


                    for (int k = 0; k <= countAll; k++) {

                        if (k <= count) {

                            NULL;

                        }

                        else {

                            getline(maintemp, replace);

                            if (k == count + 1) {

                                NULL;

                            }

                            else {

                                temp << replace << endl;

                            }

                        }

                    }

                    temp.close();

                    maintemp.close();

                    ofstream userpasswordNew("user.txt", ios::trunc);

                    ifstream userReplace("usertemp.txt");

                    string temperory;

                    for (int k = 0; k <= countAll; k++) {

                        getline(userReplace, temperory);

                        userpasswordNew << temperory << endl;

                    }

                    userpasswordNew.close();

                    userReplace.close();



                }

            }

            userpassword.close();

            if (changePASSWORD == "yes") {

                cout << endl << "Change successful!" << endl;

            }
        }

        //NAME
        if (answer == "name") {

            ifstream name("user.txt");

            string NAME;

            string changeNAME;

            int count = 0, countAll = 0;

            while (getline(name, NAME)) {

                count++;                

                if (user.name == NAME) {

                    cout << "This is your name: " << NAME << ".\n Do you wish to change it? (yes/no)\n> ";

                    cin >> changeNAME;

                }

                if (changeNAME == "yes") {

                    cout << " Please enter your name\n> ";

                    string newNAME, replace;

                    cin >> newNAME;

                    user.name = newNAME;

                    fstream line("user.txt");

                    string counting;

                    while (getline(line, counting)) {

                        countAll++;

                    }

                    line.close();                    

                    ofstream temp("usertemp.txt", ios::trunc);

                    ifstream maintemp("user.txt");

                    for (int k = 0; k < count - 1; k++) {

                        getline(maintemp, replace);

                        temp << replace << endl;

                    }

                    temp << user.name << endl;


                    for (int k = 0; k <= countAll; k++) {

                        if (k <= count) {

                            NULL;

                        }

                        else {

                            getline(maintemp, replace);

                            if (k == count + 1) {

                                NULL;

                            }

                            else {

                                temp << replace << endl;

                            }

                        }

                    }

                    temp.close();

                    maintemp.close();

                    ofstream usernameNew("user.txt", ios::trunc);

                    ifstream userReplace("usertemp.txt");

                    string temperory;

                    for (int k = 0; k <= countAll; k++) {

                        getline(userReplace, temperory);

                        usernameNew << temperory << endl;

                    }

                    usernameNew.close();

                    userReplace.close();



                }

            }
            name.close();

            if (changeNAME == "yes") {

                cout << endl << "Change successful!" << endl;

            }
        }

        //FAMILY NAME
        if (answer == "family") {

            ifstream familyname("user.txt");

            string FAMILYNAME;

            string changeFAMILYNAME;

            int count = 0, countAll = 0;

            while (getline(familyname, FAMILYNAME)) {

                count++;
                
                if (user.family_name == FAMILYNAME) {

                    cout << "This is your family name: " << FAMILYNAME << ".\n Do you wish to change it? (yes/no)\n> ";

                    cin >> changeFAMILYNAME;

                }

                if (changeFAMILYNAME == "yes") {

                    cout << " Please enter your family name\n> ";

                    string newFAMILYNAME, replace;

                    cin >> newFAMILYNAME;

                    user.family_name = newFAMILYNAME;

                    fstream line("user.txt");

                    string counting;

                    while (getline(line, counting)) {

                        countAll++;

                    }

                    line.close();

                    ofstream temp("usertemp.txt", ios::trunc);

                    ifstream maintemp("user.txt");

                    for (int k = 0; k < count - 1; k++) {

                        getline(maintemp, replace);

                        temp << replace << endl;

                    }

                    temp << user.family_name << endl;


                    for (int k = 0; k <= countAll; k++) {

                        if (k <= count) {

                            NULL;

                        }

                        else {

                            getline(maintemp, replace);

                            if (k == count + 1) {

                                NULL;

                            }

                            else {

                                temp << replace << endl;

                            }

                        }

                    }

                    temp.close();

                    maintemp.close();

                    ofstream userfamilynameNew("user.txt", ios::trunc);

                    ifstream userReplace("usertemp.txt");

                    string temperory;

                    for (int k = 0; k <= countAll; k++) {

                        getline(userReplace, temperory);

                        userfamilynameNew << temperory << endl;

                    }

                    userfamilynameNew.close();

                    userReplace.close();



                }

            }
            familyname.close();

            if (changeFAMILYNAME == "yes") {

                cout << endl << "Change successful!" << endl;

            }

        }

        //DATE OF BIRTH
        if (answer == "date") {

            ifstream birth("user.txt");

            string BIRTH;

            string changeBIRTH;

            int count = 0, countAll = 0;

            while (getline(birth, BIRTH)) {

                count++;                

                if (user.date_of_birth == BIRTH) {

                    cout << "This is your birth day: " << user.date_of_birth << ".\n Do you wish to change it? (yes/no)\n> ";

                    cin >> changeBIRTH;

                }

                if (changeBIRTH == "yes") {

                    cout << " Please enter the year you were born\n> ";

                    string year , month , day , newBirth, replace;

                    cin >> year;

                    cout << " Please enter the month you were born\n> ";

                    cin >> month;

                    cout << " Please enter the day you were born\n> ";

                    cin >> day;

                    user.date_of_birth = year;

                    user.date_of_birth += "/";

                    user.date_of_birth += month;

                    user.date_of_birth += "/";

                    user.date_of_birth += day;

                    fstream line("user.txt");

                    string counting;

                    while (getline(line, counting)) {

                        countAll++;

                    }

                    line.close();

                    ofstream temp("usertemp.txt", ios::trunc);

                    ifstream maintemp("user.txt");

                    for (int k = 0; k < count - 1; k++) {

                        getline(maintemp, replace);

                        temp << replace << endl;

                    }

                    temp << user.date_of_birth << endl;


                    for (int k = 0; k <= countAll; k++) {

                        if (k <= count) {

                            NULL;

                        }

                        else {

                            getline(maintemp, replace);

                            if (k == count + 1) {

                                NULL;

                            }

                            else {

                                temp << replace << endl;

                            }

                        }

                    }

                    temp.close();

                    maintemp.close();

                    ofstream userbirthNew("user.txt", ios::trunc);

                    ifstream userReplace("usertemp.txt");

                    string temperory;

                    for (int k = 0; k <= countAll; k++) {

                        getline(userReplace, temperory);

                        userbirthNew << temperory << endl;

                    }

                    userbirthNew.close();

                    userReplace.close();

                }

            }

            birth.close();

            if (changeBIRTH == "yes") {

                cout << endl << "Change successful!" << endl;

            }

        }

        //ADDRESS
        if (answer == "address") {

            ifstream address("user.txt");

            string ADDRESS;

            string changeADDRESS;

            int count = 0, countAll = 0;

            while (getline(address, ADDRESS)) {

                count++;                

                if (user.address == ADDRESS) {

                    cout << "This is your address: " << ADDRESS << ".\n Do you wish to change it? (yes/no)\n> ";

                    cin >> changeADDRESS;

                }

                if (changeADDRESS == "yes") {

                    cout << " Please enter your address\n> ";


                    string newADDRESS, replace;

                    cin >> newADDRESS;

                    user.address = newADDRESS;

                    fstream line("user.txt");

                    string counting;

                    while (getline(line, counting)) {

                        countAll++;

                    }

                    line.close();

                    ofstream temp("usertemp.txt", ios::trunc);

                    ifstream maintemp("user.txt");

                    for (int k = 0; k < count - 1; k++) {

                        getline(maintemp, replace);

                        temp << replace << endl;

                    }

                    temp << user.address << endl;


                    for (int k = 0; k <= countAll; k++) {

                        if (k <= count) {

                            NULL;

                        }

                        else {

                            getline(maintemp, replace);

                            if (k == count + 1) {

                                NULL;

                            }

                            else {

                                temp << replace << endl;

                            }

                        }

                    }

                    temp.close();

                    maintemp.close();

                    ofstream userfamilynameNew("user.txt", ios::trunc);

                    ifstream userReplace("usertemp.txt");

                    string temperory;

                    for (int k = 0; k <= countAll; k++) {

                        getline(userReplace, temperory);

                        userfamilynameNew << temperory << endl;

                    }

                    userfamilynameNew.close();

                    userReplace.close();

                }

            }

            address.close();

            if (changeADDRESS == "yes") {

                cout << endl << "Change successful!" << endl;

            }

        }

        //PHONE NUMBER
        if (answer == "phone") {

            ifstream phonenumber("user.txt");

            string PHONENUMBER;

            string changePHONENUMBER;

            int count = 0, countAll = 0;

            while (getline(phonenumber, PHONENUMBER)) {

                count++;

                if (user.phone_number == PHONENUMBER) {

                    cout << "This is your phone number: " << PHONENUMBER << ".\n Do you wish to change it? (yes/no)\n> ";

                    cin >> changePHONENUMBER;

                }

                if (changePHONENUMBER == "yes") {

                    cout << " Please enter your family name\n> ";

                    string newPHONENUMBER, replace;

                    cin >> newPHONENUMBER;

                    user.phone_number = newPHONENUMBER;

                    fstream line("user.txt");

                    string counting;

                    while (getline(line, counting)) {

                        countAll++;

                    }

                    line.close();

                    ofstream temp("usertemp.txt", ios::trunc);

                    ifstream maintemp("user.txt");

                    for (int k = 0; k < count - 1; k++) {

                        getline(maintemp, replace);

                        temp << replace << endl;

                    }

                    temp << user.phone_number << endl;


                    for (int k = 0; k <= countAll; k++) {

                        if (k <= count) {

                            NULL;

                        }

                        else {

                            getline(maintemp, replace);

                            if (k == count + 1) {

                                NULL;

                            }

                            else {

                                temp << replace << endl;

                            }

                        }

                    }

                    temp.close();

                    maintemp.close();

                    ofstream userphonenumberNew("user.txt", ios::trunc);

                    ifstream userReplace("usertemp.txt");

                    string temperory;

                    for (int k = 0; k <= countAll; k++) {

                        getline(userReplace, temperory);

                        userphonenumberNew << temperory << endl;

                    }

                    userphonenumberNew.close();

                    userReplace.close();



                }

            }
            phonenumber.close();

            if (changePHONENUMBER == "yes") {

                cout << endl << "Change successful!" << endl;

            }
        }

        //FINISH EDITING
        if (answer == "finish") {
            edit = false;
        }

    } while (edit);

}

//show borrowed books - complete
void show_user_book() {

    if (user.borrowed_list != "0") {

        cout << "\nHere are the books you have borrowed:\n\n";

        string book, string;

        int count = 0;

        ifstream line("books.txt.");

        while (getline(line, string)) {

            count++;

        }

        line.close();

        for (int i = 0; i < user.borrowed_list.length(); i += 2) {

            fstream books("books.txt");

            for (int j = 0; j < count; j++) {

                getline(books, book);

                if (user.borrowed_list.substr(i, 2) == book) {

                    for (int k = 0; k < 15; k++) {

                        cout << book << endl;

                        getline(books, book);

                    }

                    cout << "\n" << "-------------------------------\n" << endl;

                }


            }

        }

    }
    else {

        cout << "\n You don't have any borrowed book!\n";

    }

}

//admin - complete
void adminstrator() {
    do {

        fstream file("admins.txt");

        int count = 0;

        bool passwrodIsWrong = false;

        cout << " id : ";

        cin >> admin.id;

        cout << "password : ";

        cin >> admin.password;

        while (getline(file, id)) {

            if (count % 2 == 0 || count == 0) {

                getline(file, password);

                if (admin.id == id) {

                    passwrodIsWrong = true;

                }

                if (admin.id == id && admin.password == password) {

                    AdminisLoggedIn = true;

                    adminSignIn = true;



                    break;

                }

            }

            count+=2;

        }

        if (!AdminisLoggedIn) {

            if (passwrodIsWrong) {

                cout << "Password is wrong!" << endl;

            }

            if (!passwrodIsWrong) {

                cout << "This user does not exist!" << endl;

            }

        }

        file.close();

    } while (!AdminisLoggedIn);

}

//admin menu - complete
void admin_menu() {

    cout << " What do you wish to do?" << endl;

    cout << "1. Add a book\n2. Edit a book\n3. Remove a book\n4. Remove a user\n5. Show library\n> ";

    cin >> admin_option;

}

//remove a book - complete
void remove_book()
{
    string id, line;
    int count, temp;
    bool edit = false;

    cout << " book id : \n>";
    cin >> id;

    ifstream file("books.txt");

    count = 0;

    while (getline(file, line)) {

        count++;

        if ((count - 1) % 15 == 0 && id == line) {

            temp = count;
            edit = true;
        }

    }

    file.close();

    if (edit) {

        ifstream read("books.txt");
        ofstream write("new.txt");
        count = 0;

        while (getline(read, line)) {

            count++;

            if (count < temp || count >= (temp + 15)) {

                write << line << endl;
            }

        }

        read.close();
        write.close();

    }
    else {

        cout << " id does not found . \n";
    }

    if (edit) {

        cout << "remove successfully :) \n";

        remove("books.txt");
        rename("new.txt", "books.txt");
    }

}

//show the book list - complete
void show_book_list() {

    cout << "\nHere are the available books:\n\n";
    string book, string;

    int count = 0;

    ifstream line("books.txt.");

    while (getline(line, string)) {

        count++;

    }

    line.close();


    fstream books("books.txt");

    for (int j = 0; j < count ; j += 15) {

        for (int k = 0; k < 15; k++) {

            getline(books, book);

            cout << book << endl;            

        }

        cout << "\n" << "-------------------------------\n" << endl;

    }

}

//adding a book - complete
void addbook()
{
    fstream books("books.txt", ios::app);

    do {
        cout << "please enter book id :     *** id should be 2 characters long ***    example : b1 \n>";

        cin >> book.id;

        system("CLS");

        if (book.id.length() != 2) {

            cout << "wrong !!!   *** id should be 2 characters long *** \n please try again \n";

        }

    } while (book.id.length() != 2);

    books << endl;

    cout << "book id enter successfully \n";

    books << book.id << endl;

    Sleep(2000);

    system("CLS");

    cout << "please enter book title :    example : salam_bar_ebrahim \n>";

    cin >> book.title;

    system("CLS");

    cout << "book title enter successfully \n";

    books << book.title << endl;

    Sleep(2000);

    system("CLS");

    cout << "please enter book category :    example : omomi \n>";

    cin >> book.category;

    system("CLS");

    cout << "book category enter successfully \n";

    books << book.category << endl;

    Sleep(2000);

    system("CLS");

    cout << "please enter book publisher :    example : daftar_nashr_maaref \n>";

    cin >> book.publisher;

    system("CLS");

    cout << "book publisher enter successfully \n";

    books << book.publisher << endl;

    Sleep(2000);

    system("CLS");

    cout << "please enter book issued :      example : 17 \n>";

    cin >> book.issued;

    system("CLS");

    cout << "book issued enter successfully \n";

    books << book.issued << endl;

    Sleep(2000);

    system("CLS");

    cout << "please enter book edition :      example : virast_panjom  \n>";

    cin >> book.edition;

    system("CLS");

    cout << "book edition enter successfully \n";

    books << book.edition << endl;

    Sleep(2000);

    system("CLS");

    cout << "please enter book date published :     example : 1390 \n>";

    cin >> book.date_published;

    system("CLS");


    cout << "book date published enter successfully \n";

    books << book.date_published << endl;

    Sleep(2000);

    system("CLS");

    cout << "please enter book date last edited :     example : 1398 \n>";

    cin >> book.last_edited;

    system("CLS");

    cout << "book date last edited enter successfully \n";

    books << book.last_edited << endl;

    Sleep(2000);

    system("CLS");

    cout << "please enter book price :    *** The amount is in Toman ***    example : 70000 \n>";

    cin >> book.price;
    
    system("CLS");

    cout << "book price enter successfully \n";

    books << book.price << endl;

    Sleep(2000);

    system("CLS");

    cout << "please enter book author :     example : william_Shakespeare\n>";

    cin >> book.author;
    
    system("CLS");

    cout << "book author enter successfully \n";

    books << book.author << endl;

    Sleep(2000);

    system("CLS");


    do {

        cout << "please enter book canLend :   *** if it can be borrowed eter (1)  and  if it can not be borrowed enter (3) ***       example : 1 \n>";

        cin >> book.canLend;

        if (book.canLend != "1" && book.canLend != "3") {

            cout << "wrong !!!    *** if it can be borrowed enter (1)  and  if it can not be borrowed enter (3) ***       example : 1 \n";

            Sleep(2000);

            system("CLS");

        }

    } while (book.canLend != "1" && book.canLend != "3");

    cout << "book canLend enter successfully \n";

    Sleep(2000);

    system("CLS");

    books << book.canLend << endl;

    books << 0 << endl;         // last user

    cout << "please enter daily fine :      *** The amount is in Toman ***        example : 500 \n>";

    cin >> book.daily_fine;

    system("CLS");

    cout << "book daily fine enter successfully \n";

    books << book.daily_fine << endl;

    books << 0 << endl;         // last borrow date

    books << 0 << endl;         // time limit
    
    Sleep(2000);

    system("CLS");

}

//search book - complete
void search_book() {

    bool skipBook = true;

    string search, Line, temp, result, replace;

    fstream Replace("books.txt");

    ofstream file2("booktemp.txt", ios::trunc);

    while (getline(Replace, replace)) {

        file2 << replace << endl;

    }

    file2.close();

    Replace.close();

    int count = 0;

    cout << "\nPlease enter a phrase to search\n";

    cin >> search;

    system("CLS");

    cout << "\nSearching... please wait\n";

    fstream line("books.txt");

    while (getline(line, Line)) {

        count++;

    }

    line.close();

    fstream file("books.txt");

    fstream temperory("booktemp.txt");

    for (int i = 0; i < count; i++) {

        skipBook = true;

        for (int l = 0; l < 15; l++) {

            getline(temperory, temp);

            for (int k = 0; k < temp.length(); k++) {

                if (search == temp.substr(k, search.length())) {

                    Sleep(500);

                    cout << "\n-------------------------------\n";

                    for (int j = 0; j < 15; j++) {

                        getline(file, result);

                        cout << result << endl;

                        skipBook = false;

                    }

                }

            }


        }

        if (skipBook) {

            for (int j = 0; j < 15; j++) {

                getline(file, result);

            }

        }

    }

    temperory.close();

    file.close();

    cout << "\n-------------------------------\n";

}

//book_list_edit - complete
void booklist_edit() {



}

//check expire date - complete
void expire_date() {

    string Time;

    int  date[3];

    fstream time("date.txt");

    for (int i = 0; i < 3; i++) {

        getline(time, Time);

        date[i] = stoi(Time);

    }

    time.close();

    int i = 0;

    if (i == 0) {

        if (date[i] > user.sign_up_expire_date_year) {

            expire = true;

            UserisLoggedIn = false;

        }

        if (date[i] == user.sign_up_expire_date_year) {

            i++;

        }

    }

    if (i == 1) {

        if (date[i] > user.sign_up_expire_date_month) {

            expire = true;

            UserisLoggedIn = false;

        }

        if (date[i] == user.sign_up_expire_date_month) {

            i++;

        }

        

    }

    if (i == 2) {

        if (user.sign_up_expire_date_day <  date[i]) {

            expire = true;

            UserisLoggedIn = false;

        }

    }

}

//borrowing a book - complete
void borrow_book() {

    bool complete = false, search = true, finish = false, show = true , first = true;

    string BOOK, ID, changeBOOK;

    int count = 0, countAll = 0;

    while (!complete) {

        while (first) {

            if (user.borrowed_list == "0") {

                show = false;

                cout << "\nYou have not borrowed any books!\n";

            }

            first = false;

        }

        while (show) {

            ifstream booklist("books.txt");

            cout << "This is your book list:\n";

            for (int k = 0; k < user.borrowed_list.length(); k += 2) {

                while (getline(booklist, BOOK)) {

                    count++;

                    if (user.borrowed_list.substr(k, 2) == BOOK) {

                        cout << "----------\n";

                        for (int i = 0; i < 15; i++) {

                            cout << BOOK << endl;

                            getline(booklist, BOOK);

                        }

                        cout << "----------\n";

                    }

                }

            }

            booklist.close();

            show = false;

        }

        cout << "\n Do you wish to borrow a book? (yes/no)\n> ";

        cin >> changeBOOK;

        bool length = false;

        if (changeBOOK == "yes") {

            while (!length) {

                string newBOOK;

                cout << "\nPlease enter book's id\n> ";

                cin >> newBOOK;

                if (newBOOK.length() == 2) {

                    length = true;

                    ID = newBOOK;

                }
                else {

                    cout << endl << "Error! Book's id should be 2 characters long!" << endl;

                }

            }

        }

        if (changeBOOK == "no") {

            break;

        }

        string code;

        while (search) {

            fstream canlend("books.txt");

            while (getline(canlend, code)) {

                if (code == ID) {

                    for (int k = 0; k < 10; k++) {

                        getline(canlend, code);

                    }

                    search = false;

                    break;

                }

            }

            canlend.close();

        }

        if (code == "1") {

            if (user.borrowed_list == "0") {

                user.borrowed_list = ID;

            }
            else {

                user.borrowed_list += ID;

            }

            ifstream mainTOtemp("user.txt");

            string MAINtotemp;

            ofstream temp("usertemp.txt", ios::trunc);

            while (getline(mainTOtemp, MAINtotemp)) {

                temp << MAINtotemp << endl;

                if (MAINtotemp == user.id) {

                    for (int i = 0; i < 15; i++) {

                        getline(mainTOtemp, MAINtotemp);

                        temp << MAINtotemp << endl;

                    }

                    temp << user.borrowed_list << endl;

                    getline(mainTOtemp, MAINtotemp);

                }

            }

            mainTOtemp.close();

            temp.close();

            string temptoMaiN;

            ifstream tempTOmain("usertemp.txt");

            ofstream MaiN("user.txt", ios::trunc);

            while (getline(tempTOmain, temptoMaiN)) {

                MaiN << temptoMaiN << endl;

            }

            complete = true;

            finish = true;

        }

        if (code == "2") {

            cout << "\nThis book is already borrowed!\n\n\n";

            search = true;

        }

        if (code == "3") {

            cout << "\nSorry for the inconvenience, but this book can only be read at our library and can't be accessed through this app!\n\n\n";

            search = true;

        }

    }

    if (finish) {

        ifstream MaintoTemp("books.txt");

        ofstream Temp("booktemp.txt", ios::trunc);

        string MAINtoTEMP;

        while (getline(MaintoTemp, MAINtoTEMP)) {

            Temp << MAINtoTEMP << endl;

            if (MAINtoTEMP == ID) {

                for (int i = 0; i < 9; i++) {

                    getline(MaintoTemp, MAINtoTEMP);

                    Temp << MAINtoTEMP << endl;

                }

                getline(MaintoTemp, MAINtoTEMP);

                Temp << "2" << endl;

                for (int i = 0; i < 2; i++) {

                    getline(MaintoTemp, MAINtoTEMP);

                    Temp << MAINtoTEMP << endl;

                }

                ifstream time("date.txt");

                string Time, Zero;

                for (int i = 0; i < 3; i++){
                
                    getline(time, Time);

                    Zero = "0";

                    if (Time.length() == 1) {

                        Zero += Time;

                        Time = Zero;

                    }

                    Temp << Time ;

                }

                time.close();

                Temp << endl;

                getline(MaintoTemp, MAINtoTEMP);

            }

        }

        MaintoTemp.close();

        Temp.close();

        ifstream TemptoMain("booktemp.txt");

        ofstream Main("books.txt", ios::trunc);

        string TEMPtoMAIN;

        while (getline(TemptoMain, TEMPtoMAIN)) {

            Main << TEMPtoMAIN << endl;

        }

        Main.close();

        TemptoMain.close();

        cout << endl << "Book added!\n Please wait..." << endl;

        finish = true;

    }

}

// extend account expiry date - complete
void extend_expiry_date()
{
    string id, line, code;

    int count;
    int a, x = 0, y = 0;

    bool months = false;
    bool edit = false;

    id = user.id;

    fstream userr("user.txt", ios::in);
    fstream newfile("new.txt", ios::out);

    count = 0;

    while (getline(userr, line)) {

        edit = false;
        count++;

        if ((count - 1) % 17 == 0 && line == id) {

            if (code == "1") {

                x = count + 9;
                y = count + 8;
            }
            else {
                y = count + 8;
            }
        }

        if (code == "1" && count == x) {

            a = stoi(line);
            a = a + 6;

            edit = true;

            if (a > 12) {

                months = true;
                a = a - 12;
            }

        }

        if (code == "2" && count == y) {

            a = stoi(line);
            a = a + 1;

            edit = true;
        }


        if (edit) {

            newfile << a << endl;
        }
        else {
            newfile << line << endl;
        }

    }

    newfile.close();
    userr.close();

    if (months) {

        fstream newfile("neww.txt", ios::out);
        fstream userr("new.txt", ios::in);

        count = 0;

        while (getline(userr, line)) {

            count++;

            if (count == y) {

                a = stoi(line);
                a = a + 1;

                newfile << a << endl;
            }
            else {

                newfile << line << endl;
            }

        }

    }

    if (months) {

        remove("new.txt");

        remove("user.txt");

        rename("neww.txt", "user.txt");
    }
    else {

        remove("user.txt");

        rename("new.txt", "user.txt");
    }

    newfile.close();

    userr.close();

    expire = false;

}

//returning a book
void return_book() {

    if (user.borrowed_list != "0") {

        cout << "\nHere are the books you have borrowed:\n\n";

        string book, string;

        int count = 0;

        ifstream line("books.txt.");

        while (getline(line, string)) {

            count++;

        }

        line.close();

        for (int i = 0; i < user.borrowed_list.length(); i += 2) {

            fstream books("books.txt");

            for (int j = 0; j < count; j++) {

                getline(books, book);

                if (user.borrowed_list.substr(i, 2) == book) {

                    for (int k = 0; k < 15; k++) {

                        cout << book << endl;

                        getline(books, book);

                    }

                }

                cout << "------------------------------- \n";

            }

        }

        char a[100];

        bool correct = false;

        while (!correct) {

            cout << "\nDo you wish to continue? (yes/no)\n> ";

            cin >> a;

            if (a == "yes" || a == "no") {

                correct = true;

            }

            if (!correct) {

                cout << "\nPlease enter your answer correctly!\n\n";

            }

        }

        if (a == "no") {

            NULL;

        }
        else {

            if (correct) {

                string answer;

                cout << "\nSelect the book's id that you want to return\n> ";




            }

        }






    }
    else {

        cout << "\nYou have not borrowed any books yet!\n\n";

    }

}

//delete a user - complete
void delete_user()
{

    string line, id;

    cout << "enter the user id which you want to delete : \n>";
    cin >> id;

    ifstream read("user.txt");
    bool edit = false;
    int count = 0, temp;

    while (getline(read, line)) {

        count++;

        if ((count - 1) % 17 == 0 && id == line) {

            edit = true;
            temp = count;
        }

    }

    read.close();

    if (edit) {

        ifstream read("user.txt");
        ofstream write("new.txt");

        count = 0;

        while (getline(read, line)) {

            count++;

            if (count < temp || count >= (temp + 17)) {

                write << line << endl;
            }
        }

        read.close();
        write.close();

    }
    else {

        cout << " id does not found . \n";
    }

    if (edit) {

        cout << "user deleted successfully :) \n";

        remove("user.txt");
        rename("new.txt", "user.txt");

    }

}

//edit a book - complete
void edit_book()
{
    string line, id, code, x;


    cout << "please enter id of the book which you want to change information : \n>";
    cin >> id;

    ifstream read("books.txt");

    bool find = false, edit = false;
    int count = 0, temp;


    while (getline(read, line)) {

        count++;

        if ((count - 1) % 15 == 0 && id == line) {

            find = true;
            temp = count;
        }

    }

    read.close();

    if (find) {

        cout << "book found seccessfully :) \n";
        cout << "please enter what you want to edit :\n for more information enter (help) \n your answer ? \n>";
        cin >> code;

        while (code == "help") {

            cout << "***********************************************************\n\n";
            cout << "\tbook id , enter ( id ) \n";
            cout << "\tbook title , enter ( title ) \n";
            cout << "\tbook category , enter ( category ) \n";
            cout << "\tbook publisher , enter ( publisher ) \n";
            cout << "\tbook issued , enter ( issued ) \n";
            cout << "\tbook edition , enter ( edition ) \n";
            cout << "\tbook date published , enter ( date_published ) \n";
            cout << "\tbook last edited , enter ( last_edited ) \n";
            cout << "\tbook price , enter ( price ) \n";
            cout << "\tbook author , enter ( author ) \n";
            cout << "\tbook canLend , enter ( canLend ) \n";

            cout << "\tbook daily fine , enter ( daily_fine ) \n\n";
            cout << "***********************************************************\n\n";

            cin >> code;
        }

        if (code == "id") {

            cout << "please enter new book id :      *** book id should be 2 characters ***        example : b1 \n>";
            cin >> x;

            edit = true;

            ifstream read("books.txt");
            ofstream write("new.txt");

            count = 0;

            while (getline(read, line)) {

                count++;

                if (count == temp) {

                    write << x << endl;
                }
                else {

                    write << line << endl;
                }

            }

            read.close();
            write.close();
        }


        if (code == "title") {

            cout << "please enter new book title :   \n>";
            cin >> x;

            edit = true;

            ifstream read("books.txt");
            ofstream write("new.txt");

            count = 0;

            while (getline(read, line)) {

                count++;

                if (count == (temp + 1)) {

                    write << x << endl;
                }
                else {

                    write << line << endl;
                }

            }

            read.close();
            write.close();
        }

        if (code == "category") {

            cout << "please enter new book category :   \n>";
            cin >> x;

            edit = true;

            ifstream read("books.txt");
            ofstream write("new.txt");

            count = 0;

            while (getline(read, line)) {

                count++;

                if (count == (temp + 2)) {

                    write << x << endl;
                }
                else {

                    write << line << endl;
                }

            }

            read.close();
            write.close();
        }


        if (code == "publisher") {

            cout << "please enter new book publisher :   \n>";
            cin >> x;

            edit = true;

            ifstream read("books.txt");
            ofstream write("new.txt");

            count = 0;

            while (getline(read, line)) {

                count++;

                if (count == (temp + 3)) {

                    write << x << endl;
                }
                else {

                    write << line << endl;
                }

            }

            read.close();
            write.close();
        }

        if (code == "issued") {

            cout << "please enter new book issued :   \n>";
            cin >> x;

            edit = true;

            ifstream read("books.txt");
            ofstream write("new.txt");

            count = 0;

            while (getline(read, line)) {

                count++;

                if (count == (temp + 4)) {

                    write << x << endl;
                }
                else {

                    write << line << endl;
                }

            }

            read.close();
            write.close();
        }

        if (code == "edition") {

            cout << "please enter new book edition :   \n>";
            cin >> x;

            edit = true;

            ifstream read("books.txt");
            ofstream write("new.txt");

            count = 0;

            while (getline(read, line)) {

                count++;

                if (count == (temp + 5)) {

                    write << x << endl;
                }
                else {

                    write << line << endl;
                }

            }

            read.close();
            write.close();
        }

        if (code == "date_published") {

            cout << "please enter new book date published :   \n>";
            cin >> x;

            edit = true;

            ifstream read("books.txt");
            ofstream write("new.txt");

            count = 0;

            while (getline(read, line)) {

                count++;

                if (count == (temp + 6)) {

                    write << x << endl;
                }
                else {

                    write << line << endl;
                }

            }

            read.close();
            write.close();
        }

        if (code == "last_edited") {

            cout << "please enter new book last edited :   \n>";
            cin >> x;

            edit = true;

            ifstream read("books.txt");
            ofstream write("new.txt");

            count = 0;

            while (getline(read, line)) {

                count++;

                if (count == (temp + 7)) {

                    write << x << endl;
                }
                else {

                    write << line << endl;
                }

            }

            read.close();
            write.close();
        }

        if (code == "price") {

            cout << "please enter new book price :   \n>";
            cin >> x;

            edit = true;

            ifstream read("books.txt");
            ofstream write("new.txt");

            count = 0;

            while (getline(read, line)) {

                count++;

                if (count == (temp + 8)) {

                    write << x << endl;
                }
                else {

                    write << line << endl;
                }

            }

            read.close();
            write.close();
        }


        if (code == "author") {

            cout << "please enter new book author :   \n>";
            cin >> x;

            edit = true;

            ifstream read("books.txt");
            ofstream write("new.txt");

            count = 0;

            while (getline(read, line)) {

                count++;

                if (count == (temp + 9)) {

                    write << x << endl;
                }
                else {

                    write << line << endl;
                }

            }

            read.close();
            write.close();
        }

        if (code == "canLend") {

            cout << "please enter new book canLend :   \n>";
            cin >> x;

            edit = true;

            ifstream read("books.txt");
            ofstream write("new.txt");

            count = 0;

            while (getline(read, line)) {

                count++;

                if (count == (temp + 10)) {

                    write << x << endl;
                }
                else {

                    write << line << endl;
                }

            }

            read.close();
            write.close();
        }

        if (code == "daily_fine") {

            cout << "please enter new book daily fine :   \n>";
            cin >> x;

            edit = true;

            ifstream read("books.txt");
            ofstream write("new.txt");

            count = 0;

            while (getline(read, line)) {

                count++;

                if (count == (temp + 12)) {

                    write << x << endl;
                }
                else {

                    write << line << endl;
                }

            }

            read.close();
            write.close();
        }

        remove("books.txt");
        rename("new.txt", "books.txt");

    }

    if (!find) {

        cout << "book does not found . \n";
    }

    if (!edit) {

        cout << " edit not successfull . \n";
    }

}

//fine
void fine() {



}