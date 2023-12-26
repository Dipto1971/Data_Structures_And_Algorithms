#include <bits/stdc++.h>
using namespace std;

// Struct for the dynamic 2D array
struct Dynamic2DArray {
    vector<vector<int>> data;
    vector<string> topics;
};

// Function to insert a column (topic) into the dynamic 2D array
void insertTopic(Dynamic2DArray &dynArray, const string &topic) {
    dynArray.topics.push_back(topic);
    for (vector<int> &row : dynArray.data) {
        row.push_back(0); // Initialize new column with zeros
    }
}

// Function to insert data into the dynamic 2D array
void insertData(Dynamic2DArray &dynArray, int row, int col, int value) {
    if (row < 1 || col < 1) {
        cout << "Invalid row or column index" << endl;
        return;
    }

    // Ensure that there are enough rows
    if (row > dynArray.data.size()) {
        // Insert new rows with zeros up to the specified row
        for (int i = dynArray.data.size(); i < row; i++) {
            dynArray.data.push_back(vector<int>(dynArray.topics.size(), 0));
        }
    }

    // Ensure that there are enough columns
    if (col > dynArray.topics.size()) {
        cout << "Column index exceeds the number of topics" << endl;
        return;
    }

    dynArray.data[row - 1][col - 1] = value;
}

// Function to delete a column (topic) and adjust the dynamic 2D array
void deleteTopic(Dynamic2DArray &dynArray, int col) {
    if (col < 1 || col > dynArray.topics.size()) {
        cout << "Invalid column index" << endl;
        return;
    }

    dynArray.topics.erase(dynArray.topics.begin() + col - 1);
    for (vector<int> &row : dynArray.data) {
        row.erase(row.begin() + col - 1);
    }
}

// Function to delete data at a specific row and column
void deleteData(Dynamic2DArray &dynArray, int row, int col) {
    if (row < 1 || row > dynArray.data.size() || col < 1 || col > dynArray.topics.size()) {
        cout << "Invalid row or column index" << endl;
        return;
    }

    dynArray.data[row - 1][col - 1] = -1; // Mark the data as deleted (-1)
}

// Function to display the table names (topics) with their corresponding keys
void displayTopics(const Dynamic2DArray &dynArray) {
    cout << "Table Names and Keys:" << endl;
    cout << "|";
    for (size_t i = 0; i < dynArray.topics.size(); i++) {
        cout <<"(" << i + 1 << ")" << " " << dynArray.topics[i] << " |";
    }
    cout << endl;
}

// Function to display the dynamic 2D array as a table
void displayTable(const Dynamic2DArray &dynArray) {
    cout << "\nTable Contents:\n";

    // Display topics (column names)
    cout << "|";
    for (const string &topic : dynArray.topics) {
        cout << " " << topic << " |";
    }
    cout << endl;

    // Display data
    for (const vector<int> &row : dynArray.data) {
        cout << "|";
        for (int value : row) {
            if (value == -1) {
                cout << " " << "Deleted" << " |"; // Display "Deleted" for deleted data
            } else {
                cout << " " << value << " |";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Dynamic2DArray dynArray;
    int choice;

    do {
        cout << "\n=========================================" << endl;
        cout << "            Dynamic Table Menu" << endl;
        cout << "=========================================" << endl;
        cout << "1. Insert Topic" << endl;
        cout << "2. Insert Data" << endl;
        cout << "3. Delete Topic" << endl;
        cout << "4. Delete Data" << endl;
        cout << "5. Display Table" << endl;
        cout << "6. Display Topics" << endl;
        cout << "7. Quit" << endl;
        cout << "=========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string topic;
                cout << "Enter the topic name: ";
                cin >> topic;
                insertTopic(dynArray, topic);
                break;
            }
            case 2: {
                int row, col, value;
                displayTopics(dynArray);
                cout << "Enter row index, column index, and value: ";
                cin >> row >> col >> value;
                insertData(dynArray, row, col, value);
                break;
            }
            case 3: {
                int col;
                cout << "Enter the column index to delete: ";
                cin >> col;
                deleteTopic(dynArray, col);
                break;
            }
            case 4: {
                int row, col;
                cout << "Enter row index and column index to delete data: ";
                cin >> row >> col;
                deleteData(dynArray, row, col);
                break;
            }
            case 5:
                displayTable(dynArray);
                break;
            case 6:
                displayTopics(dynArray);
                break;
            case 7:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
