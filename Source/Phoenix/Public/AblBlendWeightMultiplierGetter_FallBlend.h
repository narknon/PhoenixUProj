#pragma once
#include "CoreMinimal.h"
#include "AblBlendWeightMultiplierGetter.h"
#include "AblBlendWeightMultiplierGetter_FallBlend.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBlendWeightMultiplierGetter_FallBlend : public UAblBlendWeightMultiplierGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendSpeed;
    
public:
    UAblBlendWeightMultiplierGetter_FallBlend();
};

