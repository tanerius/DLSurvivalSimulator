# Deep Learning Survival Simulator

A survival simulator in C++ which uses deep learning for surviving its environment.

## How to build

- Go to root folder
- `mk build`
- `cd build`
- `cmake -S ..`
- `make`

The to run just :

`./DLSim`

## Prerequisites

There is a set of conditions anr rules that are necessary for evolution and natural selection.

### Self Replication

An organizm must me able to self replicate, automatically without oversight and planning **if certain conditions are met**.

### Blueprint 

Every organizm born must be constructed in accordance with a blueprint.

### Inherritance 

Each blueprint should be inherrited from the replicator to the replicant. That means copying some of the genome from one parent and some from the other to form a new genome for the child.

### Mutation

The inherrited blueprint has to undergo occasional mutations. 

### Selection

There must be a selection method for who gets to reproduce and who doesn't.

## Simulation

Can be configured via:

- Size of the world
- Population
- Steps in a generation
- genome length
- inner neurons
