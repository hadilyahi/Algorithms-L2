#include <stdio.h>

int main() {
    FILE *file = fopen("file.txt", "a"); 

   
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

 
    fprintf(file, "Hello\n");

  
    fclose(file);

    printf("done\n");
    return 0;
}
