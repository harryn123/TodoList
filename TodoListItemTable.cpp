#include "TodoListItemTable.h"
#include <chrono>
#include <iostream>
#include <stdexcept>

using namespace std;


const vector<TodoListItem> TodoListItemTable::getItems() const {
    return todoListTable;
}

TodoListItem TodoListItemTable::getItem(int itemId) {
    // iterate through and check if the id is in our table:
    for (const auto& item : todoListTable) {
        if (item.getId() == itemId) {
            return item;
        }
    }

    throw runtime_error("item id not found in your todo list\n");
}

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
        for (auto& item : todoListTable) {
            if (item.getId() == itemToUpdate.getId()) {
                item.setDescription(itemToUpdate.getDescription());
                cout << "Successfully updated item: " << item.getId() << " \n";
                return;
            }
        }
    }

    cout << "Error: Item not found in the todo list. Item ID: " << itemToUpdate.getId() << " \n";

}

void TodoListItemTable::updateItemStatus(TodoListItem &itemToUpdateStatus) {
    if (todoListTable.empty()) {
        cout << "Error: Your table is empty. Please add items before you want to update them: " << "\n";
        return;
    } else {
        for (auto& item : todoListTable) {
            if (item.getId() == itemToUpdateStatus.getId()) {
                item.setStatus(!item.getStatus());
                cout << "Successfully updated status of item:  " << item.getId() << "\n";
                return;
            }
        }
    }
}


int TodoListItemTable::getTableSize() {
    return todoListTable.size();
}
