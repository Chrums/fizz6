#ifndef SCENE_H
#define SCENE_H

#include <map>
#include <set>
#include <typeindex>
#include "storage.h"
#include "unique.h"

namespace strife {
    namespace core {
        
        class Scene : public common::Unique {
            
        public:
        
            class Entities {
                
            public:
            
                Entities(Scene& scene);
                ~Entities() = default;
                
                const Entity add();
                void remove(const Entity entity);
                
            private:
            
                Scene& scene_;
                std::set<Entity> entities_;
                
            };
            
            class Components {
                
                friend class Entity;
                
            public:
            
                Components(Scene& scene);
                ~Components();
                
                template <class C>
                Storage<C>& initialize() {
                    std::type_index type(typeid(C));
                    Storage<C>* const storage = new Storage<C>();
                    components_.insert({type, storage});
                    return *storage;
                }
                
                template <class C>
                C& add(const Entity entity) {
                    std::type_index type(typeid(C));
                    Component& component = add(type, entity);
                    return static_cast<C&>(component);
                }
                
                template <class C>
                void remove(const Entity entity) {
                    std::type_index type(typeid(C));
                    remove(type, entity);
                }
                
                template <class C>
                C& get(const Entity entity) const {
                    std::type_index type(typeid(C));
                    Component& component = get(type, entity);
                    return static_cast<C&>(component);
                }
                
                template <class C>
                Storage<C>& get() const {
                    std::type_index type(typeid(C));
                    IStorage& storage = get(type);
                    return static_cast<Storage<C>&>(storage);
                }
                
            private:
            
                Scene& scene_;
                std::map<const std::type_index, IStorage* const> components_;
                
                Component& add(const std::type_index type, const Entity entity);
                void remove(const std::type_index type, const Entity entity);
                IStorage& get(const std::type_index type) const;
                Component& get(const std::type_index type, const Entity entity) const;
                
            };
            
        public:
            
            Entities entities;
            Components components;
            
            Scene();
            ~Scene() = default;
            
        };
        
    }
}

#endif