#ifndef Particle
#define Particle

#include<vector>
#include<string>

using namespace std;
struct particle
{
	vector<double> Position;
	vector<double> Speed;
	vector<double> pBestPosition;
	double pBestValue;
};

double static theFunction(vector<double> Position)
{
	return -(Position.at(0) - 2) * (Position.at(0) + 1) * (Position.at(0) -5) *(Position.at(0) + 3);
}
class ParticleSwarmAlgorithm
{
private:
	vector<particle> particles;
	double gBestValue;
	vector <double> gBestPosition;
	const double w;
	const double c_1;
	const double c_2;
	const int D;
	const vector <double> UpperBound;
	const vector <double> LowerBound;
	void initializer(int quant);
public:
	void speedCalculator();
	void fly();
	ParticleSwarmAlgorithm(int quant, int D, double w, double c_1, double c_2, vector <double> UpperBound, vector <double> LowerBound);
	void printer();

}
#endif
;

