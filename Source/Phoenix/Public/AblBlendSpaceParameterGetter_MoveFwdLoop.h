#pragma once
#include "CoreMinimal.h"
#include "AblBlendSpaceParameterGetter.h"
#include "ECustomInterpType.h"
#include "AblBlendSpaceParameterGetter_MoveFwdLoop.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBlendSpaceParameterGetter_MoveFwdLoop : public UAblBlendSpaceParameterGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WadingInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECustomInterpType::Type> InterpType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBlendInputOnTransitionOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseVelocity;
    
public:
    UAblBlendSpaceParameterGetter_MoveFwdLoop();
};

