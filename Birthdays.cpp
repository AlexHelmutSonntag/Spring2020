#include <iostream>
using namespace std;

struct Date {
  int month, day;
};

int main() {
  	int n;
    bool repeat = true;
    while (repeat) {
        cout << "Please enter the count of birthdays! (integer number, 1<=number<=20)" << endl;
        cin >> n;
        // Error, if it is not an integer or less than 1 or greater than 20
        repeat = cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ') || n < 1 || n > 20;
        if (repeat) cout << "You entered a string or an invalid number." << endl;
        cin.clear();
        cin.ignore(999, '\n');
    }
    
    Date birth[n + 1];
    for (int i = 1; i <= n; i++) {
        repeat = true;
        while (repeat) {
            cout << "Please enter the " << i << " month! (integer number, 1<=number<=12)" << endl;
            cin >> birth[i].month;
            // Error, if it is not an integer or less than 0 or greater than 100
            repeat = cin.fail() || cin.peek() != '\n' || birth[i].month < 1 || birth[i].month > 12;
            if (repeat) cout << "You entered a string or an invalid number." << endl;
            cin.clear();
            cin.ignore(999, '\n');
        }
        repeat = true;
        while (repeat) {
            cout << "Please enter the " << i << " day! (integer number, 1<=number<=31)" << endl;
            cin >> birth[i].day;
            // Error, if it is not an integer or less than 0 or greater than 100
            repeat = cin.fail() || cin.peek() != '\n' || birth[i].day < 1 || birth[i].day > 31;
            if (repeat) cout << "You entered a string or an invalid number." << endl;
            cin.clear();
            cin.ignore(999, '\n');
        }
    }
    
    int first = 1;
    for (int i = 2; i <= n; i++) {
        if (birth[i].month < birth[first].month ||
            (birth[i].month == birth[first].month
            && birth[i].day < birth[first].day)) {
            first = i;
        }
    }

    cout << "First birthday in year: " << birth[first].month
         << " " << birth[first].day << ", person " << first << endl;
    return 0;
}
