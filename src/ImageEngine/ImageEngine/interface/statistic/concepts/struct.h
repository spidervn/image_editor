#ifndef IMAGEENGINE_INTERFACE_STATISTIC_CONCEPTS_STRUCT_H_
#define IMAGEENGINE_INTERFACE_STATISTIC_CONCEPTS_STRUCT_H_

struct SampleSpace {};
struct Experiment {};
struct ProbabilityFunction {};

struct Probabilistic
{
    SampleSpace O;
    Experiment e;
    Probabilistic p;
};

/* Random variables */
struct DiscreteRandomVariable
{};

struct ContinousRandomVariable
{};

#endif 