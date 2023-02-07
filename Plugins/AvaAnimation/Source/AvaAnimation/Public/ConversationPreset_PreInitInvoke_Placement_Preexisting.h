#pragma once
#include "CoreMinimal.h"
#include "ConversationPreset_PreInitInvoke_Placement.h"
#include "ConversationPreset_PreInitInvoke_Placement_Preexisting.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UConversationPreset_PreInitInvoke_Placement_Preexisting : public UConversationPreset_PreInitInvoke_Placement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RotateInteractionActorToAvatar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InteractionActorRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RotateActorToInteractionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvatarRotationOffset;
    
    UConversationPreset_PreInitInvoke_Placement_Preexisting();
};

