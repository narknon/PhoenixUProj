#pragma once
#include "CoreMinimal.h"
#include "TagsChangedEvent.generated.h"

UENUM(BlueprintType)
enum TagsChangedEvent {
    TagAdded,
    TagRemoved,
};

