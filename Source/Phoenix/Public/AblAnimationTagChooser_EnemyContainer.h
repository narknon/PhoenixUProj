#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "GameplayTagContainer.h"
#include "EEnemy_TagContainer.h"
#include "AblAnimationTagChooser_EnemyContainer.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_EnemyContainer : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_TagContainer ContainerSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AttackTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddWeaponTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddWeaponsTagsIfMatchAttackType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer WeaponTagsAttackTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddDirectionalTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddDirectionalTagsIfMatchAttackType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer DirectionalTagsAttackTagContainer;
    
    UAblAnimationTagChooser_EnemyContainer();
};

