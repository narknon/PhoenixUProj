#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNode_AssetPlayerBase.h"
#include "AblAnimation.h"
#include "AnimNode_AbilityAnimPlayer.generated.h"

USTRUCT(BlueprintType)
struct ABLECORE_API FAnimNode_AbilityAnimPlayer : public FAnimNode_AssetPlayerBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAblAnimation AblAnimation;
    
    FAnimNode_AbilityAnimPlayer();
};

