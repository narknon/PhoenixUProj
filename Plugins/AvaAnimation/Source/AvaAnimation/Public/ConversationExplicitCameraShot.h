#pragma once
#include "CoreMinimal.h"
#include "ConversationExplicitCameraShot_CameraListItem.h"
#include "ConversationExplicitCameraShot.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversationExplicitCameraShot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConversationExplicitCameraShot_CameraListItem> AvatarCameras;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConversationExplicitCameraShot_CameraListItem> InteractionActorCameras;
    
    FConversationExplicitCameraShot();
};

