#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "GameplayTagContainer.h"
#include "EWandCastCommand.h"
#include "AblAnimationTagChooser_WandCast.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_WandCast : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer TooCloseToEnemyTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpinMoveBlendTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeleeMoveBlendTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EWandCastCommand::Type> WandCastCommand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSampleYawRemainingFromCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float YawRemainingSampleEndTime;
    
public:
    UAblAnimationTagChooser_WandCast();
};

