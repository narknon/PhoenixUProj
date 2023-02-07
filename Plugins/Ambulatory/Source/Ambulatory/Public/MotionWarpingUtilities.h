#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AvaMotionWarpingSyncPoint.h"
#include "MotionWarpingUtilities.generated.h"

class UAnimSequenceBase;

UCLASS(Blueprintable)
class AMBULATORY_API UMotionWarpingUtilities : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMotionWarpingUtilities();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FAvaMotionWarpingSyncPoint MakeMotionWarpingSyncPoint(FVector Location, FRotator Rotation);
    
    UFUNCTION(BlueprintCallable)
    static FTransform ExtractRootMotionFromAnimation(const UAnimSequenceBase* Animation, float StartTime, float EndTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void BreakMotionWarpingSyncPoint(const FAvaMotionWarpingSyncPoint& SyncPoint, FVector& Location, FRotator& Rotation);
    
};

