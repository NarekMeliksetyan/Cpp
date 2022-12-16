#ifndef DEVICE_HPP
#define DEVICE_HPP

#include "head.hpp"

class Device
{
protected:
    size_t address_;
    size_t connNbr_;
    vector<Device *> connections_;

public:
    Device(size_t address)
    {
        connNbr_ = 0;
        address_ = address;
    }

    virtual ~Device()
    {
        connections_.clear();
    }

    virtual size_t address()
    {
        return address_;
    }

    virtual size_t connNbr()
    {
        return connNbr_;
    }

    virtual vector<Device *> connections()
    {
        return connections_;
    }

    virtual void connect(Device *devc)
    {
        connections_.push_back(devc);
        connNbr_++;
    }

    virtual bool connected(Device *devc)
    {
        for (auto conn : connections_)
            if (conn->address() == devc->address())
            {
                return true;
            }
        return false;
    }

    virtual void findServers(Call *call, Answer *answer) {}
};

#endif
