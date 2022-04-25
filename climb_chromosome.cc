#include "climb_chromosome.hh"
#include <cassert>

void
ClimbChromosome::mutate() {
    //Step 0: Calculate order size.
    std::size_t ORDER_SIZE = order_.size();

    //Step 1: Calculate original fitness.
    Cities::permutation_t base_order(order_);
    double base_fitness = get_fitness();

    //Step 2: Pick a random member.
    std::uniform_int_distribution<unsigned> distribution(0, ORDER_SIZE-1);
    unsigned rand_pt = distribution(generator_);        //p

    //Step 3: Swap p and p-1 (with circular topology so if p==0, (p-1) = N-1)
    auto p = order_[rand_pt];
    order_[rand_pt] = order_[(rand_pt - 1) % ORDER_SIZE];
    order_[(rand_pt -1) % ORDER_SIZE] = p;
    assert(is_valid());
    double second_fitness = get_fitness();
    

    if (second_fitness < base_fitness) {
        order_ = base_order;
    } 
    auto bestOrder = order_;
    auto bestFitness = get_fitness();

    //Step 4: Swap p and p+1.
    order_ = base_order;
    order_[rand_pt] = order_[(rand_pt + 1) % ORDER_SIZE];
    order_[(rand_pt + 1) % ORDER_SIZE] = p;
    assert(is_valid());
    double third_fitness = get_fitness();

    if (third_fitness < bestFitness){
        order_ = bestOrder;
    }
} 

