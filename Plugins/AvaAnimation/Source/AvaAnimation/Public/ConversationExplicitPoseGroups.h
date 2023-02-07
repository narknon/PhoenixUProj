#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ConversationExplicitPoseGroup.h"
#include "ConversationExplicitPoseGroups.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UConversationExplicitPoseGroups : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConversationExplicitPoseGroup> PoseGroups;
    
    UConversationExplicitPoseGroups();
};

