#pragma once
#include "CoreMinimal.h"
#include "FloatProvider.h"
#include "Float_RandomInRange.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UFloat_RandomInRange : public UFloatProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Min;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Max;
    
    UFloat_RandomInRange();
};

