#pragma once

#include <functional>
#include <set>
#include "dispatcher.h"
#include "events.h"
#include "scene.h"

namespace strife {
    namespace core {
        
        class ISystem {
            
        public:
        
            ISystem() = default;
            virtual ~ISystem() = default;
            
            virtual void subscribe(common::Dispatcher& dispatcher) = 0;
            virtual void unsubscribe(common::Dispatcher& dispatcher) = 0;
            
        };
        
        template <class C>
        class System : public ISystem {
            
        public:
        
            System()
                : ISystem()
                , scene_(nullptr) {};
            ~System() = default;
            
            void subscribe(common::Dispatcher& dispatcher) {
                dispatcher.subscribe<SceneSwapEvent>(std::bind(&System::onSceneSwap, this, std::placeholders::_1));
            }
            
            void unsubscribe(common::Dispatcher& dispatcher) {
                dispatcher.unsubscribe<SceneSwapEvent>(std::bind(&System::onSceneSwap, this, std::placeholders::_1));
            }
            
        private:
            
            Scene* scene_;
            
            void onSceneSwap(const SceneSwapEvent& sceneSwapEvent) {
                scene_ = sceneSwapEvent.to;
            }
            
        };
        
    }
}