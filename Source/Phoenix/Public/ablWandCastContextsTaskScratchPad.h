#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "EWandCastType.h"
#include "ablWandCastContextsTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablWandCastContextsTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EWandCastType::Type> WandCastType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<int32, bool> FrameReachedMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UablWandCastContextsTaskScratchPad();
};

