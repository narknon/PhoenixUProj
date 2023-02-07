#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser_AppendToBaseChooser.h"
#include "AblAppendToBaseChooser_NpcReactVelocityDirection.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAppendToBaseChooser_NpcReactVelocityDirection : public UAblAnimationTagChooser_AppendToBaseChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowForwardBackwardOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowLeftRightOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInverse;
    
    UAblAppendToBaseChooser_NpcReactVelocityDirection();
};

