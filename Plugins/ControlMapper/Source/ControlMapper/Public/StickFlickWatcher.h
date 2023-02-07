#pragma once
#include "CoreMinimal.h"
#include "StickWatcher.h"
#include "StickFlickWatcher.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UStickFlickWatcher : public UStickWatcher {
    GENERATED_BODY()
public:
    UStickFlickWatcher();
};

