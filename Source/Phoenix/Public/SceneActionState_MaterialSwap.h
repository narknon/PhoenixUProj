#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_MaterialSwap.generated.h"

class UMaterialPermuterLoadingBundle;
class UMaterialSwap;

UCLASS(Blueprintable)
class USceneActionState_MaterialSwap : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMaterialPermuterLoadingBundle> MaterialBundle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialSwap* MaterialSwap;
    
    USceneActionState_MaterialSwap();
};

