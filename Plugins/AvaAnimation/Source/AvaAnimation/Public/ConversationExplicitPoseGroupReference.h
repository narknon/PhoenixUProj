#pragma once
#include "CoreMinimal.h"
#include "ConversationExplicitPoseGroupReference.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversationExplicitPoseGroupReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PoseGroupName;
    
    FConversationExplicitPoseGroupReference();
};

