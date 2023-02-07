#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_SkinFX.generated.h"

class UMaterialPermuterLoadingBundle;
class UNiagaraSystem;
class USkinFXComponent;

UCLASS(Blueprintable)
class USceneActionState_SkinFX : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMaterialPermuterLoadingBundle> MaterialBundle;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkinFXComponent> SkinFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName FXName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bHaveSetSkinFXBlueprintVariables;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bNeedsNiagaraOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraOverrideLoaded;
    
public:
    USceneActionState_SkinFX();
};

