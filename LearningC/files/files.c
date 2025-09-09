#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fptr;
    char filename[256]; 
    char filecontent[1024];

    printf("Type the file name: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Error reading filename\n");
        return 1;
    }

    // strip trailing newline from filename
    filename[strcspn(filename, "\n")] = '\0';

    printf("Type the file content: ");
    if (fgets(filecontent, sizeof(filecontent), stdin) == NULL) {
        fprintf(stderr, "Error reading content\n");
        return 1;
    }

    // strip trailing newline from content
    filecontent[strcspn(filecontent, "\n")] = '\0';

    // open file in write mode
    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    fprintf(fptr, "%s", filecontent);
    fclose(fptr);

    // open file in read mode
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    char buff[256];
    while (fgets(buff, sizeof(buff), fptr)) {
        printf("%s", buff);
    }
    printf("\n");

    fclose(fptr);
    return 0;
}
