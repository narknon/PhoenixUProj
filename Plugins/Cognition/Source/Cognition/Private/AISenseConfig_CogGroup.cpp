#include "AISenseConfig_CogGroup.h"
#include "AISense_CogGroup.h"

UAISenseConfig_CogGroup::UAISenseConfig_CogGroup() {
    this->Implementation = UAISense_CogGroup::StaticClass();
    this->FocusDirectionClass = NULL;
    this->UpDirectionClass = NULL;
    this->PerceiverPointClass = NULL;
    this->TraceRadius = 100.00f;
    this->TargetPointClass = NULL;
    this->PriorityBase = 100.00f;
    this->bNormalizePriorityWeights = true;
    this->MinBufferDistance = 500.00f;
    this->MaxBufferDistance = 1000.00f;
    this->MinReevaluationTime = 0.10f;
    this->DebugClass = NULL;
}

