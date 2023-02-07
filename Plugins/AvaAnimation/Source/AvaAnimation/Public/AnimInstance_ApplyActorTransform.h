#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimInstance.h"
#include "AnimInstance_ApplyActorTransform.generated.h"

UCLASS(Blueprintable, NonTransient)
class AVAANIMATION_API UAnimInstance_ApplyActorTransform : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform ActorInWorldSpace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldSetActorInWorldSpace;
    
    UAnimInstance_ApplyActorTransform();
};

