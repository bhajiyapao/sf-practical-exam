#include <stdio.h>
#include <stdlib.h>

#define size 100

int cylinders[size];
int request;
int cylinder_size;
int seektime;
int totalmoment;
int total_seek_time;
int temporary[size];

void CLOOK(int cylinders[], int temporary[], int cylinder_size, int request, int seektime);

int main() {
    printf("\nEnter the size of disk:");
    scanf("%d", &cylinder_size);

    printf("\nStart entering cylinders for disk:");
    for (int i = 0; i < cylinder_size; i++) {
        scanf("%d", &cylinders[i]);
    }

    printf("\nEnter Seek time:");
    scanf("%d", &seektime);

    printf("\nEnter request disk:");
    scanf("%d", &request);

    temporary[0] = request;
    for (int i = 1; i <= cylinder_size; i++) {
        temporary[i] = cylinders[i - 1];
    }

    CLOOK(cylinders, temporary, cylinder_size, request, seektime);
    printf("\nTOTAL movement (C-LOOK): %d", totalmoment);
    printf("\nTOTAL seek time (C-LOOK): %d\n", total_seek_time);

    return 0;
}

void CLOOK(int cylinders[], int temporary[], int cylinder_size, int request, int seektime) {
    int temp1, temp2, result;
    int head_position = request;
    printf("\nThe C-LOOK iterations:");

    // Sort the temporary array
    for (int i = 0; i <= cylinder_size; i++) {
        for (int j = i + 1; j <= cylinder_size; j++) {
            if (temporary[i] > temporary[j]) {
                int temp = temporary[i];
                temporary[i] = temporary[j];
                temporary[j] = temp;
            }
        }
    }

    // Find the index of head position
    int index;
    for (index = 0; index <= cylinder_size; index++) {
        if (temporary[index] == head_position) {
            break;
        }
    }

    // Move towards the right
    for (int i = index; i < cylinder_size; i++) {
        temp1 = temporary[i];
        temp2 = temporary[i + 1];
        result = temp1 - temp2;
        totalmoment += (result < 0) ? -result : result;
        printf("\t|%d - %d|+", temp1, temp2);
    }

    // Move to the beginning (non-wrapping)
    totalmoment += temporary[cylinder_size] - temporary[index];
    printf("\t|%d - %d|+", temporary[cylinder_size], temporary[index]);

    total_seek_time = totalmoment * seektime;
}
