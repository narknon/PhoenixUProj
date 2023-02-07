#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TargetTypeBase.h"
#include "TargetTypeStaticWorldDirection.generated.h"

UCLASS(Blueprintable)
class AMBULATORY_API UTargetTypeStaticWorldDirection : public UTargetTypeBase {
    GENERATED_BODY()
public:
    UTargetTypeStaticWorldDirection();
    UFUNCTION(BlueprintCallable)
    void SetStaticWorldDirection(FVector InStaticWorldDirection);
    
};

