#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "FXFilter_InstigatorIsPlayer.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_InstigatorIsPlayer : public UFXFilter {
    GENERATED_BODY()
public:
    UFXFilter_InstigatorIsPlayer();
};

