#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EMountTransitionAnimState.h"
#include "Templates/SubclassOf.h"
#include "CreatureMountTransitionActor.generated.h"

class ACharacter;
class ACreature_Character;
class ASkinFXDefinition;
class UAblAbility;
class UMaterialPermuterLoadingBundle;
class USkeletalMesh;

UCLASS(Blueprintable)
class ACreatureMountTransitionActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerMountAbility_Start;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerMountAbility_Cancel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerMountAbility_Standing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerMountAbility_Trot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerMountAbility_Standing_End_Partial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerMountAbility_Trot_End_Partial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> CreatureAbility_Standing_FromBag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> CreatureAbility_Trot_FromBag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerDismountAbility_Standing_Start;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerDismountAbility_Trot_Start;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerDismountAbility_Standing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerDismountAbility_Trot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerDismountAbility_End;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> CreatureAbility_Standing_ToBag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> CreatureAbility_Trot_ToBag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMountTransitionAnimState MountTransitionAnimState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCreatureMountBagVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASkinFXDefinition> MountSkinFXPreload;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* MountSkinFXPreloadMesh;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter* RiderCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACreature_Character* CreatureCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMaterialPermuterLoadingBundle* SkinFXLoadingBundle;
    
public:
    ACreatureMountTransitionActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnKnockdownDismountStart();
    
    UFUNCTION(BlueprintCallable)
    void OnKnockdownDismountEndCallback();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCreatureOutOfBagStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCreatureOutOfBagEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCreatureIntoBagStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCreatureIntoBagEnd();
    
};

