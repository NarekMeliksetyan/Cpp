#ifndef SERVER_HPP
#define SERVER_HPP

#include "head.hpp"

class Server : public Device
{
private:
    string name_;

public:
    Server(string name, size_t address) : Device(address)
    {
        name_ = name;
        address = address;
    }

    string name()
    {
        return name_;
    }

    void find_servers(Call *call, Answer *answer)
    {
        call->insert(address_);
        answer->insert(name_);
        cout << " -> " << name_;
    }
};

#endif
