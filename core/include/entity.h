#pragma once

#include <typeindex>
#include "unique.h"

namespace strife {
    namespace core {
        
        class Scene;
        class Component;
        
        class Entity : public common::Unique {
            
        private:
            
            class Components {
                
            public:
            
                Components(Entity& entity);
                ~Components() = default;
                
                Component& add(const std::type_index type);
				void remove(const std::type_index type);
				Component& get(const std::type_index type) const;
				
				template <class C>
				C& add() {
					const std::type_index type(typeid(C));
					Component& component = add(type);
					return static_cast<C&>(component);
				};
				
				template <class C>
				void remove() {
					const std::type_index type(typeid(C));
					remove(type);
				};
				
				template <class C>
				C& get() const {
					const std::type_index type(typeid(C));
					Component& component = get(type);
					return static_cast<C&>(component);
				};
                
            private:
            
                Entity& entity_;
                
            };
            
        public:
        
            Scene& scene;
            Components components;
        
            Entity(const Entity& entity);
			Entity(Scene& scene);
			~Entity() = default;
			
			bool operator==(const Entity& entity) const;
			bool operator!=(const Entity& entity) const;
            
            void destroy();
            
        };
        
    }
}