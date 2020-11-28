/* prgm1 - aloha - takes in hawaiian words and converts them to english pronunciation
 *  Cameron Dennis
 *  09/23/19
 *
 */

#include <stdio.h>


//checks for the presence of char let in array of char letterList
int isLet(char let, const char letterList[]) {
    int countLet = 0;
    int isLet = 0;
    for (countLet = 0; letterList[countLet] != '\0'; ++countLet) {
        if (let == letterList[countLet]) {
            isLet = 1;
            break;
        }
    }
    return isLet;
}


int main() {
    char word[50];   // input from user

    printf("Enter a Hawaiian word:\n");     //requests input from user
    fflush(stdout);
    scanf("%s", word);

    int charCheck = 0;
    int countVow = 0;
    int countCon = 0;
    int charBreak = 0;
    int prevType = 2; // 0 = vowel, 1 = consonant
    int doubleCon = 0;
    int error = 0;
    char letVow[11] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}; //Arrays containing values for checks
    char letCon[16] = {'p', 'k', 'h', 'l', 'm', 'n', 'w', 'P', 'K', 'H', 'L', 'M', 'N', 'W', 39};
    //checks for valid input begins here
    for (charCheck = 0; word[charCheck] != '\0'; ++charCheck) { //for loop to check for valid chars
        charBreak = 0;
        for (countVow = 0; letVow[countVow] != '\0'; ++countVow) { //for loop to check for vowels
            if (isLet(word[charCheck], letVow)) {  //if character is a vowel
                charBreak = 1;
                prevType = 0;
                //printf("%c\n", word[charCheck]);
            }
            if (charBreak) {    //then break back to 1st for
                break;
            }
        }
        if (charBreak) {    //then continue with 1st for
            continue;
        }
        for (countCon = 0; letCon[countCon] != '\0'; ++countCon) {  //checks if letter in word is a consonant
            if (isLet(word[charCheck], letCon)) {
                if (charCheck == 0) { //skips check for double consonant for first operation
                    charBreak = 1;
                    prevType = 1;
                }
                else if (prevType == 1) { //checks for double consonant
                    printf("Double consonants: %c%c.\n", word[charCheck-1], word[charCheck]);
                    return 0;
                    doubleCon = 1;
                    error = 1;
                    break;
                }
                else {  //tells for to break and sets previous type to con
                    charBreak = 1;
                    prevType = 1;
                    if (word[charCheck + 1] == '\0') { //checks for consonant at end of word
                        printf("Consonant %c at the end of the word.\n", word[charCheck]);
                        return 0;
                    }
                }
                if (charBreak) {
                    break;
                }
            }
        }
        if (charBreak) {    //then continue with 1st for
            continue;
        }
        else if (error) {    //breaks out of 1st for
            return 0;
        }
        else {  //prints if invalid char
            printf("Character %c is not allowed.\n", word[charCheck]);
            return 0;
        }
        }
    if (doubleCon) {    //prints if double consonant
        printf("Double consonants: %c%c.", word[charCheck-1], word[charCheck]);
        return 0;
    }
    //starts return of translated words once string is validated

    for (charCheck = 0; word[charCheck] != '\0'; ++charCheck) {
        if (isLet(word[charCheck], letVow)) {   //if letter at charCheck is a vowel
            if ((isLet(word[charCheck+1], letCon))||(word[charCheck]==word[charCheck+1])||(word[charCheck+1])=='\0') { //if letter after charCheck is either a consonant, ending \0, or the same vowel
                if ((word[charCheck]=='a')||(word[charCheck]=='A')) {       //if A
                    printf("ah");
                }
                else if ((word[charCheck]=='e')||(word[charCheck]=='E')) {  //if E
                    printf("eh");
                }
                else if ((word[charCheck]=='i')||(word[charCheck]=='I')) {  //if I
                    printf("ee");
                }
                else if ((word[charCheck]=='o')||(word[charCheck]=='O')) {  //if O
                    printf("oh");
                }
                else if ((word[charCheck]=='u')||(word[charCheck]=='U')) {  //if U
                    printf("oo");
                }
                if (word[charCheck+1] == '\'') {    //if trailing consonant is a 'okina
                    printf("\'");
                    charCheck += 1;
                }
                else if (word[charCheck+1]=='\0') { //if followed by end of array
                    printf("\n");
                }
                else {  //otherwise, add dash
                    printf("-");
                }
                continue;
            }
            if ((word[charCheck]=='a')||(word[charCheck]=='A')) {   //vowel A
                if ((word[charCheck+1]=='i')||(word[charCheck+1]=='I')||(word[charCheck+1]=='e')||(word[charCheck+1]=='E')) { //vowel pair AI && AE
                    printf("eye");
                    if (word[charCheck+2]=='\'') {
                        printf("\'");
                        charCheck += 2;
                    }
                    else if (word[charCheck+2]=='\0') { //if followed by end of array
                        printf("\n");
                        return 0;
                    }
                    else {
                        printf("-");
                        charCheck += 1;
                    }
                    continue;
                }
                if ((word[charCheck+1]=='o')||(word[charCheck+1]=='O')||(word[charCheck+1]=='u')||(word[charCheck+1]=='U')) { //vowel pair AO && AU
                    printf("ow");
                    if (word[charCheck+2]=='\'') {
                        printf("\'");
                        charCheck += 2;
                    }
                    else if (word[charCheck+2]=='\0') { //if followed by end of array
                        printf("\n");
                        return 0;
                    }
                    else {
                        printf("-");
                        charCheck += 1;
                    }
                    continue;
                }
                else {      //no vowel pair
                    printf("ah");
                    if (word[charCheck+1] =='\'') {
                        printf("\'");
                        charCheck += 1;
                    }
                    else if (word[charCheck+1]=='\0') { //if followed by end of array
                        printf("\n");
                        return 0;
                    }
                    else {
                        printf("-");
                    }
                }
            }
            if ((word[charCheck]=='e')||(word[charCheck]=='E')) {   //vowel E
                if ((word[charCheck+1]=='i')||(word[charCheck+1]=='I')) {   //vowel pair EI
                    printf("ay");
                    if (word[charCheck+2]=='\'') {
                        printf("\'");
                        charCheck += 2;
                    }
                    else if (word[charCheck+2]=='\0') { //if followed by end of array
                        printf("\n");
                        return 0;
                    }
                    else {
                        printf("-");
                        charCheck += 1;
                    }
                    continue;
                }
                else {  //no vowel pair
                    printf("eh");
                    if (word[charCheck+1] =='\'') {
                        printf("\'");
                        charCheck += 1;
                    }
                    else if (word[charCheck+1]=='\0') { //if followed by end of array
                        printf("\n");
                        return 0;
                    }
                    else {
                        printf("-");
                    }
                }
            }
            if ((word[charCheck]=='i')||(word[charCheck]=='I')) {   //vowel I
                if ((word[charCheck+1]=='u')||(word[charCheck+1]=='U')) {   //vowel pair UI
                    printf("ew");
                    if (word[charCheck+2]=='\'') {
                        printf("\'");
                        charCheck += 2;
                    }
                    else if (word[charCheck+2]=='\0') { //if followed by end of array
                        printf("\n");
                        return 0;
                    }
                    else {
                        printf("-");
                        charCheck += 1;
                    }
                    continue;
                }
                else {  //no vowel pair
                    printf("ee");
                    if (word[charCheck+1] =='\'') {
                        printf("\'");
                        charCheck += 1;
                    }
                    else if (word[charCheck+1]=='\0') { //if followed by end of array
                        printf("\n");
                        return 0;
                    }
                    else {
                        printf("-");
                    }
                }
            }
            if ((word[charCheck]=='o')||(word[charCheck]=='O')) {   //vowel O
                if ((word[charCheck+1]=='i')||(word[charCheck+1]=='I')) {   //vowel pair OI
                    printf("oy");
                    if (word[charCheck+2]=='\'') {
                        printf("\'");
                        charCheck += 2;
                    }
                    else if (word[charCheck+2]=='\0') { //if followed by end of array
                        printf("\n");
                        return 0;
                    }
                    else {
                        printf("-");
                        charCheck += 1;
                    }
                    continue;
                }
                if ((word[charCheck+1]=='u')||(word[charCheck+1]=='U')) {   //vowel pair OU
                    printf("ow");
                    if (word[charCheck + 2] == '\'') {
                        printf("\'");
                        charCheck += 2;
                    }
                    else if (word[charCheck+2]=='\0') { //if followed by end of array
                        printf("\n");
                        return 0;
                    }
                    else {
                        printf("-");
                        charCheck += 1;
                    }
                    continue;
                }
                else {  //no vowel pair
                    printf("oh");
                    if (word[charCheck+1] =='\'') {
                        printf("\'");
                        charCheck += 1;
                    }
                    else if (word[charCheck+1]=='\0') { //if followed by end of array
                        printf("\n");
                        return 0;
                    }
                    else {
                        printf("-");
                    }
                }
            }
            if ((word[charCheck]=='u')||(word[charCheck]=='U')) {   //vowel U
                if ((word[charCheck+1]=='i')||(word[charCheck+1]=='I')) {   //vowel pair UI
                    printf("ooey");
                    if (word[charCheck+2]=='\'') {
                        printf("\'");
                        charCheck += 2;
                    }
                    else if (word[charCheck+2]=='\0') { //if followed by end of array
                        printf("\n");
                        return 0;
                    }
                    else {
                        printf("-");
                        charCheck += 1;
                    }
                    continue;
                }
                else {  //no vowel pair
                    printf("oo");
                    if (word[charCheck+1] =='\'') {
                        printf("\'");
                        charCheck += 1;
                    }
                    else if (word[charCheck+1]=='\0') { //if followed by end of array
                        printf("\n");
                        return 0;
                    }
                    else {
                        printf("-");
                    }
                }
            }
        }
        if (isLet(word[charCheck], letCon)) {   //char at charCheck is consonant
            if ((word[charCheck]=='w')||(word[charCheck]=='W')) {   //char is W
                if (charCheck == 0) {   //char is first W
                    printf("w");
                }
                else if (((word[charCheck-1] == 'a')||(word[charCheck-1] == 'A'))) {    //char is W following A
                    printf("w");
                }
                else if ((word[charCheck-1] == 'e')||(word[charCheck-1] == 'E')||((word[charCheck-1] == 'i')||(word[charCheck-1] == 'I'))) {    //char is W following E || I
                    printf("v");
                }
                else {  //char is W
                    printf("w");
                }
            }
            else {
                printf("%c", (word[charCheck])|32);
            }
        }
    }
    return 0;
}