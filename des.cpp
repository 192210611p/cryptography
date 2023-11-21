#include <stdio.h>
#include <string.h>


void encryptRailFence(char *message, int rails) {
    int len = strlen(message);
    
    char railFence[rails][len];

   
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            railFence[i][j] = ' ';
        }
    }

  
    int row = 0, col = 0;
    int direction = 0; // 0 for down, 1 for up

    for (int i = 0; i < len; i++) {
        if (row == 0 || row == rails - 1) {
            direction = !direction; // Change direction when reaching the top or bottom rail
        }

        railFence[row][col++] = message[i];

        direction ? row-- : row++;
    }
    printf("Encrypted Message: ");
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (railFence[i][j] != ' ') {
                printf("%c", railFence[i][j]);
 }
        }
    }
    printf("\n");
}

void decryptRailFence(char *message, int rails) {
    int len = strlen(message);

   
    char railFence[rails][len];

  
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            railFence[i][j] = ' ';
        }
    }

    
    int row = 0, col = 0;
    int direction = 0; // 0 for down, 1 for up

    for (int i = 0; i < len; i++) {
        if (row == 0 || row == rails - 1) {
            direction = !direction; // Change direction when reaching the top or bottom rail
        }

        railFence[row][col++] = '*';

        direction ? row-- : row++;
    }
  int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (railFence[i][j] == '*' && index < len) {
                railFence[i][j] = message[index++];
            }
        }
    }

   
    printf("Decrypted Message: ");
    row = 0, col = 0;
    direction = 0;

    for (int i = 0; i < len; i++) {
        if (row == 0 || row == rails - 1) {
            direction = !direction;
        }

        printf("%c", railFence[row][col++]);

        direction ? row-- : row++;
    }
    printf("\n");
}

int main() {
    char message[100];
    int rails;

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    encryptRailFence(message, rails);
    decryptRailFence(message, rails);

    return 0;
}
