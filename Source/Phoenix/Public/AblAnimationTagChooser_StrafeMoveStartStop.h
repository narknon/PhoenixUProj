#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "UObject/NoExportTypes.h"
#include "AblAnimationTagChooser_StrafeMoveStartStop.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_StrafeMoveStartStop : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FootPositionWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FootVelocityWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FootMatchSearchTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickFlickTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShuffleStepInterpTime;
    
public:
    UAblAnimationTagChooser_StrafeMoveStartStop();
};

