#include "chromosome.hh"

class ClimbChromosome : public Chromosome {
    public:    
    
    ClimbChromosome(const Cities* cities_ptr)
        : Chromosome(cities_ptr)
        {}
    virtual ~ClimbChromosome() = default;

    virtual ClimbChromosome* clone() const override
    {
        return new ClimbChromosome(cities_ptr_);
    }

    virtual void mutate() override;
};