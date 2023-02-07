#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ActorsOfClass.h"
#include "EnvQueryGenerator_StationsNearby.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEnvQueryGenerator_StationsNearby : public UEnvQueryGenerator_ActorsOfClass {
    GENERATED_BODY()
public:
    UEnvQueryGenerator_StationsNearby();
};

