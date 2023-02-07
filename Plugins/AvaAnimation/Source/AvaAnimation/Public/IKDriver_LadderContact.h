#pragma once
#include "CoreMinimal.h"
#include "IKDriver.h"
#include "IKDriver_LadderContactControl.h"
#include "IKDriver_LadderContact.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UIKDriver_LadderContact : public UIKDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKDriver_LadderContactControl LeftHand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKDriver_LadderContactControl RightHand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKDriver_LadderContactControl LeftFoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKDriver_LadderContactControl RightFoot;
    
    UIKDriver_LadderContact();
};

