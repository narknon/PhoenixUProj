#pragma once
#include "CoreMinimal.h"
#include "AddedFoliageInstancesData.generated.h"

USTRUCT(BlueprintType)
struct FAddedFoliageInstancesData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WorldFoliageDataIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FoliageTransformsIndex;
    
    PHOENIX_API FAddedFoliageInstancesData();
};

