#pragma once
#include "CoreMinimal.h"
#include "EBroomEnemyState.generated.h"

UENUM(BlueprintType)
namespace EBroomEnemyState {
    enum Type {
        None,
        Follow,
        Lead,
        LeadChangePosition,
        Wait,
    };
}

