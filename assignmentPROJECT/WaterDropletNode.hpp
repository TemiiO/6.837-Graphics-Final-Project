#ifndef WATER_DROPLET_NODE_H_
#define WATER_DROPLET_NODE_H_

#include "gloo/SceneNode.hpp"
#include "gloo/VertexObject.hpp"
#include "ParticleState.hpp"
#include "ParticleSystemBase.hpp"
#include "ForwardEulerIntegrator.hpp"
#include "gloo/shaders/ShaderProgram.hpp"
#include "gloo/components/ShadingComponent.hpp"
#include "gloo/components/RenderingComponent.hpp"
#include "IntegratorType.hpp"
#include "IntegratorFactory.hpp"

namespace GLOO {
    class WaterDropletNode : public SceneNode {
        public:
            WaterDropletNode(IntegratorType type, flaot integration_step);

        private:
            std::shared_ptr<VertexObject> particle_mesh_;
            ParticleState state_;
            # TODO Add WaterDropletSystem
            std::shared_ptr<ShaderProgram> shader_;
            SceneNode* particle_;
            std::unique_ptr<GLOO::IntegratorBase<WaterDropletSystem, ParticleState>> integrator_;
            float integration_step_;
            double time_;

            void Update(double dt);
    };
}
#endif