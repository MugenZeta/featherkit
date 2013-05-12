#include <application.h>
#include <SFML/Graphics.hpp>
#include <inputhandler.h>
#include <sfmlinputbackend.h>
#include <actionhandler.h>
#include <window.h>
#include <sfmlwindowbackend.h>
#include <iostream>
#include <cstring>
#include <gamestatemachine.h>

class Particles : public windstorm::Application
{
    public:
        void setup() override;
        void run() override;
        void destroy() override; 
    private:
        windstorm::GameStateMachine stateMachine;

        sf::RenderWindow sfWindow;
        windbreeze::SFMLWindowBackend sfmlWindowBackend = sfWindow;
        windbreeze::Window window = sfmlWindowBackend;

        windbreeze::SFMLInputBackend sfmlInputBackend = sfWindow;
        windbreeze::InputHandler inputHandler = sfmlInputBackend;
        windbreeze::ActionHandler<std::string> actionHandler;
};