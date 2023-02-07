#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyHiddenTeleportAttackComponent.generated.h"

class UMultiFX2Asset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemyHiddenTeleportAttackComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMultiFX2Asset* TargetLocationFxAsset;
    
    UEnemyHiddenTeleportAttackComponent();
};

