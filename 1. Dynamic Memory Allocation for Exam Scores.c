#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    float *scores, sum = 0, average;
    
    printf("Enter number of exam scores: ");
    scanf("%d", &n);
    
    scores = (float*)malloc(n * sizeof(float));
    
    if (scores == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter %d exam scores: ", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &scores[i]);
        sum += scores[i];
    }
    
    average = sum / n;
    
    printf("Average score: %.2f\n", average);
    
    free(scores);
    
    return 0;
}
