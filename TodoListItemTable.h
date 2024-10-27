#ifndef LISTITEMTABLE_H

#define LISTITEMTABLE_H

#include "TodoListItem.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class TodoListItemTable {
private:
    vector<TodoListItem> todoListTable;     // this is used for private data members

public:
    TodoListItem getItem(int itemId);

    bool addItem(const TodoListItem &itemToAdd);

    void removeItem(const TodoListItem &itemToRemove);

    void updateItem(TodoListItem &itemToUpdate);

private:
    bool itemFound(const string &itemDescription) const;    // this is used for helper functions



};

#endif
