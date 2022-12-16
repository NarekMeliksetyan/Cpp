#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "head.hpp"

class Computer : public Device
{
public:
    Computer(size_t address) : Device(address) {}

    void find_servers(Call *call, Answer *answer)
    {
        call->insert(address_);
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
