#pragma once
#include "CoreMinimal.h"
#include "AblBlendSpaceParameterGetter.h"
#include "AblBlendSpaceParameterGetter_BodyLean2D.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBlendSpaceParameterGetter_BodyLean2D : public UAblBlendSpaceParameterGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinMaxForwardAcceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinMaxSideAcceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpAlphaX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpAlphaY;
    
public:
    UAblBlendSpaceParameterGetter_BodyLean2D();
};

