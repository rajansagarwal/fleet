// Define the assumptions and parameters of the simulation
int populationSize = 10;
int generationCount = 100;
float mutationRate = 0.1;

// Generate the theoretical data based on the assumptions and parameters
vector<float> theoreticalFitness = generateTheoreticalFitness(populationSize, generationCount, mutationRate);

// Run the simulation to generate the actual data
vector<Organism> population = initializePopulation(populationSize);
vector<float> actualFitness = runSimulation(population, generationCount, mutationRate);

// Compare the theoretical and actual data
for (int i = 0; i < generationCount; i++) {
  // Calculate the difference between the theoretical and actual fitness for the current generation
  float fitnessDifference = theoreticalFitness[i] - actualFitness[i];

  // Print the difference to the console
  Serial.println("Generation " + i + ": fitness difference = " + fitnessDifference);
}

void compareResults(String strategies, double actual_heart, double actual_lungs, double actual_kidney) {
  // Compute the average payoff for each organ in the simulation
  double simulated_heart = 0;
  double simulated_lungs = 0;
  double simulated_kidney = 0;
  for (int i = 0; i < strategies.length(); i++) {
    if (strategies[i] == STRATEGY_COOPERATE) {
      simulated_heart += 3;
      simulated_lungs += 3;
      simulated_kidney += 3;
    } else if (strategies[i] == STRATEGY_DEFECT) {
      simulated_heart += 4;
      simulated_lungs += 2;
      simulated_kidney += 2;
    }
  }
  simulated_heart /= strategies.length();
  simulated_lungs /= strategies.length();
  simulated_kidney /= strategies.length();

  // Compute the mean squared error for each organ
  double mse_heart = pow(simulated_heart - actual_heart, 2);
  double mse_lungs = pow(simulated_lungs - actual_lungs, 2);
  double mse_kidney = pow(simulated_kidney - actual_kidney, 2);

  // Print the results
  Serial.print(mse_heart);
  Serial.print(mse_lungs);
  Serial.print(mse_kideny);
}
