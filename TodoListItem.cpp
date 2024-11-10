#include "TodoListItem.h"
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;

// Default constructor
TodoListItem::TodoListItem()
    : id(0), complete(false), description(""), inputDateTime(chrono::system_clock::now()) {}

// Overloaded constructor
TodoListItem::TodoListItem(int currId, bool currStatus, const string &currDesc, chrono::system_clock::time_point currTime)
    : id(currId), complete(currStatus), description(currDesc), inputDateTime(currTime) {}

// Destructor
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

string TodoListItem::getHumanReadableSubmitTime() const {
    time_t submissionTime = chrono::system_clock::to_time_t(inputDateTime);

    // need to convert to local time:
    tm *local = localtime(&submissionTime);

    // read that this should display into human redable
    ostringstream readableTime;
    readableTime << put_time(local,"%Y-%m-%d %H:%M:%S");

    return readableTime.str();

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
