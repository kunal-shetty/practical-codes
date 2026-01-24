#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char letters[] = "abcdefghijklmnopqrstuvwxyz ,.ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char target[] = "KUNAL SHETTY";
    char result[100] = "";  
    int j,target_length = strlen(target);
    
    srand(time(NULL));  

    for (j = 0; j < target_length; j++) {
        while (1) {

            char l = letters[rand() % strlen(letters)];

            printf("\r%s%c", result, l);
            fflush(stdout); 

            if (l == target[j]) {
                result[j] = l;  
                break;
            }

            usleep(10000); 
        }
    }

    result[target_length] = '\0';

    return 0;
}

