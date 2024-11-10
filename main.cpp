#include "TodoListItem.h"
#include "TodoListItemTable.h"
#include <cstdlib>
#include <ios>
#include <limits>
#include <stdexcept>
#include <string>
#include <chrono>
#include <iostream>
using namespace std;


void homeScreen(const TodoListItemTable &currTable) {
    cout << "\n---- Welcome to your TodoList ----\n";

    // print out the current todo list:

    const auto& tasks = currTable.getItems();
    if (tasks.empty()) {
        cout << "TodoList is empty. Please start by adding a task\n";
    } else {
        cout << "\n---- Current tasks ----\n";
        for (const auto &item : tasks) {
            cout << "ID: " << item.first << "\n";
            cout << "Description: " << item.second.getDescription() << "\n";
            cout << "Status: " << (item.second.getStatus() ? "Complete" : "Incomplete") << "\n";
            cout << "Submission Time: " << item.second.getHumanReadableSubmitTime() << "\n";
            cout << "--------------------------\n";
        }
    }

    cout << "\n\n";
    cout << "1. Add Task\n";
    cout << "2. Update Task Description\n";
    cout << "3. Update Task Status\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
    cout << "what would you like to do?\n";

}

int main() {
    TodoListItemTable currTable;
    int choice;

    while (true) {
        homeScreen(currTable);


        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore();

        if (choice == 1) {
            string desc;
            cout << "what is the description for this task:\n";
            getline(cin, desc);

            TodoListItem toAdd(false, desc, chrono::system_clock::now());
            currTable.addItem(toAdd);

        } else if (choice == 2) {
            int idToUpdate;
            while (true) {
                try {
                    if (currTable.isEmpty()) {
                        cout << "Cannot edit task list since there are no items in the list. Please add item first.\n";
                    } else {
                        cout << "Enter task id that you'd like to edit:\n";

                       if (!(cin >> idToUpdate)) {
                           cout << "Invalid input for updating ID\n";
                           cin.clear();
                           cin.ignore(numeric_limits<streamsize>::max(), '\n');
                           continue;;
                       }

                        cin.ignore();

                        if (!currTable.itemFound(idToUpdate)) {
                            cout << "ID does not exsists in the current tasks list\n";
                            continue;
                        }

                        string updatedDescription;
                        cout << "please enter updated description:\n";
                        getline(cin, updatedDescription);

                        currTable.updateItemDescription(idToUpdate, updatedDescription);
                        cout << "Task description updated successfully!\n!";
                        break;
                    }
                } catch(const runtime_error &error) {
                    cout << error.what() << "Invalid entry. Please try again.\n";
                }
            }
        } else if (choice == 3) {
            int idToChangeStatus;
            while (true) {
                try {
                    cout << "Which id would you like to change the status to?\n";
                    cin >> idToChangeStatus;

                    if (!(cin >> idToChangeStatus)) {
                        cout << "Invalid input for updating ID\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }

                    cin.ignore();

                    currTable.updateItemStatus(idToChangeStatus);
                    cout << "Task status updated successfully!\n";
                    break;
                } catch(runtime_error &error) {
                    cout << error.what() << "Invalid entry. Please try again.\n";
                }
            }
        } else if (choice == 4) {
            int idToRemove;
            while (true) {
                try {
                    cout << "What id would you like to remove?\n";
                    cin >> idToRemove;

                    if (!(cin >> idToRemove)) {
                        cout << "Invalid inout for removing ID\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }

                    cin.ignore();

                    currTable.removeItem(idToRemove);
                    cout << "Task removed successfully!\n";
                    break;
                } catch(runtime_error &error) {
                    cout << error.what() << "Invalid entry. Please try again!\n";
                }
            }
        } else if (choice == 5) {
            cout << "Make sure to finish your tasks!\n";
            break;
        }
        else {
            cout << "Invalid input, please enter a valid choice from choices below:\n";
        }
    }
}
