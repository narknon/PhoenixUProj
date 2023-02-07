#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "EEnemy_WeaponSource.h"
#include "AblAnimationTagChooser_EnemyWeapon.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_EnemyWeapon : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_WeaponSource WeaponSource;
    
    UAblAnimationTagChooser_EnemyWeapon();
};

