#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DynamicSpline.h"
#include "DynamicSplineSet.generated.h"

UCLASS(Blueprintable)
class DYNAMICSPLINESRUNTIME_API UDynamicSplineSet : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<FDynamicSpline> DynamicSplines;
    
    UDynamicSplineSet();
};

