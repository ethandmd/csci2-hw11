#pragma once
#include "deme.hh"

class TournamentDeme : public Deme {
    public:
    TournamentDeme(const Cities* ciities_ptr, unsigned pop_size, double mut_rate)
        : Deme(ciities_ptr, pop_size, mut_rate) {}

    virtual ~TournamentDeme() = default;

    protected:
    //virtual Chromosome* select_parent() override;
    virtual ClimbChromosome* select_parent() const override;
};