#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "SplineHelper.generated.h"

class USplineComponent;

UCLASS(Blueprintable)
class UTILITIESRUNTIME_API USplineHelper : public UObject {
    GENERATED_BODY()
public:
    USplineHelper();
    UFUNCTION(BlueprintCallable)
    static bool IsLocationCloseEnoughToSplineAtDistance(USplineComponent* SplineComponent, float DistanceAlongSpline, FVector TestLocation, float DistanceRange, bool bDebug);
    
    UFUNCTION(BlueprintCallable)
    static float GetDistanceAlongSplineFromWorldLocation(USplineComponent* SplineComponent, FVector Location, bool& bFound);
    
};

