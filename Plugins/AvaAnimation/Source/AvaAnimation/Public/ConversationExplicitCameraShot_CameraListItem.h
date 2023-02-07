#pragma once
#include "CoreMinimal.h"
#include "ConversationExplicitCameraShot_CameraListItem.generated.h"

class UActorProvider;

USTRUCT(BlueprintType)
struct FConversationExplicitCameraShot_CameraListItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* Camera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    AVAANIMATION_API FConversationExplicitCameraShot_CameraListItem();
};

