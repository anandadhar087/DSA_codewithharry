#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Enter age" << endl;
    cin >> age;

    if (age > 150 || age < 1) //    || means or and && means and
    {
        cout << "Invalid age";
    }

    else if (age >= 18)
    {
        cout << "You can vote";
    }

    else
    {
        cout << "You cannot vote";
    }
    return 0;
}