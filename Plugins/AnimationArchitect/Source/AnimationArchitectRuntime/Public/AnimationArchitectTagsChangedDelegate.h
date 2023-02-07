#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TagsChangedEvent.h"
#include "AnimationArchitectTagsChangedDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAnimationArchitectTagsChanged, AActor*, Actor, FGameplayTag, GameplayTag, TEnumAsByte<TagsChangedEvent>, TagsChanged);

