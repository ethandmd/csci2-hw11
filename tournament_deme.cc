#include "tournament_deme.hh"
#include <math.h>
#include <cassert>
#include <algorithm>

ClimbChromosome*
TournamentDeme::select_parent() {
    //Select P parents. S.t. P is a const pow of 2 <= pop_size().
    //P = 2 ** floor( log_2 ( POP_SIZE ))
    auto POP_SIZE = pop_.size();
    assert(POP_SIZE > 0);       //Sanity check.

    auto p_exp = floor(log2(POP_SIZE));
    unsigned P = pow(2, p_exp);     //Tournament size.

    assert(P <= POP_SIZE);      //Sanity check.

    //Tournament of P parents:
    //Compare the first pair of parents, etc... until you have P/2 parents.
    //Then repeat until you have one parent left.
    //
    //Get P indices at random.
    std::vector<unsigned> cmp_idx(POP_SIZE, 0);
    std::iota(cmp_idx.begin(), cmp_idx.end(), 0);
    std::shuffle(cmp_idx.begin(), cmp_idx.end(), generator_);
    std::vector<unsigned> cmp(cmp_idx.begin(), cmp_idx.begin()+P); //Slice of length P.

    //Tournament has lg(P) rounds
    //Each round has cmp.size()/2 comparisons.
    for (int i = 0; i < log2(P); i++) {
        for (int j = 0; j < cmp.size(); j = j + 2) {
            auto first = pop_[cmp[j]];
            auto second = pop_[cmp[j+1]];

            if (first->get_fitness() > second->get_fitness()) {
                cmp.erase(cmp.begin() + (j+1));     //Discard 2nd element in pair
            } else {
                cmp.erase(cmp.begin() + j);         //Discard 1st element in pair.
            }
        }
    }
    assert(cmp.size() == 1);        //Sanity check.
    return pop_[cmp[0]];            //Return winning chromosome.
}