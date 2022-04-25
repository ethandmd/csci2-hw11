# CSCI2-HW11
#### Authors: Ethan McDonald and Will Barcott

## Usage:
Default is to use ```TournamentDeme``` class and ```ClimbChromosome```. (Un)comment in ```tsp.cc``` to toggle ```(Tournament)Deme```, and toggle ```(Climb)Chromosome``` from ```(Tournament)Deme```.

Example valgrind test:
```
$ valgrind --tool=memcheck ./tsp challenge.tsv 64 0.2
```