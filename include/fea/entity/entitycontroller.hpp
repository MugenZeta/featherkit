#pragma once
#include <fea/config.hpp>
#include <unordered_map>
#include <fea/entity/entity.hpp>

namespace fea
{
    class FEA_API EntityController
    {
        public:
            void entityCreated(WeakEntityPtr entity);
            void entityRemoved(EntityId entityId);
            virtual bool keepEntity(WeakEntityPtr entity) const;
            virtual void entityKept(WeakEntityPtr entity);
            virtual void entityDropped(WeakEntityPtr entity);
            const std::unordered_map<EntityId, WeakEntityPtr>& getEntities() const;
            virtual ~EntityController();
        protected:
            std::unordered_map<EntityId, WeakEntityPtr> mEntities;
    };

    /** @addtogroup EntitySystem
     *@{
     *  @class EntityController
     *@}
     ***
     *  @class EntityController
     *  @brief Class to inherit to create entity components
     *
     *  This class is the base for creating entity components. An entity component is simply a subsystem for processing an entity in a specific way. For example, you might want a PhysicsController dealing with physics, a PlayerControlController to implement player control behavior or a CameraFollowController which makes the camera follow a specific entity.
     *
     *  Controllers are created by inheriting this class and then specializing their behavior. 
     *
     *  When entities are created and removed, all components must be notified using the EntityController::entityCreated and EntityController::entityRemoved functions.
     ***
     *  @fn void EntityController::entityCreated(WeakEntityPtr entity)
     *  @brief Let the component know that an entity has been created.
     *  
     *  This will pass the entity to the EntityController::keepEntity function and if that one returns true, the entity will be stored in EntityController::mEntities.
     *  @param entity Created entity.
     ***
     *  @fn void EntityController::entityRemoved(EntityId entityId)
     *  @brief Let the component know that an entity has been removed.
     *
     *  If the entity exists in the member variable EntityController::mEntities, then it will be removed from there.
     ***
     *  @fn virtual bool EntityController::keepEntity(WeakEntityPtr entity) const
     *  @brief Decide if an entity should be kept or not.
     *
     *  Override this function to specify which entities the component should keep track of. In the case that the entity should be kept, then it will be put in the EntityController::mEntities variable.
     *  @param entity Entity to investigate.
     *  @return True if the entity should be kept.
     ***
     *  @fn virtual void EntityController::entityKept(WeakEntityPtr entity)
     *  @brief Handle a newly kept entity.
     *
     *  Override this function to specify what the component should do with an entity that is kept.
     *  @param entity kept Entity.
     ***
     *  @fn virtual void EntityController::entityDropped(WeakEntityPtr entity)
     *  @brief Handle an entity that is dropped.
     *
     *  Override this function to specify what the component should do with an entity that is dropped.
     *  @param entity dropped Entity.
     ***
     *  @fn const std::unordered_map<EntityId, WeakEntityPtr>& EntityController::getEntities() const
     *  @brief Get the entities that this component is keeping track of.
     *  @return Map with entities.
     ***
     *  @fn virtual EntityController::~EntityController()
     *  @brief Destructor.
     ***
     *  @var EntityController::mEntities
     *  @brief Set containing all entities.
     ***/
}


