#pragma once
#include "CoreMinimal.h"
#include "GameplayProperty.h"
#include "GameplayPropertyNumeric.generated.h"

USTRUCT(BlueprintType)
struct FGameplayPropertyNumeric : public FGameplayProperty {
    GENERATED_BODY()
public:
    GAMEPLAYMODS_API FGameplayPropertyNumeric();
};

