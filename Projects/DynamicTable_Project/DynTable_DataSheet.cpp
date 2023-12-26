#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

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

// Function to delete an entire row and deallocate memory
void deleteRow(Dynamic2DArray &dynArray, int row) {
    if (row < 1 || row > dynArray.data.size()) {
        cout << "Invalid row index" << endl;
        return;
    }

    // Erase the row from the data vector
    dynArray.data.erase(dynArray.data.begin() + row - 1);
}

// Function to display the table names (topics) with their corresponding keys
void displayTopics(const Dynamic2DArray &dynArray) {
    cout << "Table Names and Keys:" << endl;
    cout << "|";
    for (size_t i = 0; i < dynArray.topics.size(); i++) {
        cout << "(" << i + 1 << ")" << " " << dynArray.topics[i] << " |";
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
    for (size_t i = 0; i < dynArray.data.size(); i++) {
        cout << "|";
        for (int value : dynArray.data[i]) {
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

// Function to enter specific data for one entire row
void enterSpecificDataRow(Dynamic2DArray &dynArray, size_t rowIndex) {
    cout << "\nEnter Data for Row " << rowIndex + 1 << ":" << endl;

    for (size_t i = 0; i < dynArray.topics.size(); i++) {
        int value;
        cout << "Enter data for topic (" << i + 1 << ") " << dynArray.topics[i] << ": ";
        cin >> value;
        insertData(dynArray, rowIndex + 1, i + 1, value);
    }
}

// Function to enter specific data for all rows
void enterSpecificData(Dynamic2DArray &dynArray) {
    int numRowsToAdd;
    cout << "Enter the number of rows to add data for: ";
    cin >> numRowsToAdd;

    for (int i = 0; i < numRowsToAdd; i++) {
        enterSpecificDataRow(dynArray, dynArray.data.size());
    }
}

// Function to save data to a text file
void saveDataToFile(const Dynamic2DArray &dynArray, const string &filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the file for saving." << endl;
        return;
    }

    // Save topics
    for (size_t i = 0; i < dynArray.topics.size(); i++) {
        file << dynArray.topics[i];
        if (i < dynArray.topics.size() - 1) {
            file << " ";
        }
    }
    file << endl;

    // Save data
    for (size_t i = 0; i < dynArray.data.size(); i++) {
        for (size_t j = 0; j < dynArray.data[i].size(); j++) {
            file << dynArray.data[i][j];
            if (j < dynArray.data[i].size() - 1) {
                file << " ";
            }
        }
        file << endl;
    }

    file.close();
    cout << "Data saved to " << filename << endl;
}

// Function to load data from a text file
void loadDataFromFile(Dynamic2DArray &dynArray, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the file for loading." << endl;
        return;
    }

    // Clear existing data
    dynArray.data.clear();
    dynArray.topics.clear();

    // Load topics
    string topicLine;
    getline(file, topicLine);
    stringstream topicStream(topicLine);
    string topic;
    while (topicStream >> topic) {
        dynArray.topics.push_back(topic);
    }

    // Load data
    string dataLine;
    while (getline(file, dataLine)) {
        stringstream dataStream(dataLine);
        vector<int> row;
        int value;
        while (dataStream >> value) {
            row.push_back(value);
        }
        dynArray.data.push_back(row);
    }

    file.close();
    cout << "Data loaded from " << filename << endl;
}

int main() {
    Dynamic2DArray dynArray;
    int choice;
    string filename = "data.txt"; // Change the filename as needed

    // Load data from the file at the start
    loadDataFromFile(dynArray, filename);

    do {
        cout << "\n=========================================" << endl;
        cout << "            Dynamic Table Menu" << endl;
        cout << "=========================================" << endl;
        cout << "1. Insert Topic" << endl;
        cout << "2. Insert Data" << endl;
        cout << "3. Delete Topic" << endl;
        cout << "4. Delete Data" << endl;
        cout << "5. Delete Row" << endl;
        cout << "6. Display Table" << endl;
        cout << "7. Display Topics" << endl;
        cout << "8. Enter Specific Data for All Rows" << endl;
        cout << "9. Save Data to File" << endl;
        cout << "10. Load Data from File" << endl;
        cout << "11. Quit" << endl;
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
            case 5: {
                int row;
                cout << "Enter the row index to delete: ";
                cin >> row;
                deleteRow(dynArray, row);
                break;
            }
            case 6:
                displayTable(dynArray);
                break;
            case 7:
                displayTopics(dynArray);
                break;
            case 8:
                enterSpecificData(dynArray);
                break;
            case 9:
                saveDataToFile(dynArray, "Data.txt");
                break;
            case 10:
                loadDataFromFile(dynArray, "Data.txt");
                break;
            case 11:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 11);

    return 0;
}
