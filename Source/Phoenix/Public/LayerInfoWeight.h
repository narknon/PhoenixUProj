#pragma once
#include "CoreMinimal.h"
#include "LayerInfoWeight.generated.h"

USTRUCT(BlueprintType)
struct FLayerInfoWeight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    PHOENIX_API FLayerInfoWeight();
};

