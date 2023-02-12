#pragma once
#include "CoreMinimal.h"
#include "AkPlatformInfo.h"
#include "AkWin32PlatformInfo.generated.h"

UCLASS(Blueprintable)
class UAkWin32PlatformInfo : public UAkPlatformInfo {
    GENERATED_BODY()
public:
    UAkWin32PlatformInfo();
};

