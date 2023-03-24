#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CreatureEgg.generated.h"

class UObjectStateComponent;

UCLASS(Blueprintable)
class ACreatureEgg : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjectStateComponent* ObjectStateComponent;
    
    ACreatureEgg(const FObjectInitializer& ObjectInitializer);
};

