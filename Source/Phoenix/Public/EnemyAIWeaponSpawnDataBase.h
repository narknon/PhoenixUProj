#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Templates/SubclassOf.h"
#include "EnemyAIWeaponSpawnDataBase.generated.h"

class AEnemyAIWeapon;

UCLASS(Abstract, Blueprintable, EditInlineNew, Config=Game)
class UEnemyAIWeaponSpawnDataBase : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AEnemyAIWeapon> Weapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Chance;
    
    UEnemyAIWeaponSpawnDataBase();
};

