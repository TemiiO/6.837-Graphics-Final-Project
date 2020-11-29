#ifndef WATER_DROPLET_SYSTEM_H_
#define WATER_DROPLET_SYSTEM_H_

#include "ParticleState.hpp"
#include "ParticleSystemBase.hpp"

namespace GLOO {
    class WaterDropletSystem : ParticleSystemBase
    {
    public:
        WaterDropletSystem() {};
        ParticleState ComputeTimeDerivative(const ParticleState& state,
            float time) const {

            return glm::vec3(-state[1], state[0], 0);
        }
    };
}
// namespace GLOO

#endif