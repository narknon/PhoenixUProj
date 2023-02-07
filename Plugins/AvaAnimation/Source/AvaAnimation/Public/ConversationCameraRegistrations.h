#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ConversationCameraRegistration.h"
#include "ConversationCameraRegistrations.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UConversationCameraRegistrations : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConversationCameraRegistration> Registrations;
    
    UConversationCameraRegistrations();
};

