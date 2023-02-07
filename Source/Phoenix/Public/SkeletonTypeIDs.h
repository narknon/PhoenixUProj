#pragma once
#include "CoreMinimal.h"
#include "SkeletonTypeIDs.generated.h"

UENUM(BlueprintType)
enum SkeletonTypeIDs {
    SK_TYPE_ADULTFEMALE,
    SK_TYPE_ADULTMALE,
    SK_TYPE_CHILDFEMALE,
    SK_TYPE_CHILDMALE,
    SK_TYPE_DEATHMINION,
    SK_TYPE_ELFANY,
    SK_TYPE_GOBLINANY,
    SK_TYPE_TROLLANY,
    SK_TYPE_UNKNOWN,
    SK_TYPE_COUNT,
    SK_TYPE_MAX UMETA(Hidden),
};

