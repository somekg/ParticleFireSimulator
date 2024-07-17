#pragma once
namespace acg
{
	struct Particle
	{
		double m_x;
		double m_y;
	private:
		double m_speed;
		double m_direction;
		void init();

	public:
		Particle();
		void update(int interval);
	};
}

