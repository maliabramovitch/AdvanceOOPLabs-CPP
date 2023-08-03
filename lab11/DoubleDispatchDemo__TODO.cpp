#include <iostream>
#include <list>
#include <iterator>
#include <cstdlib>      // for random number generation
#include <memory>

using namespace std;

// Forward declaration of Processor
class Processor;

/* The base class of Events containing a send-yourself virtual function
 and a static counter to give each event an id number
 It uses std::enabled_shared_from_this to enable accept(this)
 */
class Event { //: public enable_shared_from_this<Event> {
public:
    Event() : id(++count) {}

    virtual void accept(shared_ptr<Processor>) {}

    int get_id() { return id; }

private:
    int id;
    static int count;
};

int Event::count = 0;    // the static counter

// Two concrete classes of Events
class ConcreteEventA : public Event, public enable_shared_from_this<ConcreteEventA> {
public:
    virtual void accept(shared_ptr<Processor> p) override;
};

class ConcreteEventB : public Event, public enable_shared_from_this<ConcreteEventB> {
public:
    virtual void accept(shared_ptr<Processor>) override;
};

/* The Processor base class has virtual functions overloaded to handle each type of element. */
class Processor {
/* TODO1: define the necessary within Visitor */
public:
    virtual void compute_event(const shared_ptr<ConcreteEventA> &event) = 0;

    virtual void compute_event(const shared_ptr<ConcreteEventB> &event) = 0;

};

/* TODO2: derive a concrete Visitor */
class ConcreteProcessorA : public Processor {
    void compute_event(const shared_ptr<ConcreteEventA> &event) override {
        cout << "ConcreteProcessorA for ConcreteEventA" << " id: " << event->get_id() << endl;
    }

    void compute_event(const shared_ptr<ConcreteEventB> &event) override {
        cout << "ConcreteProcessorA for ConcreteEventB" << " id: " << event->get_id() << endl;
    }
};

/* TODO3: derive another concrete Visitor */
class ConcreteProcessorB : public Processor {
    void compute_event(const shared_ptr<ConcreteEventA> &event) override {
        cout << "ConcreteProcessorB for ConcreteEventA" << " id: " << event->get_id() << endl;
    }

    void compute_event(const shared_ptr<ConcreteEventB> &event) override {
        cout << "ConcreteProcessorB for ConcreteEventB" << " id: " << event->get_id() << endl;
    }
};


// Event self-dispatch.
void ConcreteEventA::accept(shared_ptr<Processor> p) {
    // send this event to the designated processor
    shared_ptr<ConcreteEventA> sp_this = shared_from_this();
    p->compute_event(sp_this);
}

// Event self-dispatch
void ConcreteEventB::accept(shared_ptr<Processor> p) {
    // send this event to the designated processor
    shared_ptr<ConcreteEventB> sp_this = shared_from_this();
    p->compute_event(sp_this);
}


const int NEVENTS = 10;

void fill_event_list(list<shared_ptr<Event>> &events);

int main(void) {

    /* TODO4: simulate the Double-Dispatch of Processors + Events */
    list<shared_ptr<Event>> events;
    shared_ptr<Processor> pa = make_shared<ConcreteProcessorA>();
    shared_ptr<Processor> pb = make_shared<ConcreteProcessorB>();
    fill_event_list(events);
    for (auto &event: events) {
        event->accept(pa);
        event->accept(pb);
    }

    return 0;
}

// create a series of events, randomly chosen by type
void fill_event_list(list<shared_ptr<Event>> &events) {
    for (int i = 0; i < NEVENTS; i++) {
        if (static_cast<double>(rand()) / RAND_MAX < .5)    // flip a coin
            events.push_back(make_shared<ConcreteEventA>());
        else
            events.push_back(make_shared<ConcreteEventB>());
    }
}