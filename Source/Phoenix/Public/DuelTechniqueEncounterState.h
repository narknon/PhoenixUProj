#pragma once
#include "CoreMinimal.h"
#include "DuelTechniqueEncounterState.generated.h"

class UDuelTechniqueState;

USTRUCT(BlueprintType)
struct FDuelTechniqueEncounterState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDuelTechniqueState*> Items;
    
    PHOENIX_API FDuelTechniqueEncounterState();
};

