#include "event.h"

using namespace strife::core;
using namespace strife::common;
using namespace std;

Event::Event()
    : common::Message()
    , target(nullopt) {}
    
Event::Event(const Entity target)
    : common::Message()
    , target(target) {}