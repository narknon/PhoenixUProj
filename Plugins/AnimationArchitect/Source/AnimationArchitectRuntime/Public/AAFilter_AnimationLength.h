#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectFilter.h"
#include "AAFilter_AnimationLength.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ANIMATIONARCHITECTRUNTIME_API UAAFilter_AnimationLength : public UBaseArchitectFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAnimationLength;
    
    UAAFilter_AnimationLength();
};

