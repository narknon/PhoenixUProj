#pragma once
#include "CoreMinimal.h"
#include "AblNpcPopupTask.h"
#include "EAblNpcReactPopupTaskType.h"
#include "AblNpcReactPopupTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNpcReactPopupTask : public UAblNpcPopupTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseReactionPopupType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAblNpcReactPopupTaskType ReactPopupType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvertReactPopupTypeDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConvertReactPopupTypeDirectionTo2D;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseReactionVelocityIfSendTargetExists;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseReactionDataMagnitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bModifyGravityAtReactionEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GravityScaleAtReactionEnd;
    
public:
    UAblNpcReactPopupTask();
};

