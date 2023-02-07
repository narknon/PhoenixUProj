#pragma once
#include "CoreMinimal.h"
#include "AddedFoliageInstancesData.h"
#include "AddedFoliageInstancesDataList.generated.h"

USTRUCT(BlueprintType)
struct FAddedFoliageInstancesDataList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAddedFoliageInstancesData> Data;
    
    PHOENIX_API FAddedFoliageInstancesDataList();
};

