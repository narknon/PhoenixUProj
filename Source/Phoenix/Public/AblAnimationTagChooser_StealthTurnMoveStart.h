#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "UObject/NoExportTypes.h"
#include "AblAnimationTagChooser_StealthTurnMoveStart.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_StealthTurnMoveStart : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FootPositionWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FootVelocityWeight;
    
public:
    UAblAnimationTagChooser_StealthTurnMoveStart();
};

