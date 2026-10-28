
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool validIP(string ip, unsigned int &result)
{
    stringstream ss(ip);
    string part;
    int count = 0;
    result = 0;

    while (getline(ss, part, '.'))
    {
        if (part.empty() || part.size() > 3)
            return false;

        for (char c : part)
        {
            if (c < '0' || c > '9')
                return false;
        }

        int num = stoi(part);

        if (num < 0 || num > 255)
            return false;

        result = (result << 8) | num;
        count++;
    }

    return count == 4;
}

int main()
{
    string ip1, ip2, mask;
    unsigned int a, b, m;

    cout << "Enter First IP Address: ";
    cin >> ip1;

    cout << "Enter Second IP Address: ";
    cin >> ip2;

    cout << "Enter Subnet Mask: ";
    cin >> mask;

    if (!validIP(ip1, a) ||
        !validIP(ip2, b) ||
        !validIP(mask, m))
    {
        cout << "Invalid IP address or subnet mask!";
        return 0;
    }

    cout << "\nIP addresses are valid.\n";

    cout << "Network Address 1: "
         << ((a & m) >> 24) << "."
         << ((a & m) >> 16 & 255) << "."
         << ((a & m) >> 8 & 255) << "."
         << ((a & m) & 255) << endl;

    cout << "Network Address 2: "
         << ((b & m) >> 24) << "."
         << ((b & m) >> 16 & 255) << "."
         << ((b & m) >> 8 & 255) << "."
         << ((b & m) & 255) << endl;

    if ((a & m) == (b & m))
        cout << "Both hosts belong to the SAME subnet.";
    else
        cout << "Hosts belong to DIFFERENT subnets.";

    return 0;
}
