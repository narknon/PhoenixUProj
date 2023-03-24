#pragma once
#include "CoreMinimal.h"
#include "ConversationAnimationManager.h"
#include "ConversationAssetTracker.h"
#include "ConversationCameraManager.h"
#include "SceneRigStage_Actor.h"
#include "SceneRigStage_Bool.h"
#include "SceneRigStage_Float.h"
#include "SceneRigStage_Int.h"
#include "SceneRigStage_String.h"
#include "SceneRigStage_Transform.h"
#include "StoryGraphActor.h"
#include "ConversationActor.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API AConversationActor : public AStoryGraphActor, public IConversationCameraManager, public IConversationAnimationManager, public IConversationAssetTracker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor interactionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor LocalPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor Camera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_String DialogueSequenceID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_String DialogueEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Int DialogueFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Transform AvatarHead;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Transform AvatarRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Transform AvatarRootFinal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Transform A1Head;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Transform A1Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Transform A1RootFinal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Bool EnableInitialFadeOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Bool EnableInitialFadeIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Bool EnableFinalFadeOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Bool EnableFinalFadeIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Int SynchronizationMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Bool EnableLightRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Bool UsesSkyColors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Float KeyLightColorTemperature;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Float RimLightColorTemperature;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Float FillLightColorTemperature;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Float KeyLightIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Float RimLightIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Float FillLightIntensity;
    
    AConversationActor(const FObjectInitializer& ObjectInitializer);
    
    // Fix for true pure virtual functions not being implemented
};

