#include <stdio.h>
void footballScorePossibilites(int score) {
    for(int twoPoint = 0; twoPoint * 8 <= score; twoPoint++) {
        for(int onePoint = 0; onePoint * 7 + twoPoint * 8 <= score; onePoint++) {
            for(int TD = 0; TD * 6 + onePoint * 7 + twoPoint * 8 <= score; TD++) {
                for(int FG = 0; FG * 3 + TD * 6 + onePoint * 7 + twoPoint * 8 <= score; FG++) {
                    if((score - (FG * 3 + TD * 6 + onePoint * 7 + twoPoint * 8)) % 2 == 0) {
                        int safeties = (score - (FG * 3 + TD * 6 + onePoint * 7 + twoPoint * 8))/2;
                        char result[100];
                        sprintf(result,"%i TD + 2pt, %i TD + FG, %i TD, %i 3pt FG, %i Safety\n", twoPoint, onePoint, TD, FG, safeties);
                        printf(result);
                    }
                }
            }
        }
    }
}

int main(void) {
    printf("Enter a football score, or enter 0/1 to exit: \n");
    int score;
    scanf("%i", &score);
    while(score > 1) {
        footballScorePossibilites(score);
        printf("Enter a football score, or enter 0/1 to exit: \n");
        scanf("%i", &score);
    }

    return 0;
}


