#ifndef NETW0RK_HPP
#define NETW0RK_HPP

#include "head.hpp"

class Network : public Device
{
private:
    size_t compNbr_;
    size_t switchNbr_;
    size_t servNbr_;
    size_t compMaxConn_;
    size_t swtchMaxConn_;
    size_t servMaxConn_;
    set<int> checked_;

    vector<Computer *> computers_;
    vector<Switch *> switches_;
    vector<Server *> servers_;

    Call *call_;
    Answer *ans_;

public:
    Network(
        size_t compNbr,
        size_t switchNbr,
        size_t servNbr,
        size_t compMaxConn,
        size_t swtchMaxConn,
        size_t servMaxConn) : Device(address_)
    {
        address_ = 0;
        compNbr_ = compNbr;
        switchNbr_ = switchNbr;
        servNbr_ = servNbr;
        compMaxConn_ = compMaxConn;
        swtchMaxConn_ = swtchMaxConn;
        servMaxConn_ = servMaxConn;

        call_ = new Call;
        ans_ = new Answer();

        initDevices();
        randomConnect();
    }

    ~Network()
    {
        for (auto comp : computers_)
        {
            delete comp;
        }
        for (auto swtch : switches_)
        {
            delete swtch;
        }
        for (auto serv : servers_)
        {
            delete serv;
        }

        delete call_;
        delete ans_;
    }

    void initDevices()
    {
        size_t i = 0;
        vector<string> names = {"tiktok", "faceapp", "snapchat"};

        while (computers_.size() < compNbr_)
        {
            Computer *comp = new Computer(address_++);
            computers_.push_back(comp);
        }
        while (switches_.size() < switchNbr_)
        {
            Switch *swtch = new Switch(address_++);
            switches_.push_back(swtch);
        }
        while (servers_.size() < servNbr_)
        {
            string name;
            if (i < 3)
            {
                Server *serv = new Server(names[i], address_++);
                servers_.push_back(serv);
            }
            else
            {
                cout << "Enter server name: ";
                cin >> name;
                Server *serv = new Server(names[i], address_++);
                servers_.push_back(serv);
            }
            i++;
        }
        cout << endl;
    }

    void randomConnect()
    {
        cout << "Connecting" << endl;
        randomServerConnect();
        randomComputerConnect();
        randomSwitchConnect();
        cout << endl;
    }

    void randomComputerConnect()
    {
        cout << "Computers: ";
        size_t i = 0;

        for (auto comp : computers_)
        {
            cout << ".";
            if (comp->connNbr() >= compMaxConn_)
            {
                continue;
            }
            i = rand() % switchNbr_;
            while (switches_[i]->connNbr() >= swtchMaxConn_ - 1)
            {
                i = rand() % switchNbr_;
            }
            connect(comp, switches_[i]);
        }
        cout << " connected" << endl;
    }

    void randomSwitchConnect()
    {
        cout << "Switches ";
        size_t j = 0;

        for (size_t i = 0; i < switchNbr_; i++)
        {
            cout << ".";
            if (switches_[i]->connNbr() >= swtchMaxConn_)
            {
                continue;
            }
            j = rand() % switchNbr_;
            while (i == j || switches_[i]->connected(switches_[j]) || switches_[j]->connNbr() >= swtchMaxConn_)
            {
                j = rand() % switchNbr_;
            }
            connect(switches_[i], switches_[j]);
        }
        cout << " connected" << endl;
    }

    void randomServerConnect()
    {
        cout << "Servers ";
        size_t i = 0;

        for (auto serv : servers_)
        {
            cout << ".";
            if (serv->connNbr() >= servMaxConn_)
            {
                continue;
            }
            while (serv->connNbr() < servMaxConn_)
            {
                i = rand() % switchNbr_;
                while (serv->connected(switches_[i]) || switches_[i]->connNbr() >= 1)
                {
                    i = rand() % switchNbr_;
                }
                connect(serv, switches_[i]);
            }
        }
        cout << " connected" << endl;
    }

    size_t comp_nbr()
    {
        return compNbr_;
    }

    size_t switch_nbr()
    {
        return switchNbr_;
    }

    size_t serv_nbr()
    {
        return servNbr_;
    }

    vector<Computer *> computers()
    {
        return computers_;
    }

    vector<Switch *> switches()
    {
        return switches_;
    }

    vector<Server *> servers()
    {
        return servers_;
    }

    Call *call()
    {
        return call_;
    }

    Answer *ans()
    {
        return ans_;
    }

    void connect(Device *devc1, Device *devc2)
    {
        devc1->connect(devc2);
        devc2->connect(devc1);
    }
};

#endif
