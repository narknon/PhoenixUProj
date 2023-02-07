#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "AblAnimationTagChooser_MoveJump.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_MoveJump : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D FootMatchTimeRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FootPositionWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FootVelocityWeight;
    
public:
    UAblAnimationTagChooser_MoveJump();
};

