#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 9
#define INF 10000


int weight[MAX_VERTICES][MAX_VERTICES] = {
	{ 0,1,INF,5,INF,INF,20,INF,INF },
	{ INF,0,INF,INF,INF,4,INF,INF,INF },
	{ 3,INF,0,INF,5,INF,INF,INF,8 },
	{ INF,INF,INF,0,INF,INF,7,20,15 },
	{ INF,INF,4,INF,0,INF,INF,INF,5 },
	{ INF,5,INF,15,INF,0,INF,2,INF },
	{ INF,INF,INF,9,INF,INF,0,8,INF },
	{ INF,INF,INF,INF,INF,INF,6,0,INF },
	{ INF,INF,INF,INF,9,INF,INF,INF,0 }
};

int A[MAX_VERTICES][MAX_VERTICES];

void printStep(int step) {
	int i, j;
	printf("\n A%d :", step);
	for (i = 0; i < MAX_VERTICES; i++) {
		printf("\t");
		for (j = 0; j < MAX_VERTICES; j++) {
			if (A[i][j] == 10000)
				printf("%4c", "*");
			else printf("%4d", A[i][j]);
		}
		printf("\n\n");
	}
}

void Floyd_shortestPath(int n) {
	int v, w, k, step = -1;

	for (v = 0; v < n; v++)
		for (w = 0; w < n; w++)
			A[v][w] = weight[v][w];

	printStep(step);

	for (k = 0; k < n; k++)
		for (v = 0; v < n; v++)
			for (w = 0; w < n; w++)
				if (A[v][k] + A[k][w] < A[v][w])
					A[v][w] = A[v][k] + A[k][w];
	printStep(++step);

}

void main(void) {
	int i, j;
	printf("\n ********* 가중치 인접 행렬 **********\n\n");
	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++) {
			if (weight[i][j] == 10000)
				printf("%4c", "*");
			else printf("%4d", weight[i][j]);
		}
		printf("\n\n");
	}
	printf("\n ************ 플로이드 최단 경로 구하기 ***************\n\n");
	Floyd_shortestPath(MAX_VERTICES);

	getchar();
}
