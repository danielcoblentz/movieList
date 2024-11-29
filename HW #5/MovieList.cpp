//
// Created by Dan Coblentz on 11/27/24.
//

#include <iostream>
#include <string>
using namespace std;

// Node structure for a movie
struct Movie {
    string title;
    Movie* prev;
    Movie* next;

    Movie(string t) : title(t), prev(nullptr), next(nullptr) {}
};

// MovieList class
class MovieList {
private:
    Movie* head;
    Movie* tail;
    int count;

public:
    MovieList() : head(nullptr), tail(nullptr), count(0) {}

    // Retrieve the first movie
    string front() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return "";
        }
        return head->title;
    }

    // Retrieve the last movie
    string back() {
        if (tail == nullptr) {
            cout << "List is empty!" << endl;
            return "";
        }
        return tail->title;
    }

    // Insert a movie into an empty list (Case 1)
    void insertEmpty(string title) {
        Movie* newMovie = new Movie(title);
        head = tail = newMovie;
        count++;
        cout << "Inserted \"" << title << "\" into empty list." << endl;
    }


    // Insert a movie at the beginning (Case 2)
    void insertBeginning(string title) {
        if (head == nullptr) {
            insertEmpty(title);
            return;
        }
        Movie* newMovie = new Movie(title);
        newMovie->next = head;
        head->prev = newMovie;
        head = newMovie;
        count++;
        cout << "Inserted \"" << title << "\" at the beginning" << endl;
    }

    // Insert a movie at the end (Case 3)
    void insertEnd(string title) {
        if (tail == nullptr) {
            insertEmpty(title);
            return;
        }
        Movie* newMovie = new Movie(title);
        tail->next = newMovie;
        newMovie->prev = tail;
        tail = newMovie;
        count++;
        cout << "Inserted \"" << title << "\" at the end" << endl;
    }


    // Insert a movie after a specific movie (Case 4)
    void insertAfter(string afterTitle, string title) {
        Movie* temp = head;
        while (temp != nullptr && temp->title != afterTitle) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Movie \"" << afterTitle << "\" not found!" << endl;
            return;
        }



        Movie* newMovie = new Movie(title);
        newMovie->next = temp->next;
        newMovie->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newMovie;
        } else {
            tail = newMovie;
        }

        temp->next = newMovie;
        count++;
        cout << "Inserted \"" << title << "\" after \"" << afterTitle << "\"." << endl;
    }



    // Insert a movie before a specific movie (additional feature 2)
    void insertBefore(string beforeTitle, string title) {
        Movie* temp = head;

        while (temp != nullptr && temp->title != beforeTitle) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Movie \"" << beforeTitle << "\" not found!" << endl;
            return;
        }

        Movie* newMovie = new Movie(title);
        newMovie->next = temp;
        newMovie->prev = temp->prev;

        if (temp->prev != nullptr) {
            temp->prev->next = newMovie;
        } else {
            head = newMovie;
        }

        temp->prev = newMovie;
        count++;
        cout << "inserted \"" << title << "\" before \"" << beforeTitle << endl;
    }


    //delete a movie by title (additional feature 1)
    void deleteMovie(string title) {
        Movie* temp = head;

        while (temp != nullptr && temp->title != title) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Movie \"" << title << "\" not found!" << endl;
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }
        delete temp;
        count--;
        cout << "deleted movie: \"" << title << "\"." << endl;
    }


    //Display the movie list
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Movie* temp = head;
        cout << "Movie List: ";
        while (temp != nullptr) {
            cout << temp->title << " -> ";
            temp = temp->next;
        }
        cout << "END" << endl;
    }
};


////////////////////////////////////
//main function test methods above
int main() {
    MovieList movieList;

    // insert movies then call display after to see if it works
    movieList.insertEmpty("Inception");
    movieList.displayList();
    movieList.insertBeginning("The Dark Knight");
    movieList.displayList();
    movieList.insertEnd("Interstellar");
    movieList.displayList();
    movieList.insertAfter("Inception", "Dunkirk");
    movieList.displayList();
    movieList.insertBefore("Inception", "Memento");

    // display the list
    movieList.displayList();

    //test deletion
    movieList.deleteMovie("Dunkirk");
    movieList.displayList();
    movieList.deleteMovie("Avatar"); // nonexistent movie (testing if it can handle this case)



    //display the list after deletions
    movieList.displayList();

    return 0;
}
