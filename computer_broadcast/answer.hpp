#ifndef ANSWER_HPP
#define ANSWER_HPP

#include "head.hpp"

class Answer : public Call
{
private:
    set<string> servers_;

public:
    Answer() : Call() {}

    ~Answer()
    {
        servers_.clear();
    }

    bool have(string serv)
    {
        if (servers_.count(serv))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(string serv)
    {
        servers_.insert(serv);
    }

    void clear()
    {
        servers_.clear();
    }

    set<string> servers()
    {
        return servers_;
    }
};

#endif
