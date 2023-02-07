#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TargetTypeBase.h"
#include "TargetTypeLocation.generated.h"

UCLASS(Blueprintable)
class AMBULATORY_API UTargetTypeLocation : public UTargetTypeBase {
    GENERATED_BODY()
public:
    UTargetTypeLocation();
    UFUNCTION(BlueprintCallable)
    void SetTargetLocation(FVector InTargetLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetTargetLocation() const;
    
};

