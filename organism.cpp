class Organism {
  public:
    // Constructor
    Organism() {
      // Initialize the organism's genome with random genetic variation
      genome = initializeGenome();

      // Initialize the organism's environment
      temperature = 0.0;
      humidity = 0.0;
      resources = 0.0;

      // Initialize the organism's age and health
      age = 0;
      health = 1.0;
    }

    // Member variables
    string genome;
    float temperature;
    float humidity;
    float resources;
    int age;
    float health;
    float fitness;

    // Member functions
    string initializeGenome() {
      // Generate a random string of DNA bases
      string genome = "";
      for (int i = 0; i < 100; i++) {
        genome += generateRandomBase();
      }
      return genome;
    }

    char generateRandomBase() {
      // Generate a random DNA base (A, C, T, or G)
      int randomIndex = rand() % 4;
      char base = "ACTG"[randomIndex];
      return base;
    }

    float calculateFitness() {
      // Calculate the organism's fitness based on its age, health, and environment
      float fitness = 1.0 / (1.0 + age + (1.0 - health) + temperature + humidity + (1.0 - resources));
      return fitness;
    }
};
