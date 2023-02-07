#pragma once
#include "CoreMinimal.h"
#include "FloatProvider.h"
#include "Float_ProjectedTimeAnimationValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UFloat_ProjectedTimeAnimationValue : public UFloatProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OriginalTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OriginalTimeAnimationValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float animationLength;
    
    UFloat_ProjectedTimeAnimationValue();
};

