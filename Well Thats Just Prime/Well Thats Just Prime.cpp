/*
    Leonardo Gonzalez   2/6/2024

    Week 3              Well That's Just Prime
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void primeSearch(int);

vector<int> primeList;


int main()
{
    int numInput, size;
restart:
    cout << "Enter -1 to quit." << endl;
    cout << "Enter a number greater than 1: ";

    cin >> numInput;
    while (numInput != -1) {
        if (numInput > 0) {
            primeSearch(numInput);
            if (primeList.size() == 1) {
                cout << "\n" << primeList[0] << " is a prime number." << endl;
            }
            else {
                cout << "\n\nThe prime factors of " << numInput << " are ";
                for (int i = 0; i < primeList.size() - 1; i++) {
                    cout << primeList[i] << ", ";
                }
                cout << "and " << primeList[primeList.size() - 1] << "." << endl;
            }
        }
        else {
            cout << "I cannot calculate the prime factors of that number." << endl;
            goto restart;
        }

        size = primeList.size();

        for (int i = 0; i < size; i++) {
            primeList.pop_back();
        }
        cout << "Enter -1 to quit." << endl;
        cout << "Enter a number greater than 1: ";

        cin >> numInput;
    }
    
}

void primeSearch(int num) {
    
    if (num == 2) {
        primeList.push_back(num);
        return;
    }
    else if (num % 2 == 0) {
        primeSearch(2);
        primeSearch(num / 2);
        return;
    }
    else {
        for (int i = 3; i < num; i += 2) {
            if (num % i == 0) {
                if (num == i) {
                    primeList.push_back(num);
                    return;
                }
                else {
                    primeSearch(i);
                    primeSearch(num / i);
                    return;
                }
            }
        }
        primeList.push_back(num);
        return;
    }
    
}
