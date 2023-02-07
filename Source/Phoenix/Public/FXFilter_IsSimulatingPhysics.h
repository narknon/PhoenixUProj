#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "FXFilter_IsSimulatingPhysics.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_IsSimulatingPhysics : public UFXFilter {
    GENERATED_BODY()
public:
    UFXFilter_IsSimulatingPhysics();
};

