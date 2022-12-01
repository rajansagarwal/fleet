#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

// Define the possible strategies for each organ
const char STRATEGY_COOPERATE = 'C';
const char STRATEGY_DEFECT = 'D';

// Define the number of rounds to play
const int NUM_ROUNDS = 10;

// Define the mutation rate for the evolutionary algorithm
const double MUTATION_RATE = 0.01;

// This function simulates a round of the organ game
void playRound(unordered_map<string, char>& strategies) {
  // Generate a random number between 0 and 1
  double random = (double)rand() / RAND_MAX;

  // If the random number is less than the mutation rate,
  // randomly change the strategy of the brain
  if (random < MUTATION_RATE) {
    strategies["brain"] = (strategies["brain"] == STRATEGY_COOPERATE) ? STRATEGY_DEFECT : STRATEGY_COOPERATE;
  }

  // Generate another random number between 0 and 1
  random = (double)rand() / RAND_MAX;

  // If the random number is less than the mutation rate,
  // randomly change the strategy of the heart
  if (random < MUTATION_RATE) {
    strategies["heart"] = (strategies["heart"] == STRATEGY_COOPERATE) ? STRATEGY_DEFECT : STRATEGY_COOPERATE;
  }

  // Compute the payoffs for each organ based on their strategies
  int payoff_brain, payoff_heart;
  if (strategies["brain"] == STRATEGY_COOPERATE && strategies["heart"] == STRATEGY_COOPERATE) {
    // Both organs cooperate
    payoff_brain = 3;
    payoff_heart = 3;
  } else if (strategies["brain"] == STRATEGY_COOPERATE && strategies["heart"] == STRATEGY_DEFECT) {
    // Brain cooperates, heart defects
    payoff_brain = 0;
    payoff_heart = 5;
  } else if (strategies["brain"] == STRATEGY_DEFECT && strategies["heart"] == STRATEGY_COOPERATE) {
    // Brain defects, heart cooperates
    payoff_brain = 5;
    payoff_heart = 0;
  } else {
    // Both organs defect
    payoff_brain = 1;
    payoff_heart = 1;
  }

  // Print the payoffs for each organ
  cout << "Brain: " << payoff_brain << " Heart: " << payoff_heart << endl;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Define the initial strategies for each organ
  unordered_map<string, char> strategies;
  strategies["brain"] = STRATEGY_COOPERATE;
  strategies["heart"] = STRATEGY_COOPERATE;

  // Play multiple rounds of the organ game
  for (int i = 0; i < NUM_ROUNDS; i++) {
    playRound(strategies);
  }

  return 0;
}
