#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "PhysicalResponseEventData.h"
#include "PhysicalResponseReporter.generated.h"

UCLASS(Blueprintable)
class UPhysicalResponseReporter : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPhysicalResponseEventData> NewImpactEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPhysicalResponseEventData> ImpactEventsPendingDispatch;
    
public:
    UPhysicalResponseReporter();
    UFUNCTION(BlueprintCallable)
    static void HandlePhysicalSweep_Static(const FVector& SweepPosition, const FVector& PreviousPosition, const FName SourceName, const float Radius, const float StrengthFactor);
    
};

