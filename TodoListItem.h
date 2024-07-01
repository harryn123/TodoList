#ifndef LISTITEM_H
#endif
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

        TodoListItem(int currId, bool currStatus,  string &currDesc, chrono::system_clock::time_point &currTime);

        ~TodoListItem();

        int getId();

        bool getStatus();

        string getDescription();

        chrono::system_clock::time_point getSubmissionTime();

        void setId(int currId);

        void setStatus(bool currStatus);

        void setDescription(string currDescription);

        void setInputDateTime(chrono::system_clock::time_point currSubmitTime);
};

