#pragma once
#include "CoreMinimal.h"
#include "SpellLevelData.h"
#include "LumosLevelData.generated.h"

USTRUCT(BlueprintType)
struct FLumosLevelData : public FSpellLevelData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Intensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistance;
    
    PHOENIX_API FLumosLevelData();
};

