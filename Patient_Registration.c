#include <stdio.h>
#include <string.h>

// 1. CREATING A DATA TYPE TO STORE PATIENT INFORMATION
typedef struct {
    int id;
    char name[50];
    int room;
} Patient;

// PROTOTYPES OF FUNCTIONS TO BE USED
void sort_patients(Patient list[], int count);
int search_patient(Patient list[], int count, int target_id);
void list_all(Patient list[], int count);

int main(void) {
    int total_patients;

    printf("=== PATIENT REGISTRATION ===\n");
    printf("How many patients do you want to register? ");
    scanf("%d", &total_patients);

    // Variable Length Array (VLA) declaration
    Patient list[total_patients];

    // --- PHASE 1: REGISTRATION ---
    for (int i = 0; i < total_patients; i++) {
        printf("\nPatient #%d:\n", i + 1);
        printf("Chart Number (ID): ");
        scanf("%d", &list[i].id);
        printf("Name (First name): ");
        scanf("%s", list[i].name);
        printf("Room Number: ");
        scanf("%d", &list[i].room);
    }

    // --- PHASE 2: ORGANIZE ACQUIRED INFORMATION ---
    sort_patients(list, total_patients);
    printf("\nDATA SAVED SUCCESSFULLY!\n");

    // --- PHASE 3: USER OPTION MENU ---
    int option;
    int search_id;

    do {
        printf("\n=== MAIN MENU ===\n");
        printf("1. Search Patient by ID\n");
        printf("2. View Full Patient List\n");
        printf("0. Exit System\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: // SEARCH
                printf("\nEnter patient ID: ");
                scanf("%d", &search_id);

                int result = search_patient(list, total_patients, search_id);

                if (result != -1) {
                    printf("\n>> PATIENT FOUND:\n");
                    printf("   Name: %s | ID: %d | Room: %d\n",
                           list[result].name, list[result].id, list[result].room);
                } else {
                    printf("\n[!] Patient not found.\n");
                }
                break;

            case 2: // LIST ALL
                list_all(list, total_patients);
                break;

            case 0: // EXIT
                printf("System terminated!\n");
                break;

            default:
                printf("Invalid option! Try again.\n");
        }

    } while (option != 0); // Repeats until user types 0

    return 0;
}

// --- FUNCTIONS ---

// NEW FUNCTION: Prints the entire list on the screen
void list_all(Patient list[], int count) {
    printf("\n--- GENERAL PATIENT REPORT ---\n");
    printf("ID\t| ROOM\t| NAME\n"); // Simple header
    printf("------------------------------\n");

    for (int i = 0; i < count; i++) {
        // \t adds a "Tab" to align columns
        printf("%d\t| %d\t| %s\n", list[i].id, list[i].room, list[i].name);
    }
    printf("------------------------------\n");
}

// Bubble Sort algorithm
void sort_patients(Patient list[], int count) {
    Patient temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (list[j].id > list[j + 1].id) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

// Binary Search algorithm
int search_patient(Patient list[], int count, int target_id) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (list[middle].id == target_id) return middle;

        if (list[middle].id < target_id)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}
