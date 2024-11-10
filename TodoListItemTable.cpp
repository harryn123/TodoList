#include "TodoListItemTable.h"
#include <chrono>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

using namespace std;


const unordered_map<int,TodoListItem> TodoListItemTable::getItems() const {
    // iterate through the map and get the items:
    return todoListTable;
}

TodoListItem TodoListItemTable::getItem(int itemId) {
    // check if the item is in the todoListItemTable
    if (itemFound(itemId)) {
        return todoListTable[itemId];
    } else {
        throw runtime_error("Error: Task ID not found in your todo list\n");
   }
}

bool TodoListItemTable::itemFound(const int keyToSearch) const {
    return todoListTable.find(keyToSearch) != todoListTable.end();
}

int TodoListItemTable::getMaxId() const {
    // returns the highest id that we have seen so far:
    int maxId = -1;
    for (auto &data : todoListTable) {
        if (data.first > maxId) {
            maxId = data.first;
        }
    }
    return maxId;
}

void TodoListItemTable::addItem(const TodoListItem &itemToAdd) {
    // find the max id we have so far:
    int currId;

    if (todoListTable.empty()) {
        currId = 1;
        maxId = 1;
    } else {
        currId = maxId + 1;
        maxId++;
    }

    // add the item:
    todoListTable[currId] = itemToAdd;


}

void TodoListItemTable::removeItem(const int itemId) {
    if (todoListTable.empty() || !itemFound((itemId))) {
        if (todoListTable.empty()) {
            throw runtime_error("Error: Table is currently empty. Please add tasks before trying to delete.\n");
        }

        if (!itemFound(itemId)) {
            throw runtime_error("Error: Given ID doesn't exsists in your tasks at the moment. Please add it.\n");
        }

    } else {
        todoListTable.erase(itemId);
    }
}

void TodoListItemTable::updateItemDescription(const int itemId, string updatedDescription) {
    if (todoListTable.empty()) {
        throw runtime_error("Error: Table is currently empty. Please add tasks before trying to delete.\n");
    }
    if (!itemFound(itemId)) {
        throw runtime_error("Error: Given ID doesn't exsists in your tasks at the moment. Please add it.\n");
    } else {
        todoListTable[itemId].setDescription(updatedDescription);
    }
}

void TodoListItemTable::updateItemStatus(const int itemId) {
    if (todoListTable.empty()) {
        throw runtime_error("Error: Table is currently empty. Please add tasks before trying to delete.\n");
    }

    if (!itemFound(itemId)) {
        throw runtime_error("Error: Given ID doesn't exsists in your tasks at the moment. Please add it.\n");
    }
    else {
        todoListTable[itemId].setStatus(!todoListTable[itemId].getStatus());
    }
}

bool TodoListItemTable::isEmpty() {
    return todoListTable.empty();
}

