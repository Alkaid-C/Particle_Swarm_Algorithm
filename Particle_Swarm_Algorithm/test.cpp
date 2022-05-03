#include <iostream>
#include "Particle.h"

int main()
{
	int quant = 5;//quantity of particles
	double w=1;//inertia weight
	double c_1=0.5;//acceleration constants for individual
	double c_2=0.3;//acceleration constants for group
	int D=1;//Dimension 
	vector <double> UpperBound = {10};
	vector <double> LowerBound = {-10};
	srand(time(NULL));
	ParticleSwarmAlgorithm particles(quant, D, w, c_1, c_2, UpperBound, LowerBound);
		particles.fly();
		particles.fly();
		particles.printer();
		particles.fly();
		particles.fly();
		particles.printer();
		particles.fly();
		particles.fly();
		particles.printer();
		particles.fly();
		particles.fly();
		particles.printer();
		particles.fly();
		particles.fly();
		particles.printer();
		particles.fly();
		particles.fly();
		particles.fly();
		particles.fly();
		particles.printer();
		particles.fly();
		particles.fly();
		particles.fly();
		particles.fly();
		particles.printer();
		particles.fly();
		particles.fly();
		particles.fly();
		particles.fly();
		particles.printer();
	return 0;
}