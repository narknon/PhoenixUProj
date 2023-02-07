#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_Filtered.h"
#include "MultiFX2_ForceFeedback.generated.h"

class UForceFeedbackEffect;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_ForceFeedback : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UForceFeedbackEffect* ForceFeedbackEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterRadius;
    
public:
    UMultiFX2_ForceFeedback();
};

