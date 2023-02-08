#pragma once
#include "CoreMinimal.h"
#include "OnPlayAnimationPlayedDelegate.generated.h"

class UAblAbilityContext;


UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayAnimationPlayed, float, CurrentTime, const UAnimationAsset*, AnimationAsset, const UAblAbilityContext*, Context);

