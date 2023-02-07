#pragma once
#include "CoreMinimal.h"
#include "Conversation_InitialTransformSettings.generated.h"

class UConversationPreset_InitialTransform;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversation_InitialTransformSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UConversationPreset_InitialTransform* TransformType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CheckGroundCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CheckNavMesh;
    
    FConversation_InitialTransformSettings();
};

