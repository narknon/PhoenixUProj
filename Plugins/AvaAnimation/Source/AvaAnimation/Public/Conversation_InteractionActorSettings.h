#pragma once
#include "CoreMinimal.h"
#include "Conversation_FinalTransformSettings.h"
#include "Conversation_InitialTransformSettings.h"
#include "Conversation_InteractionActorSettings.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversation_InteractionActorSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableInitialPositionOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InitialPositionOverrideCheckGroundCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InitialPositionOverrideCheckNavMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableInitialPositionFromStationSockets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InitialPositionFromStationSocketsCheckGroundCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InitialPositionFromStationSocketsCheckNavMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversation_InitialTransformSettings InitialTransformSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversation_FinalTransformSettings FinalTransformSettings;
    
    FConversation_InteractionActorSettings();
};

