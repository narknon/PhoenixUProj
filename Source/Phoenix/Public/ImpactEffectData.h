#pragma once
#include "CoreMinimal.h"
#include "EImpactTypes.h"
#include "ImpactEffectData.generated.h"

class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FImpactEffectData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EImpactTypes ChainedType;
    
    PHOENIX_API FImpactEffectData();
};

