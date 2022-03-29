#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<book> books;
vector<user> users;

class book
{
    public:
        string title;
        string author;
        string isbn;
        string publication;
        bool available = true; // check if the book is available or not
        string user = "None"; // store the id of the user taking this book

    public:
        bool Book_Request(string t){
            system("cls");
            cout << "This is the window for request a book"<<endl;
            // cout << "Enter the title of the book you want to request:"<<endl;
            // string t;
            // cin >> t;

            for(auto it: books){
                if(it.title == t){
                    if(it.available){
                        cout << "The book is available " << endl;
                        cout << "Do you want to confirm the borrow of this book? Press Y for yes and N for no."<<endl;
                        char res;
                        cin >> res;
                        if(res == 'y' || res == 'Y'){
                            it.available = false;
                            return true;
                        }
                        else{
                            cout << "Borrow Denied" << endl;
                            return false;
                        }
                    }
                }
                cout << "Wrong title entered" << endl;
                return false;
            }
            return false;
            
        }



};   

class bookDatabase
{        
    public:

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

            cout << "Book added with us! Thank you" << endl;
        }

        void update(){
            
            here:
                string t;
                system("cls");
                cout << "Enter the title of the book you want to update: ";
                cin >> t;
                int n = books.size();
                book obj;
                int flag = 0;
                for(auto it : books){
                    if(it.title == t){
                        cout << "Enter the new title: ";
                        cin >> it.title;
                        cout << endl;

                        cout << "Enter the new author: ";
                        cin >> it.author;
                        cout << endl;

                        cout << "Enter the new isbn: ";
                        cin >> it.isbn;
                        cout << endl;

                        cout << "Enter the new publication: ";
                        cin >> it.publication;
                        cout << endl;

                        cout << "Book update successful" << endl;
                        system("cls");
                        flag = 1;
                        break;
                    }
                }
                if(!flag){
                    cout << "Wrong title entered" << endl;
                    goto here;
                }
        }

        void deleteBook(){
            here:
                string t;
                system("cls");
                cout << "Enter the title of the book you want to delete: ";
                cin >> t;
                int n = books.size();
                book obj;
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
                    goto here;
                }
        }

        void search(){
            here:
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
                        cout << "The publication of the book is" << books[i].publication << endl;
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
                    goto here;
                }
        }
};

class user{
    public:
        string name;
        string id;
        string password = "123456";
};

class professor:user{
    public:
        vector<pair<book,int> > owned;
        int fineAmount=0;
    public:

        void calculateFine(){
            here:
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
                    goto here;
                }
        }

        void clearFineAmount(){
            here:
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
                    goto here;
                }
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

class student:user{
    public:
        vector<pair<book, int>> owned;
        int fineAmount=0;
    public:
        void calculateFine(){
                here:
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
                        goto here;
                    }
            }

            void clearFineAmount(){
                here:
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
                        goto here;
                    }
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

class userdatabase{
        
    public:

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

        void update(){
            
            here:
                string t;
                system("cls");
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
                    goto here;
                }
        }

        void deleteuser(){
            here:
                string t;
                system("cls");
                cout << "Enter the name of the user you want to delete: ";
                cin >> t;
                int n = users.size();
                user obj;
                int flag = 0;
                for(auto it : users){
                    if(it.name == t){
                        cout << "Enter the new name: ";
                        cin >> it.name;
                        cout << endl;

                        cout << "Enter the new id: ";
                        cin >> it.id;
                        cout << endl;

                        cout << "Enter the new password: ";
                        cin >> it.password;
                        cout << endl;

                        cout << "User update successful" << endl;
                        system("cls");
                        flag = 1;
                        break;
                    }
                }
                if(!flag){
                    cout << "Wrong name entered" << endl;
                    goto here;
                }
        }
        
        void search(){
            here:
                string t;
                system("cls");
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
                    goto here;
                }
        }
};

