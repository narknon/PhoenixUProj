#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "MasterTickThrottlerSettings.h"
#include "PhoenixBudgetedActor.h"
#include "SpellInterface.h"
#include "PropOwl.generated.h"

class AActor;
class ASpellTool;
class UAnimationComponent;
class UCapsuleComponent;
class UPropOwl_AnimInstance;
class USkeletalMeshComponent;
class USpellToolRecord;

UCLASS(Abstract, Blueprintable)
class APropOwl : public APhoenixBudgetedActor, public ISpellInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationComponent* AnimationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableSpellReaction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableImpactReaction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpactReactionRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableLookAt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxLookAtDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxLookAtAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanSleep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SleepingProbability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinStanceSwitchTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FGameplayTag> IgnoredMunitionTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FName> IgnoredSpellNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMasterTickThrottlerSettings TickThrottlerSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPropOwl_AnimInstance* AnimInstance;
    
public:
    APropOwl();
protected:
    UFUNCTION(BlueprintCallable)
    void StartReaction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnHitBySpell(const ASpellTool* SpellTool, AActor* InInstigator, USpellToolRecord* SpellToolRecord, FName SpellType, const FHitResult& Hit, const FVector& ImpactDirection);
    
private:
    UFUNCTION(BlueprintCallable)
    void EndReaction();
    
    
    // Fix for true pure virtual functions not being implemented
};

