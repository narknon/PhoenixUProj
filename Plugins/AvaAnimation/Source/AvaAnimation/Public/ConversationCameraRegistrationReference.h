#pragma once
#include "CoreMinimal.h"
#include "ConversationCameraRegistrationReference.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversationCameraRegistrationReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CameraRegistrationName;
    
    FConversationCameraRegistrationReference();
};

