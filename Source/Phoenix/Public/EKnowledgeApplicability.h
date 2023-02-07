#pragma once
#include "CoreMinimal.h"
#include "EKnowledgeApplicability.generated.h"

UENUM(BlueprintType)
enum EKnowledgeApplicability {
    Always,
    OnlyIfUnknown,
};

