#ifndef ACTION_H
#define ACTION_H

#include <functional>

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
                callbacks_.emplace_back(std::forward<U>(callback));
            }
            
            template <class U>
            void operator-=(U&& callback)
            {
                // TODO: Implement this...
            }
            
            template <class ... Args>
            void operator()(Args&&... args) const{
                for(std::function<T>& callback : callbacks_) {
                    callback(args...);
                }
            }
            
        private:
        
            std::vector<std::function<T>> callbacks_;
            
        };
        
    }
}

#endif