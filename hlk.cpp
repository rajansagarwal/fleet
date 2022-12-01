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
  // randomly change the strategy of the heart
  if (random < MUTATION_RATE) {
    strategies["heart"] = (strategies["heart"] == STRATEGY_COOPERATE) ? STRATEGY_DEFECT : STRATEGY_COOPERATE;
  }

  // Generate another random number between 0 and 1
  random = (double)rand() / RAND_MAX;

  // If the random number is less than the mutation rate,
  // randomly change the strategy of the lungs
  if (random < MUTATION_RATE) {
    strategies["lungs"] = (strategies["lungs"] == STRATEGY_COOPERATE) ? STRATEGY_DEFECT : STRATEGY_COOPERATE;
  }

  // Generate another random number between 0 and 1
  random = (double)rand() / RAND_MAX;

  // If the random number is less than the mutation rate,
  // randomly change the strategy of the kidney
  if (random < MUTATION_RATE) {
    strategies["kidney"] = (strategies["kidney"] == STRATEGY_COOPERATE) ? STRATEGY_DEFECT : STRATEGY_COOPERATE;
  }

  // Compute the payoffs for each organ based on their strategies
  int payoff_heart, payoff_lungs, payoff_kidney;
  if (strategies["heart"] == STRATEGY_COOPERATE && strategies["lungs"] == STRATEGY_COOPERATE && strategies["kidney"] == STRATEGY_COOPERATE) {
    // All organs cooperate
    payoff_heart = 3;
    payoff_lungs = 3;
    payoff_kidney = 3;
  } else if (strategies["heart"] == STRATEGY_COOPERATE && strategies["lungs"] == STRATEGY_COOPERATE && strategies["kidney"] == STRATEGY_DEFECT) {
    // Heart and lungs cooperate, kidney defects
    payoff_heart = 2;
    payoff_lungs = 2;
    payoff_kidney = 4;
  } 
}
