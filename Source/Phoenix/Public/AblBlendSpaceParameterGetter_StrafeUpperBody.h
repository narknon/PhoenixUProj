#pragma once
#include "CoreMinimal.h"
#include "AblBlendSpaceParameterGetter.h"
#include "UObject/NoExportTypes.h"
#include "AblBlendSpaceParameterGetter_StrafeUpperBody.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBlendSpaceParameterGetter_StrafeUpperBody : public UAblBlendSpaceParameterGetter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HipBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector HipForwardLocal;
    
    UAblBlendSpaceParameterGetter_StrafeUpperBody();
};

