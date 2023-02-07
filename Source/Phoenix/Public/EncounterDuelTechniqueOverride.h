#pragma once
#include "CoreMinimal.h"
#include "EEncounterDuelTechniqueOverrideType.h"
#include "EncounterDuelTechniqueOverride.generated.h"

USTRUCT(BlueprintType)
struct FEncounterDuelTechniqueOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EEncounterDuelTechniqueOverrideType OverrideType;
    
    PHOENIX_API FEncounterDuelTechniqueOverride();
};

