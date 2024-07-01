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
int TodoListItem::getId() {
    return this->id;
}

bool TodoListItem::getStatus() const {
    return complete;
}

string TodoListItem::getDescription() {
    return this->description;
}

chrono::system_clock::time_point TodoListItem::getSubmissionTime() {
    return this->inputDateTime;
}

void TodoListItem::setId(int currId) {
    this->id = currId;
}

void TodoListItem::setStatus(bool currStatus) {
    this->complete = currStatus;
}

void TodoListItem::setDescription(string currDescription) {
    this->description = currDescription;
}

void TodoListItem::setInputDateTime(chrono::system_clock::time_point currSubmitTime) {
    this->inputDateTime = currSubmitTime;
}
