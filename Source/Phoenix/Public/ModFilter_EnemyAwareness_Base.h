#pragma once
#include "CoreMinimal.h"
#include "ModFilter.h"
#include "ModFilter_EnemyAwareness_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UModFilter_EnemyAwareness_Base : public UModFilter {
    GENERATED_BODY()
public:
    UModFilter_EnemyAwareness_Base();
};

