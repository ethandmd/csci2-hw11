# CSCI2-HW11
#### Authors: Ethan McDonald and Will Barcott

## Usage:
Default is to use ```TournamentDeme``` class and ```ClimbChromosome```. (Un)comment in ```tsp.cc``` to toggle ```(Tournament)Deme```, and toggle ```(Climb)Chromosome``` from ```(Tournament)Deme```.

Example valgrind test:
```
$ valgrind --tool=memcheck ./tsp challenge.tsv 64 0.2
```

## Implementation Design:

### ClimbChromosome::mutate()
This method seeks to compare the fitness from three different orderings. To implement this, we calculate the starting base fitness, and then proceed to swap the order in the given chromosome two more times, each time comparing against the preceding best fitness. Finally, the chromosome's order is the one which resulted in the best fitness.

### TournamentDeme::select_parent()
This implementation has three principle components:
+ Find P := greatest power of 2 less than the population size.
+ Select P random indices between [0,population size].
+ Compare pairs of chromosomes by fitness until one chromsome ("winner") remains.

The third component is interesting, it is implemented here with a circular queue (FIFO). While the queue has more than one element, the leading two queue elements are de-queued, and the chromosomes corresponding to the index at each dequeued element are compared by fitness. Then, the chromosome with higher fitness has its corresponding index enqueued, while the losing chromsome's index is not reinserted into the queue.