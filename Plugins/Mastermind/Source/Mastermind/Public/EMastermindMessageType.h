#pragma once
#include "CoreMinimal.h"
#include "EMastermindMessageType.generated.h"

UENUM(BlueprintType)
enum class EMastermindMessageType : uint8 {
    TestResult,
    StepResult,
    ProgressUpdate,
};

