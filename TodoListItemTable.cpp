#include "TodoListItemTable.h"
#include <vector>
#include <algorithm>

using namespace std;


bool itemFound() {
    return false;
}


bool TodoListItemTable::addItem(const TodoListItem &itemToAdd) {
    if (itemFound(itemToAdd.getDescription())) {

    }
}
