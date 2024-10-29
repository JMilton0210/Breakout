#pragma once
#include "Particle.h"

class DefaultParticle :
    public Particle
{
    void CreateParticle() override {};
    void UpdateParticle(float dt) override;
    void DestroyParticle() override {};
};

