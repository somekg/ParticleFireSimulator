#pragma once
#include "Particle.h"

namespace acg
{
	class Swarm
	{
		Particle* m_pParticles;
	public: 
		const static int NPARTICLES = 500;
		int lastTime;
	public:
		Swarm();
		virtual ~Swarm();
		const Particle* const getParticles() { return m_pParticles; };
		void update(int elapsed);
	};
}

