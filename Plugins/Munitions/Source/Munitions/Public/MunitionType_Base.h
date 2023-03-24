#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "MunitionImpactData.h"
#include "MunitionType_Base.generated.h"

class UInteractionArchitectAsset;

UCLASS(Abstract, Blueprintable)
class MUNITIONS_API AMunitionType_Base : public AActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOverlap, AMunitionType_Base*, MunitionInstance, const FMunitionImpactData&, MunitionImpactData);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImpactDamage, AMunitionType_Base*, MunitionInstance, const FMunitionImpactData&, MunitionImpactData);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnImpact, AMunitionType_Base*, MunitionInstance, const FMunitionImpactData&, MunitionImpactData);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDestroyed, AMunitionType_Base*, MunitionInstance);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_damage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_minLifeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_maxLifeTime;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MunitionImpactTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInteractionArchitectAsset*> MunitionDataAssets;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnOverlap OnOverlap;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnImpact OnImpact;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDestroyed OnMunitionDestroyed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnImpactDamage OnImpactDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDOAOnParrySuccess;
    
    AMunitionType_Base(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TargetDestroyed();
    
    UFUNCTION(BlueprintCallable)
    void SetVelocityIncludeTarget(bool bInFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetTarget(AActor* i_pActor);
    
    UFUNCTION(BlueprintCallable)
    void SetStartingVelocity(FVector InVelocity);
    
    UFUNCTION(BlueprintCallable)
    void SetSourcePosition(FVector i_sourcePos);
    
    UFUNCTION(BlueprintCallable)
    void SetRemainingLifeTime(float InRemaningTime);
    
    UFUNCTION(BlueprintCallable)
    void SetRecomputeVelocity(bool bInFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetMunitionOwner(AActor* i_pActor);
    
    UFUNCTION(BlueprintCallable)
    void SetMunitionImpactType(FName InMunitionImpactType);
    
    UFUNCTION(BlueprintCallable)
    void SetMunitionDataAssets(const TArray<UInteractionArchitectAsset*>& InMunitionDataAssets);
    
    UFUNCTION(BlueprintCallable)
    void SetMaxRange(float Range);
    
    UFUNCTION(BlueprintCallable)
    void SetMaxDamage(float InMaxDamage);
    
    UFUNCTION(BlueprintCallable)
    void SetLifeTime(float InMaxTime);
    
    UFUNCTION(BlueprintCallable)
    void SetInstigator(AActor* i_pActor);
    
    UFUNCTION(BlueprintCallable)
    void SetFromAimMode(bool bInFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetDestinationPosition(FVector i_destPos);
    
    UFUNCTION(BlueprintCallable)
    void SetDamage(float InDamage);
    
    UFUNCTION(BlueprintCallable)
    void ResetMunitionTagContainer();
    
    UFUNCTION(BlueprintCallable)
    void ResetMunitionDataAssets();
    
    UFUNCTION(BlueprintCallable)
    void RemoveMunitionTagContainer(const FGameplayTagContainer& InMunitionTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void RemoveMunitionTag(const FGameplayTag& InMunitionTag);
    
    UFUNCTION(BlueprintCallable)
    void RemoveMunitionDataAsset(UInteractionArchitectAsset* InMunitionDataAsset);
    
    UFUNCTION(BlueprintCallable)
    void MunitionIgnored();
    
    UFUNCTION(BlueprintCallable)
    void MunitionFailed();
    
    UFUNCTION(BlueprintCallable)
    void MunitionDOA();
    
    UFUNCTION(BlueprintCallable)
    void MunitionDeflected();
    
    UFUNCTION(BlueprintCallable)
    void MunitionBlocked();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_WasMunitionDeflected() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDeflectedMunition_K2() const;
    
    UFUNCTION(BlueprintCallable)
    void IgnoreActor(AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetVelocityIncludeTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetStartingVelocity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetSourcePosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRemainingLifeTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetRecomputeVelocity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTagContainer GetMunitionTagContainer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetMunitionOwner() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetMunitionImpactType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UInteractionArchitectAsset*> GetMunitionDataAssets() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxRange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxDamage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetFromAimMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetDestinationPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDamage() const;
    
    UFUNCTION(BlueprintCallable)
    void Fire();
    
    UFUNCTION(BlueprintCallable)
    static FVector ComputeVelocity_NoGravity(FVector i_sourcePos, FVector i_destPos, FVector i_destVel, float i_speed, float& o_time);
    
    UFUNCTION(BlueprintCallable)
    static FVector ComputeVelocity(FVector i_sourcePos, FVector i_destPos, FVector i_destVel, float i_speed, float i_gravity, float& o_time, const bool assertOnError);
    
    UFUNCTION(BlueprintCallable)
    void AddMunitionTagContainer(const FGameplayTagContainer& InMunitionTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void AddMunitionTag(const FGameplayTag& InMunitionTag);
    
    UFUNCTION(BlueprintCallable)
    void AddMunitionDataAsset(UInteractionArchitectAsset* InMunitionDataAsset);
    
};

