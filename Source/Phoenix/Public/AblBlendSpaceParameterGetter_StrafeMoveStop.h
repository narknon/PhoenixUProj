#pragma once
#include "CoreMinimal.h"
#include "AblBlendSpaceParameterGetter_MoveStrafe.h"
#include "AblBlendSpaceParameterGetter_StrafeMoveStop.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBlendSpaceParameterGetter_StrafeMoveStop : public UAblBlendSpaceParameterGetter_MoveStrafe {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseWorldSpeedTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideWalkSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WalkSpeedOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideJogSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JogSpeedOverride;
    
public:
    UAblBlendSpaceParameterGetter_StrafeMoveStop();
};

