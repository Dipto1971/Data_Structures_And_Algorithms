#include <algorithm>
#include <iostream>
using namespace std;
 
// A structure to represent a job
struct Job {
   
    char id; // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on
                // deadline
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparison);
    
    cout << "Sorted jobs are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].id << " " << arr[i].dead << " " << arr[i].profit << endl;
    }

    int result[n];
    bool slot[n];
 
    for (int i = 0; i < n; i++){
        slot[i] = false;
    }
    int profit = 0;
    
    for (int i = 0; i < n; i++) {
        cout << "Last possible slot for job " << arr[i].id << " is: " << min(n, arr[i].dead) << endl;// Last possible slot for job the job i
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            // Free slot found
            if (slot[j] == false) {
                cout << "Slot " << j + 1<< " is free for job " << arr[i].id<< endl;
                result[j] = i; // Add this job to result
                slot[j] = true; // Make this slot occupied
                profit += arr[i].profit; // Add profit of current job to result
                break;
            }
        }
    }
    cout << "Total profit is: " << profit << endl;
    // Print the result
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
    
    // Time Complexity: O(n^2)
}
// Output:
// Following is maximum profit sequence of jobs 
// Sorted jobs are: 
// a 2 100
// c 2 27
// d 1 25
// b 1 19
// e 3 15
// Last possible slot for job a is: 1
// Slot 1 is free for job a
// Last possible slot for job c is: 1
// Slot 0 is free for job c
// Last possible slot for job d is: 0
// Last possible slot for job b is: 0
// Last possible slot for job e is: 2
// Slot 2 is free for job e
// Total profit is: 142
// c a e


int main()
{
    Job arr[] = { { 'a', 5, 200 },
                  { 'b', 3, 180 },
                  { 'c', 3, 190 },
                  { 'd', 2, 300 },
                  { 'e', 4, 120 },
                  { 'f', 2, 100 } };
   
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";
    printJobScheduling(arr, n);
    return 0;
}