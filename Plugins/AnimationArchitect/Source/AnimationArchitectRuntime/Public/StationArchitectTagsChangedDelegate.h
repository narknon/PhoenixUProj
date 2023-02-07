#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TagsChangedEvent.h"
#include "StationArchitectTagsChangedDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FStationArchitectTagsChanged, AActor*, Actor, FGameplayTag, GameplayTag, TEnumAsByte<TagsChangedEvent>, TagsChanged);

