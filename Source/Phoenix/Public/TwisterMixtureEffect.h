#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "MunitionType_AOESpell.h"
#include "TwisterMixtureEffect.generated.h"

class AActor;
class AMunitionType_Base;
class UPrimitiveComponent;
class USphereComponent;

UCLASS(Blueprintable)
class ATwisterMixtureEffect : public AMunitionType_AOESpell {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_PullRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_StopRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_PullTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_PullDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector m_Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_TwisterImpulseMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_UpgradeRadiusMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag m_TwisterUpgradeAbilityTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* m_TwisterEffectSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* m_TwisterStoppingSphere;
    
    ATwisterMixtureEffect(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Tick(float DeltaSeconds);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapEndStoppingSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCharacterLand(const FHitResult& Hit);
    
public:
    UFUNCTION(BlueprintCallable)
    void Cleanup(AMunitionType_Base* MunitionInstance);
    
    UFUNCTION(BlueprintCallable)
    void BeginPull();
    
    UFUNCTION(BlueprintCallable)
    void BeginPlay();
    
};

