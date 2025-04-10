#include <iostream>
using namespace std;

#define MAX 10

void initializeMatrix(int matrix[MAX][MAX], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            matrix[i][j] = 0;
        }
    }
}

void addEdge(int matrix[MAX][MAX], int src, int dest) {
    matrix[src][dest] = 1;
    matrix[dest][src] = 1;
}

void displayMatrix(int matrix[MAX][MAX], int vertices) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[MAX][MAX];
    int vertices, edges, src, dest;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    initializeMatrix(matrix, vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        cout << "Enter source and destination for edge " << i + 1 << " (0-based indexing): ";
        cin >> src >> dest;
        addEdge(matrix, src, dest);
    }

    displayMatrix(matrix, vertices);

    return 0;
}
