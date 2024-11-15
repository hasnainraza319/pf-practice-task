#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define MAX_ISBN_LEN 20

// Book structure
typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char isbn[MAX_ISBN_LEN];
    int publication_year;
    int is_available;  
} Book;


void addBook(Book **library, int *num_books, int *capacity);
void viewBooks(Book *library, int num_books);
Book* searchBookByTitle(Book *library, int num_books, const char *title);
Book* searchBookByISBN(Book *library, int num_books, const char *isbn);
void checkOutBook(Book *book);
void checkInBook(Book *book);
void resizeLibrary(Book **library, int *capacity);

int main() {
    int capacity = 2;  
    int num_books = 0;
    Book *library = (Book *)malloc(capacity * sizeof(Book)); 

    if (!library) {
    printf("Memory allocation failed!\n");
    return 1;
    }

    int choice;
    do {
   printf("\nLibrary Management System\n");
   printf("1. Add a new book\n");
   printf("2. View all books\n");
   printf("3. Search book by title\n");
   printf("4. Search book by ISBN\n");
   printf("5. Check out a book\n");
   printf("6. Check in a book\n");
   printf("7. Exit\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);
   getchar();  

switch (choice) {
   case 1:
   addBook(&library, &num_books, &capacity);
   break;
case 2:
     viewBooks(library, num_books);
 break;
 case 3: {
  char title[MAX_TITLE_LEN];
  printf("Enter the book title to search: ");
 fgets(title, MAX_TITLE_LEN, stdin);
 title[strcspn(title, "\n")] = '\0';
                Book *book = searchBookByTitle(library, num_books, title);
                if (book) {
                    printf("Book found: %s by %s\n", book->title, book->author);
                } else {
                    printf("Book not found!\n");
                }
                break;
            }
            case 4: {
                char isbn[MAX_ISBN_LEN];
                printf("Enter the book ISBN to search: ");
                fgets(isbn, MAX_ISBN_LEN, stdin);
                isbn[strcspn(isbn, "\n")] = '\0';
                Book *book = searchBookByISBN(library, num_books, isbn);
                if (book) {
                    printf("Book found: %s by %s\n", book->title, book->author);
                } else {
                    printf("Book not found!\n");
                }
                break;
            }
            case 5: {
                char isbn[MAX_ISBN_LEN];
                printf("Enter the ISBN of the book to check out: ");
                fgets(isbn, MAX_ISBN_LEN, stdin);
                isbn[strcspn(isbn, "\n")] = '\0'; 
                Book *book = searchBookByISBN(library, num_books, isbn);
                if (book) {
                    checkOutBook(book);
                } else {
                    printf("Book not found!\n");
                }
                break;
            }
            case 6: {
     char isbn[MAX_ISBN_LEN];
  printf("Enter the ISBN of the book to check in: ");
    fgets(isbn, MAX_ISBN_LEN, stdin);
   isbn[strcspn(isbn, "\n")] = '\0';
   Book *book = searchBookByISBN(library, num_books, isbn);
   if (book) {
   checkInBook(book);
   } else {
   printf("Book not found!\n");
     }
    break;
  }
   case 7:
     printf("Exiting the system...\n");
  break;
  default:
   printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    free(library);
    return 0;
}

void addBook(Book **library, int *num_books, int *capacity) {
    if (*num_books >= *capacity) {
   resizeLibrary(library, capacity);
    }

    Book *new_book = &(*library)[*num_books];
    printf("Enter book title: ");
    fgets(new_book->title, MAX_TITLE_LEN, stdin);
    new_book->title[strcspn(new_book->title, "\n")] = '\0';

    printf("Enter author name: ");
    fgets(new_book->author, MAX_AUTHOR_LEN, stdin);
    new_book->author[strcspn(new_book->author, "\n")] = '\0';

    printf("Enter ISBN: ");
    fgets(new_book->isbn, MAX_ISBN_LEN, stdin);
    new_book->isbn[strcspn(new_book->isbn, "\n")] = '\0';

    printf("Enter publication year: ");
    scanf("%d", &new_book->publication_year);

    new_book->is_available = 1; 

    (*num_books)++;
    printf("Book added successfully!\n");
}


void viewBooks(Book *library, int num_books) {
    if (num_books == 0) {
 printf("No books available.\n");
    return;
    }

    printf("\nList of books:\n");
    for (int i = 0; i < num_books; i++) {
   printf("Title: %s, Author: %s, ISBN: %s, Year: %d, Availability: %s\n",
  library[i].title, library[i].author, library[i].isbn, 
 library[i].publication_year, library[i].is_available ? "Available" : "Checked Out");
    }
}

Book* searchBookByTitle(Book *library, int num_books, const char *title) {
    for (int i = 0; i < num_books; i++) {
    if (strcmp(library[i].title, title) == 0) {
    return &library[i];
  }
    }
    return NULL;
}

Book* searchBookByISBN(Book *library, int num_books, const char *isbn) {
    for (int i = 0; i < num_books; i++) {
  if (strcmp(library[i].isbn, isbn) == 0) {
    return &library[i];
  }
    }
    return NULL; 
}


void checkOutBook(Book *book) {
    if (book->is_available) {
   book->is_available = 0;
   printf("Book '%s' has been checked out.\n", book->title);
    } else {
    printf("Book '%s' is already checked out.\n", book->title);
    }
}


void checkInBook(Book *book) {
    if (!book->is_available) {
  book->is_available = 1;
  printf("Book '%s' has been checked in.\n", book->title);
    } else {
   printf("Book '%s' is already available.\n", book->title);
    }
}

void resizeLibrary(Book **library, int *capacity) {
    *capacity *= 2;
    *library = (Book *)realloc(*library, *capacity * sizeof(Book));
    if (*library == NULL) {
   printf("Memory allocation failed!\n");
   exit(1);
    }
    printf("Library capacity increased to %d books.\n", *capacity);
}
