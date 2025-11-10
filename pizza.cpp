#include <iostream>
using namespace std;

#define INF 9999

int main() {
    int n;
    cout << "Enter number of locations: ";
    cin >> n;

    int a[10][10];
    cout << "Enter time matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int src;
    cout << "Enter pizza shop location (source): ";
    cin >> src;

    int dist[10], visited[10] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = a[src][i];
    dist[src] = 0;
    visited[src] = 1;

    // Dijkstra algorithm
    for (int k = 1; k < n; k++) {
        int min = INF, u = -1;

        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && dist[u] + a[u][v] < dist[v])
                dist[v] = dist[u] + a[u][v];
    }

    cout << "\nMinimum delivery time from pizza shop:\n";
    for (int i = 0; i < n; i++)
        cout << "To location " << i << " = " << dist[i] << " mins\n";

    return 0;
}