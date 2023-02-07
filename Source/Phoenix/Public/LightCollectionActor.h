#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightCollectionActor.generated.h"

class ULocalLightComponent;

UCLASS(Blueprintable, Transient)
class ALightCollectionActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ULocalLightComponent>> Lights;
    
    ALightCollectionActor();
};

