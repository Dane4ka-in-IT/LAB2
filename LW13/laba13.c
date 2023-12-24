#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define VOWELS (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))
#define VOICED_CONSONANTS (1u << ('b' - 'a') | 1u << ('d' - 'a') | 1u << ('g' - 'a') | 1u << ('j' - 'a') | 1u << ('l' - 'a') | 1u << ('m' - 'a') | 1u << ('n' - 'a') | 1u << ('r' - 'a') | 1u << ('v' - 'a') | 1u << ('w' - 'a') | 1u << ('z' - 'a'))

bool isVowel(char c) {
    c = tolower(c);
    return VOWELS & (1u << (c - 'a'));
}

bool isConsonant(char c) {
    return isalpha(c) && !(VOWELS & (1u << (tolower(c) - 'a')));
}

bool isVoiced(char c) {
    c = tolower(c);
    return VOICED_CONSONANTS & (1u << (c - 'a'));
}

void checkWord(bool word_has_voiced_consonant, bool word_has_unvoiced_consonant, bool *found) {
    if (word_has_voiced_consonant && !word_has_unvoiced_consonant) {
        *found = true;
    }
}

int main() {
    bool word_has_unvoiced_consonant = false;
    bool word_has_voiced_consonant = false;
    bool found = false;
    char c;

    printf("words:\n");

    while ((c = getchar()) != EOF) {
        if (isConsonant(c)) {
            if (isVoiced(c)) {
                word_has_voiced_consonant = true;
            } else {
                word_has_unvoiced_consonant = true;
            }
        }

        if (c == ' ' || c == '\n' || c == '\t' || c == ',') {
            checkWord(word_has_voiced_consonant, word_has_unvoiced_consonant, &found);
            word_has_unvoiced_consonant = false;
            word_has_voiced_consonant = false;
        }
    }

    checkWord(word_has_voiced_consonant, word_has_unvoiced_consonant, &found);

    if (found) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}