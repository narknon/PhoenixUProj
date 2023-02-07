#pragma once
#include "CoreMinimal.h"
#include "AblBlendSpaceParameterGetter.h"
#include "AblBlendSpaceParameterGetter_JumpLand2Move.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBlendSpaceParameterGetter_JumpLand2Move : public UAblBlendSpaceParameterGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ClampDesiredAngle;
    
public:
    UAblBlendSpaceParameterGetter_JumpLand2Move();
};

