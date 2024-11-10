#ifndef LISTITEMTABLE_H

#define LISTITEMTABLE_H

#include "TodoListItem.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;


class TodoListItemTable {
private:
    // changing todolisttable to be a map for much faster lookup times.
    unordered_map<int, TodoListItem> todoListTable;
    int maxId;

public:
    TodoListItem getItem(int itemId);

    void addItem(const TodoListItem &itemToAdd);

    void removeItem(const int itemId);

    void updateItemDescription(const int itemId, string updatedDescription);

    void updateItemStatus(const int itemId);

    const unordered_map<int, TodoListItem> getItems() const;

    bool isEmpty();

    bool itemFound(const int keyToSearch) const;    // this is used for helper functions
private:
    int getMaxId() const;
};

#endif
