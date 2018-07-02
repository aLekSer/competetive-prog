#include <random>
    
double start_time = 0;
double timeout = 10; // seconds
const double ticks_per_sec = 2500000000;
inline double get_time() {
    uint32_t lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return (((uint64_t)hi << 32) | lo) / ticks_per_sec;
}
double max_temperature = 0.9;
double min_temperature = 0.1;

double prob_change_1 = 0.4;
double prob_change_2 = 0.3;
double prob_change_3 = 0.3;
void simulated_annealing() {
      double skip_time = get_time() - start_time;
      double used_time = skip_time;
      std::uniform_real_distribution<double> type_dist(0, 1);
      std::mt19937 rnd;
      while (used_time < timeout) {
        double temperature = (1.0 - (used_time - skip_time) / (timeout - skip_time))
          * (max_temperature - min_temperature) + min_temperature;
        
        for (int iteration = 0; iteration < 1000; iteration++) {
          double type = type_dist(rnd);
            
          // prob_change_1 + prob_change_2 + prob_change_3 == 1.0
          if (type < prob_change_1) {
            state_change_1 sd1 = random_state_change_1();
            if (accept(sd1.delta, temperature)) {
              sd1.apply();
            }
          }
          else if (type < prob_change_1 + prob_change_2) {
            state_change_2 sd2 = random_state_change_2();
            if (accept(sd2.delta, temperature)) {
              sd2.apply();
            }
          }
          else {
            state_change_3 sd3 = random_state_change_3();
            if (accept(sd3.delta, temperature)) {
              sd3.apply();
            }
          }
            
        }
      }
      used_time = get_time() - start_time;
    }
    
int main() 
{
  start_time = get_time();

  return 0;
}
