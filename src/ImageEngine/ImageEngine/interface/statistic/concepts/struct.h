#ifndef IMAGEENGINE_INTERFACE_STATISTIC_CONCEPTS_STRUCT_H_
#define IMAGEENGINE_INTERFACE_STATISTIC_CONCEPTS_STRUCT_H_

struct SampleSpace {};
struct Experiment {};
struct ProbabilityFunction {};

struct Probabilistic
{
    SampleSpace O;
    Experiment e;
    ProbabilityFunction p;
};

/* Random variables */
struct DiscreteRandomVariable
{};
struct ContinousRandomVariable
{};

// ContinousRandomVariable p;
struct ExpectedValue
{};
struct Variance
{};
struct StandardDeviation
{};

// Distributions
struct BernoulliDistribution
{};

struct BinomialDistribution
{};

struct NormalDistribution   // <=> Gaussian distribution
{}; 

struct GeometricDistribution
{};
struct UniformDistribution
{};
// Standard deviation
struct JointDistribution
{};



#endif