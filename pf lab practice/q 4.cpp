#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_CITY_LEN 100
#define MAX_FLIGHT_NO_LEN 10


typedef struct {
    char flightNumber[MAX_FLIGHT_NO_LEN];
    char departureCity[MAX_CITY_LEN];
    char arrivalCity[MAX_CITY_LEN];
    char departureTime[MAX_CITY_LEN];
    char arrivalTime[MAX_CITY_LEN];
    int availableSeats;  
} Flight;

void bookSeat(Flight *flight);
void displayAvailableFlights(Flight *flights, int numFlights, const char *departureCity, const char *arrivalCity);
void updateFlightDetails(Flight *flight);

int main() {
    int numFlights = 0;
    int capacity = 2;  
    Flight *flights = (Flight *)malloc(capacity * sizeof(Flight));  

    if (!flights) {
   printf("Memory allocation failed!\n");
    return 1;
    }

    strcpy(flights[numFlights].flightNumber, "FL123");
    strcpy(flights[numFlights].departureCity, "New York");
    strcpy(flights[numFlights].arrivalCity, "Los Angeles");
    strcpy(flights[numFlights].departureTime, "10:00 AM");
    strcpy(flights[numFlights].arrivalTime, "1:00 PM");
    flights[numFlights].availableSeats = 100;
    numFlights++;

    strcpy(flights[numFlights].flightNumber, "FL124");
    strcpy(flights[numFlights].departureCity, "New York");
    strcpy(flights[numFlights].arrivalCity, "Chicago");
    strcpy(flights[numFlights].departureTime, "12:00 PM");
    strcpy(flights[numFlights].arrivalTime, "2:30 PM");
    flights[numFlights].availableSeats = 80;
    numFlights++;

    int choice;
    do {
   printf("\nFlight Booking System\n");
 printf("1. Book a seat\n");
 printf("2. Display available flights between two cities\n");
 printf("3. Update flight details\n");
  printf("4. Exit\n");
  printf("Enter your choice: ");
 scanf("%d", &choice);
   getchar();  
  switch (choice) {
  case 1: {
    char flightNumber[MAX_FLIGHT_NO_LEN];
   printf("Enter the flight number to book a seat: ");
    fgets(flightNumber, MAX_FLIGHT_NO_LEN, stdin);
   flightNumber[strcspn(flightNumber, "\n")] = '\0';
 int found = 0;
    for (int i = 0; i < numFlights; i++) {
    if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
   bookSeat(&flights[i]);
    found = 1;
    break;
    }
}
  if (!found) {
   printf("Flight not found!\n");
   }
  break;
  }
    case 2: {
  char departureCity[MAX_CITY_LEN], arrivalCity[MAX_CITY_LEN];
   printf("Enter departure city: ");
   fgets(departureCity, MAX_CITY_LEN, stdin);
  departureCity[strcspn(departureCity, "\n")] = '\0';
 printf("Enter arrival city: ");
  fgets(arrivalCity, MAX_CITY_LEN, stdin);
    arrivalCity[strcspn(arrivalCity, "\n")] = '\0'; 
displayAvailableFlights(flights, numFlights, departureCity, arrivalCity);
   break;
    }
  case 3: {
   char flightNumber[MAX_FLIGHT_NO_LEN];
    printf("Enter the flight number to update details: ");
    fgets(flightNumber, MAX_FLIGHT_NO_LEN, stdin);
flightNumber[strcspn(flightNumber, "\n")] = '\0';
int found = 0;
     for (int i = 0; i < numFlights; i++) {
                    if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
                        updateFlightDetails(&flights[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Flight not found!\n");
                }
                break;
            }
            case 4:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free(flights); 
    return 0;
}

void bookSeat(Flight *flight) {
    if (flight->availableSeats > 0) {
   flight->availableSeats--;
 printf("Seat booked successfully on flight %s!\n", flight->flightNumber);
  printf("Remaining available seats: %d\n", flight->availableSeats);
    } else {
   printf("Sorry, no available seats on flight %s!\n", flight->flightNumber);
    }
}

void displayAvailableFlights(Flight *flights, int numFlights, const char *departureCity, const char *arrivalCity) {
    int found = 0;
    printf("\nAvailable flights from %s to %s:\n", departureCity, arrivalCity);
    for (int i = 0; i < numFlights; i++) {
    if (strcmp(flights[i].departureCity, departureCity) == 0 && strcmp(flights[i].arrivalCity, arrivalCity) == 0) {
    printf("Flight %s: %s -> %s, Departure: %s, Arrival: %s, Available Seats: %d\n",
  flights[i].flightNumber, flights[i].departureCity, flights[i].arrivalCity,
   flights[i].departureTime, flights[i].arrivalTime, flights[i].availableSeats);
  found = 1;
  }
    }
    if (!found) {
  printf("No flights available between %s and %s.\n", departureCity, arrivalCity);
    }
}

void updateFlightDetails(Flight *flight) {
    int choice;
    printf("\nUpdate details for flight %s\n", flight->flightNumber);
    printf("1. Update departure time\n");
    printf("2. Update arrival time\n");
    printf("3. Update available seats\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();  

    switch (choice) {
   case 1: {
    printf("Enter new departure time: ");
    fgets(flight->departureTime, MAX_CITY_LEN, stdin);
    flight->departureTime[strcspn(flight->departureTime, "\n")] = '\0'; 
    printf("Departure time updated to %s\n", flight->departureTime);
    break;
  }
    case 2: {
  printf("Enter new arrival time: ");
    fgets(flight->arrivalTime, MAX_CITY_LEN, stdin);
    flight->arrivalTime[strcspn(flight->arrivalTime, "\n")] = '\0';  
   printf("Arrival time updated to %s\n", flight->arrivalTime);
   break;
 }
 case 3: {
  printf("Enter new available seats: ");
  scanf("%d", &flight->availableSeats);
 printf("Available seats updated to %d\n", flight->availableSeats);
    break;
    }
   default:
   printf("Invalid choice! No updates made.\n");
    }
}
