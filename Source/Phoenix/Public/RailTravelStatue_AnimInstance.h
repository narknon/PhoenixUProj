#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RailTravelStatue_AnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class URailTravelStatue_AnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Turn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    
    URailTravelStatue_AnimInstance();
};

