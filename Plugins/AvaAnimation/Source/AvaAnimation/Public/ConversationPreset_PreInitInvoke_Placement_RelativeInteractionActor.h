#pragma once
#include "CoreMinimal.h"
#include "ConversationPreset_PreInitInvoke_Placement.h"
#include "ConversationPreset_PreInitInvoke_Placement_RelativeInteractionActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UConversationPreset_PreInitInvoke_Placement_RelativeInteractionActor : public UConversationPreset_PreInitInvoke_Placement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IdealDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NearDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvatarPositionDirectionFromInteractionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvatarRotationFromInteractionActor;
    
    UConversationPreset_PreInitInvoke_Placement_RelativeInteractionActor();
};

