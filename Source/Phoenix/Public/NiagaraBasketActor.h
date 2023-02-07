#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraBasketActor.generated.h"

class UNiagaraComponent;

UCLASS(Blueprintable, Transient)
class ANiagaraBasketActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UNiagaraComponent>> Components;
    
    ANiagaraBasketActor();
};

