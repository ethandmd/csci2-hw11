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
        //auto clone = new ClimbChromosome(cities_ptr_);
        //clone = this;
        //return clone;
        return new ClimbChromosome(*this);
    }

    virtual void mutate() override;

    protected:
    ClimbChromosome(const ClimbChromosome&) = default;

};