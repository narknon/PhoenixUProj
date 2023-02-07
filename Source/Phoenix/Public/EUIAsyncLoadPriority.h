#pragma once
#include "CoreMinimal.h"
#include "EUIAsyncLoadPriority.generated.h"

UENUM(BlueprintType)
enum class EUIAsyncLoadPriority : uint8 {
    LoadingPriority_Low,
    LoadingPriority_Normal,
    LoadingPriority_AboveNormal,
    LoadingPriority_High,
    LoadingPriority_Critical,
    LoadingPriority_MAX UMETA(Hidden),
};

