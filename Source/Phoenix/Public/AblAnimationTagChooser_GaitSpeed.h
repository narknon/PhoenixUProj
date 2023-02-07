#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "GameplayTagContainer.h"
#include "EAblGaitSpeed.h"
#include "ESpeedType.h"
#include "AblAnimationTagChooser_GaitSpeed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_GaitSpeed : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAblGaitSpeed, FGameplayTagContainer> GaitTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ESpeedType::Type> SpeedType;
    
    UAblAnimationTagChooser_GaitSpeed();
};

