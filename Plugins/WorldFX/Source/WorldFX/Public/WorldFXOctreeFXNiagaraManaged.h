#pragma once
#include "CoreMinimal.h"
#include "WorldFXOctreeFX.h"
#include "WorldFXOctreeFXNiagaraManaged.generated.h"

class UNiagaraComponent;

UCLASS(Blueprintable, NonTransient)
class WORLDFX_API UWorldFXOctreeFXNiagaraManaged : public UWorldFXOctreeFX {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UNiagaraComponent> NiagaraComponent;
    
    UWorldFXOctreeFXNiagaraManaged();
};

