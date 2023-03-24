#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HighContrastGameplayMarkupOtherActor.generated.h"

class UHighContrastGameplayMarkupOtherActorComponent;

UCLASS(Blueprintable)
class AHighContrastGameplayMarkupOtherActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHighContrastGameplayMarkupOtherActorComponent* Component;
    
    AHighContrastGameplayMarkupOtherActor(const FObjectInitializer& ObjectInitializer);
};

