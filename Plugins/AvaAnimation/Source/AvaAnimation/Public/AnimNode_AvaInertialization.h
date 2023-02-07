#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNode_Inertialization.h"
#include "AnimNode_AvaInertialization.generated.h"

class UAnimationComponent;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimNode_AvaInertialization : public FAnimNode_Inertialization {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationComponent* AnimComponent;
    
    FAnimNode_AvaInertialization();
};

