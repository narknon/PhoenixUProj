#pragma once
#include "CoreMinimal.h"
#include "BonySkeletonAudioEvent.h"
#include "BonySkeletonTimer.h"
#include "Templates/SubclassOf.h"
#include "BonySkeletonTimerProfile.generated.h"

class ASkinFXDefinition;
class UParticleSystem;

USTRUCT(BlueprintType)
struct FBonySkeletonTimerProfile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ProfileName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBonySkeletonTimer ShowSkeletonTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBonySkeletonTimer HideNonSkeletonTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBonySkeletonTimer ParticleStartTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* Particle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ParticleFXBones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBonySkeletonTimer SkinFXStartTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASkinFXDefinition> SkinFXEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBonySkeletonAudioEvent> AudioEvents;
    
    PHOENIX_API FBonySkeletonTimerProfile();
};

