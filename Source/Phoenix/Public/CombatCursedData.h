#pragma once
#include "CoreMinimal.h"
#include "CombatCursedData.generated.h"

class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FCombatCursedData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> ActivateFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FlairFX2;
    
    PHOENIX_API FCombatCursedData();
};

