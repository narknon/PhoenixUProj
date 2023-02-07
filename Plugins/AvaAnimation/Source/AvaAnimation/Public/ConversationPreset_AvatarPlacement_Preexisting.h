#pragma once
#include "CoreMinimal.h"
#include "ConversationPreset_AvatarPlacement.h"
#include "EConversationPreset_ProximityType.h"
#include "ConversationPreset_AvatarPlacement_Preexisting.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UConversationPreset_AvatarPlacement_Preexisting : public UConversationPreset_AvatarPlacement {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EConversationPreset_ProximityType Proximity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RotateInteractionActorToAvatar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InteractionActorRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RotateActorToInteractionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvatarRotationOffset;
    
    UConversationPreset_AvatarPlacement_Preexisting();
};

