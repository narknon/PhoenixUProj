#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "IKDriver.h"
#include "IKDriver_LedgeContactFootControl.h"
#include "IKDriver_LedgeContactHandControl.h"
#include "IKDriver_LedgeContactHipsControl.h"
#include "IKDriver_LedgeContact.generated.h"

class UAnimSequence;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UIKDriver_LedgeContact : public UIKDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* LedgePoseAnimSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LedgePoseTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKDriver_LedgeContactHandControl LeftHand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKDriver_LedgeContactHandControl RightHand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKDriver_LedgeContactFootControl LeftFoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKDriver_LedgeContactFootControl RightFoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKDriver_LedgeContactHipsControl Hips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionChannel> TraceChannel;
    
    UIKDriver_LedgeContact();
};

