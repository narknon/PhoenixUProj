#pragma once
#include "CoreMinimal.h"
#include "EConversationCameraFilterType.h"
#include "StoryGraph_Conversation_CameraFilter.generated.h"

class UNameProvider;

USTRUCT(BlueprintType)
struct PHOENIX_API FStoryGraph_Conversation_CameraFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EConversationCameraFilterType ConversationCameraFilterType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UNameProvider*> EnableCameraNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UNameProvider*> DisableCameraNames;
    
    FStoryGraph_Conversation_CameraFilter();
};

