#include <stdio.h>
#include <string.h>

struct Book {
    char title[50];
    int isbn;
};

int binarySearch(struct Book books[], int l, int r, int isbn) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (books[mid].isbn == isbn) return mid;
        if (books[mid].isbn > isbn) return binarySearch(books, l, mid - 1, isbn);
        return binarySearch(books, mid + 1, r, isbn);
    }
    return -1;
}

int main() {
    struct Book books[] = {
        {"The C Programming Language", 9780131103627},
        {"Clean Code", 9780132350884},
        {"Design Patterns", 9780201633610},
        {"Introduction to Algorithms", 9780262033848},
        {"The Pragmatic Programmer", 9780201616224}
    };

    int n = sizeof(books) / sizeof(books[0]);
    int isbnToSearch = 9780132350884;
    int result = binarySearch(books, 0, n - 1, isbnToSearch);

    if (result == -1) printf("Book with ISBN %d not found\n", isbnToSearch);
    else printf("Book found: %s (ISBN: %d)\n", books[result].title, books[result].isbn);

    return 0;
}
