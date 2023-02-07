#pragma once
#include "CoreMinimal.h"
#include "MultiFX2Data.h"
#include "MultiFX2DataArray.generated.h"

USTRUCT(BlueprintType)
struct MULTIFX2_API FMultiFX2DataArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMultiFX2Data> DataArray;
    
    FMultiFX2DataArray();
};

