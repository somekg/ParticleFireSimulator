#include "Particle.h"
#include "Screen.h"
#include <stdlib.h>

namespace acg {	
	Particle::Particle() : m_x(0), m_y(0){
		init();
	}
	void Particle::init() {
		m_x = 0;
	    m_y = 0;

		//Direction works in radians. Pi is 180º. 
		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		
		//Setting speed to a constant value around 0.1 or slower make cool round waves or a total round circle
		m_speed = (0.03 * rand()) / RAND_MAX;
		m_speed *= m_speed;
	}
	void Particle::update(int interval) {
		//Speed at which the particles get close to the center. 
		//Try setting a high rotation ~0.1 and a constant speed!
		const double rotation = 0.001;

		m_direction += interval * rotation;
		
		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		m_x += xspeed*interval;
		m_y += yspeed*interval;

		if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
			init();
		}
		if (rand() < RAND_MAX/100) {
			init();
		}
	}
};
