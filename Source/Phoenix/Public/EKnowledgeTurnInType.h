#pragma once
#include "CoreMinimal.h"
#include "EKnowledgeTurnInType.generated.h"

UENUM(BlueprintType)
enum class EKnowledgeTurnInType : uint8 {
    SingleKnowledge,
    ScholarSpell,
    Location,
    Student,
};

