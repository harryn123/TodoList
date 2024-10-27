#include "TodoListItemTable.h"
#include <chrono>
#include <iostream>

using namespace std;

bool TodoListItemTable::itemFound(const string& itemDescription) const {
    for (const auto& item : todoListTable) {
        if (item.getDescription() == itemDescription) {
            return true;
        }
    }
    return false;
}

bool TodoListItemTable::addItem(const TodoListItem &itemToAdd) {
    string itemDescription = itemToAdd.getDescription();
    if (itemFound(itemDescription)) {
        cout << "Error: this task has already been added to your list for the time being: " << itemDescription << "\n";
        return false;
    } else {
        todoListTable.push_back(itemToAdd);
    }

    return true;
}

void TodoListItemTable::removeItem(const TodoListItem &itemToRemove) {
    if (todoListTable.empty()) {
        cout << "Error: there are no items in your todo list, please add item first then try to remove: " << "\n";
        return;
    } else {
        // we can search through the vector to remove the item with the same id as the item that was passed:
        for (auto item = todoListTable.begin(); item != todoListTable.end(); ) {
            if (item -> getId() == itemToRemove.getId()) {
                item = todoListTable.erase(item);
            }
            else {
                item++;
            }
        }
    }
}

void TodoListItemTable::updateItem(TodoListItem &itemToUpdate) {
    if (todoListTable.empty()) {
        cout << "Error: Your table is empty. Please add items before you want to update them: " << "\n";
        return;
    } else {
        // we need to search through and find the item we are looking for:
        for (auto item = todoListTable.begin(); item != todoListTable.end(); ++item) {
            *item = itemToUpdate;
            cout << "Successfully updated item: " << item->getId() << " \n";
            return;
        }
    }

    cout << "Error: Item not found in the todo list. Item ID: " << itemToUpdate.getId() << " \n";

}
