#pragma once
#include "CoreMinimal.h"
#include "CharacterStateData.h"
#include "BipedStateData.generated.h"

USTRUCT(BlueprintType)
struct FBipedStateData : public FCharacterStateData {
    GENERATED_BODY()
public:
    PHOENIX_API FBipedStateData();
};

