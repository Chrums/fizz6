#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <boost/uuid/uuid.hpp>

namespace strife {
    namespace common {
        
        using Identifier = boost::uuids::uuid;
        
    }
}

#endif