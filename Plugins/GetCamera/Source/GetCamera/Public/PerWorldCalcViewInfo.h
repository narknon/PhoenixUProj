#pragma once
#include "CoreMinimal.h"
#include "CalcViewInfo.h"
#include "PerWorldCalcViewInfo.generated.h"

USTRUCT(BlueprintType)
struct GETCAMERA_API FPerWorldCalcViewInfo {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint32, FCalcViewInfo> Views;
    
    FPerWorldCalcViewInfo();
};

