# Fleet — Exploring Evolutionary Game Theory

Evolutionary game theory is a framework for analyzing the interactions between individuals or groups in a population. It is used to study the evolution of cooperation and competition, and to understand the dynamics of social and economic systems.

In the context of biology, evolutionary game theory can be used to model the interactions between organs in the body. By simulating the strategies and payoffs for each organ, we can gain insights into the evolution of cooperation and competition within the body, and how these interactions affect the overall functioning of the organism.

### `playRound()` function

This function simulates a single round of the organ game. It takes in a reference to a map of organ strategies, and updates the strategies based on the payoffs from the previous round.

```
void playRound(unordered_map<string, char>& strategies) {
  // Generate a random number between 0 and 1
  double random = (double)rand() / RAND_MAX;

  ...
  random = (double)rand() / RAND_MAX;
  if (random < MUTATION_RATE) {
    strategies["kidney"] = (strategies["kidney"] == STRATEGY_COOPERATE) ? STRATEGY_DEFECT : STRATEGY_COOPERATE;
  }
  int payoff_heart, payoff_lungs, payoff_kidney;
  if (strategies["heart"] == STRATEGY_COOPERATE && strategies["lungs"] == STRATEGY_COOPERATE && strategies["kidney"] == STRATEGY_COOPERATE) {
    payoff_heart = 3;
    payoff_lungs = 3;
    payoff_kidney = 3;
  } else if (strategies["heart"] == STRATEGY_COOPERATE && strategies["lungs"] == STRATEGY_COOPERATE && strategies["kidney"] == STRATEGY_DEFECT) {
    payoff_heart = 2;
    payoff_lungs = 2;
    payoff_kidney = 4;
  }
   ...

if (payoff_heart >= payoff_lungs && payoff_heart >= payoff_kidney) {
    strategies[0] = STRATEGY_COOPERATE;
  } else if (payoff_lungs >= payoff_heart && payoff_lungs >= payoff_kidney) {
    strategies[1] = STRATEGY_COOPERATE;
  } else if (payoff_kidney >= payoff_heart && payoff_kidney >= payoff_lungs) {
    strategies[2] = STRATEGY_COOPERATE;
  }
}
```

This function also updates the strategies of each organ based on their payoffs from the previous round. It uses a simple evolutionary algorithm to select the organ with the highest payoff, and sets its strategy to cooperate. This allows the most successful strategy to be passed on to the next generation.
