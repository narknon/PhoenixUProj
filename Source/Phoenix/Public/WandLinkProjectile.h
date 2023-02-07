#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WandLinkProjectile.generated.h"

class UNiagaraComponent;

UCLASS(Blueprintable)
class AWandLinkProjectile : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* VFXComponent;
    
    AWandLinkProjectile();
};

