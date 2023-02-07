#pragma once
#include "CoreMinimal.h"
#include "PetrificusData.generated.h"

class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FPetrificusData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FX2;
    
    PHOENIX_API FPetrificusData();
};

