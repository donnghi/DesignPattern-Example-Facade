#include <iostream>
#include <memory>
#include <string>

using namespace std;

class IButton
{
protected:
    string state;
public:
    IButton() = default;
    virtual ~IButton() {};
    virtual void commingHome() = 0;
    virtual void goingOut() = 0;
    virtual void print() = 0;
};
class TV : public IButton
{
public:
    TV(string s) {state = s;}
    virtual ~TV() {};
    void commingHome() override
    {
        state = "TV is ON";
    }
    void goingOut() override
    {
        state = "TV is OFF";
    }
    void print() override
    {
        cout << state << endl;
    }
};
class Computer : public IButton
{
public:
    Computer(string s) {state = s;}
    virtual ~Computer() {};
    void commingHome()
    {
        state = "Computer is ON";
    }
    void goingOut()
    {
        state = "Computer is OFF";
    }
    void print() override
    {
        cout << state << endl;
    }
};
class Cuisine : public IButton
{
public:
    Cuisine(string s) {state = s;}
    virtual ~Cuisine() {};
    void commingHome()
    {
        state = "Cuisine is ON";
    }
    void goingOut()
    {
        state = "Cuisine is OFF";
    }
    void print() override
    {
        cout << state << endl;
    }
};
class Alarm : public IButton
{
public:
    Alarm(string s) {state = s;}
    virtual ~Alarm() {};
    void commingHome()
    {
        state = "Alamr is OFF";
    }
    void goingOut()
    {
        state = "Alarm is ON";
    }
    void print() override
    {
        cout << state << endl;
    }
};

class FacadePattern : public IButton
{
protected:
    unique_ptr<IButton> tv;
    unique_ptr<IButton> cpu;
    unique_ptr<IButton> kitchen;
    unique_ptr<IButton> alarm;
public:
    FacadePattern(string tv, string cpu, string kitchen, string alarm) :
            tv(make_unique<TV>(tv)), cpu(make_unique<Computer>(cpu)), kitchen(make_unique<Cuisine>(kitchen)), alarm(make_unique<Alarm>(alarm))
    {}
    FacadePattern() = default;
    virtual ~FacadePattern(){};
    void commingHome() override 
    {
        tv->commingHome();
        cpu->commingHome();
        kitchen->commingHome();
        alarm->commingHome();
    }
    void goingOut() override
    {
        tv->goingOut();
        cpu->goingOut();
        kitchen->goingOut();
        alarm->goingOut();
    }
    void print() override
    {
        tv->print();
        cpu->print();
        kitchen->print();
        alarm->print();
    }
};

int main() {
    FacadePattern facade("uuu", "xxx", "yyy", "zzz");

    cout << "Initialize" << endl;
    facade.print();

    cout << "Going out" << endl;
    facade.goingOut();
    facade.print();

    cout << "Comming home" << endl;
    facade.commingHome();
    facade.print();

    return 0;
}