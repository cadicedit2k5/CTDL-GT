#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Graph
{
    int **g;
    int capacity;
    int n;

    Graph(int cap = 100)
    {
        g = new int *[cap];
        for (int i = 0; i < cap; i++)
        {
            g[i] = new int[cap];
            fill(g[i], g[i] + cap, 0); // Initialize all elements to 0 (default behavior)
        }
        capacity = cap;
        n = 0;
    }

    ~Graph()
    { // Destructor to deallocate memory when object goes out of scope
        for (int i = 0; i < capacity; i++)
        {
            delete[] g[i];
        }
        delete[] g;
    }

    void init()
    {
        cout << "Nhap vao so dinh cua ma tran ke: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> g[i][j];
            }
        }
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }

    void BFS(int start)
    {
        bool *visited = new bool[capacity];
        fill(visited, visited + capacity, false); // Efficiently initialize visited array
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int i = 0; i < n; i++)
            {
                if (g[v][i] != 0 && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;

        delete[] visited; // Deallocate memory for visited array
    }

    void DFS(int start)
    {
        bool *visited = new bool[capacity];
        fill(visited, visited + capacity, false); // Efficiently initialize visited array
        stack<int> st;

        st.push(start);
        visited[start] = true;

        while (!st.empty())
        {
            int v = st.top();
            st.pop();
            cout << v << " ";

            for (int i = n - 1; i >= 0; i--)
            { // Explore neighbors in reverse order (optional)
                if (g[v][i] != 0 && !visited[i])
                {
                    st.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;

        delete[] visited; // Deallocate memory for visited array
    }
};

int main()
{
    Graph g;
    g.init();
    g.display();
    g.BFS(0);
    g.DFS(0);
    return 0;
}
