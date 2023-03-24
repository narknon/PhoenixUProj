#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "MunitionType_AOESpell.h"
#include "Templates/SubclassOf.h"
#include "DrainingDraughtEffect.generated.h"

class AActor;
class ADraingingDraughtOrb;
class AMunitionType_SubsonicSpell;
class UInteractionArchitectAsset;
class UPrimitiveComponent;
class USphereComponent;

UCLASS(Blueprintable)
class ADrainingDraughtEffect : public AMunitionType_AOESpell {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_CloudRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_AOEDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_AOEDamageRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_SeekRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_SeekTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_OrbDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_OrbGroundDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_OrbRotationRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 m_NumOrbs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_OrbDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_bTimingBasedOnOrbAmt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_BufferTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 m_OrbIncreaseAmt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInteractionArchitectAsset*> m_AOEInteractionArchitectMunitionAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer m_AOEInteractionArchitectMunitionTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_SubsonicSpell> m_OrbMunition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* m_OrbSeekSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* m_CloudDamageSphere;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ADraingingDraughtOrb*> m_ActiveOrbs;
    
public:
    ADrainingDraughtEffect(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Tick(float DeltaSeconds);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SpawnOrbs();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetNumberOrbs(int32 NumOrbs);
    
    UFUNCTION(BlueprintCallable)
    void SendOutOrb();
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapEndSeekSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapEndCloudSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapBeginSeekSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapBeginCloudSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
protected:
    UFUNCTION(BlueprintCallable)
    ADraingingDraughtOrb* GetBestAvailableOrb(AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    void DoAOECloudDamageCallback();
    
public:
    UFUNCTION(BlueprintCallable)
    void BeginPlay();
    
};

