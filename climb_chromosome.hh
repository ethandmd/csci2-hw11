#include "chromosome.hh"

class ClimbChromosome : public Chromosome {
    public:
    virtual ~ClimbChromosome() = default;

    virtual ClimbChromosome* clone() const override
    {
        return new ClimbChromosome(cities_ptr_);
    }

    virtual void mutate() override;

    protected:
    
    ClimbChromosome(const Cities* cities_ptr)
        : Chromosome(cities_ptr)
        {}
};