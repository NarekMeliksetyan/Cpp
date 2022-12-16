#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "head.hpp"

class Switch : public Device
{
private:
    size_t calls_;

public:
    Switch(size_t address) : Device(address)
    {
        calls_ = 0;
    }

    virtual size_t calls()
    {
        return calls_;
    }

    void add_call()
    {
        calls_++;
    }

    virtual void find_servers(Call *call, Answer *answer)
    {
        call->insert(address_);
        add_call();
        for (auto conn : connections())
        {
            if (call->have(conn->address()))
            {
                continue;
            }
            cout << " -> " << conn->address();
            call->insert(conn->address());
            conn->findServers(call, answer);
        }
    }
};

#endif
