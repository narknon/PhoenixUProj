#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "AblAnimationTagChooser_ThrowItem.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_ThrowItem : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThrowLongDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThrowMedDistance;
    
public:
    UAblAnimationTagChooser_ThrowItem();
};

