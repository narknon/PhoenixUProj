#pragma once
#include "CoreMinimal.h"
#include "CreatureVariation.generated.h"

class UMaterialInstance;
class UObjectArchitectAsset;

USTRUCT(BlueprintType)
struct FCreatureVariation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VariationName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, TSoftObjectPtr<UMaterialInstance>> MaterialSlotsMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObjectArchitectAsset> AudioAsset;
    
    PHOENIX_API FCreatureVariation();
};

