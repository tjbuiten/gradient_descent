// Includes
#include <vector>

// Start of the program
int main()
{
	// Variables that the user 'should' alter
	int tries = 1;
	float learning_rate = 0.05;

	// Variables
	std::vector<float> x;
	std::vector<float> y;
	std::vector<float> test_y;
	float gradient = 0;
	float x_zero = 0;
	float average_fault = 0;

	// Train
	for (int i = 0; i < tries; i++)
		for (int j = 0; j < x.size() * 0.8; j++) {
			float error = y[j] - (x[j] * gradient + x_zero);
			gradient += error * x[j] * learning_rate;
			x_zero += error * learning_rate;
			error = NULL;
		}

	// Test
	for (int i = x.size() * 0.8; i < x.size(); i++) {
		test_y.push_back(x_zero + i * gradient);
	}

	// Calculate the average fault ratio
	for (int i = x.size() * 0.8; i < x.size(); i++) {
		average_fault += (test_y[i - x.size() * 0.8] - y[i]);
	}
	average_fault = average_fault / (x.size() * 0.8);

	// End of the program
	return 0;
}