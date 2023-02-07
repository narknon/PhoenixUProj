#include "EnvQueryGenerator_Mercuna_Sphere.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"

UEnvQueryGenerator_Mercuna_Sphere::UEnvQueryGenerator_Mercuna_Sphere() {
    this->Distribution = EMercunaPointDistribution::Uniform;
    this->Center = UEnvQueryContext_Querier::StaticClass();
}

