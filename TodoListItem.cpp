#include "TodoListItem.h"
#include <string>
#include <chrono>


using namespace std;


// we need a default constructor:
TodoListItem::TodoListItem(): id(0), complete(false), description(""), inputDateTime(chrono::system_clock::now()) {}

// overloaded constructor
TodoListItem::TodoListItem(int currId, bool currStatus,  string &currDesc, chrono::system_clock::time_point &currTime):
    id(currId), complete(currStatus), description(currDesc), inputDateTime(currTime) {}

// descructor?
TodoListItem::~TodoListItem() {}

// getters and setters?
int TodoListItem::getId() const {
    return id;
}

bool TodoListItem::getStatus() const {
    return complete;
}

string TodoListItem::getDescription() const{
    return description;
}

chrono::system_clock::time_point TodoListItem::getSubmissionTime() {
    return inputDateTime;
}

void TodoListItem::setId(int currId) {
    id = currId;
}

void TodoListItem::setStatus(bool currStatus) {
    complete = currStatus;
}

void TodoListItem::setDescription(string currDescription) {
    description = currDescription;
}

void TodoListItem::setInputDateTime(chrono::system_clock::time_point currSubmitTime) {
    inputDateTime = currSubmitTime;
}
