#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneActionState_NiagaraSystem.generated.h"

class UNiagaraComponent;

UCLASS(Blueprintable)
class USceneActionState_NiagaraSystem : public USceneRigActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraComponent;
    
    USceneActionState_NiagaraSystem();
};

