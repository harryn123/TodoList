#ifndef LISTITEM_H
#define LISTITEM_H

#include <string>
#include <chrono>

using namespace std;


class TodoListItem {
private:
    int id;
    bool complete;
    string description;
    chrono::system_clock::time_point inputDateTime;

public:
    TodoListItem();

    TodoListItem(int currId, bool currStatus,  const string &currDesc, chrono::system_clock::time_point currTime);

    ~TodoListItem();

    int getId() const;

    bool getStatus() const;

    string getDescription() const;

    chrono::system_clock::time_point getSubmissionTime();

    string getHumanReadableSubmitTime() const;

    void setId(int currId);

    void setStatus(bool currStatus);

    void setDescription(string currDescription);

    void setInputDateTime(chrono::system_clock::time_point currSubmitTime);
};

#endif
