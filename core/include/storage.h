#ifndef STORAGE_H
#define STORAGE_H

#include <map>
#include "component.h"
#include "entity.h"
#include "identifier.h"
#include "iterator.h"

namespace strife {
    namespace core {
        
        class IStorage {
        
        public:
            
            IStorage() = default;
            virtual ~IStorage() = default;
            
            virtual Component& add(const Entity entity) = 0;
            virtual void remove(const Entity entity) = 0;
            virtual Component& get(const Entity entity) = 0;
            
        };
        
        template <class C>
        class Storage : public IStorage {
            
        public:
        
            class Iterator : public common::IIterator<Iterator, std::pair<const Entity, C&>> {
                
            public:
            
                Iterator(typename std::map<Entity, C>::iterator iterator)
                    : iterator_(iterator) {}
                ~Iterator() = default;
                
                Iterator& operator++() {
                    iterator_++;
                    return *this;
                }
                
                Iterator& operator++(int) {
                    ++iterator_;
                    return *this;
                }
                
                bool operator==(const Iterator& iterator) const {
                    return iterator_ == static_cast<const Iterator&>(iterator).iterator_;
                }
                
                bool operator!=(const Iterator& iterator) const {
                    return iterator_ != static_cast<const Iterator&>(iterator).iterator_;
                }
                
                std::pair<const Entity, C&> operator*() const {
                    return {iterator_->first, iterator_->second};
                }
                
            private:
            
                typename std::map<Entity, C>::iterator iterator_;
                
            };
            
        public:
        
            Storage()
                : IStorage() {}
            ~Storage() = default;
            
            C& add(const Entity entity) {
                return components_.emplace(entity, entity).first->second;
            }
            
            void remove(const Entity entity) {
                components_.erase(entity);
            }
            
            C& get(const Entity entity) {
                return components_.at(entity);
            }
            
            Iterator begin() {
                auto mapIterator = components_.begin();
                return Iterator(mapIterator);
            }
            
            Iterator end() {
                auto mapIterator = components_.end();
                return Iterator(mapIterator);
            }
            
        private:
            
            std::map<Entity, C> components_;
        
        };
        
    }
}

#endif