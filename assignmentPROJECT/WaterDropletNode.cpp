#include "ParticleSystemBase.hpp"

#include "gloo/utils.hpp"
#include "gloo/debug/PrimitiveFactory.hpp"
#include "gloo/MeshLoader.hpp"
#include "gloo/shaders/PhongShader.hpp"
#include "gloo/components/ShadingComponent.hpp"
#include "gloo/components/RenderingComponent.hpp"
#include "WaterDropletSystem.hpp"
#include "IntegratorType.hpp"
#include "IntegratorFactory.hpp"

namespace GLOO {
    WaterDropletNode::WaterDropletNode(IntegratorType type, float integration_step) : SceneNode() {
        particle_mesh_ = PrimitiveFactory::CreateSphere(0.035f, 25, 25);
        integrator_ = IntegratorFactory::CreateIntegrator<WaterDropletSystem>(type);
        integration_step_ = integration_step;
        time_ = 0;
        shader_ = make_unique<PhongShader>();
    }
}