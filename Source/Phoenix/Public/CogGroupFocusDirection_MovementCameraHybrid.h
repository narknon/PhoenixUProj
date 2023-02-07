#pragma once
#include "CoreMinimal.h"
#include "CogGroupFocusDirection.h"
#include "CogGroupFocusDirection_MovementCameraHybrid.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UCogGroupFocusDirection_MovementCameraHybrid : public UCogGroupFocusDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequiredCameraMovementToUseCameraFocus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCameraDirectionHasPriority;
    
    UCogGroupFocusDirection_MovementCameraHybrid();
};

