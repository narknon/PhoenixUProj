#pragma once
#include "CoreMinimal.h"
#include "Conversation_FinalTransformSettings.generated.h"

class UConversationPreset_FinalTransform;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversation_FinalTransformSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UConversationPreset_FinalTransform* TransformType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CheckGroundCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CheckNavMesh;
    
    FConversation_FinalTransformSettings();
};

