#pragma once
#include "CoreMinimal.h"
#include "AkXboxOneGDKPlatformInfo.h"
#include "AkXB1PlatformInfo.generated.h"

UCLASS(Blueprintable)
class UAkXB1PlatformInfo : public UAkXboxOneGDKPlatformInfo {
    GENERATED_BODY()
public:
    UAkXB1PlatformInfo();
};

