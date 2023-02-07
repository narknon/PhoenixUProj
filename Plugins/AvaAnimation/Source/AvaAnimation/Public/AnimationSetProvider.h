#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "AnimationSetProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UAnimationSetProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UAnimationSetProvider();
};

