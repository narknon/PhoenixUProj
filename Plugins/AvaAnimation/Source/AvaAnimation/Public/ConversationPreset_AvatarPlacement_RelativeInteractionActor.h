#pragma once
#include "CoreMinimal.h"
#include "ConversationPreset_AvatarPlacement.h"
#include "EConversationPreset_ProximityType.h"
#include "ConversationPreset_AvatarPlacement_RelativeInteractionActor.generated.h"

class UConversationPreset_CheckBetweenTest;
class UConversationPreset_DistanceProvider;
class UConversationPreset_RelativeInteractionActorTest;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UConversationPreset_AvatarPlacement_RelativeInteractionActor : public UConversationPreset_AvatarPlacement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UConversationPreset_DistanceProvider*> DistanceProviders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UConversationPreset_RelativeInteractionActorTest*> TestsToPerform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvatarPositionDirectionFromInteractionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvatarRotationFromInteractionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CheckGroundCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CheckNavMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UConversationPreset_CheckBetweenTest*> CheckBetweenTests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseMaxHeightAngleThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHeightAngleThreshold;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EConversationPreset_ProximityType FailProximity;
    
    UConversationPreset_AvatarPlacement_RelativeInteractionActor();
};

