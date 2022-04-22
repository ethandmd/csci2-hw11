#include "climb_chromosome.hh"
#include <sstream>


class TestClimbChromo : public ClimbChromosome {
    public:
    TestClimbChromo(const Cities* cities_ptr) : ClimbChromosome(cities_ptr)
    {}

    void test_mutate() {
        mutate();
    }

    void test_protected() {
        test_mutate();
    }
};

int main() {
    std::stringstream ss;
    ss << "1 \t 1";
    ss << "33 \t 3";
    ss << "11 \t 123";
    
    Cities city;
    ss >> city;
    TestClimbChromo tc(&city);

    tc.test_protected();
}