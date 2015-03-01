#pragma once
#include <fea/config.hpp>
#include <fea/ui/event.hpp>
#include <fea/ui/vec2i.hpp>
#include <queue>

namespace fea
{
    class FEA_API InputBackend
    {
        public:
            virtual std::queue<Event> fetchEvents() = 0;

            virtual bool isKeyPressed(Keyboard::Code code) = 0;

            virtual bool isMouseButtonPressed(Mouse::Button button) = 0;
            virtual Vec2I getMouseGlobalPosition() = 0;
            virtual Vec2I getMouseWindowPosition() = 0;
            virtual void setMouseGlobalPosition(int32_t x, int32_t y) = 0;
            virtual void setMouseWindowPosition(int32_t x, int32_t y) = 0;

            virtual bool isGamepadConnected(uint32_t id) = 0;
            virtual uint32_t getGamepadButtonCount(uint32_t id) = 0;
            virtual bool isGamepadButtonPressed(uint32_t id, uint32_t button) = 0;
            virtual bool gamepadHasAxis(uint32_t id, Gamepad::Axis axis) = 0;
            virtual float getGamepadAxisPosition(uint32_t id, Gamepad::Axis axis) = 0;

            virtual void setGamepadThreshold(float threshold) = 0;
            virtual void setKeyRepeatEnabled(bool enabled) = 0;
    };

    /** @addtogroup UI
     *@{
     *  @class InputBackend
     *@}
     ***
     *  @class InputBackend
     *  @brief Abstract base class for various InputBackend implementations.
     *
     *  The purpose of an InputBackend is to generate Event instances based on what input the application receives from the user. For example, if the user pushes a key on the keyboard, the backend is responsible for creating an Event of the type Event::KEYPRESSED. The InputHandler can then fetch the events generated using the fetchEvents() function. With this abstract class, it is possible to create multiple backend implementations based on different libraries or platforms. 
     *** 
     *  @fn virtual std::queue<Event> InputBackend::fetchEvents() = 0 
     *  @brief Fetch the events generated so far, emptying the internal event queue of the InputBackend. This function is called by the InputHandler that owns the InputBackend and this is how it accesses events and makes them available for the user.
     *  @return A queue with Event instances.
     ***
     *  @fn virtual bool InputBackend::isKeyPressed(Keyboard::Code code) const
     *  @brief Check if a key on the keyboard is pressed or not.
     *  @param code The key to check.
     *  @return True if the key is currently pushed down.
     ***
     *  @fn virtual bool InputBackend::isMouseButtonPressed(Mouse::Button button) const
     *  @brief Check if a button on the mouse is pressed or not.
     *  @param button The button to check.
     *  @return True if the button is currently pushed down.
     ***
     *  @fn virtual Vec2I InputBackend::getMouseGlobalPosition() const
     *  @brief Access the current mouse position relative to the whole screen.
     *  @return Coordinates as a vector.
     ***
     *  @fn virtual Vec2I InputBackend::getMouseWindowPosition() const
     *  @brief Access the current mouse position relative to the window.
     *  @return Coordinates as a vector.
     ***
     *  @fn virtual void InputBackend::setMouseGlobalPosition(int32_t x, int32_t y)
     *  @brief Set the mouse position relative to the whole screen.
     *  @param x X coordinate.
     *  @param y Y coordinate.
     ***
     *  @fn virtual void InputBackend::setMouseWindowPosition(int32_t x, int32_t y)
     *  @brief Set the mouse position relative to the window.
     *  @param x X coordinate.
     *  @param y Y coordinate.
     ***
     *  @fn virtual bool InputBackend::isGamepadConnected(uint32_t id) const
     *  @brief Check if a gamepad is connected.
     *  @param id Gamepad to check.
     *  @return True if connected.
     ***
     *  @fn virtual uint32_t InputBackend::getGamepadButtonCount(uint32_t id) const
     *  @brief Get the amount of buttons available on a specific gamepad.
     *  @param id Gamepad to check.
     *  @return Amount of buttons.
     ***
     *  @fn virtual bool InputBackend::isGamepadButtonPressed(uint32_t id, uint32_t button) const
     *  @brief Check if a button on a specific gamepad is being pressed down.
     *  @param id Gamepad to check.
     *  @param button Button to check.
     *  @return True if the button is pressed.
     ***
     *  @fn virtual bool InputBackend::gamepadHasAxis(uint32_t id, Gamepad::Axis axis) const
     *  @brief Check if a gamepad has a specific axis.
     *  @param id Gamepad to check.
     *  @param axis Axis to look for.
     *  @return True if the axis exists.
     ***
     *  @fn virtual float InputBackend::getGamepadAxisPosition(uint32_t id, Gamepad::Axis axis) const
     *  @brief Access the current position of an axis on a specific gamepad.
     *  @param id Gamepad to check.
     *  @param axis Axis of which to get the position.
     *  @return Position of the axis.
     ***
     *  @fn virtual void InputBackend::setGamepadThreshold(float threshold)
     *  @brief Set the threshold level for when Event::GAMEPADMOVED events are fired.
     *  @param threshold Threshold level.
     ***
     *  @fn virtual void InputBackend::setKeyRepeatEnabled(bool enabled)
     *  @brief Set Event::KEYPRESSED events to only fire once instead of continuously if a key is being pressed down.
     *  @param enabled True for on, false for off.
     ***/
}
