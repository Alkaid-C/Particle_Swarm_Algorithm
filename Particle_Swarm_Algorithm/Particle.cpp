#include "Particle.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <iostream>
void ParticleSwarmAlgorithm::speedCalculator()
{
	for (int i = 0; i < particles.size(); i++)
	{
		for (int j = 0; j < D; j++)
		{
			particles.at(i).Speed.at(j) = w * particles.at(i).Speed.at(j) + c_1 * ((double)rand() / RAND_MAX) * (particles.at(i).pBestPosition.at(j) - particles.at(i).Position.at(j)) + c_2 * ((double)rand() / RAND_MAX) * (gBestPosition.at(j) - particles.at(i).Position.at(j));
		}
	}
}

void ParticleSwarmAlgorithm::fly()
{
	speedCalculator();
	for (int i = 0; i < particles.size(); i++)
	{
		for (int j = 0; j < D; j++)
		{
			const double tempPosition = particles.at(i).Position.at(j) + particles.at(i).Speed.at(j);
			if (LowerBound.at(j) < tempPosition && tempPosition < UpperBound.at(j))
			{
				particles.at(i).Position.at(j) = tempPosition;
			}
			else if (LowerBound.at(j) >= tempPosition)
			{
				particles.at(i).Position.at(j) = LowerBound.at(j);
			}
			else
			{
				particles.at(i).Position.at(j) = UpperBound.at(j);
			}
		}
		double currentValue = theFunction(particles.at(i).Position);
		if (currentValue > particles.at(i).pBestValue)
		{
			particles.at(i).pBestValue = currentValue;
			for (int k=0; k<D; k++)
				particles.at(i).pBestPosition.at(k) = particles.at(i).Position.at(k);
			if (currentValue > gBestValue)
			{
				gBestValue = currentValue;
				for (int k = 0; k < D; k++)
					gBestPosition.at(k) = particles.at(i).Position.at(k);
			}
		}
	}
}
void ParticleSwarmAlgorithm::initializer(int quant)
{
	for (int i = 0; i < quant; i++)
	{
		particle newParticle;
		for (int j = 0; j < D; j++)
		{
			newParticle.Position.push_back((double)rand() / RAND_MAX * (UpperBound.at(j) - LowerBound.at(j)) + LowerBound.at(j));
			newParticle.Speed.push_back((double)rand() / RAND_MAX * (UpperBound.at(j) - LowerBound.at(j)) * 0.3);
			newParticle.pBestPosition.push_back(newParticle.Position.back());
		}
		newParticle.pBestValue = theFunction(newParticle.Position);
		particles.push_back(newParticle);
	}
}
ParticleSwarmAlgorithm::ParticleSwarmAlgorithm(int quant, int _D, double _w, double _c_1, double _c_2, vector <double> _UpperBound, vector <double> _LowerBound):D(_D), w(-w), c_1(_c_1), c_2(_c_2), UpperBound(_UpperBound), LowerBound(_LowerBound)
{
	double gBestValue=0;
	gBestPosition = UpperBound;
	initializer(quant);
}
void ParticleSwarmAlgorithm::printer()
{
	cout << gBestPosition.at(0) << " | " << gBestValue << endl;
}
