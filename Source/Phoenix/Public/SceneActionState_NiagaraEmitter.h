#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_NiagaraEmitter.generated.h"

class UNiagaraComponent;

UCLASS(Blueprintable)
class USceneActionState_NiagaraEmitter : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraComponent;
    
    USceneActionState_NiagaraEmitter();
};

