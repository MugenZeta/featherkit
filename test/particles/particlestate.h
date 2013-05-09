#include <gamestate.h>
#include <string>
#include <vector>
#include <entity/entitygroup.h>
#include "component.h"

enum {ORANGE, LIME, TURQUOISE, SKYBLUE, PURPLE, PINK};

void colourSetter(std::string attribute, std::vector<std::string>& arguments, windgale::WeakEntityPtr entity);
void floatVec2Setter(std::string attribute, std::vector<std::string>& arguments, windgale::WeakEntityPtr entity);


class ParticleState : public windstorm::GameState
{
    public:
        void activate() override;
        void deactivate() override;
        void setup() override;
        std::string run() override;
        void destroy() override;
        ~ParticleState() override;
};
