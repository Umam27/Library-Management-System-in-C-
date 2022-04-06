///////////////////////////////
////        Header         ////
///////////////////////////////

#include<bits/stdc++.h>
using namespace std;

///////////////////////////////
////     Book Class        ////
///////////////////////////////

class book
{
    public:
        string title;
        string author;
        string isbn; //isbn
        string publication;
        bool available = true; // check if the book is available or not
        string user = "None"; // store the id of the user taking this book

};

///////////////////////////////
////     User Class        ////
///////////////////////////////

class user{
    public:
        string name;
        string id;
        string password;
        vector< pair< book , int > > owned;
};



void bookRequest(book b, user u){
    system("cls");
    string n = u.id;
    if(n[0] == 's'){
        if(u.owned.size() < 5 && b.available == true){
            (u.owned).push_back({b , 0});
            b.available = false;
            b.user = u.id;
            cout << "Book request successful";
        }
        else{
            cout << "Student can only borrow at MAX 5 books." << endl;
        }
        return;
        
    }
    if(n[0] == 'p'){
        if(b.available == true){
            (u.owned).push_back({b , 0});
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
        vector<book> books;

        // This function adds a book to the database.
        void add(){
            book temp;

            string t, a, i , p;
            system("cls");
            cout << "Enter the title of the book: ";
            cin >> t ;
            cout << endl;

            cout << "Enter the author of the book: ";
            cin >> a ;
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
            temp.available = true;
            temp.user = "None";
            books.push_back(temp);
            cout << books.size() << endl;

            cout << "Book added with us! Thank you" << endl;
        }


        // This function updates a book from the database.
        void update(){
            
            string t;
            cout << "Enter the title of the book you want to update: ";
            cin >> t;
            int flag = 0;
            cout << books.size() << endl;
            for(int i = 0 ; i < books.size(); i++){
                cout << books[i].title << endl;
                if(books[i].title == t){
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
            if(!flag){
                cout << "Wrong title entered" << endl;
                return;
            }
            return;
        }

        // This function deletes a book from the database.
        void deleteBook(){
                string t;
                system("cls");
                cout << "Enter the title of the book you want to delete: ";
                cin >> t;
                int n = books.size();
                int flag = 0;
                for(int i = 0; i < n; i++){
                    if(books[i].title == t){
                        cout << "Are you sure you want to delete the book ? Press Y for yes and N for no." << endl;
                        char c;
                        cin >> c;
                        if(c == 'y' || c == 'Y'){
                            books.erase(books.begin() + i);
                            cout << "Book Deleted" << endl;
                            flag = 1;
                            break;
                        }
                        else{
                            cout<< "Book delete confirmation denied" << endl;
                            flag = 1;
                            break;
                        }
                        
                    }
                }
                if(!flag){
                    cout << "Wrong title entered" << endl;
                    return;
                }
            return;
        }

        // This function deletes the book from the database.
        void search(){
                string t;
                system("cls");
                cout << "Enter the title of the book you want to search: ";
                cin >> t;
                int n = books.size();
                book obj;
                int flag = 0;
                for(int i = 0; i < n; i++){
                    if(books[i].title == t){
                        cout << "The title of the book is - " << books[i].title << endl;
                        cout << "The author of the book is " << books[i].author << endl;
                        cout << "The isbn of the book is " << books[i].isbn << endl;
                        cout << "The publication of the book is " << books[i].publication << endl;
                        if(books[i].available){
                            cout << "The following book is available" << endl;
                        }
                        else{
                            cout << "The following book is not available" << endl;
                        }
                        flag = 1;
                        break;
                    }
                }
                if(!flag){
                    cout << "Wrong title entered" << endl;
                    return;
                }
            return;
        }


        book borrow(){
            system("cls");
            book trash;
            trash.title = "null";
            string t;
            cout << "Enter the title of the book you want to borrow : ";
            cin >> t;
            for(int i = 0; i < books.size(); i ++){
                cout << books[i].title<< " ";
                if(books[i].title == t){
                    return books[i];
                }
            } 
            return trash;
        }

        void dispAll(){
            string t;
                cout << "Displaying all the users ";
                int n = books.size();
                book obj;
                int flag = 0;
                for(int i = 0; i < n; i++){
                    cout << "Book #" << i + 1 << " : " ; 
                    cout << "The title of the book is - " << books[i].title <<" "<< "The author of the book is " << books[i].author <<" "<< "The isbn of the book is " << books[i].isbn << " " << "The publication of the book is " << books[i].publication<< " ";
                        if(books[i].available){
                            cout << "The following book is available" ;
                        }
                        else{
                            cout << "The following book is not available" ;
                        }
                    cout << "----------------------------------------------------------------------------------------------------------";
                }
            return;
        }
};




/////////////////////////////////////
//     Class for User database     //
/////////////////////////////////////

class userdatabase{
        
    public:
        vector<user>users;

        // This function adds user to the database
        void add(){
            user temp;
            string n , i, p;
            system("cls");
            cout << "Enter the name of the user: ";
            cin >> n ;
            cout << endl;

            cout << "Enter the id of the user: ";
            cin >> i ;
            cout << endl;

            cout << "Enter the password for the user: ";
            cin >> p;
            cout << endl;

            temp.name = n;
            temp.id = i;
            temp.password = p;

            users.push_back(temp);

            cout << "User added with us! Thank you" << endl;
        }

        // This function deletes the user from the database
        void deleteuser(){
                string t;
                cout << "Enter the name of the user you want to update: ";
                cin >> t;
                int n = users.size();
                user obj;
                int flag = 0;
                for(int i = 0 ; i < n ; i++){
                    if(users[i].name == t){

                        cout << "Are you sure you want to delete the user ? Press Y for yes and N for no." << endl;
                        char c;
                        cin >> c;
                        if(c == 'y' || c == 'Y'){
                            users.erase(users.begin() + i);
                            cout << "Book Deleted" << endl;
                            flag = 1;
                            break;
                        }
                        else{
                            cout<< "User delete confirmation denied" << endl;
                            flag = 1;
                            break;
                        }
                    }
                }
                if(!flag){
                    cout << "Wrong name entered" << endl;
                    return;
                }
            return;
        }

        // This function updates the user from the database
        void update(){
                string t;
                cout << "Enter the name of the user you want to update: ";
                cin >> t;
                int n = users.size();
                user obj;
                int flag = 0;
                for(int i = 0 ; i < users.size(); i++){
                    if(users[i].name == t){
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
                if(!flag){
                    cout << "Wrong title entered" << endl;
                    return;
                }
            return;
        }

        // This function searches the user from the database.
        void search(){
                string t;
                cout << "Enter the name of the user you want to search: ";
                cin >> t;
                int n = users.size();
                book obj;
                int flag = 0;
                for(int i = 0; i < n; i++){
                    if(users[i].name == t){
                        cout << "The name of the user is - " << users[i].name << endl;
                        cout << "The id of the user is - " << users[i].id << endl;
                        flag = 1;
                        break;
                    }
                }
                if(!flag){
                    cout << "Wrong name entered" << endl;
                   return;
                }
            return;
        }

        // Login Function makes provides the user with feature of logging in.
        user loginCheck(string name, string pass){
            user trash;
            trash.name = "null";
            cout << users.size() << endl;
            for(int i = 0 ; i < users.size(); i++){
                if(users[i].name == name){
                    if(users[i].password == pass){
                        cout << "Login Successful" << endl;
                        return users[i];
                    }
                    else{
                        cout << "Wrong Password entered" << endl;
                        return trash;
                    }
                }
                else{
                    cout << "Wrong username" << endl;
                    return trash;
                }
            }
            return trash;
        }

        void dispAll(){
            string t;
                cout << "Displaying all the users ";
                int n = users.size();
                book obj;
                int flag = 0;
                for(int i = 0; i < n; i++){
                    cout << "User #" << i + 1 << " : " ; 
                    cout << "The name of the user is - " << users[i].name << " " << "The id of the user is - " << users[i].id ;
                    cout << "----------------------------------------------------------------------------------------------------------";
                }
            return;
        }
};

//////////////////////////////////////////////////////////////////
////      Professor class being the child class of user       ////
//////////////////////////////////////////////////////////////////

class professor:user{
    public:
        int fineAmount = 0;
    public:
        void calculateFine(){
                system("cls");
                cout << "Enter the title of the book you want to check fine for - " << endl;
                string n ;
                cin >> n;
                int flag = 0;
                for(auto it: owned){
                    if((it.first).title == n){
                        if(it.second > 60){
                            cout << "The fine for this book for you is - " << (it.second - 60) * 5 << endl;
                        }
                        else{
                            cout << "The fine for this book for you is - " << 0 << endl;
                        }
                        flag = 1;
                        break;
                    }

                }
                if(!flag) {
                    cout << "Wrong title entered "<< endl;
                    return;
                }
            return;
        }
        void clearFineAmount(){
                system("cls");
                cout << "Enter the title of the book you want to clear fine amount - " << endl;
                string n ;
                cin >> n;
                int flag = 0;
                int indexer = 0;
                for(auto it: owned){
                    if((it.first).title == n){
                        
                        cout << "When you clear the fine amount then this book will be considered as a returned one." << endl;
                        it.first.available = true;
                        it.first.user = "None";
                        owned.erase(owned.begin() + indexer);
                        cout << "This book is now globally available and is removed from you account" << endl;

                        flag = 1;
                        break;
                    }
                    indexer ++ ;

                }
                if(!flag) {
                    cout << "Wrong title entered "<< endl;
                    return;
                }
            return;
        }


        void RequestBook(){

            string tit;
            cout << "Enter the title of the book you want to borrow : " << endl;
            cin >> tit; 
            if(owned.size() >=5 ) {
                cout << "cannot borrow more than 5"<< endl;
            }
            // else{
            //     bool respon = book_request(tit);
            // }
        }

        void selfDisp(){
            system("cls");
            int n = owned.size();
            for(int i = 0; i < n; i++){
                cout << "Book Number " << i + 1 << " : " << owned[i].first.title << " " << owned[i].first.publication ;
            }
            cout << "That is it" << endl;
            system("cls");
        }

};


//////////////////////////////////////////////////////////////////
////       Student class being the child class of user        ////
//////////////////////////////////////////////////////////////////


class student:user{
    public:
        int fineAmount = 0;
    public:
        void calculateFine(){
                    system("cls");
                    cout << "Enter the title of the book you want to check fine for - " << endl;
                    string n ;
                    cin >> n;
                    int flag = 0;
                    for(auto it: owned){
                        if((it.first).title == n){
                            if(it.second > 60){
                                cout << "The fine for this book for you is - " << (it.second - 30) * 2 << endl;
                            }
                            else{
                                cout << "The fine for this book for you is - " << 0 << endl;
                            }
                            flag = 1;
                            break;
                        }

                    }
                    if(!flag) {
                        cout << "Wrong title entered "<< endl;
                        return;
                    }
                return;
            }

            void clearFineAmount(){
                    system("cls");
                    cout << "Enter the title of the book you want to clear fine amount - " << endl;
                    string n ;
                    cin >> n;
                    int flag = 0;
                    int indexer = 0;
                    for(auto it: owned){
                        if((it.first).title == n){
                            
                            cout << "When you clear the fine amount then this book will be considered as a returned one." << endl;
                            it.first.available = true;
                            it.first.user = "None";
                            owned.erase(owned.begin() + indexer);
                            cout << "This book is now globally available and is removed from you account" << endl;

                            flag = 1;
                            break;
                        }
                        indexer ++ ;

                    }
                    if(!flag) {
                        cout << "Wrong title entered "<< endl;
                        return;
                    }
                return;
            }
            void selfDisp(){
                system("cls");
                int n = owned.size();
                for(int i = 0; i < n; i++){
                    cout << "Book Number " << i + 1 << " : " << owned[i].first.title << " " << owned[i].first.publication ;
                }
                cout << "That is it" << endl;
                system("cls");
                return;
            }
};


/////////////////////////////////////
// Main Function - User Interface  //
/////////////////////////////////////

int main(){
    bookDatabase db;
    userdatabase ub;
    student st;
    professor pt;

    MainMenu:
    cout << "Welcome to Library Management system." << endl;
    cout << "1. Student" << endl;
    cout << "2. Professor" << endl;
    cout << "3. Librarian" << endl;
    cout << "Enter your role ---- " << endl;
    int ch;
    cin >> ch;
    switch(ch){

        /////////////////////////////////////
        //         Student menu            //
        /////////////////////////////////////
        case 1:{

            system("cls");
            cout << "----------- Login Page - User -----------" << endl;
            cout << "----------------------------------" << endl;
            cout << "Enter your Username : " << endl;
            cout << "Enter you Password : " << endl;

            string userPassword ;
            string userName;
            cin >> userName;
            cin >> userPassword;
            user User = ub.loginCheck(userName, userPassword);
            int userIndex;
            for(int i = 0 ; i < ub.users.size() ; i++){
                if(ub.users[i].id == User.id){
                    userIndex = i;
                }
            }
            if( User.name != "null"){
                system("cls");

                studentModule:
                cout << "Welcome user interface -- Student" << endl;
                cout << "-------------------------------------" << endl;
                cout << "1. To search any book" << endl;
                cout << "2. To check list of books currently taken" << endl;
                cout << "3. To borrow a book" << endl;
                cout << "0. Logout"<< endl;
                int studentChoice;
                cin >> studentChoice;
                switch( studentChoice){
                    case 1:{
                        system("cls");
                        db.search();
                        goto studentModule;
                        break;
                    }
                    case 2:{
                        system("cls");
                        User = ub.users[userIndex];
                        cout << "There are currently " << (User.owned).size() << " books owned by the " << User.name << endl;
                        if(User.owned.size() > 0){
                            cout << "The books are following:" << endl;
                            for(int i = 0; i < (User.owned).size(); i ++){
                                cout << "Title : " << (User.owned[i].first).title << "Author : " << (User.owned[i].first).author << "ISBN : " << (User.owned[i].first).isbn << endl;  
                            }
                        }

                        cout << "----------------------------------------------" << endl;
                        goto studentModule;
                        break;

                    }
                    case 3:{
                        system("cls");
                        book Book = db.borrow(); 
                        int bookIndex = 0;
                        for(int i = 0 ; i < db.books.size() ; i++){
                            if(db.books[i].isbn == Book.isbn){
                                bookIndex = i;
                                break ;
                            }
                        }
                        for(int i = 0 ; ub.users.size() ; i ++){
                            if(ub.users[i].id == User.id){
                                userIndex = i;
                                break ;
                            }
                        }
                        if(Book.title != "null"){
                            bookRequest(Book, User);
                            db.books[bookIndex] = Book;
                            ub.users[userIndex] = User;
                        }
                        cout << "Wrong title entered" << endl;
                        goto studentModule;
                        break; 
                    }
                    case 0:{
                        system("cls");
                        cout << "Bye Bye | Thank you for working for us" << endl;
                        goto MainMenu;
                    }
                    default:{
                        cout << "Wrong choice" << endl;
                        break;
                    }
                }
            }
            else{
                cout << "Login Failed"<< endl;
                goto MainMenu;
                break;
            }

            break;
        }


        /////////////////////////////////////
        //         Professor menu          //
        /////////////////////////////////////
        case 2:{


            system("cls");
            cout << "----------- Login Page - Professor -----------" << endl;
            cout << "----------------------------------" << endl;
            cout << "Enter your Username : " << endl;
            cout << "Enter you Password : " << endl;

            string userPassword ;
            string userName;
            cin >> userName;
            cin >> userPassword;
            user User = ub.loginCheck(userName, userPassword); // stores the user.
            int userIndex;
            for(int i = 0 ; i < ub.users.size() ; i++){
                if(ub.users[i].id == User.id){
                    userIndex = i;
                }
            }
            if( User.name != "null"){
                system("cls");
                
                profModule:
                cout << "Welcome user interface -- Professor" << endl;
                cout << "-------------------------------------" << endl;
                cout << "1. To search any book" << endl;
                cout << "2. To check list of books currently taken" << endl;
                cout << "3. To borrow a book" << endl;
                cout << "4. To calculate fine for a borrowed book" << endl;
                cout << "5. To clear fine amount of a particular book" << endl;
                cout << "4. To see all the books" << endl; 
                cout << "0. Logout"<< endl;
                int studentChoice;
                cin >> studentChoice;
                switch( studentChoice){
                    case 1:{
                        system("cls");
                        db.search();
                        goto profModule;
                        break;
                    }
                    case 2:{
                        system("cls");
                        User = ub.users[userIndex];
                        cout << "There are currently " << (User.owned).size() << "books owned by the " << User.name << endl;

                        if(User.owned.size() > 0){
                            cout << "The books are following:" << endl;
                            for(int i = 0; i < (User.owned).size(); i ++){
                                cout << "Title : " << (User.owned[i].first).title << "Author : " << (User.owned[i].first).author << "ISBN : " << (User.owned[i].first).isbn << endl;  
                            }
                        }

                        cout << "----------------------------------------------" << endl;
                        goto profModule;
                        break;

                    }
                    case 3:{
                        system("cls");
                        book Book = db.borrow(); 
                        int bookIndex = 0;
                        for(int i = 0 ; i < db.books.size() ; i++){
                            if(db.books[i].isbn == Book.isbn){
                                bookIndex = i;
                                break ;
                            }
                        }
                        for(int i = 0 ; ub.users.size() ; i ++){
                            if(ub.users[i].id == User.id){
                                userIndex = i;
                                break ;
                            }
                        }
                        if(Book.title != "null"){
                            bookRequest(Book, User);
                            db.books[bookIndex] = Book;
                            ub.users[userIndex] = User;
                        }
                        cout << "Wrong title entered" << endl;
                        goto profModule;
                        break; 
                    }

                    case 4:{
                        system("cls");
                        db.dispAll();
                        goto profModule;
                        break;
                    }
                    case 0:{
                        system("cls");
                        cout << "Bye Bye | Thank you for working for us" << endl;
                        goto MainMenu;
                        break;
                    }
                    default:{
                        cout << "Wrong choice" << endl;
                        goto profModule;
                        break;
                    }
                }
            }
            else{
                cout << "Login Failed"<< endl;
                goto MainMenu;
                break;
            }

            break;
        }


        /////////////////////////////////////
        //         Librarian menu          //
        /////////////////////////////////////
        case 3:{
            system("cls");
            cout << "----------- Login Page -----------" << endl;
            cout << "----------------------------------" << endl;
            cout << "Enter the admin password : " << endl;
            string adminPassword ;
            cin >> adminPassword;
            if(adminPassword == "Admin1234"){
                goto librarianModule;
            } 
            else{
                cout << "You are not the admin" << endl;
                cout << "-------------------------------" << endl;
                goto MainMenu;
            }

            librarianModule:
            cout << endl;
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
            cout << "Enter your choice" << endl;

            int choice;
            cin >> choice;

            switch (choice){
                case 1:{
                    system("cls");
                    db.add();
                    goto librarianModule;
                    break;
                }
                case 2:{
                    system("cls");
                    db.update();
                    goto librarianModule;
                    break;
                }
                case 3:{
                    system("cls");
                    db.deleteBook();
                    goto librarianModule;
                    break;
                }
                case 4:{
                    system("cls");
                    db.search();
                    goto librarianModule;
                    break;
                }
                case 5:{
                    system("cls");
                    ub.add();
                    goto librarianModule;
                    break;
                }
                case 6:{
                    system("cls");
                    ub.update();
                    goto librarianModule;
                    break;
                }
                case 7:{
                    system("cls");
                    ub.deleteuser();
                    goto librarianModule;
                    break;
                }
                case 8:{
                    system("cls");
                    ub.search();
                    goto librarianModule;
                    break;
                }
                case 9:{
                    system("cls");
                    cout << "Bye Bye | Thank you for working for us" << endl;
                    goto MainMenu;
                }
                case 0:{
                    system("cls");
                    db.dispAll();
                    goto librarianModule;
                    break;
                }
                case 11:{
                    system("cls");
                    ub.dispAll();
                    goto librarianModule;
                    break;
                }
                default:{
                    cout << "Wrong choice" << endl;
                    goto librarianModule;
                    break;
                }
            }
            
            break;
        }
        default:{
            cout << "Wrong choice" << endl;
            goto MainMenu;
            break;
        }
    }
}