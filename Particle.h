#pragma once

namespace acg
{
	struct Particle {
		double m_x;
		double m_y;
		double m_var;
	private:
		double m_speed;
		double m_direction;

		void init();
	public:
		Particle();
		void update(int interval);
	};
}
