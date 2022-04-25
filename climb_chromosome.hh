#pragma once
#include "chromosome.hh"

class ClimbChromosome : public Chromosome {
    public:    
    ClimbChromosome(const Cities* cities_ptr)
        : Chromosome(cities_ptr)
        {}
    
    virtual ~ClimbChromosome() = default;

    virtual ClimbChromosome* clone() const override
    {
        //Need to create new protected copy constructor for climb 
        //Allocates new memory.
        return new ClimbChromosome(*this);
    }

    virtual void mutate() override;

    protected:
    ClimbChromosome(const ClimbChromosome&) = default;
};