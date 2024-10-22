#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

// Question 1: Find the Subarray with the Largest Sum
void question1() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int max_sum = nums[0];
    int current_sum = nums[0];
    int start = 0, end = 0, temp_start = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (current_sum < 0) {
            current_sum = nums[i];
            temp_start = i;
        } else {
            current_sum += nums[i];
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }
    cout << "The largest sum is: " << max_sum << endl;
    cout << "The subarray with the largest sum is: [ ";
    for (int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
}

// Question 2: Count Inversions in an Array
void question2() {
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int inversions = 0;

    cout << "\nInversions in the array: " << endl;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
                inversions++;
            }
        }
    }

    cout << "Number of inversions: " << inversions << endl;
}

// Question 3: Find the k-th Largest Element
void question3() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    priority_queue<int, vector<int>, greater<int> > minHeap;

    for (int i = 0; i < n; i++) {
        minHeap.push(arr[i]);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    cout << "The " << k << "th largest element is: " << minHeap.top() << endl;
}

// Question 4: Check if a String is a Palindrome
void question4() {
    string s;
    
    cout << "Enter a phrase: ";
    cin.ignore();
    getline(cin, s);

    string filtered = "";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            if (c >= 'A' && c <= 'Z') {
                c += 32;
            }
            filtered += c;
        }
    }

    int left = 0;
    int right = filtered.length() - 1;

    while (left < right) {
        if (filtered[left] != filtered[right]) {
            cout << "Output: false" << endl;
            return;
        }
        left++;
        right--;
    }

    cout << "Output: true" << endl;
}

// Question 5: Find the Equilibrium Index
void question5() {
    int n;
    
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int totalSum = 0;

    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int leftSum = 0;

    for (int i = 0; i < n; i++) {
        if (leftSum == totalSum - leftSum - arr[i]) {
            cout << "Equilibrium index: " << i + 1 << endl;
            return;
        }
        leftSum += arr[i];
    }

    cout << "-1" << endl;
}

// Question 6a: Find Pair with Sum X (Naive Approach)
bool question6a(vector<int>& A, int X) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = i + 1; j < A.size(); j++) {
            if (A[i] + A[j] == X) return true;
        }
    }
    return false;
}

// Question 6b: Find Pair with Sum X (Two Pointer Technique)
bool question6b(vector<int>& A, int X) {
    sort(A.begin(), A.end());
    int left = 0, right = A.size() - 1;
    while (left < right) {
        int sum = A[left] + A[right];
        if (sum == X) return true;
        else if (sum < X) left++;
        else right--;
    }
    return false;
}

// Question 7: Maximum Sum of k Consecutive Elements (Sliding Window)
void question7() {
    int n, k;

    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be greater than 0." << endl;
        return;
    }

    vector<int> a(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter the size of the sliding window (k): ";
    cin >> k;

    if (k <= 0 || k > n) {
        cout << "Sliding window size must be between 1 and the size of the array." << endl;
        return;
    }

    cout << "Maximums in each sliding window: ";
    for (int i = 0; i <= n - k; i++) {
        int max_val = a[i];
        for (int j = 1; j < k; j++) {
            if (a[i + j] > max_val) {
                max_val = a[i + j];
            }
        }
        cout << max_val << " ";
    }
    cout << endl;
}

// Question 8: Maximize Profit from Stock Prices
void question8() {
    int n;

    cout << "Enter the number of days (prices): ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of days must be greater than 0." << endl;
        return;
    }

    vector<int> prices(n);

    cout << "Enter the prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int minPrice = prices[0]; 
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        int profit = prices[i] - minPrice;
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    cout << "Maximum Profit: " << maxProfit << endl; 
}

int main() {
    int choice;

    while (true) {
        cout << "Enter question number (1-8) to execute or 0 to exit: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                question1();
                break;
            }
            case 2: {
                question2();
                break;
            }
            case 3: {
                question3();
                break;
            }
            case 4: {
                question4();
                break;
            }
            case 5: {
                question5();
                break;
            }
            case 6: {
                int n, X;
                cout << "Enter the number of elements in the array: ";
                cin >> n;
                vector<int> nums6(n);
                cout << "Enter the elements of the array: ";
                for (int i = 0; i < n; i++) {
                    cin >> nums6[i];
                }
                cout << "Enter the value of X (target sum): ";
                cin >> X;
                cout << "Question 6a - Pair with Sum X (Naive): " << (question6a(nums6, X) ? "Yes" : "No") << endl;
                cout << "Question 6b - Pair with Sum X (Two Pointer): " << (question6b(nums6, X) ? "Yes" : "No") << endl;
                break;
            }
            case 7: {
                question7();
                break;
            }
            case 8: {
                question8();
                break;
            }
            case 0: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please choose between 0 and 8." << endl;
            }
        }
    }

    return 0;
}