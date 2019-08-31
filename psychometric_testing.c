#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int upperBound(int up, int n, int s[])
{
    if(s[n-1]<=up)
        return n;
    int l=0, r=n;
    int mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(s[mid]<=up)
            l=mid+1;
        else
            r=mid;
    }
    if(l==r)
        return l;
    else
        return mid;
}
int lowerBound(int low, int n, int s[])
{
    int l=0, r=n;
    int mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(s[mid]<low)
            l=mid+1;
        else
            r=mid;
    }
    if(l==r)
        return l;
    else
        return mid;
}
int cmp(const void*a, const void*b)
{
    return *(int *)a-*(int *)b;
}
int* jobOffers(int scores_size, int* scores, int lowerLimits_size, int* lowerLimits, int upperLimits_size, int* upperLimits, int* result_size) {
    int i;
    qsort(scores, scores_size, sizeof(int), cmp);
    int *result=(int*)malloc(sizeof(int)*lowerLimits_size) ;
    for(i=0;i<lowerLimits_size;i++)
    {
        int upper=upperBound(upperLimits[i], scores_size, scores);
        int lower=lowerBound(lowerLimits[i], scores_size, scores);
        result[i]=upper-lower;
    }
    *result_size=lowerLimits_size;
    return result;
} int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    int* res;
int res_size;
    int scores_size = 0;
    scanf("%d\n", &scores_size);

    int scores[scores_size];
    for(int i = 0; i < scores_size; i++) {
        int scores_item;
        scanf("%d", &scores_item);
        scores[i] = scores_item;
    }

    int lowerLimits_size = 0;
    scanf("%d\n", &lowerLimits_size);

    int lowerLimits[lowerLimits_size];
    for(int i = 0; i < lowerLimits_size; i++) {
        int lowerLimits_item;
        scanf("%d", &lowerLimits_item);
        lowerLimits[i] = lowerLimits_item;
    }

    int upperLimits_size = 0;
    scanf("%d\n", &upperLimits_size);

    int upperLimits[upperLimits_size];
    for(int i = 0; i < upperLimits_size; i++) {
        int upperLimits_item;
        scanf("%d", &upperLimits_item);
        upperLimits[i] = upperLimits_item;
    }

    res = jobOffers(scores_size, scores, lowerLimits_size, lowerLimits, upperLimits_size, upperLimits, &res_size);
    for (int res_i = 0; res_i < res_size; res_i++) {

        fprintf(f, "%d\n", res[res_i]);

    }


    fclose(f);
    return 0;
}
