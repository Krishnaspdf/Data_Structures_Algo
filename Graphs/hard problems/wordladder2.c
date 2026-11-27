#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 20

char wordList[MAX][LEN];

int dist[MAX];
int parent[MAX][MAX];
int parentCount[MAX];

int visited[MAX];

int n, wordLen;

char queue[MAX][LEN];

char paths[MAX][LEN];
int pathLen;

char result[MAX][MAX][LEN];
int resultCount = 0;

int findWord(char word[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(wordList[i], word) == 0)
            return i;
    }
    return -1;
}

// Backtracking to construct paths
void dfs(int target, int start) {
    strcpy(paths[pathLen++], wordList[target]);

    if (target == start) {
        for (int i = 0; i < pathLen; i++) {
            strcpy(result[resultCount][i],
                   paths[pathLen - 1 - i]);
        }

        resultCount++;
    }
    else {
        for (int i = 0; i < parentCount[target]; i++) {
            dfs(parent[target][i], start);
        }
    }

    pathLen--;
}

void findSequences(char startWord[], char targetWord[]) {
    int start = findWord(startWord);
    int target = findWord(targetWord);

    // Add startWord if not in wordList
    if (start == -1) {
        strcpy(wordList[n], startWord);
        start = n++;
    }

    target = findWord(targetWord);

    if (target == -1) {
        printf("No transformation sequence exists.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        dist[i] = -1;
        parentCount[i] = 0;
    }

    int front = 0, rear = 0;

    strcpy(queue[rear++], startWord);
    dist[start] = 0;

    // BFS
    while (front < rear) {
        char current[LEN];
        strcpy(current, queue[front++]);

        int currentIndex = findWord(current);

        for (int i = 0; i < wordLen; i++) {
            char original = current[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == original)
                    continue;

                current[i] = ch;

                int nextIndex = findWord(current);

                if (nextIndex != -1) {

                    if (dist[nextIndex] == -1) {
                        dist[nextIndex] =
                            dist[currentIndex] + 1;

                        strcpy(queue[rear++], current);

                        parent[nextIndex][parentCount[nextIndex]++] =
                            currentIndex;
                    }

                    else if (dist[nextIndex] ==
                             dist[currentIndex] + 1) {

                        parent[nextIndex][parentCount[nextIndex]++] =
                            currentIndex;
                    }
                }
            }

            current[i] = original;
        }
    }

    if (dist[target] == -1) {
        printf("No transformation sequence exists.\n");
        return;
    }

    // Generate all shortest paths
    pathLen = 0;
    dfs(target, start);

    printf("All shortest transformation sequences:\n");

    for (int i = 0; i < resultCount; i++) {
        for (int j = 0; j < pathLen; j++) {
            printf("%s ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char startWord[LEN], targetWord[LEN];

    printf("Enter startWord and targetWord: ");
    scanf("%s %s", startWord, targetWord);

    printf("Enter number of words: ");
    scanf("%d", &n);

    printf("Enter wordList:\n");

    for (int i = 0; i < n; i++) {
        scanf("%s", wordList[i]);
    }

    wordLen = strlen(startWord);

    findSequences(startWord, targetWord);

    return 0;
}