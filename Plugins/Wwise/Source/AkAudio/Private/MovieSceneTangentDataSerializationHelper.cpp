#include "MovieSceneTangentDataSerializationHelper.h"

FMovieSceneTangentDataSerializationHelper::FMovieSceneTangentDataSerializationHelper() {
    this->ArriveTangent = 0.00f;
    this->LeaveTangent = 0.00f;
    this->TangentWeightMode = RCTWM_WeightedNone;
    this->ArriveTangentWeight = 0.00f;
    this->LeaveTangentWeight = 0.00f;
}

