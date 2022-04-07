///////////////////////////////
////        Header         ////
///////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

///////////////////////////////
////     Book Class        ////
///////////////////////////////

class book
{

public:
    string title;          // title
    string author;         // author
    string isbn;           // isbn
    string publication;    // publication
    bool available = true; // check if the book is available or not
    string user = "None";  // store the id of the user taking this book
};

///////////////////////////////
////     User Class        ////
///////////////////////////////

class user
{

    // There is a specific technicality with the id of the user
    // All the student must use s before their id number
    // All the professors must use p before their id number

public:
    string name;                   // name
    string id;                     // id
    string password;               // Password
    vector<pair<book, int>> owned; // This stores the set of books borrowed by the user.
};

/////////////////////////////////////////////
////     Function for book Request       ////
/////////////////////////////////////////////

void bookRequest(book b, user u) // Takes input as book and user object and changes the attributes of these objects;
{
    system("cls");
    string n = u.id;
    if (n[0] == 's')
    {
        if (u.owned.size() < 5 && b.available == true)
        {
            (u.owned).push_back({b, 0});
            b.available = false;
            b.user = u.id;
            cout << "Book request successful" << endl;
        }
        else
        {
            cout << "Student can only borrow at MAX 5 books." << endl;
        }
        return;
    }
    if (n[0] == 'p')
    {
        if (b.available == true)
        {
            (u.owned).push_back({b, 0});
            b.available = false;
            b.user = u.id;
            cout << "Book request successful" << endl;
            return;
        }
    }
    return;
}

/////////////////////////////////////
//     Class for Book database     //
/////////////////////////////////////

class bookDatabase
{
public:
    vector<book> books; // Database vector to store all the books.

    // This function adds a book to the database.
    void add()
    {
        book temp;

        // Here we take all the inputs basically required for a book object
        string t, a, i, p;
        system("cls");
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Enter the title of the book: ";
        cin >> t;
        cout << endl;

        cout << "Enter the author of the book: ";
        cin >> a;
        cout << endl;

        cout << "Enter the isbn of the book: ";
        cin >> i;
        cout << endl;

        cout << "Enter the publication of the book: ";
        cin >> p;
        cout << endl;

        temp.title = t;
        temp.author = a;
        temp.isbn = i;
        temp.publication = p;
        temp.available = true; // Initially the book is available to all
        temp.user = "None";    // initializing the user as None.
        books.push_back(temp);
        cout << books.size() << endl;

        cout << "Book added with us! Thank you" << endl;
        cout << "---------------------------------------------------------------" << endl;
    }

    // This function updates book from the database.
    void update()
    {

        string t;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Enter the title of the book you want to update: ";
        cin >> t;
        int flag = 0;
        cout << books.size() << endl;
        for (int i = 0; i < books.size(); i++)
        {
            cout << books[i].title << endl;
            if (books[i].title == t)
            {
                cout << "Enter the new title: ";
                cin >> books[i].title;
                cout << endl;

                cout << "Enter the new author: ";
                cin >> books[i].author;
                cout << endl;

                cout << "Enter the new isbn: ";
                cin >> books[i].isbn;
                cout << endl;

                cout << "Enter the new publication: ";
                cin >> books[i].publication;
                cout << endl;

                cout << "Book update successful" << endl;
                flag = 1;
                return;
            }
        }
        if (!flag)
        {
            cout << "Wrong title entered" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            return;
        }
        cout << "-----------------------------------------------------------------" << endl;
        return;
    }

    // This function deletes a book from the database.
    void deleteBook()
    {
        string t;
        system("cls");
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Enter the title of the book you want to delete: ";
        cin >> t;
        int n = books.size();
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (books[i].title == t)
            {
                cout << "Are you sure you want to delete the book ? Press Y for yes and N for no." << endl;
                char c;
                cin >> c;
                if (c == 'y' || c == 'Y')
                {
                    books.erase(books.begin() + i);
                    cout << "Book Deleted" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    cout << "Book delete confirmation denied" << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << "Wrong title entered" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            return;
        }
        cout << "-----------------------------------------------------------------" << endl;
        return;
    }

    // This function deletes the book from the database.
    void search()
    {
        string t;
        system("cls");
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Enter the title of the book you want to search: ";
        cin >> t;
        int n = books.size();
        book obj;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (books[i].title == t)
            {
                cout << " ---- Book found ---" << endl;
                cout << "The title of the book is - " << books[i].title << endl;
                cout << "The author of the book is " << books[i].author << endl;
                cout << "The isbn of the book is " << books[i].isbn << endl;
                cout << "The publication of the book is " << books[i].publication << endl;
                if (books[i].available)
                {
                    cout << "The following book is available" << endl;
                }
                else
                {
                    cout << "The following book is not available" << endl;
                    cout << "Id of the user who has this book currently : " << books[i].user << endl;
                }
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            cout << "---- Book not found ----" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            return;
        }
        cout << "-----------------------------------------------------------------" << endl;
        return;
    }

    // This function return the book object which the user wants to borrow.
    book borrow()
    {
        system("cls");

        // Idea == Here i created a trash object which is returned when the book is not found
        book trash;
        trash.title = "null";

        string t;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Enter the title of the book you want to borrow : ";
        cin >> t;
        for (int i = 0; i < books.size(); i++)
        {
            cout << books[i].title << " ";
            if (books[i].title == t)
            {
                cout << "-----------------------------------------------------------------" << endl;
                return books[i];
            }
        }
        cout << "-----------------------------------------------------------------" << endl;
        return trash;
    }

    void dispAll()
    {
        string t;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Displaying all the users ";
        int n = books.size();
        book obj;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            cout << "Book #" << i + 1 << endl;
            cout << "The title of the book is - " << books[i].title << endl;
            cout << " The author of the book is " << books[i].author << endl;
            cout << " The isbn of the book is " << books[i].isbn << endl;
            cout << " The publication of the book is " << books[i].publication << endl;
            if (books[i].available)
            {
                cout << "The following book is available" << endl;
            }
            else
            {
                cout << "The following book is not available" << endl;
                cout << "Id of the user who currently have this book - " << books[i].user << endl;
            }
            cout << "----------------------------------------------------------------------------------------------------------"<< endl;
        }
        return;
    }
};

/////////////////////////////////////
//     Class for User database     //
/////////////////////////////////////

class userdatabase
{

public:
    vector<user> users;

    // This function adds user to the database
    void add()
    {
        user temp;
        string n, i, p;
        system("cls");
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Enter the name of the user: ";
        cin >> n;
        cout << endl;

        cout << "Enter the id of the user: ";
        cin >> i;
        cout << endl;

        cout << "Enter the password for the user: ";
        cin >> p;
        cout << endl;

        temp.name = n;
        temp.id = i;
        temp.password = p;

        users.push_back(temp);

        cout << "User added with us! Thank you" << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }

    // This function deletes the user from the database
    void deleteuser()
    {
        string t;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Enter the name of the user you want to delete: ";
        cin >> t;
        int n = users.size();
        user obj;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (users[i].name == t)
            {

                cout << "Are you sure you want to delete the user ? Press Y for yes and N for no." << endl;
                char c;
                cin >> c;
                if (c == 'y' || c == 'Y')
                {
                    users.erase(users.begin() + i);
                    cout << "Book Deleted" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    cout << "User delete confirmation denied" << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << "Wrong name entered" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            return;
        }
        cout << "-----------------------------------------------------------------" << endl;
        return;
    }

    // This function updates the user from the database
    void update()
    {
        string t;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Enter the name of the user you want to update: ";
        cin >> t;
        int n = users.size();
        user obj;
        int flag = 0;
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].name == t)
            {
                cout << "Enter the new name: ";
                cin >> users[i].name;
                cout << endl;

                cout << "Enter the new id: ";
                cin >> users[i].id;
                cout << endl;

                cout << "User update successful" << endl;
                flag = 1;
                return;
            }
        }
        if (!flag)
        {
            cout << "Wrong title entered" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            return;
        }
        cout << "-----------------------------------------------------------------" << endl;
        return;
    }

    // This function searches the user from the database.
    void search()
    {
        string t;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Enter the name of the user you want to search: ";
        cin >> t;
        int n = users.size();
        book obj;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (users[i].name == t)
            {
                cout << "The name of the user is - " << users[i].name << endl;
                cout << "The id of the user is - " << users[i].id << endl;
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            cout << "Wrong name entered" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            return;
        }
        cout << "-----------------------------------------------------------------" << endl;
        return;
    }

    // Login Function makes provides the user with feature of logging in.

    // Very Important Feature
    user loginCheck(string name, string pass)
    {

        // Return object when there is an error in login
        user trash;
        trash.name = "null";

        cout << users.size() << endl;
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].name == name)
            {
                if (users[i].password == pass)
                {
                    cout << "Login Successful" << endl;
                    return users[i];
                }
                else
                {
                    cout << "Wrong Password entered" << endl;
                    return trash;
                }
            }
            else
            {
                cout << "Wrong username" << endl;
                return trash;
            }
        }
        return trash;
    }

    // Function to display all the users stored in the database;
    void dispAll()
    {
        string t;
        cout << "Displaying all the users ";
        int n = users.size();
        book obj;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            cout << "User #" << i + 1 << endl;
            cout << "The name of the user is - " << users[i].name << endl;
            cout << "The id of the user is - " << users[i].id;
            cout << "----------------------------------------------------------------------------------------------------------" << endl;
        }
        return;
    }
};

////////////////////////////////////
////      Professor class       ////
////////////////////////////////////

class professor : user
{
public:
    user u;

public:
    // Function to caculate the fine amount of a book
    user calculatFine()
    {
        system("cls");
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Enter the title of the book for which you want to calculate fine for : " << endl;
        string t;
        cin >> t;
        for (int i = 0; i < u.owned.size(); i++)
        {
            if (u.owned[i].first.title == t)
            {
                cout << "Enter the number of days you borrowed this book for : " << endl;
                int days;
                cin >> days;
                if (u.id[0] == 'p')
                {
                    if (days > 30)
                    {
                        cout << "The fine for this book is : " << (days - 30) * 5 << endl;
                    }
                    else
                    {
                        cout << "There is no fine for this book" << endl;
                    }
                }
            }
            cout << "-----------------------------------------------------------------" << endl;
            return u;
        }
        cout << "Wrong title entered" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        return u;
    }

    // Function to clear fine amount of the book and return it to the library.
    user clearFineAmount(string n)
    {
        int flag = 0;
        int indexer = 0;
        for (auto it : u.owned)
        {
            if ((it.first).title == n)
            {
                cout << "-----------------------------------------------------------------" << endl;
                cout << "When you clear the fine amount then this book will be considered as a returned one." << endl;
                it.first.available = true;
                it.first.user = "None";
                u.owned.erase(u.owned.begin() + indexer);
                cout << "This book is now available to and is removed from you account" << endl;
                flag = 1;
                break;
            }
            indexer++;
        }
        if (!flag)
        {
            cout << "-----------------------------------------------------------------" << endl;
            cout << "Wrong title entered " << endl;
            return u;
        }
        cout << "-----------------------------------------------------------------" << endl;

        return u;
    }
};

////////////////////////////////
////     Student class      ////
////////////////////////////////

class student : user
{
public:
    user u;

public:
    user calculatFine()
    {
        system("cls");
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Enter the title of the book for which you want to calculate fine for : " << endl;
        string t;
        cin >> t;
        for (int i = 0; i < u.owned.size(); i++)
        {
            if (u.owned[i].first.title == t)
            {
                cout << "Enter the number of days you borrowed this book for : " << endl;
                int days;
                cin >> days;
                if (u.id[0] == 's')
                {
                    if (days > 30)
                    {
                        cout << "The fine for this book is : " << (days - 30) * 2 << endl;
                    }
                    else
                    {
                        cout << "There is no fine for this book" << endl;
                    }
                }
            }
            cout << "-----------------------------------------------------------------" << endl;

            return u;
        }
        cout << "-----------------------------------------------------------------" << endl;

        cout << "Wrong title entered" << endl;
        return u;
    }

    user clearFineAmount(string n)
    {
        system("cls");
        int flag = 0;
        int indexer = 0;
        for (auto it : u.owned)
        {
            if ((it.first).title == n)
            {
                cout << "-----------------------------------------------------------------" << endl;

                cout << "When you clear the fine amount then this book will be considered as a returned one." << endl;
                it.first.available = true;
                it.first.user = "None";
                u.owned.erase(u.owned.begin() + indexer);
                cout << "This book is now available to and is removed from you account" << endl;

                flag = 1;
                break;
            }
            indexer++;
        }
        if (!flag)
        {
            cout << "Wrong title entered " << endl;
            cout << "-----------------------------------------------------------------" << endl;

            return u;
        }
        cout << "-----------------------------------------------------------------" << endl;

        return u;
    }
};

/////////////////////////////////////
// Main Function - User Interface  //
/////////////////////////////////////

int main()
{
    bookDatabase db;
    userdatabase ub;
    professor pt;

MainMenu:

    cout << "//////////////////////////////////////////////////////" << endl;
    cout << "Welcome to Library Management system." << endl;
    cout << "//////////////////////////////////////////////////////" << endl;

    cout << "--------- You are welcome to our library  --------------" << endl;
    cout << "           1. Student" << endl;
    cout << "           2. Professor" << endl;
    cout << "           3. Librarian" << endl;
    cout << "           4. Register for new User" << endl;
    cout << "           5. Exit" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "           Enter you choice :" ;
    int ch;
    cin >> ch;
    switch (ch)
    {

    /////////////////////////////////////
    //         Student menu            //
    /////////////////////////////////////
    case 1:
    {

        system("cls");
        cout << "------------- Login --------------" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter your Username : ";
        string userPassword;
        string userName;
        cin >> userName;
        cout << endl;
        cout << "Enter you Password : " ;
        cin >> userPassword;
        cout << endl;
        
        // Returns object user whose login if and password matches with the given.
        user User = ub.loginCheck(userName, userPassword);


        // userIndex stores the index of the user which is logged in.
        int userIndex;

        for (int i = 0; i < ub.users.size(); i++)
        {
            if (ub.users[i].id == User.id)
            {
                userIndex = i;
            }
        }


        //Here the trash object comes to user.
        if (User.name != "null")
        {
            system("cls");

        studentModule:
            cout << "/////////////////////////////////////////////////" << endl;
            cout << "***************   STUDENT MENU   ****************";
            cout << "/////////////////////////////////////////////////" << endl;
            cout << "                  1. To search any book" << endl;
            cout << "                  2. To check list of books currently taken" << endl;
            cout << "                  3. To borrow a book" << endl;
            cout << "                  4. To calculate fine for any book taken" << endl;
            cout << "                  5. To clear fine amount for any book" << endl;
            cout << "                  5. To see all the books" << endl;
            cout << "                  0. Logout" << endl;
            cout << "---------------------------------------------------------" << endl;
            int studentChoice;
            cin >> studentChoice;

            switch (studentChoice)
            {
            // Working.
            case 1:
            {
                system("cls");
                db.search();
                goto studentModule;
                break;
            }
            // Working
            case 2:
            {
                system("cls");
                User = ub.users[userIndex];
                cout << "There are currently " << (User.owned).size() << " books owned by " << User.name << endl;
                if (User.owned.size() > 0)
                {
                    cout << "The books are following:" << endl;
                    for (int i = 0; i < (User.owned).size(); i++)
                    {
                        cout << "Title : " << (User.owned[i].first).title << "---" << " Author : " << (User.owned[i].first).author << "---" << " ISBN : " << (User.owned[i].first).isbn << endl;
                    }
                }
                cout << "----------------------------------------------" << endl;
                goto studentModule;
                break;
            }

            // Working
            case 3:
            {
                system("cls");

                book Book = db.borrow();
                int bookIndex = 0;
                for (int i = 0; i < db.books.size(); i++)
                {
                    if (db.books[i].isbn == Book.isbn)
                    {
                        bookIndex = i;
                        break;
                    }
                }
                for (int i = 0; ub.users.size(); i++)
                {
                    if (ub.users[i].id == User.id)
                    {
                        userIndex = i;
                        break;
                    }
                }

                if (Book.title != "null")
                {
                    if (ub.users[userIndex].id[0] == 's')
                    {
                        if (db.books[bookIndex].available == false)
                        {
                            cout << "Book not available" << endl;
                        }
                        else
                        {
                            if (ub.users[userIndex].owned.size() < 5)
                            {
                                ub.users[userIndex].owned.push_back({db.books[bookIndex], 0});
                                db.books[bookIndex].available = false;
                                db.books[bookIndex].user = ub.users[userIndex].id;
                                cout << "Book request successful" << endl;
                            }
                            else
                            {
                                cout << "Student can only borrow at MAX 5 books." << endl;
                            }
                        }
                        goto studentModule;
                        break;
                    }
                    if (ub.users[userIndex].id[0] == 'p')
                    {
                        cout << "Wrong user" << endl;
                    }
                    cout << "ID wrong" << endl;
                    goto studentModule;
                    break;
                }
                else
                {
                    cout << "Wrong title entered" << endl;
                    goto studentModule;
                    break;
                }
                break;
            }

            // Working
            case 4:
            {
                system("cls");
                student st;
                st.u = ub.users[userIndex];
                ub.users[userIndex] = st.calculatFine();
                goto studentModule;
                break;
            }

            case 5:
            {
                system("cls");
                cout << "Enter the title of the book you want to clear fine amount - " << endl;
                string n;
                cin >> n;
                student st;
                st.u = ub.users[userIndex];
                ub.users[userIndex] = st.clearFineAmount(n);
                for (int i = 0; i < db.books.size(); i++)
                {
                    if (db.books[i].title == n)
                    {
                        db.books[i].available = true;
                    }
                }
                goto studentModule;
                break;
            }

            case 6:{
                system("cls");
                db.dispAll();
                goto studentModule;
                break;
            }

            // Working
            case 0:
            {
                cout << " -------- Hope you had a good time reading ! -----------" << endl;
                goto MainMenu;
            }
            default:
            {
                cout << "Wrong choice" << endl;
                break;
            }
            }
        }

        else
        {
            cout << "------------- Bad Login Request -------------" << endl;
            goto MainMenu;
            break;
        }

        break;
    }

    /////////////////////////////////////
    //         Professor menu          //
    /////////////////////////////////////
    case 2:
    {

        system("cls");
        cout << "----------- Login Page - Professor -----------" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter your Username : " << endl;
        cout << "Enter you Password : " << endl;

        string userPassword;
        string userName;
        cin >> userName;
        cin >> userPassword;
        user User = ub.loginCheck(userName, userPassword); // stores the user.
        int userIndex;
        for (int i = 0; i < ub.users.size(); i++)
        {
            if (ub.users[i].id == User.id)
            {
                userIndex = i;
            }
        }
        if (User.name != "null")
        {
            system("cls");

        profModule:
            cout << "Welcome user interface -- Professor" << endl;
            cout << "-------------------------------------" << endl;
            cout << "1. To search any book" << endl;
            cout << "2. To check list of books currently taken" << endl;
            cout << "3. To borrow a book" << endl;
            cout << "4. To calculate fine for a borrowed book" << endl;
            cout << "5. To clear fine amount of a particular book" << endl;
            cout << "6. To see all the books" << endl;
            cout << "7. To see all the users" << endl;
            cout << "0. Logout" << endl;
            int studentChoice;
            cin >> studentChoice;
            switch (studentChoice)
            {
            case 1:
            {
                system("cls");
                db.search();
                goto profModule;
                break;
            }
            case 2:
            {
                system("cls");
                User = ub.users[userIndex];
                cout << "There are currently " << (User.owned).size() << "books owned by the " << User.name << endl;

                if (User.owned.size() > 0)
                {
                    cout << "The books are following:" << endl;
                    for (int i = 0; i < (User.owned).size(); i++)
                    {
                        cout << "Title : " << (User.owned[i].first).title << "Author : " << (User.owned[i].first).author << "ISBN : " << (User.owned[i].first).isbn << endl;
                    }
                }

                cout << "----------------------------------------------" << endl;
                goto profModule;
                break;
            }
            case 3:
            {
                system("cls");

                book Book = db.borrow();
                int bookIndex = 0;
                for (int i = 0; i < db.books.size(); i++)
                {
                    if (db.books[i].isbn == Book.isbn)
                    {
                        bookIndex = i;
                        break;
                    }
                }
                for (int i = 0; ub.users.size(); i++)
                {
                    if (ub.users[i].id == User.id)
                    {
                        userIndex = i;
                        break;
                    }
                }

                if (Book.title != "null")
                {
                    if (ub.users[userIndex].id[0] == 's')
                    {
                        cout << "Wrong User" << endl;
                        goto MainMenu;
                    }
                    if (ub.users[userIndex].id[0] == 'p')
                    {
                        if (db.books[bookIndex].available == false)
                        {
                            cout << "Book not available" << endl;
                        }
                        else
                        {
                            ub.users[userIndex].owned.push_back({db.books[bookIndex], 0});
                            db.books[bookIndex].available = false;
                            db.books[bookIndex].user = ub.users[userIndex].id;
                            cout << "Book request successful" << endl;
                        }
                    }
                    cout << "ID wrong" << endl;
                    goto profModule;
                    break;
                }
                else
                {
                    cout << "Wrong title entered" << endl;
                    goto profModule;
                    break;
                }
                break;
            }

            // Working
            case 4:
            {
                system("cls");
                professor st;
                st.u = ub.users[userIndex];
                ub.users[userIndex] = st.calculatFine();
                goto profModule;
                break;
            }

            case 5:
            {
                system("cls");
                cout << "Enter the title of the book you want to clear fine amount - " << endl;
                string n;
                cin >> n;
                professor st;
                st.u = ub.users[userIndex];
                ub.users[userIndex] = st.clearFineAmount(n);
                for (int i = 0; i < db.books.size(); i++)
                {
                    if (db.books[i].title == n)
                    {
                        db.books[i].available = true;
                    }
                }
                goto profModule;
                break;
            }
            case 6:{
                system("cls");
                db.dispAll();
                goto profModule;
                break;
            }
            case 7:{
                system("cls");
                ub.dispAll();
                goto profModule;
                break;
            }
            // Working
            case 0:
            {
                cout << " -------- Hope you had a good time reading ! -----------" << endl;
                goto MainMenu;
            }
            default:
            {
                cout << "Wrong choice" << endl;
                break;
            }
            }
        }
        else
        {
            cout << "Login Failed" << endl;
            goto MainMenu;
            break;
        }

        break;
    }

    /////////////////////////////////////
    //         Librarian menu          //
    /////////////////////////////////////
    case 3:
    {
        system("cls");
        cout << "----------- Login Page -----------" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter the admin password : " << endl;
        string adminPassword;
        cin >> adminPassword;
        if (adminPassword == "Admin1234")
        {
            goto librarianModule;
        }
        else
        {
            cout << "You are not the admin" << endl;
            cout << "-------------------------------" << endl;
            goto MainMenu;
        }

    librarianModule:
        cout << endl;
        cout << "******************** ADMIN *********************" << endl;
        cout << "Welcome to user interface - Librarian" << endl;
        cout << "Please select your choice" << endl;
        cout << "Press 1 to add a book" << endl;
        cout << "Press 2 to update a book" << endl;
        cout << "Press 3 to delete a book" << endl;
        cout << "Press 4 to search a book" << endl;
        cout << "Press 5 to add a user" << endl;
        cout << "Press 6 to update a user" << endl;
        cout << "Press 7 to delete a user" << endl;
        cout << "Press 8 to search a user" << endl;
        cout << "Press 0 to see all books" << endl;
        cout << "Press 11 to see all users" << endl;
        cout << "Press 9 for Logging out" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter your choice:  ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            db.add();
            goto librarianModule;
            break;
        }
        case 2:
        {
            system("cls");
            db.update();
            goto librarianModule;
            break;
        }
        case 3:
        {
            system("cls");
            db.deleteBook();
            goto librarianModule;
            break;
        }
        case 4:
        {
            system("cls");
            db.search();
            goto librarianModule;
            break;
        }
        case 5:
        {
            system("cls");
            ub.add();
            goto librarianModule;
            break;
        }
        case 6:
        {
            system("cls");
            ub.update();
            goto librarianModule;
            break;
        }
        case 7:
        {
            system("cls");
            ub.deleteuser();
            goto librarianModule;
            break;
        }
        case 8:
        {
            system("cls");
            ub.search();
            goto librarianModule;
            break;
        }
        case 9:
        {
            system("cls");
            cout << "Bye Bye | Thank you for working for us" << endl;
            goto MainMenu;
        }
        case 0:
        {
            system("cls");
            db.dispAll();
            goto librarianModule;
            break;
        }
        case 11:
        {
            system("cls");
            ub.dispAll();
            goto librarianModule;
            break;
        }
        default:
        {
            cout << "Wrong choice" << endl;
            goto librarianModule;
            break;
        }
        }

        break;
    }

    /////////////////////////////////////
    //         Register menu           //
    /////////////////////////////////////
    case 4:
    {
        system("cls");
        cout << "-----------Register with us---------------" << endl;
        cout << "------------------------------------------" << endl;
        cout << "------------------------------------------" << endl;
        ub.add();
        cout << "Registration Successful" << endl;
        goto MainMenu;
        break;
    }
    case 5:
    {
        goto exit;
        break;
    }
    default:
    {
        cout << "Wrong choice" << endl;
        goto MainMenu;
        break;
    }
    }

exit:
    cout << "CREATED AND CODED BY:  Mohd Umam" << endl;
    cout << "Library Management system" << endl;
    cout << "Thanks for visiting us !!" << endl;
    return 0;
}