#pragma once
#include "CoreMinimal.h"
#include "AISenseConfig_NPC.h"
#include "Templates/SubclassOf.h"
#include "AISenseConfig_EnemyAIWeapon.generated.h"

class APerceptionPointArea;
class UAISense_EnemyAIWeapon;

UCLASS(Blueprintable, EditInlineNew)
class UAISenseConfig_EnemyAIWeapon : public UAISenseConfig_NPC {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NoClear, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAISense_EnemyAIWeapon> Implementation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideDistanceRequirement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceiveRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APerceptionPointArea*> PerceiveVolumeList;
    
    UAISenseConfig_EnemyAIWeapon();
};

