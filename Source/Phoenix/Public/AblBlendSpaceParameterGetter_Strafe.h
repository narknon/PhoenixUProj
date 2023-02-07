#pragma once
#include "CoreMinimal.h"
#include "AblBlendSpaceParameterGetter.h"
#include "AblBlendSpaceParameterGetter_Strafe.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBlendSpaceParameterGetter_Strafe : public UAblBlendSpaceParameterGetter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AngleInterpSpeed;
    
    UAblBlendSpaceParameterGetter_Strafe();
};

