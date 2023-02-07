#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SpawnStoredWeaponStr.generated.h"

class AEnemyAIWeapon;

USTRUCT(BlueprintType)
struct FSpawnStoredWeaponStr {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AEnemyAIWeapon> weaponClassType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSkipSpawnStored;
    
    PHOENIX_API FSpawnStoredWeaponStr();
};

