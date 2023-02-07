#pragma once
#include "CoreMinimal.h"
#include "InsideOutsideOverrideVolume.h"
#include "InsideOverrideVolume.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API AInsideOverrideVolume : public AInsideOutsideOverrideVolume {
    GENERATED_BODY()
public:
    AInsideOverrideVolume();
};

