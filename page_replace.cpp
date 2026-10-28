#include <iostream>
using namespace std;

void FIFO(int pages[], int n, int frames)
{
    int a[10], faults = 0, hits = 0, pos = 0;

    for (int i = 0; i < frames; i++)
        a[i] = -1;

    cout << "\n--- FIFO Algorithm ---\n";

    for (int i = 0; i < n; i++)
    {
        bool found = false;

        for (int j = 0; j < frames; j++)
        {
            if (a[j] == pages[i])
                found = true;
        }

        if (found)
            hits++;
        else
        {
            a[pos] = pages[i];
            pos = (pos + 1) % frames;
            faults++;
        }

        cout << pages[i] << " : ";
        for (int j = 0; j < frames; j++)
        {
            if (a[j] == -1)
                cout << "- ";
            else
                cout << a[j] << " ";
        }
        cout << endl;
    }

    cout << "Page Faults = " << faults << endl;
    cout << "Page Hits = " << hits << endl;
}

void LRU(int pages[], int n, int frames)
{
    int a[10], time[10], faults = 0, hits = 0, count = 0;

    for (int i = 0; i < frames; i++)
    {
        a[i] = -1;
        time[i] = 0;
    }

    cout << "\n--- LRU Algorithm ---\n";

    for (int i = 0; i < n; i++)
    {
        int pos = -1;

        for (int j = 0; j < frames; j++)
        {
            if (a[j] == pages[i])
                pos = j;
        }

        if (pos != -1)
        {
            hits++;
            time[pos] = ++count;
        }
        else
        {
            int lru = 0;

            for (int j = 1; j < frames; j++)
            {
                if (a[j] == -1 || (a[lru] != -1 && time[j] < time[lru]))
                    lru = j;
            }

            a[lru] = pages[i];
            time[lru] = ++count;
            faults++;
        }

        cout << pages[i] << " : ";
        for (int j = 0; j < frames; j++)
        {
            if (a[j] == -1)
                cout << "- ";
            else
                cout << a[j] << " ";
        }
        cout << endl;
    }

    cout << "Page Faults = " << faults << endl;
    cout << "Page Hits = " << hits << endl;
}

void Optimal(int pages[], int n, int frames)
{
    int a[10], faults = 0, hits = 0;

    for (int i = 0; i < frames; i++)
        a[i] = -1;

    cout << "\n--- Optimal Algorithm ---\n";

    for (int i = 0; i < n; i++)
    {
        bool found = false;

        for (int j = 0; j < frames; j++)
        {
            if (a[j] == pages[i])
                found = true;
        }

        if (found)
            hits++;
        else
        {
            int replace = -1, farthest = i + 1;

            for (int j = 0; j < frames; j++)
            {
                if (a[j] == -1)
                {
                    replace = j;
                    break;
                }

                int k;
                for (k = i + 1; k < n; k++)
                {
                    if (a[j] == pages[k])
                        break;
                }

                if (k == n)
                {
                    replace = j;
                    break;
                }

                if (k > farthest)
                {
                    farthest = k;
                    replace = j;
                }
            }

            if (replace == -1)
                replace = 0;

            a[replace] = pages[i];
            faults++;
        }

        cout << pages[i] << " : ";
        for (int j = 0; j < frames; j++)
        {
            if (a[j] == -1)
                cout << "- ";
            else
                cout << a[j] << " ";
        }
        cout << endl;
    }

    cout << "Page Faults = " << faults << endl;
    cout << "Page Hits = " << hits << endl;
}

int main()
{
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int n = 7;
    int frames = 3;

    FIFO(pages, n, frames);
    LRU(pages, n, frames);
    Optimal(pages, n, frames);

    return 0;
}