```cpp
#include <iostream>
using namespace std;

void firstFit(int blocks[], int m, int processes[], int n)
{
    int b[10], alloc[10];

    for (int i = 0; i < m; i++)
        b[i] = blocks[i];

    for (int i = 0; i < n; i++)
        alloc[i] = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[j] >= processes[i])
            {
                alloc[i] = j;
                b[j] -= processes[i];
                break;
            }
        }
    }

    cout << "\nFIRST FIT\n";
    cout << "Process\tSize\tBlock\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << processes[i] << "\t";

        if (alloc[i] != -1)
            cout << alloc[i] + 1;
        else
            cout << "Not Allocated";

        cout << endl;
    }
}

void bestFit(int blocks[], int m, int processes[], int n)
{
    int b[10], alloc[10];

    for (int i = 0; i < m; i++)
        b[i] = blocks[i];

    for (int i = 0; i < n; i++)
        alloc[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int best = -1;

        for (int j = 0; j < m; j++)
        {
            if (b[j] >= processes[i])
            {
                if (best == -1 || b[j] < b[best])
                    best = j;
            }
        }

        if (best != -1)
        {
            alloc[i] = best;
            b[best] -= processes[i];
        }
    }

    cout << "\nBEST FIT\n";
    cout << "Process\tSize\tBlock\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << processes[i] << "\t";

        if (alloc[i] != -1)
            cout << alloc[i] + 1;
        else
            cout << "Not Allocated";

        cout << endl;
    }
}

void worstFit(int blocks[], int m, int processes[], int n)
{
    int b[10], alloc[10];

    for (int i = 0; i < m; i++)
        b[i] = blocks[i];

    for (int i = 0; i < n; i++)
        alloc[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int worst = -1;

        for (int j = 0; j < m; j++)
        {
            if (b[j] >= processes[i])
            {
                if (worst == -1 || b[j] > b[worst])
                    worst = j;
            }
        }

        if (worst != -1)
        {
            alloc[i] = worst;
            b[worst] -= processes[i];
        }
    }

    cout << "\nWORST FIT\n";
    cout << "Process\tSize\tBlock\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << processes[i] << "\t";

        if (alloc[i] != -1)
            cout << alloc[i] + 1;
        else
            cout << "Not Allocated";

        cout << endl;
    }
}

int main()
{
    int blocks[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};

    int m = 5;
    int n = 4;

    firstFit(blocks, m, processes, n);
    bestFit(blocks, m, processes, n);
    worstFit(blocks, m, processes, n);

    return 0;
}
``
