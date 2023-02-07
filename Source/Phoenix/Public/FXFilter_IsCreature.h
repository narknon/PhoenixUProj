#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "FXFilter_IsCreature.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_IsCreature : public UFXFilter {
    GENERATED_BODY()
public:
    UFXFilter_IsCreature();
};

