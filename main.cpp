#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <limits> // Required for numeric_limits

using namespace std;

// Function to check for bad words
bool containsBadWords(const string& text) {
    string badWords[] = {"fuck", "shit", "bitch", "asshole", "damn", "hell", "cunt",
                         "бля", "сука", "пиздец", "ебать", "хуй", "жопа", "говно"};

    for (const string& badWord : badWords) {
        if (text.find(badWord) != string::npos) {
            return true;
        }
    }
    return false;
}

// Function to calculate factorial
long long factorial(int n) { // Changed to long long to handle larger factorials
    if (n < 0) return -1; //Error for negative input
    if (n == 0) return 1;
    long long result = 1;
    for (int i = 1; i <= n; ++i) result *= i;
    return result;
}

// Function to calculate the average of numbers
double calculateAverage(const vector<double>& numbers) {
    if (numbers.empty()) return 0;
    double sum = 0;
    for (double num : numbers) sum += num;
    return sum / numbers.size();
}

// Function to find the maximum of numbers
double findMax(const vector<double>& numbers) {
    if (numbers.empty()) return numeric_limits<double>::lowest(); // Handle empty input
    double maxNum = numbers[0];
    for (double num : numbers) maxNum = max(maxNum, num);
    return maxNum;
}

// Function to find the minimum of numbers
double findMin(const vector<double>& numbers) {
    if (numbers.empty()) return numeric_limits<double>::max(); // Handle empty input
    double minNum = numbers[0];
    for (double num : numbers) minNum = min(minNum, num);
    return minNum;
}


// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    cout << "Welcome to Fish" << endl;
    cout << "By SmolCutiePie" << endl;
    cout << "Copyright (c) 2024 FishLang . All Rights Reserved." << endl;

    string a = "/start";
    cin >> a;

    if (a != "/start") {
        cout << "Syntax Error!" << endl;
        return 0;
    }


    while (true) {
        string b = "";
        cin >> b;
        transform(b.begin(), b.end(), b.begin(), ::tolower);

        if (containsBadWords(b)) {
            cout << "Be kinder =( Try again!" << endl;
        } else if (b == "!plus:") {
            int c, d;
            cin >> c >> d;
            cout << c + d << endl;
        } else if (b == "!minus:") {
            int c, d;
            cin >> c >> d;
            cout << c - d << endl;
        } else if (b == "!mp:") {
            int c, d;
            cin >> c >> d;
            cout << c * d << endl;
        } else if (b == "!dn:") {
            int c, d;
            cin >> c >> d;
            if (d != 0) {
                cout << c / d << endl;
            } else {
                cout << "I can't (Division by Zero!" << endl;
            }
        } else if (b == "?sst?") {
            int e;
            cin >> e;
            cout << e << endl;
        } else if (b == "!rnd:") {
            int min, max;
            cin >> min >> max;
            srand(time(0));
            int random = rand() % (max - min + 1) + min;
            cout << "Random Number: " << random << endl;
        } else if (b == "!ftrl:") {
            int n;
            cin >> n;
            long long result = factorial(n);
            if (result == -1) cout << "Error: Factorial is not defined for negative numbers!" << endl;
            else cout << "Factorial of " << n << ": " << result << endl;
        } else if (b == "!sqrt:") {
            double x;
            cin >> x;
            if (x >= 0) {
                cout << "Square root of " << x << ": " << sqrt(x) << endl;
            } else {
                cout << "Error: Square root is not defined for negative numbers!" << endl;
            }
        } else if (b == "!pow:") {
            double base, exponent;
            cin >> base >> exponent;
            cout << base << " raised to the power of " << exponent << ": " << pow(base, exponent) << endl;
        } else if (b == "!avg:") { // New: Average
            int count;
            cin >> count;
            vector<double> numbers(count);
            for (int i = 0; i < count; ++i) cin >> numbers[i];
            cout << "Average: " << calculateAverage(numbers) << endl;
        } else if (b == "!max:") { // New: Maximum
            int count;
            cin >> count;
            vector<double> numbers(count);
            for (int i = 0; i < count; ++i) cin >> numbers[i];
            cout << "Maximum: " << findMax(numbers) << endl;
        } else if (b == "!min:") { // New: Minimum
            int count;
            cin >> count;
            vector<double> numbers(count);
            for (int i = 0; i < count; ++i) cin >> numbers[i];
            cout << "Minimum: " << findMin(numbers) << endl;
        } else if (b == "!prime:") { // New: Is Prime
            int num;
            cin >> num;
            if (isPrime(num)) cout << num << " is a prime number." << endl;
            else cout << num << " is not a prime number." << endl;
        } else if (b == "return 0;") {
            cout << "Bye user! :] " << endl;
            break;
        } else {
            cout << "Syntax Error!" << endl;
        }
    }
    return 0;
}
