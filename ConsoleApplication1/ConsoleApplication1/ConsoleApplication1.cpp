#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main() {
    int meteoriteY = 0;
    int meteoriteX = rand() % 20;
    int numberOfmeteorite = rand() % 7;
    int meteoriteDirection = rand() % 2;

    int numberOfStar = rand() % 10 + 10;

    int moonPhases = 0;
    int moonX = 22;
    int moonY = 5;
    int frameCounterMoon = 0;

    int sunX = 22;
    int sunY = 5;
    int frameCounterSun = 0;

    int timeChange = rand() % 2;

    while (true) {
        string a[20][20];
        system("clr");

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if ((i > 14 && j == 18) || (i > 14 && j == 14) || (i + 5 == j && j > 15) ||
                    (i + j == 27 && j > 12 && j < 16) || (i == 15 && j > 13 && j < 19) ||
                    (i == 19 && j > 13 && j < 19)) {
                    a[i][j] = "\033[31m*\033[0m";
                }
                else if (i == 19) {
                    a[i][j] = "\033[32m*\033[0m";
                }
                else if (timeChange == 0) {
                    int dx = j - moonX;
                    int dy = i - moonY;
                    int radius = 3;

                    if (moonPhases == 0 && ((dx == 3 && (dy == -1 || dy == 0 || dy == 1)) ||
                        (dx == 4 && (dy == -2 || dy == -1 || dy == 0 || dy == 1 || dy == 2)))) {
                        a[i][j] = "\033[37m*\033[0m";
                    }
                    else if (moonPhases == 1 && ((dx == 3 && (dy == -2 || dy == -1 || dy == 0 || dy == 1 || dy == 2)) ||
                        (dx == 4 && (dy == -3 || dy == -2 || dy == -1 || dy == 0 || dy == 1 || dy == 2 || dy == 3)))) {
                        a[i][j] = "\033[37m*\033[0m";
                    }
                    else if (moonPhases == 2 && ((dx == 2 && (dy == -2 || dy == -1 || dy == 0 || dy == 1 || dy == 2)) ||
                        (dx == 3 && (dy == -3 || dy == -2 || dy == -1 || dy == 0 || dy == 1 || dy == 2 || dy == 3)))) {
                        a[i][j] = "\033[37m*\033[0m";
                    }
                    else if (moonPhases == 3 && dx * dx + dy * dy <= radius * radius) {
                        a[i][j] = "\033[37m*\033[0m";
                    }
                    else if (moonPhases == 4 && dx * dx + dy * dy <= radius * radius) {
                        a[i][j] = "\033[37m*\033[0m";
                    }
                    else if (moonPhases == 5 && ((dx == -2 && (dy == -2 || dy == -1 || dy == 0 || dy == 1 || dy == 2)) ||
                        (dx == -3 && (dy == -3 || dy == -2 || dy == -1 || dy == 0 || dy == 1 || dy == 2 || dy == 3)))) {
                        a[i][j] = "\033[37m*\033[0m";
                    }
                    else if (moonPhases == 6 && ((dx == -3 && (dy == -2 || dy == -1 || dy == 0 || dy == 1 || dy == 2)) ||
                        (dx == -2 && (dy == -3 || dy == -2 || dy == -1 || dy == 0 || dy == 1 || dy == 2 || dy == 3)))) {
                        a[i][j] = "\033[37m*\033[0m";
                    }
                    else if (moonPhases == 7 && ((dx == -3 && (dy == -1 || dy == 0 || dy == 1)) ||
                        (dx == -4 && (dy == -2 || dy == -1 || dy == 0 || dy == 1 || dy == 2)))) {
                        a[i][j] = "\033[37m*\033[0m";
                    }
                    else {
                        a[i][j] = " ";
                    }
                }
                else if (timeChange == 1) {
                    int dx = j - sunX;
                    int dy = i - sunY;
                    int radius = 3;
                    if (dx * dx + dy * dy <= radius * radius) {
                        a[i][j] = "\033[33m*\033[0m";
                    }
                    else {
                        a[i][j] = "\033[36m*\033[0m";
                    }
                }
            }
        }

        if (timeChange == 0) {
            for (int i = 0; i <= numberOfmeteorite; i++) {
                int meteoriteX_local = rand() % 20;
                for (int k = 1; k <= 20; k++) {
                    int my, mx;
                    if (meteoriteDirection == 0) {
                        my = meteoriteY - k;
                        mx = meteoriteX_local - k;
                    }
                    else {
                        my = meteoriteY - k;
                        mx = meteoriteX_local + k;
                    }
                    if (my >= 0 && my < 20 && mx >= 0 && mx < 20)
                        a[my][mx] = "\033[30m*\033[0m";
                }
                if (meteoriteY >= 0 && meteoriteY < 20 && meteoriteX_local >= 0 && meteoriteX_local < 20) {
                    a[meteoriteY][meteoriteX_local] = "\033[33m*\033[0m";
                }
            }
            for (int i = 0; i <= numberOfStar; i++) {
                int starX = rand() % 20;
                int starY = rand() % 8;
                if (starY >= 0 && starY < 20 && starX >= 0 && starX < 20)
                    a[starY][starX] = "\033[37m*\033[0m";
            }
        }

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) cout << a[i][j] << " ";
            cout << endl;
        }
        for (int delay = 0; delay < 50000000; delay++);

        if (timeChange == 0) {
            meteoriteY++;
            if (meteoriteDirection == 0) meteoriteX++; else meteoriteX--;
            if (meteoriteY >= 20 || meteoriteX < 0 || meteoriteX >= 20 ||
                ((meteoriteY > 14 && (meteoriteX == 18 || meteoriteX == 14)) ||
                    (meteoriteY + meteoriteX == 27 && meteoriteX > 12 && meteoriteX < 16) ||
                    (meteoriteY == 15 && meteoriteX > 13 && meteoriteX < 19))) {
                meteoriteY = 0;
                meteoriteX = rand() % 20;
                meteoriteDirection = rand() % 2;
            }
            frameCounterMoon += 2;
            if (frameCounterMoon % 20 == 0) {
                moonX--;
                if (moonX <= -5) {
                    moonPhases++;
                    timeChange = 1;
                    sunX = 23;
                }
            }
        }
        if (timeChange == 1) {
            frameCounterSun += 2;
            if (frameCounterSun % 20 == 0) {
                sunX--;
                if (sunX <= -5) {
                    timeChange = 0;
                    moonX = 23;
                }
            }
        }
    }
    return 0;
}
