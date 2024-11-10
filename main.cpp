#include "TodoListItem.h"
#include "TodoListItemTable.h"
#include <cstdlib>
#include <string>
#include <chrono>
#include <iostream>
using namespace std;


void homeScreen(const TodoListItemTable &currTable) {
    cout << "\n---- Welcome to your TodoList ----\n";

    // print out the current todo list:

    const auto& tasks =currTable.getItems();
    if (tasks.empty()) {
        cout << "TodoList is empty. Please start by adding a task\n";
    } else {
        cout << "\n---- Current tasks ----\n";
        for (const auto &item : tasks) {
            cout << "ID: " << item.getId() << "\n";
            cout << "Description: " << item.getDescription() << "\n";
            cout << "Status: " << (item.getStatus() ? "Complete" : "Incomplete") << "\n";
            cout << "Submission Time: " << item.getHumanReadableSubmitTime() << "\n";
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
        cin >> choice;

        if (choice == 1) {
            string desc;
            int id;

            cout << "set the id for this task:\n";
            cin >> id;
            cin.ignore();
            cout << "what is the description for this task:\n";
            getline(cin, desc);
            TodoListItem toAdd(id, false, desc, chrono::system_clock::now());
            currTable.addItem(toAdd);
        } else if (choice == 2) {
            int idToUpdate;
            if (currTable.getTableSize() == 0) {
                cout << "Cannot edit task list since there are no items in the list. Please add item first.\n";
            } else {
                cout << "Enter task id that you'd like to edit:\n";
                cin >> idToUpdate;
                cin.ignore();
                string updatedDescription;
                cout << "please enter updated description:\n";
                getline(cin, updatedDescription);

                TodoListItem itemToUpdate = currTable.getItem(idToUpdate);
                itemToUpdate.setDescription(updatedDescription);
                currTable.updateItem(itemToUpdate);

            }
        } else if (choice == 3) {
            int idToChangeStatus;
            cout << "Which id would you like to change the status to?\n";
            cin >> idToChangeStatus;
            cin.ignore();

            TodoListItem itemToUpdate = currTable.getItem(idToChangeStatus);
            itemToUpdate.setStatus(!itemToUpdate.getStatus());
            currTable.updateItemStatus(itemToUpdate);

        } else if (choice == 4) {
            int idToRemove;
            cout << "What id would you like to remove?\n";
            cin >> idToRemove;
            TodoListItem itemToRemove = currTable.getItem(idToRemove);
            currTable.removeItem(itemToRemove);
        } else if (choice == 5) {
            cout << "Make sure to finish your tasks!\n";
            break;
        }
        else {
            cout << "Invalid input, please enter a valid choice from choices below:\n";
        }
    }
}
