#pragma once
#include "CoreMinimal.h"
#include "ESubjectType.generated.h"

UENUM(BlueprintType)
enum class ESubjectType : uint8 {
    Class,
    Club,
    ExtraCurricular,
    Nurture,
    SelfStudy,
};

