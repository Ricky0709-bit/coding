#include <iostream>
using namespace std;

#define MAX 10

int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1;
}

void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = 0;
    }
}

void bfs(int startVertex, int vertices) {
    front = rear = -1;
    queue[++rear] = startVertex;
    visited[startVertex] = 1;
    cout << "Breadth-First Traversal: ";
    while (front != rear) {
        int currentVertex = queue[++front];
        cout << currentVertex << " ";
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

void dfs(int vertex, int vertices) {
    cout << vertex << " ";
    visited[vertex] = 1;
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfs(i, vertices);
        }
    }
}

int main() {
    int vertices, edges, src, dest, startVertex, choice;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    initializeGraph(vertices);
    for (int i = 0; i < edges; i++) {
        cout << "Enter source and destination for edge " << i + 1 << " (0-based indexing): ";
        cin >> src >> dest;
        addEdge(src, dest);
    }
    do {
        cout << "\nGraph Traversal Menu:\n";
        cout << "1. BFS\n2. DFS\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the starting vertex for BFS: ";
                cin >> startVertex;
                for (int i = 0; i < vertices; i++) visited[i] = 0;
                bfs(startVertex, vertices);
                break;
            case 2:
                cout << "Enter the starting vertex for DFS: ";
                cin >> startVertex;
                for (int i = 0; i < vertices; i++) visited[i] = 0;
                cout << "Depth-First Traversal: ";
                dfs(startVertex, vertices);
                cout << endl;
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);
    return 0;
}
