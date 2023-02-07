#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Enemy_TauntWeaponData.generated.h"

class AEnemyAIWeapon;

USTRUCT(BlueprintType)
struct FEnemy_TauntWeaponData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AEnemyAIWeapon>> RequiredWeaponList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AEnemyAIWeapon>> RequiredShieldList;
    
    PHOENIX_API FEnemy_TauntWeaponData();
};

