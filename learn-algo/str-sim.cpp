/*
 * bailing
 */

#include <iostream>
#include <cstring>
#include <algorithm>

inline int min(int a, int b, int c)
{
    int m = (a > b ? b : a);
    return (m > c ? c : m);
}

int** levenshtein_distance(const char* s, const char* t)
{
    int m = strlen(s);
    int n = strlen(t);
    int** d = new int*[m+1];
    for(int i = 0; i <= m; ++i) {
        d[i] = new int[n+1];
    }

    for(int i = 0; i <= m; ++i) {
        d[i][0] = i;
    }
    for(int j = 0; j <= n; ++j) {
        d[0][j] = j;
    }

    for(int j = 1; j <= n; ++j) {
        for(int i = 1; i <= m; ++i) {
            if(s[i-1] == t[j-1]) {
                d[i][j] = d[i-1][j-1];
            }
            else{
                d[i][j] = min(d[i-1][j],            // deletion
                              d[i][j-1],            // insert
                              d[i-1][j-1]) + 1;     // substitution
            }
        }
    }
    return d;
}

void print_matrix(int** d, const char* s, const char* t)
{
    int m = strlen(s);
    int n = strlen(t);
    printf(" \t \t");
    for(int i = 0; i < m; ++i)
        printf("%c\t", s[i]);
    printf("\n");

    for(int j = 0; j <= n; ++j) {
        if(j != 0)
            printf("%c\t", t[j-1]);
        else
            printf(" \t");

        for(int i = 0; i <= m; ++i) {
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }
}

int calc_str_distance(const char* s, int sbg, int sed, const char* t, int tbg, int ted)
{
    if(sbg > sed) {
        if(tbg > ted) return 0;
        else return ted - tbg + 1;
    }
    if(tbg > ted) {
        if(sbg > sed) return 0;
        else return sed - sbg + 1;
    }

    if(s[sbg] == t[tbg]) {
        return calc_str_distance(s, sbg+1, sed, t, tbg+1, ted);
    }
    else {
        int t1 = calc_str_distance(s, sbg, sed, t, tbg+1, ted);
        int t2 = calc_str_distance(s, sbg+1, sed, t, tbg, ted);
        int t3 = calc_str_distance(s, sbg+1, sed, t, tbg+1, ted);
        return min(t1, t2, t3) + 1;
    }
}

int main()
{
    const char* s = "kitten";
    const char* t = "sitting";
    int** matrix = levenshtein_distance(s, t);
    printf("%d\n", matrix[strlen(s)][strlen(t)]);
    print_matrix(matrix, s, t);
    int ret = calc_str_distance(s, 0, strlen(s), t, 0, strlen(t));
    printf("%d\n", ret);

    return 0;
}
