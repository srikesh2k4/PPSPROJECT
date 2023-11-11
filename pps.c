#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SCREENS 3
#define ROWS 5
#define COLS 10

// Function to display the seating arrangement
void displaySeats(bool seats[][COLS]) {
    printf("\n\nSeats:\n\n");

    // Display column numbers
    printf("  ");
    for (int i = 1; i <= COLS; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    // Display row numbers and seat status
    for (int i = 0; i < ROWS; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j]) {
                printf(" X "); // X for booked
            } else {
                printf(" O "); // O for available
            }
        }
        printf("\n");
    }
}

// Function to book a seat
void bookSeat(bool seats[][COLS], int row, int col) {
    if (seats[row - 1][col - 1]) {
        printf("Seat already booked. Choose another seat.\n");
    } else {
        seats[row - 1][col - 1] = true;
        printf("Seat booked successfully!\n");
    }
}

// Function to calculate ticket price based on row and column
float calculateTicketPrice(int row, int col) {
    // Basic pricing strategy (you can modify this based on your requirements)
    if (row <= 2) {
        return 10.0; // Higher price for premium rows
    } else {
        return 8.0;  // Standard price for regular rows
    }
}

int main() {
    bool seats[MAX_SCREENS][ROWS][COLS] = {false}; // Initialize all seats as available
    int choice, screen, row, col;

    do {
        printf("\n1. Display Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the screen number (1-%d): ", MAX_SCREENS);
                scanf("%d", &screen);
                if (screen >= 1 && screen <= MAX_SCREENS) {
                    displaySeats(seats[screen - 1]);
                } else {
                    printf("Invalid screen number. Please try again.\n");
                }
                break;
            case 2:
                printf("Enter the screen number (1-%d): ", MAX_SCREENS);
                scanf("%d", &screen);

                if (screen >= 1 && screen <= MAX_SCREENS) {
                    printf("Enter row and column to book a seat: ");
                    scanf("%d %d", &row, &col);

                    if (row >= 1 && row <= ROWS && col >= 1 && col <= COLS) {
                        bookSeat(seats[screen - 1], row, col);
                        float price = calculateTicketPrice(row, col);
                        printf("Ticket price: $%.2f\n", price);
                    } else {
                        printf("Invalid row or column number. Please try again.\n");
                    }
                } else {
                    printf("Invalid screen number. Please try again.\n");
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}
