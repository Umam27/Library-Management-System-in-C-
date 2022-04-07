1. About the code

    A) The code is written in c++ 14 using the concepts of OOPS. The code uses iostream, vector and algorithm header files. 

    B) To execute the code we need to follow the steps given: 
        a) g++ -o main main.cpp 
        b) ./main.exe
    
    C) The code has been implemented with several classes with member variables and functions

        Classes 

            a) class book
                member variables : title , author, isbn, publication, available and user.
                member functions : has no member functions.
            
            b) class user
                member variables : name, id, password and owned.
                member functions : has no member functions.
            
            c) class bookdatabase
                member variables : books.
                member functions : add, update, deleteBook, search, borrow and dispAll.

            d) class userdatabase
                member variables : users.
                member functions : add, update, deleteUser, search, loginCheck and dispAll.
            
            e) class professor
                member variables : u (object of class user).
                member functions : calculateFine, clearFineAmount.
            
            f) class student
                member variables : u (object of class).
                member functions : calculateFine, clearFineAmount.

        Functions

            a) requestBook : this function takes input - a user and a book and make changes in their variables as needed.



2. Interfaces of the code

    A) The code has a MainMenu which comes up at the start of the code or can be navigated by other interfaces. The user can select the type of login he/she has to perform. By default the code provides student, professor and librarian access to the code. There is also an option to register as new user.

    B) Choosing any of the type lands us to a login page where we need to enter our credentials.

    C) Then there are three interfaces, student, professor and librarian. The functionalities of there interfaces is given further.

    D) The exit message contains the credits.


3. Functionalities provided by the programmer

    A) To Student 

        a) Can search any book 
        b) Can check the list of books owned currently
        c) Can borrow a book 
        d) Can calculate fine for any book currently owned
        e) Clear fine and return the book 
        f) Can see all the books that
    
    B) To professor

        a) Can search any book 
        b) Can check the list of books owned currently
        c) Can borrow a book 
        d) Can calculate fine for any book currently owned
        e) Clear fine and return the book 
        f) Can see all the books 
        g) Can see all the users

    C) To librarian

        a) Can add a book
        b) Can update a book
        c) Can delete a book
        d) Can search a book
        e) Can add a user
        f) Can update a user
        g) Can delete a users
        h) Can search a users
        i) Can see all books
        j) Can see all userPassword

4. Instructions for Proper Functioning of the Code

    a) The librarian can login using password admin password -- Admin1234
    b) The id of the users must contain s at the start of the id number for students. for eg. id = s1234
    c) The id of the users must contain s at the start of the id number for professor. for eg. id = p1234

    d) I have used dynamic database i.e. We need to login as Librarian and insert two three books to see the features because iniitially the vector is empty.

    
