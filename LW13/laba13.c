#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isVowel(char c){
    char lower_c = tolower(c);
    return lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u';
}

bool isConsonant(char c){
    return isalpha(c) && !isVowel(c);
}

bool isVoiced(char c){
    char lower_c = tolower(c);
    return lower_c == 'b' || lower_c == 'd' || lower_c == 'g' || lower_c == 'j' || lower_c == 'l' || lower_c == 'm' || lower_c == 'n' || lower_c == 'r' || lower_c == 'v' || lower_c == 'w' || lower_c == 'z';
}

void checkWord(bool word_has_voiced_consonant, bool word_has_unvoiced_consonant, bool *found){
    if(word_has_voiced_consonant && !word_has_unvoiced_consonant){
        *found = true;
    }
}

int main(){
    bool word_has_unvoiced_consonant = false;
    bool word_has_voiced_consonant = false;
    bool found = false;
    char c;

    printf("words:\n");

    while ((c = getchar()) != EOF){
        if(isConsonant(c)){
            if(isVoiced(c)){
                word_has_voiced_consonant = true;
            } else {
                word_has_unvoiced_consonant = true;
            }
        }

        if(c == ' ' || c == '\n' || c == '\t' || c == ','){
            checkWord(word_has_voiced_consonant, word_has_unvoiced_consonant, &found);
            word_has_unvoiced_consonant = false;
            word_has_voiced_consonant = false;
        }
    }

    checkWord(word_has_voiced_consonant, word_has_unvoiced_consonant, &found);

    if(found) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}