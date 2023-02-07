#pragma once
#include "CoreMinimal.h"
#include "Conversation_FinalTransformSettings.h"
#include "Conversation_InitialTransformSettings.h"
#include "Conversation_AvatarSettings.generated.h"

class UConversationPreset_AvatarPlacement;
class UConversationPreset_PreInitInvoke_Placement;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversation_AvatarSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversation_InitialTransformSettings InitialTransformSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UConversationPreset_AvatarPlacement*> Placements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableFinalPositionOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FinalPositionOverrideCheckGroundCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FinalPositionOverrideCheckNavMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversation_FinalTransformSettings FinalTransformSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UConversationPreset_PreInitInvoke_Placement* PreInitInvokePlacement;
    
    FConversation_AvatarSettings();
};

