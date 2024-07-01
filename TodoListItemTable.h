#ifndef LISTITEMTABLE
#endif // !LISTITEMTABLE

#include "TodoListItem.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class TodoListItemTable {
    private:
        vector<TodoListItem> todoListTable;
    public:
        TodoListItem getItem(int itemId);

        bool addItem(const TodoListItem &itemToAdd);

        void removeItem(TodoListItem);
};

