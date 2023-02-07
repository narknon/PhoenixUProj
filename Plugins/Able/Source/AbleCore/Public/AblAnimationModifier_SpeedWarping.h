#pragma once
#include "CoreMinimal.h"
#include "AblAnimationModifier.h"
#include "KIKBone.h"
#include "AblAnimationModifier_SpeedWarping.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationModifier_SpeedWarping : public UAblAnimationModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FKIKBone> FKIKBranches;
    
    UAblAnimationModifier_SpeedWarping();
};

