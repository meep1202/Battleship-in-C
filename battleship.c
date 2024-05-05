#include <stdio.h>


void printgrid1(int rows, int cols, char grid1[rows][cols], char attackgrid1[rows][cols]) {
    printf("Player 1 Attack Grid\n   0_1_2_3_4_5_6_7_8_9");
    for (int x = 0; x < rows; x++) {
        printf("\n%2d", x);
        for (int y = 0; y < cols; y++) {
            printf(" %c", attackgrid1[x][y]);
        }
        printf("%2d", x);
    }
    printf("\n   0_1_2_3_4_5_6_7_8_9\n");
   
    printf("Player 1 Home Grid\n   0_1_2_3_4_5_6_7_8_9");
    for (int x = 0; x < rows; x++) {
        printf("\n%2d", x);
        for (int y = 0; y < cols; y++) {
            printf(" %c", grid1[x][y]);
        }
        printf("%2d", x);
    }
    printf("\n   0_1_2_3_4_5_6_7_8_9\n");
}


void printgrid2(int rows, int cols, char grid2[rows][cols], char attackgrid2[rows][cols]) {
    printf("Player 2 Attack Grid\n   0_1_2_3_4_5_6_7_8_9");
    for (int x = 0; x < rows; x++) {
        printf("\n%2d", x);
        for (int y = 0; y < cols; y++) {
            printf(" %c", attackgrid2[x][y]);
        }
        printf("%2d", x);
    }
    printf("\n   0_1_2_3_4_5_6_7_8_9\n");
   
    printf("Player 2 Home Grid\n   0_1_2_3_4_5_6_7_8_9");
    for (int x = 0; x < rows; x++) {
        printf("\n%2d", x);
        for (int y = 0; y < cols; y++) {
            printf(" %c", grid2[x][y]);
        }
        printf("%2d", x);
    }
    printf("\n   0_1_2_3_4_5_6_7_8_9\n");
}


void placeship1(char grid1[10][10], int size, int charsize, char name[charsize], int t1patrol[5], int t1sub[6], int t1destroyer[6], int t1battleship[7], int t1carrier[8]) {
    int orientationbool = 0;
    int placementbool = 0;
    int ch;
    int leaveloop = 0;
    int orientation = 1;
    int x = 0;
    int y = 0;
    while (leaveloop == 0) {
        while (orientationbool == 0) {
            if (orientation == 0) {
                printf("Placing %s:\nType '0' to change orientation between vertical and horizontal\nType '1' to continue\nOrientation: Vertical\n", name);
            }
            else if (orientation == 1) {
                printf("Placing %s:\nType '0' to change orientation between vertical and horizontal\nType '1' to continue\nOrientation: Horizontal\n", name);
            }
            ch = getchar();
            ch -= 48;
            if (ch == 0) {
                orientation = !orientation;
            }
            else if (ch == 1) {
                orientationbool = 1;
            }
        }
        ch = getchar();
        placementbool = 0;
        while (placementbool == 0) {
            if (orientation == 0) {
                printf("Placing %s:\nType a number from 0-%d for the horizontal position\n", name, 10-size);
                ch = getchar();
                ch -= 48;
                if (ch < 0 || ch > 10-size) {
                    printf("\nShip leaves boundaries, place again\n");
                }
                else {
                    x = ch;
                    placementbool = 1;
                }
            }
            else {
                printf("Placing %s:\nType a number from 0-%d for the horizontal position\n", name, 9);
                ch = getchar();
                ch -= 48;
                if (ch < 0 || ch > 9) {
                    printf("\nShip leaves boundaries, place again\n");
                }
                else {
                    x = ch;
                    placementbool = 1;
                }
            }
        }
        ch = getchar();
        placementbool = 0;
        while (placementbool == 0) {
            if (orientation == 1) {
                printf("Placing %s:\nType a number from 0-%d for the horizontal position\n", name, 10-size);
                ch = getchar();
                ch -= 48;
                if (ch < 0 || ch > 10-size) {
                    printf("\nShip leaves boundaries, place again\n");
                }
                else {
                    y = ch;
                    placementbool = 1;
                }
            }
            else {
                printf("Placing %s:\nType a number from 0-%d for the horizontal position\n", name, 9);
                ch = getchar();
                ch -= 48;
                if (ch < 0 || ch > 9) {
                    printf("\nShip leaves boundaries, place again\n");
                }
                else {
                    y = ch;
                    placementbool = 1;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (orientation == 0) {
                if (grid1[x+i][y] == 'O') {
                    printf("\nShip overlaps another, place again\n");
                    leaveloop = 0;
                    i += 30;
                }
                else {
                    leaveloop = 1;
                }
            }
            else {
                if (grid1[x][y+i] == 'O') {
                    printf("\nShip overlaps another, place again\n");
                    leaveloop = 0;
                    i += 30;
                }
                else {
                    leaveloop = 1;
                }
            }
        }
    }
    for (int i = 0; i < size; i++) {
        if (orientation == 0) {
            grid1[x+i][y] = 'O';
        }
        else {
            grid1[x][y+i] = 'O';
        }
    }
    if (name[0] == 'P') {
        t1patrol[0] = x;
        t1patrol[1] = y;
        t1patrol[2] = orientation;
    }
    else if (name[0] == 'S') {
        t1sub[0] = x;
        t1sub[1] = y;
        t1sub[2] = orientation;
    }
    else if (name[0] == 'D') {
        t1destroyer[0] = x;
        t1destroyer[1] = y;
        t1destroyer[2] = orientation;
    }
    else if (name[0] == 'B') {
        t1battleship[0] = x;
        t1battleship[1] = y;
        t1battleship[2] = orientation;
    }
    else if (name[0] == 'A') {
        t1carrier[0] = x;
        t1carrier[1] = y;
        t1carrier[2] = orientation;
    }
}


void placeship2(char grid2[10][10], int size, int charsize, char name[charsize], int t2patrol[5], int t2sub[6], int t2destroyer[6], int t2battleship[7], int t2carrier[8]) {
    int orientationbool = 0;
    int placementbool = 0;
    int ch;
    int leaveloop = 0;
    int orientation = 1;
    int x = 0;
    int y = 0;
    while (leaveloop == 0) {
        while (orientationbool == 0) {
            if (orientation == 0) {
                printf("Placing %s:\nType '0' to change orientation between vertical and horizontal\nType '1' to continue\nOrientation: Vertical\n", name);
            }
            else if (orientation == 1) {
                printf("Placing %s:\nType '0' to change orientation between vertical and horizontal\nType '1' to continue\nOrientation: Horizontal\n", name);
            }
            ch = getchar();
            ch -= 48;
            if (ch == 0) {
                orientation = !orientation;
            }
            else if (ch == 1) {
                orientationbool = 1;
            }
        }
        ch = getchar();
        placementbool = 0;
        while (placementbool == 0) {
            if (orientation == 0) {
                printf("Placing %s:\nType a number from 0-%d for the horizontal position\n", name, 10-size);
                ch = getchar();
                ch -= 48;
                if (ch < 0 || ch > 10-size) {
                    printf("\nShip leaves boundaries, place again\n");
                }
                else {
                    x = ch;
                    placementbool = 1;
                }
            }
            else {
                printf("Placing %s:\nType a number from 0-%d for the horizontal position\n", name, 9);
                ch = getchar();
                ch -= 48;
                if (ch < 0 || ch > 9) {
                    printf("\nShip leaves boundaries, place again\n");
                }
                else {
                    x = ch;
                    placementbool = 1;
                }
            }
        }
        ch = getchar();
        placementbool = 0;
        while (placementbool == 0) {
            if (orientation == 1) {
                printf("Placing %s:\nType a number from 0-%d for the vertical position\n", name, 10-size);
                ch = getchar();
                ch -= 48;
                if (ch < 0 || ch > 10-size) {
                    printf("\nShip leaves boundaries, place again\n");
                }
                else {
                    y = ch;
                    placementbool = 1;
                }
            }
            else {
                printf("Placing %s:\nType a number from 0-%d for the vertical position\n", name, 9);
                ch = getchar();
                ch -= 48;
                if (ch < 0 || ch > 9) {
                    printf("\nShip leaves boundaries, place again\n");
                }
                else {
                    y = ch;
                    placementbool = 1;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (orientation == 0) {
                if (grid2[x+i][y] == 'O') {
                    printf("\nShip overlaps another, place again\n");
                    leaveloop = 0;
                    i += 30;
                }
                else {
                    leaveloop = 1;
                }
            }
            else {
                if (grid2[x][y+i] == 'O') {
                    printf("\nShip overlaps another, place again\n");
                    leaveloop = 0;
                    i += 30;
                }
                else {
                    leaveloop = 1;
                }
            }
        }
    }
    for (int i = 0; i < size; i++) {
        if (orientation == 0) {
            grid2[x+i][y] = 'O';
        }
        else {
            grid2[x][y+i] = 'O';
        }
    }
    if (name[0] == 'P') {
        t2patrol[0] = x;
        t2patrol[1] = y;
        t2patrol[2] = orientation;
    }
    else if (name[0] == 'S') {
        t2sub[0] = x;
        t2sub[1] = y;
        t2sub[2] = orientation;
    }
    else if (name[0] == 'D') {
        t2destroyer[0] = x;
        t2destroyer[1] = y;
        t2destroyer[2] = orientation;
    }
    else if (name[0] == 'B') {
        t2battleship[0] = x;
        t2battleship[1] = y;
        t2battleship[2] = orientation;
    }
    else if (name[0] == 'A') {
        t2carrier[0] = x;
        t2carrier[1] = y;
        t2carrier[2] = orientation;
    }
}


int p1attack(char attackgrid1[10][10], char grid2[10][10], int t2patrol[6], int t2sub[7], int t2destroyer[7], int t2battleship[8], int t2carrier[9], int p2shipsunk) {
    int ch;
    int x = 0;
    int y = 0;
    int positionbool = 0;
    int attackbool = 0;
    while (attackbool == 0) {
        while (positionbool == 0) {
            printf("\nSelect row from 0-9 for your attack\n");
            ch = getchar();
            getchar();
            ch -= 48;
            if (ch >= 0 && ch <= 9) {
                x = ch;
                positionbool = 1;
            }
        }
        positionbool = 0;
        while (positionbool == 0) {
            printf("\nSelect column from 0-9 for your attack\n");
            ch = getchar();
            getchar();
            ch -= 48;
            if (ch >= 0 && ch <= 9) {
                y = ch;
                positionbool = 1;
            }
        }
        if (grid2[x][y] == 'O') {
            grid2[x][y] = 'X';
            attackgrid1[x][y] = 'X';
            printf("\nHIT\n");
            attackbool = 1;
            int sunk = 1;
            for (int i = 0; i < 2; i++) {
                if (t2patrol[2] == 1) {
                    if (y == t2patrol[0]+i && x == t2patrol[1]) {
                        t2patrol[3+i] = 1;
                    }
                }
                else {
                    if (t2patrol[1]+i == x && t2patrol[0] == y) {
                        t2patrol[3+i] = 1;
                    }
                }
                if (t2patrol[3+i] != 1) {
                    sunk = 0;
                }
            }
            if (sunk == 1 && t2patrol[5] == 0) {
                printf("\nPatrol Boat Sunk!\n");
                t2patrol[5] = 1;
                p2shipsunk += 1;
                sunk = 1;
            }
           
            for (int i = 0; i < 3; i++) {
                if (t2sub[2] == 1) {
                    if (y == t2sub[0]+i && x == t2sub[1]) {
                        t2sub[3+i] = 1;
                    }
                }
                else {
                    if (t2sub[1]+i == x && t2sub[0] == y) {
                        t2sub[3+i] = 1;
                    }
                }
                if (t2sub[3+i] != 1) {
                    sunk = 0;
                }
            }
            if (sunk == 1 && t2sub[6] == 0) {
                printf("\nSubmarine Sunk!\n");
                t2sub[6] = 1;
                p2shipsunk += 1;
                sunk = 1;
            }
           
            for (int i = 0; i < 3; i++) {
                if (t2destroyer[2] == 1) {
                    if (y == t2destroyer[0]+i && x == t2destroyer[1]) {
                        t2destroyer[3+i] = 1;
                    }
                }
                else {
                    if (t2destroyer[1]+i == x && t2destroyer[0] == y) {
                        t2destroyer[3+i] = 1;
                    }
                }
                if (t2destroyer[3+i] != 1) {
                    sunk = 0;
                }
            }
            if (sunk == 1 && t2destroyer[6] == 0) {
                printf("\nDestroyer Sunk!\n");
                t2destroyer[6] = 1;
                p2shipsunk += 1;
                sunk = 1;
            }
           
            for (int i = 0; i < 4; i++) {
                if (t2battleship[2] == 1) {
                    if (y == t2battleship[0]+i && x == t2battleship[1]) {
                        t2battleship[3+i] = 1;
                    }
                }
                else {
                    if (t2battleship[1]+i == x && t2battleship[0] == y) {
                        t2battleship[3+i] = 1;
                    }
                }
                if (t2battleship[3+i] != 1) {
                    sunk = 0;
                }
            }
            if (sunk == 1 && t2battleship[7] == 0) {
                printf("\nBattleship Sunk!\n");
                t2battleship[7] = 1;
                p2shipsunk += 1;
                sunk = 1;
            }
           
            for (int i = 0; i < 5; i++) {
                if (t2carrier[2] == 1) {
                    if (y == t2carrier[0]+i && x == t2carrier[1]) {
                        t2carrier[3+i] = 1;
                    }
                }
                else {
                    if (t2carrier[1]+i == x && t2carrier[0] == y) {
                        t2carrier[3+i] = 1;
                    }
                }
                if (t2carrier[3+i] != 1) {
                    sunk = 0;
                }
            }
            if (sunk == 1 && t2carrier[8] == 0) {
                printf("\nAircraft Carrier Sunk!\n");
                t2carrier[8] = 1;
                p2shipsunk += 1;
                sunk = 1;
            }
           
        }
        else if (grid2[x][y] == 'X' || grid2[x][y] == '*') {
            printf("\nYou already attacked there, try again");
            positionbool = 0;
        }
        else if (grid2[x][y] == ' ') {
            printf("\nMiss\n");
            grid2[x][y] = '*';
            attackgrid1[x][y] = '*';
            attackbool = 1;
        }
    }
    return p2shipsunk;
}


int p2attack(char attackgrid2[10][10], char grid1[10][10], int t1patrol[6], int t1sub[7], int t1destroyer[7], int t1battleship[8], int t1carrier[9], int p1shipsunk) {
    int ch;
    int x = 0;
    int y = 0;
    int positionbool = 0;
    int attackbool = 0;
    while (attackbool == 0) {
        while (positionbool == 0) {
            printf("\nSelect row from 0-9 for your attack\n");
            ch = getchar();
            getchar();
            ch -= 48;
            if (ch >= 0 && ch <= 9) {
                x = ch;
                positionbool = 1;
            }
        }
        positionbool = 0;
        while (positionbool == 0) {
            printf("\nSelect column from 0-9 for your attack\n");
            ch = getchar();
            getchar();
            ch -= 48;
            if (ch >= 0 && ch <= 9) {
                y = ch;
                positionbool = 1;
            }
        }
        if (grid1[x][y] == 'O') {
            grid1[x][y] = 'X';
            attackgrid2[x][y] = 'X';
            printf("\nHIT\n");
            attackbool = 1;
            int sunk = 1;
            for (int i = 0; i < 2; i++) {
                if (t1patrol[2] == 1) {
                    if (y == t1patrol[0]+i && x == t1patrol[1]) {
                        t1patrol[3+i] = 1;
                    }
                }
                else {
                    if (t1patrol[1]+i == x && t1patrol[0] == y) {
                        t1patrol[3+i] = 1;
                    }
                }
                if (t1patrol[3+i] != 1) {
                    sunk = 0;
                }
            }
            if (sunk == 1 && t1patrol[5] == 0) {
                printf("\nPatrol Boat Sunk!\n");
                t1patrol[5] = 1;
                p1shipsunk += 1;
                sunk = 1;
            }
           
            for (int i = 0; i < 3; i++) {
                if (t1sub[2] == 1) {
                    if (y == t1sub[0]+i && x == t1sub[1]) {
                        t1sub[3+i] = 1;
                    }
                }
                else {
                    if (t1sub[1]+i == x && t1sub[0] == y) {
                        t1sub[3+i] = 1;
                    }
                }
                if (t1sub[3+i] != 1) {
                    sunk = 0;
                }
            }
            if (sunk == 1 && t1sub[6] == 0) {
                printf("\nSubmarine Sunk!\n");
                t1sub[6] = 1;
                p1shipsunk += 1;
                sunk = 1;
            }
           
            for (int i = 0; i < 3; i++) {
                if (t1destroyer[2] == 1) {
                    if (y == t1destroyer[0]+i && x == t1destroyer[1]) {
                        t1destroyer[3+i] = 1;
                    }
                }
                else {
                    if (t1destroyer[1]+i == x && t1destroyer[0] == y) {
                        t1destroyer[3+i] = 1;
                    }
                }
                if (t1destroyer[3+i] != 1) {
                    sunk = 0;
                }
            }
            if (sunk == 1 && t1destroyer[6] == 0) {
                printf("\nDestroyer Sunk!\n");
                t1destroyer[6] = 1;
                p1shipsunk += 1;
                sunk = 1;
            }
           
            for (int i = 0; i < 4; i++) {
                if (t1battleship[2] == 1) {
                    if (y == t1battleship[0]+i && x == t1battleship[1]) {
                        t1battleship[3+i] = 1;
                    }
                }
                else {
                    if (t1battleship[1]+i == x && t1battleship[0] == y) {
                        t1battleship[3+i] = 1;
                    }
                }
                if (t1battleship[3+i] != 1) {
                    sunk = 0;
                }
            }
            if (sunk == 1 && t1battleship[7] == 0) {
                printf("\nBattleship Sunk!\n");
                t1battleship[7] = 1;
                p1shipsunk += 1;
                sunk = 1;
            }
           
            for (int i = 0; i < 5; i++) {
                if (t1carrier[2] == 1) {
                    if (y == t1carrier[0]+i && x == t1carrier[1]) {
                        t1carrier[3+i] = 1;
                    }
                }
                else {
                    if (t1carrier[1]+i == x && t1carrier[0] == y) {
                        t1carrier[3+i] = 1;
                    }
                }
                if (t1carrier[3+i] != 1) {
                    sunk = 0;
                }
            }
            if (sunk == 1 && t1carrier[8] == 0) {
                printf("\nAircraft Carrier Sunk!\n");
                t1carrier[8] = 1;
                p1shipsunk += 1;
                sunk = 1;
            }
           
        }
        else if (grid1[x][y] == 'X' || grid1[x][y] == '*') {
            printf("\nYou already attacked there, try again");
            positionbool = 0;
        }
        else if (grid1[x][y] == ' ') {
            printf("\nMiss\n");
            grid1[x][y] = '*';
            attackgrid2[x][y] = '*';
            attackbool = 1;
        }
    }
    return p1shipsunk;
}


int main() {
    // x, y, orientation, hp
    int p1shipsunk = 0;
    int p2shipsunk = 0;
   
    int t1patrol[6] = {0,0,0,0,0,0};
    int t1sub[7] = {0,0,0,0,0,0,0};
    int t1destroyer[7] = {0,0,0,0,0,0,0};
    int t1battleship[8] = {0,0,0,0,0,0,0,0};
    int t1carrier[9] = {0,0,0,0,0,0,0,0,0};
   
    int t2patrol[6] = {0,0,0,0,0,0};
    int t2sub[7] = {0,0,0,0,0,0,0};
    int t2destroyer[7] = {0,0,0,0,0,0,0};
    int t2battleship[8] = {0,0,0,0,0,0,0,0};
    int t2carrier[9] = {0,0,0,0,0,0,0,0,0};
   
    int rows = 10;
    int cols = 10;

    char grid1[rows][cols];
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            grid1[x][y] = ' ';
        }
    }
   
    char grid2[rows][cols];
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            grid2[x][y] = ' ';
        }
    }
   
        char attackgrid1[rows][cols];
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            attackgrid1[x][y] = ' ';
        }
    }
   
    char attackgrid2[rows][cols];
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            attackgrid2[x][y] = ' ';
        }
    }
   
    char pboat[12] = {"Patrol Boat\0"};
    char sub[10] = {"Submarine\0"};
    char destroyer[10] = {"Destroyer\0"};
    char battleship[11] = {"Battleship\0"};
    char carrier[17] = {"Aircraft Carrier\0"};
    placeship1(grid1, 2, 11, pboat, t1patrol, t1sub, t1destroyer, t1battleship, t1carrier);
    int ch = getchar();
    placeship1(grid1, 3, 9, sub, t1patrol, t1sub, t1destroyer, t1battleship, t1carrier);
    ch = getchar();
    placeship1(grid1, 3, 9, destroyer, t1patrol, t1sub, t1destroyer, t1battleship, t1carrier);
    ch = getchar();
    placeship1(grid1, 4, 10, battleship, t1patrol, t1sub, t1destroyer, t1battleship, t1carrier);
    ch = getchar();
    placeship1(grid1, 5, 16, carrier, t1patrol, t1sub, t1destroyer, t1battleship, t1carrier);
    printgrid1(rows, cols, grid1, attackgrid1);
    ch = getchar();
   
    printf("\n\n\n\n\n\nPass to player 2 (Enter anything to continue)\n\n");
   
   
   
    ch = getchar();
    placeship2(grid2, 2, 11, pboat, t2patrol, t2sub, t2destroyer, t2battleship, t2carrier);
    ch = getchar();
    placeship2(grid2, 3, 9, sub, t2patrol, t2sub, t2destroyer, t2battleship, t2carrier);
    ch = getchar();
    placeship2(grid2, 3, 9, destroyer, t2patrol, t2sub, t2destroyer, t2battleship, t2carrier);
    ch = getchar();
    placeship2(grid2, 4, 10, battleship, t2patrol, t2sub, t2destroyer, t2battleship, t2carrier);
    ch = getchar();
    placeship2(grid2, 5, 16, carrier, t2patrol, t2sub, t2destroyer, t2battleship, t2carrier);
    printgrid2(rows, cols, grid2, attackgrid2);
    ch = getchar();
    printf("%c", ch);
   
    int game = 0;
   
    while (game == 0) {
        printf("Player 1 turn (Enter anything to continue)\n");
        ch = getchar();
        printgrid1(rows, cols, grid1, attackgrid1);
        p2shipsunk = p1attack(attackgrid1, grid2, t2patrol, t2sub, t2destroyer, t2battleship, t2carrier, p2shipsunk);
        if (p2shipsunk >= 5) {
            printf("\nGame Over. Player 1 Wins\n");
            game = 1;
        }
        else {
            printf("Player 2 turn (Enter anything to continue)\n");
            ch = getchar();
            printgrid2(rows, cols, grid2, attackgrid2);
            p2shipsunk = p1attack(attackgrid2, grid1, t1patrol, t1sub, t1destroyer, t1battleship, t1carrier, p1shipsunk);
        }
        if (p1shipsunk >= 5) {
            printf("\nGame Over. Player 2 Wins\n");
            game = 1;
        }
    }

    return 0;
}
