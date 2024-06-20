#include <stdio.h>
#include <conio.h>

int main() {
    int n;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);

    int a[10][10], s[10], Indegree[10], T[10];
    int sum = 0, top = -1, k = 0, i, j, u, v;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++) {
        T[i] = 0;
    }

    printf("Enter the adjacency matrix for %d vertices \n", n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (j = 0; j < n; j++) {
        sum = 0;
        for (i = 0; i < n; i++) {
            sum += a[i][j];
        }
        Indegree[j] = sum;
    }

    for (i = 0; i < n; i++) {
        if (Indegree[i] == 0) {
            top++;
            s[top] = i;
        }
    }

    while (top != -1) {
        u = s[top];
        top--;
        T[k++] = u;
        for (v = 0; v < n; v++) {
            if (a[u][v] > 0) {
                Indegree[v]--;
                if (Indegree[v] == 0) {
                    top++;
                    s[top] = v;
                }
            }
        }
    }

    printf("The topological sequence is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");

    return 0;
}

