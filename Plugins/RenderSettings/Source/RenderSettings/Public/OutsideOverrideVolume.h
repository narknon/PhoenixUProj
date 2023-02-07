#pragma once
#include "CoreMinimal.h"
#include "InsideOutsideOverrideVolume.h"
#include "OutsideOverrideVolume.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API AOutsideOverrideVolume : public AInsideOutsideOverrideVolume {
    GENERATED_BODY()
public:
    AOutsideOverrideVolume();
};

