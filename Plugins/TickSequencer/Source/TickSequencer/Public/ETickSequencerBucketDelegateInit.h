#pragma once
#include "CoreMinimal.h"
#include "ETickSequencerBucketDelegateInit.generated.h"

UENUM(BlueprintType)
enum class ETickSequencerBucketDelegateInit : uint8 {
    GameOnly,
    EditorOnly,
    Always,
};

