#pragma once
#include "CoreMinimal.h"
#include "ELineRule_LayeredAnimationType.generated.h"

UENUM(BlueprintType)
enum class ELineRule_LayeredAnimationType : uint8 {
    OnlyWhenSpeaking,
    OnlyWhenNotSpeaking,
    Whenever,
    ELineRule_MAX UMETA(Hidden),
};

