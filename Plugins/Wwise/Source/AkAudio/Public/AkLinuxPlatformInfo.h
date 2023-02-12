#pragma once
#include "CoreMinimal.h"
#include "AkPlatformInfo.h"
#include "AkLinuxPlatformInfo.generated.h"

UCLASS(Blueprintable)
class UAkLinuxPlatformInfo : public UAkPlatformInfo {
    GENERATED_BODY()
public:
    UAkLinuxPlatformInfo();
};

