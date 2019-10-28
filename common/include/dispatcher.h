#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <functional>
#include <map>
#include <typeindex>
#include <vector>
#include "event.h"

namespace strife {
    namespace common {
        
        class Dispatcher {
            
        public:
        
            template <class E>
            using Callback = std::function<void (const E&)>;
            
        protected:
            
            template <class E>
            class Binding {
            
            public:
            
                Binding(Callback<E> callback)
                    : callback_(callback) {}
                ~Binding() = default;
                    
                void operator()(const Event& event) {
                    callback_(static_cast<const E&>(event));
                }
                
            private:
            
                Callback<E> callback_;
            
            };
            
        public:
        
            Dispatcher() = default;
            ~Dispatcher() = default;
        
            void emit(const Event& event);
            
            template <class E>
            void subscribe(Callback<E> callback) {
                const std::type_index type(typeid(E));
                std::vector<Callback<Event>>& callbacks = callbacks_[type];
                Binding<E> binding(callback);
                callbacks.push_back(binding);
            }
            
            template <class E>
            void unsubscribe(Callback<E> callback) {
                const std::type_index type(typeid(E));
                // TODO: Implement this...
            }
            
		private:
		
			std::map<const std::type_index, std::vector<Callback<Event>>> callbacks_;
            
        };
        
    }
}

#endif