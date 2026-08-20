#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize/2 + 1];
    int index = 0;
    for (int i = 0; i < tokensSize; i ++) {
        if (strcmp(tokens[i], "+") == 0) {
            stack[index-2] = stack[index-1] + stack[index-2];
            index --;
            continue;
        }
        else if (strcmp(tokens[i], "-") == 0) {
            stack[index-2] = stack[index-2] - stack[index-1];
            index --;
            continue;
        }
        else if (strcmp(tokens[i], "*") == 0) {
            stack[index-2] = stack[index-1] * stack[index-2];
            index --;
            continue;
        }
        else if (strcmp(tokens[i], "/") == 0) {
            stack[index-2] = stack[index-2] / stack[index-1];
            index --;
            continue;
        }
        stack[index ++] = atoi(tokens[i]);
    }
    return stack[0];
}
int main() {
    int tokensSize; scanf("%d", &tokensSize);
    char *tokens[tokensSize+1];
    for (int i = 0; i < tokensSize; i ++) {
        tokens[i] = (char *)malloc(4*sizeof(char));
        scanf("%s", tokens[i]);
    }
    int ans = evalRPN(tokens, tokensSize);
    printf("Answer: %d\n", ans);
    return 0;
}