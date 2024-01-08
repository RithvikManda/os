#include <stdio.h>
#include <stdlib.h>

int files[50], indexBlock[50], index, n;

void prompt2() {
    int choice, ct = 0;

    for(int i = 0; i < n ; i++) {
        scanf("%d", &indexBlock[i]);

        if (files[indexBlock[i]] == 0)
            ct++;
    }

    if (ct == n) {
        for(int i = 0; i < n; i++) {
            files[indexBlock[i]] = 1;
        }

        printf("Allocated all the files into disk and indexed into index file. \n");

        for(int i = 0; i < n; i++) {
            printf("%d -----> %d : %d\n", index, indexBlock[i], files[indexBlock[i]]);
        }
    } else {
        printf("One or more files mentioned in the index are already allocated.\n");
    }

    printf("Do you want to enter more files? \n");
    printf("Enter 1 for Yes, Enter 0 for NO: ");
    scanf("%d", &choice);

    if (choice == 1)
        prompt1();
}

void prompt1() {
    printf("Enter the index block: ");
    scanf("%d", &index);

    if (files[index] != 1) {
        printf("Enter the number of blocks needed for the index %d on disk: ", index);
        scanf("%d", &n);

        printf("Enter the files to be indexed onto index %d on the disk: \n", index);
        prompt2();
    } else {
        printf("Given index %d is already allocated.\n", index);
        int fl = 0;

        printf("Do you want to enter files into disk? (1 for YES, 0 for NO) \n");
        scanf("%d", &fl);

        if (fl == 1)
            prompt1();
    }
}

int main() {
    for(int i = 0; i < 50 ; i++)
        files[i] = 0;

    prompt1();

    return 0;
}
