#pragma once
#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "BuildNavDataCommandlet.generated.h"

UCLASS(Blueprintable, NonTransient)
class UBuildNavDataCommandlet : public UCommandlet {
    GENERATED_BODY()
public:
    UBuildNavDataCommandlet();
};

