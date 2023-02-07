#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AncientMagicEffect.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAncientMagicEffect : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LockPlayerWhileActive;
    
    UAncientMagicEffect();
};

