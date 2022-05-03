A simple sample of [Particle Swarm Optimization Algorithm](https://en.wikipedia.org/wiki/Particle_swarm_optimization) that seeks local maximum of a function. This program could calculate function with multiple variables.

Parameters are in test.cpp file. Go explore some different values.

The function is in Particle.h, and the current example is a single-variable quartic polynomial function, while the maximum 70.70 is achieved at x≈3.87

```c++
double static theFunction(vector<double> Position)
{
	return -(Position.at(0) - 2) * (Position.at(0) + 1) * (Position.at(0) -5) *(Position.at(0) + 3);//-x^4+3x^3+15x^2-19x-30
}
```

