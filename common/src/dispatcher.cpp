#include "dispatcher.h"

using namespace strife::common;
using namespace std;

void Dispatcher::emit(const Event& event) {
    const type_index type(typeid(event));
    vector<Callback<Event>> callbacks = callbacks_[type];
    for (Callback<Event> callback : callbacks) {
        callback(event);
    }
}