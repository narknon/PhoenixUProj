#pragma once
#include "CoreMinimal.h"
#include "DisillusionmentData.generated.h"

class UMaterialInterface;
class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FDisillusionmentData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* EffectMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> DisillusionmentFX2;
    
    PHOENIX_API FDisillusionmentData();
};

