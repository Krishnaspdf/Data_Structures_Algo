#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 20

struct Node {
    char word[LEN];
    int steps;
};

int wordExists(char wordList[][LEN], int n, char word[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(wordList[i], word) == 0)
            return 1;
    }
    return 0;
}

int shortestTransformation(char startWord[], char targetWord[],
                           char wordList[][LEN], int n) {
    struct Node queue[MAX];
    int front = 0, rear = 0;

    int visited[MAX] = {0};

    // Start BFS
    strcpy(queue[rear].word, startWord);
    queue[rear].steps = 1;
    rear++;

    while (front < rear) {
        struct Node current = queue[front++];
        char word[LEN];

        strcpy(word, current.word);

        for (int i = 0; word[i] != '\0'; i++) {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == original)
                    continue;

                word[i] = ch;

                if (wordExists(wordList, n, word)) {

                    // Target reached
                    if (strcmp(word, targetWord) == 0)
                        return current.steps + 1;

                    // Find index of generated word
                    for (int j = 0; j < n; j++) {
                        if (strcmp(wordList[j], word) == 0 &&
                            !visited[j]) {

                            visited[j] = 1;

                            strcpy(queue[rear].word, word);
                            queue[rear].steps = current.steps + 1;
                            rear++;
                        }
                    }
                }
            }

            word[i] = original;
        }
    }

    return 0;
}

int main() {
    int n;
    char startWord[LEN], targetWord[LEN];
    char wordList[MAX][LEN];

    printf("Enter startWord and targetWord: ");
    scanf("%s %s", startWord, targetWord);

    printf("Enter number of words: ");
    scanf("%d", &n);

    printf("Enter wordList:\n");

    for (int i = 0; i < n; i++) {
        scanf("%s", wordList[i]);
    }

    int result = shortestTransformation(
        startWord, targetWord, wordList, n
    );

    printf("Shortest transformation length: %d\n", result);

    return 0;
}