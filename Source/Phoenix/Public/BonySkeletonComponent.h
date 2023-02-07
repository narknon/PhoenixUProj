#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BoneParticleTracker.h"
#include "BonySkeletonTimerProfile.h"
#include "BonySkeletonTimerProfiles.h"
#include "BonySkeletonComponent.generated.h"

class UPhysicsAsset;
class USkeletalMesh;
class USkeletalMeshComponent;
class USkinFXComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBonySkeletonComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* SkeletonMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhysicsAsset* SkeletonPhysiscsAssetOveride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBonySkeletonTimerProfiles TimerProfiles;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletonMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBonySkeletonTimerProfile ActiveTimerProfile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBoneParticleTracker BoneParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkinFXComponent* SkinFXComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Age;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInitialized;
    
public:
    UBonySkeletonComponent();
    UFUNCTION(BlueprintCallable)
    bool Initialize(FName ProfileName);
    
    UFUNCTION(BlueprintCallable)
    void Abort();
    
};

