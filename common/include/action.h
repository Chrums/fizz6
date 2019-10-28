#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <functional>
#include <vector>

namespace strife {
    namespace common {
        
        template <class T>
        class Action {
            
        public:
        
            Action() = default;
            ~Action() = default;
            
            template <class U>
            void operator+=(U&& callback)
            {
                int address = (int)callback;
                std::cout << address << std::endl;
                callbacks_.push_back(std::forward<U>(callback));
            }
            
            template <class U>
            void operator-=(U&& callback)
            {
                // TODO: Implement this...
            }
            
            template <class ... Args>
            void operator()(Args&&... args) const{
                for (const std::function<T>& callback : callbacks_) {
                    callback(args...);
                }
            }
            
        private:
        
            std::vector<std::function<T>> callbacks_;
            
        };
        
    }
}

#endif