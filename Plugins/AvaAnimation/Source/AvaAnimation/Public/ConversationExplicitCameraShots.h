#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ConversationExplicitCameraShot.h"
#include "ConversationExplicitCameraShots.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UConversationExplicitCameraShots : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConversationExplicitCameraShot> CameraShots;
    
    UConversationExplicitCameraShots();
};

