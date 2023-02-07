#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RagdollGetupOptions.h"
#include "RagdollPoseState.h"
#include "RagdollBehaviorConfigAsset.generated.h"

class URagdollAudioBehaviorProfile;
class URagdollBehaviorProfile;
class URagdollRecoveryAssistBehaviorProfile;

UCLASS(Blueprintable)
class RAGDOLL_API URagdollBehaviorConfigAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URagdollBehaviorProfile* BehaviorProfile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URagdollAudioBehaviorProfile* AudioBehaviorProfile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URagdollRecoveryAssistBehaviorProfile* RecoveryAssistBehaviorProfile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRagdollGetupOptions> GetupAnimationTagStateFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RagdollShoulderLeftName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RagdollShoulderRightName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RagdollHipsLeftName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RagdollHipsRightName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RagdollSpineLowerBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RagdollSpineUpperBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRagdollPoseState> IdentifiablePoseStates;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 NavigationLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinMoveDist2DRetestNavPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxGroundTestDistance;
    
    URagdollBehaviorConfigAsset();
};

