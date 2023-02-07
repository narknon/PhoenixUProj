#pragma once
#include "CoreMinimal.h"
#include "OnAnimationPlayedDelegate.generated.h"

class UAblAbilityContext;
class UAnimationAsset;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAnimationPlayed, float, CurrentTime, const UAnimationAsset*, AnimationAsset, const UAblAbilityContext*, Context);

