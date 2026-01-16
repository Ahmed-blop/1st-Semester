#include <iostream>
#include <fstream>
#include <limits>
#include <termios.h>
#include <unistd.h>

using namespace std;

struct Date {
    int day, month, year;
};

struct Book {
    int id;
    char title[50];
    char author[50];
    char genre[30];
    bool isIssued;
    Date issueDate;
};

int inputMode = 1; // 1 = normal, 2 = keyboard

void setColor(int color) {
    cout << "\033[" << color << "m";
}

char getchLinux() {
    char ch;
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

void showTitle() {
    setColor(36);
    cout << endl << "=====================================" << endl;
    cout << "   LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "=====================================" << endl;
    setColor(0);
}

void displayMenu(int selected = -1) {
    // selected: -1 means no highlight, otherwise 1..5
    // Clear screen (ANSI)
    cout << "\033[2J\033[H";
    showTitle();
    for (int i = 1; i <= 5; ++i) {
        if (selected == i) {
            setColor(32); // highlight color
            cout << "> ";
        } else {
            cout << "  ";
        }
        switch (i) {
            case 1: cout << "1. Add Book"; break;
            case 2: cout << "2. Display Books"; break;
            case 3: cout << "3. Search Book"; break;
            case 4: cout << "4. Issue Book"; break;
            case 5: cout << "5. Exit"; break;
        }
        setColor(0);
        cout << endl;
    }
    if (inputMode == 1) {
        cout << "Choice: ";
    } else {
        cout << "Use Up/Down arrows and Enter, or press 1-5: ";
    }
    cout.flush();
}

int getMenuChoice() {
    if (inputMode == 1) {
        int ch;
        cin >> ch;
        return ch;
    } else {
        int current = 1;
        displayMenu(current);
        while (true) {
            char ch = getchLinux();

            // Handle Enter (LF or CR)
            if (ch == '\n' || ch == '\r') {
                return current;
            }

            // Handle escape sequences (arrow keys)
            if (ch == 27) { // ESC
                char c1 = getchLinux();
                if (c1 == '[') {
                    char c2 = getchLinux();
                    if (c2 == 'A') { // Up
                        current = (current == 1) ? 5 : current - 1;
                        displayMenu(current);
                    } else if (c2 == 'B') { // Down
                        current = (current == 5) ? 1 : current + 1;
                        displayMenu(current);
                    }
                }
                continue;
            }

            // Handle number keys
            if (ch >= '1' && ch <= '5') {
                return ch - '0';
            }

            // ignore other keys
        }
    }
}

void addBook() {
    Book b;
    ofstream file("library.dat", ios::binary | ios::app);

    setColor(32);
    cout << endl << "Enter Book ID: ";
    cin >> b.id;
    cin.ignore();

    cout << "Enter Title: ";
    cin.getline(b.title, 50);

    cout << "Enter Author: ";
    cin.getline(b.author, 50);

    cout << "Enter Genre: ";
    cin.getline(b.genre, 30);

    b.isIssued = false;
    file.write((char*)&b, sizeof(b));
    file.close();

    setColor(32);
    cout << endl << "Book added successfully!" << endl;
    setColor(0);

    cout << "Press Enter to continue...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

void displayBooks() {
    Book b;
    ifstream file("library.dat", ios::binary);

    setColor(33);
    cout << endl << "--- BOOK LIST ---" << endl;

    while (file.read((char*)&b, sizeof(b))) {
        cout << endl << "ID: " << b.id;
        cout << endl << "Title: " << b.title;
        cout << endl << "Author: " << b.author;
        cout << endl << "Genre: " << b.genre;
        cout << endl << "Status: " << (b.isIssued ? "Issued" : "Available") << endl;
    }

    file.close();
    setColor(0);

    cout << "Press Enter to continue...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

void searchBook() {
    int sid;
    Book b;
    bool found = false;

    cout << endl << "Enter Book ID: ";
    cin >> sid;

    ifstream file("library.dat", ios::binary);

    while (file.read((char*)&b, sizeof(b))) {
        if (b.id == sid) {
            setColor(32);
            cout << endl << "Book Found!" << endl;
            cout << "Title: " << b.title << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        setColor(31);
        cout << endl << "Book not found!" << endl;
    }

    file.close();
    setColor(0);

    cout << "Press Enter to continue...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

void issueBook() {
    int sid;
    Book b;

    cout << endl << "Enter Book ID to issue: ";
    cin >> sid;

    fstream file("library.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&b, sizeof(b))) {
        if (b.id == sid && !b.isIssued) {
            b.isIssued = true;
            cout << "Enter Issue Date (DD MM YYYY): ";
            cin >> b.issueDate.day >> b.issueDate.month >> b.issueDate.year;

            file.seekp(-sizeof(b), ios::cur);
            file.write((char*)&b, sizeof(b));

            setColor(32);
            cout << endl << "Book issued successfully!" << endl;
            break;
        }
    }

    file.close();
    setColor(0);

    cout << "Press Enter to continue...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

int main() {
    int choice;

    showTitle();
    cout << "Select Input Mode:" << endl << "1. Normal Input" << endl << "2. Keyboard Backup" << endl << "Choice: ";
    cin >> inputMode;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear rest of line

    do {
        if (inputMode == 1) {
            displayMenu(-1);
        } else {
            displayMenu(1); // initial draw before interactive navigation
        }

        choice = getMenuChoice();

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: cout << endl << "Exiting..." << endl; break;
            default: cout << endl << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
