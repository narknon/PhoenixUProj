#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TagsChangedEvent.h"
#include "ObjectArchitectTagsChangedDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FObjectArchitectTagsChanged, AActor*, Actor, FGameplayTag, GameplayTag, TEnumAsByte<TagsChangedEvent>, TagsChanged);

