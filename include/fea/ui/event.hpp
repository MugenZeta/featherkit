#pragma once
#include <fea/config.hpp>
#include <cstdint>
#include <fea/ui/keyboard.hpp>
#include <fea/ui/mouse.hpp>
#include <fea/ui/gamepad.hpp>

namespace fea
{
    class FEA_API Event
    {
        public:
            struct ResizeEvent
            {
                uint32_t width;
                uint32_t height;
            };
            
            struct KeyEvent
            {
                Keyboard::Code code;
                bool alt;
                bool control;
                bool shift;
                bool system;
            };

            struct TextEvent
            {
                uint32_t unicode;
            };

            struct MouseMoveEvent
            {
                int32_t x;
                int32_t y;
				int32_t relx;
				int32_t rely;
            };

            struct MouseButtonEvent
            {
                Mouse::Button button;
                int32_t x;
                int32_t y;
            };

            struct MouseWheelEvent
            {
                int32_t delta;
                int32_t x;
                int32_t y;
            };

            struct GamepadConnectEvent
            {
                uint32_t gamepadId;
            };

            struct GamepadMoveEvent
            {
                uint32_t gamepadId;
                Gamepad::Axis axis;
                float position;
            };

            struct GamepadButtonEvent
            {
                uint32_t gamepadId;
                uint32_t button;
            };

            enum EventType
            {
                CLOSED,
                RESIZED,
                LOSTFOCUS,
                GAINEDFOCUS,
                TEXTENTERED,
                KEYPRESSED,
                KEYRELEASED,
                MOUSEWHEELMOVED,
                MOUSEBUTTONPRESSED,
                MOUSEBUTTONRELEASED,
                MOUSEMOVED,
                MOUSEENTERED,
                MOUSELEFT,
                GAMEPADBUTTONPRESSED,
                GAMEPADBUTTONRELEASED,
                GAMEPADMOVED,
                GAMEPADCONNECTED,
                GAMEPADDISCONNECTED
            };
            
            EventType type;

            union
            {
                ResizeEvent size;                      ///< Holds data of RESIZED events.
                KeyEvent key;                          ///< Holds data of KEYPRESSED and KEYRELEASED events.
                TextEvent text;                        ///< Holds data of TEXTENTERED events.
                MouseMoveEvent mouseMove;              ///< Holds data of MOUSEMOVED events.
                MouseButtonEvent mouseButton;          ///< Holds data of MOUSEBUTTONPRESSED and MOUSEBUTTONRELEASED events.
                MouseWheelEvent mouseWheel;            ///< Holds data of MOUSEWHEELMOVED events.
                GamepadMoveEvent gamepadMove;          ///< Holds data of GAMEPADMOVED events.
                GamepadButtonEvent gamepadButton;      ///< Holds data of GAMEPADBUTTONPRESSED and GAMEPADBUTTONREMOVED events.
                GamepadConnectEvent gamepadConnect;    ///< Holds data of GAMEPADCONNECTED and GAMEPADDISCONNECTED events.
            };
    };
    /** @addtogroup UI
     *@{
     *  @class Event
     *  @enum Event::EventType
     *@}
     ***
     *  @class Event
     *  @brief Defines an input event. 
     *
     *  Contains various structs to define specific input events. These holds the type of the event and its related data.
     ***
     *  @enum Event::EventType
     *  @brief Describes different types of events.
     *** 
     *  @var Event::type
     *  @brief Type of the event.
     ***
     *  @struct Event::ResizeEvent
     *  @brief Data structure containing data for resize events.
     ***
     *  @var Event::ResizeEvent::width
     *  @brief width of new size.
     ***
     *  @var Event::ResizeEvent::height
     *  @brief height of new size.
     ***
     *  @struct Event::KeyEvent
     *  @brief Data structure containing data for key events.
     ***
     *  @var Event::KeyEvent::code
     *  @brief Numerical code corresponing to a key on the keyboard.
     ***
     *  @var Event::KeyEvent::alt
     *  @brief True if alt was held down while the event was fired.
     ***
     *  @var Event::KeyEvent::control
     *  @brief True if control was held down while the event was fired.
     ***
     *  @var Event::KeyEvent::shift
     *  @brief True if shift was held down while the event was fired.
     ***
     *  @var Event::KeyEvent::system
     *  @brief True if the system key was held down while the event was fired.
     ***
     *  @struct Event::TextEvent
     *  @brief Data structure containing data for text events.
     ***
     *  @var Event::TextEvent::unicode
     *  @brief Integer representing unicode value.
     ***  
     *  @struct Event::MouseMoveEvent
     *  @brief Data structure containing data for mouse move events.
     ***
     *  @var Event::MouseMoveEvent::x
     *  @brief X coordinate.
     ***
     *  @var Event::MouseMoveEvent::y
     *  @brief Y coordinate.
     ***
     *  @var Event::MouseMoveEvent::relx
     *  @brief Relative x coordinate.
     ***
     *  @var Event::MouseMoveEvent::rely
     *  @brief Relative Y coordinate.
     ***
     *  @struct Event::MouseButtonEvent
     *  @brief Data structure containing data for mouse button events.
     ***
     *  @var Event::MouseButtonEvent::button
     *  @brief Numerical code representing the mouse button.
     ***
     *  @var Event::MouseButtonEvent::x
     *  @brief X coordinate.
     ***
     *  @var Event::MouseButtonEvent::y
     *  @brief Y coordinate.
     ***
     *  @struct Event::MouseWheelEvent
     *  @brief Data structure containing data for mouse wheel events.
     ***
     *  @var Event::MouseWheelEvent::delta
     *  @brief Numerical value representing how much the mouse wheel was moved. A backwards move will yield a negative number.
     ***
     *  @var Event::MouseWheelEvent::x
     *  @brief X coordinate.
     ***
     *  @var Event::MouseWheelEvent::y
     *  @brief Y coordinate.
     ***
     *  @struct Event::GamepadConnectEvent
     *  @brief Data structure containing data for gamepad connect events.
     ***
     *  @var Event::GamepadConnectEvent::gamepadId
     *  @brief Numerical ID representing the gamepad that was connected.
     ***
     *  @struct Event::GamepadMoveEvent
     *  @brief Data structure containing data for gamepad move events.
     ***
     *  @var Event::GamepadMoveEvent::gamepadId
     *  @brief Numerical ID representing the gamepad for which the axis was moved.
     ***
     *  @var Event::GamepadMoveEvent::axis
     *  @brief Numerical code representing moved axis.
     ***
     *  @var Event::GamepadMoveEvent::position
     *  @brief Decimal number of the new position of the axis.
     ***
     *  @struct Event::GamepadButtonEvent
     *  @brief Data structure containing data for gamepad button events.
     ***
     *  @var Event::GamepadButtonEvent::gamepadId
     *  @brief Numerical ID representing the gamepad for which the button even was fired.
     ***
     *  @var Event::GamepadButtonEvent::button
     *  @brief Button code representing the button which the event belongs to.
     ***/
}
