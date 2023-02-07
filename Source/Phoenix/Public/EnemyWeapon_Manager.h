#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EnemyWeapon_Manager.generated.h"

class AEnemyAIWeapon;

UCLASS(Blueprintable)
class UEnemyWeapon_Manager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AEnemyAIWeapon>> WeaponList;
    
public:
    UEnemyWeapon_Manager();
};

