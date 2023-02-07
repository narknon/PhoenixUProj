#pragma once
#include "CoreMinimal.h"
#include "AblBlendSpaceParameterGetter.h"
#include "AblBlendSpaceParameterGetter_AttackAnticipation.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBlendSpaceParameterGetter_AttackAnticipation : public UAblBlendSpaceParameterGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeadZoneAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ClampDesiredAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToExtremesSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToZeroSpeed;
    
public:
    UAblBlendSpaceParameterGetter_AttackAnticipation();
};

