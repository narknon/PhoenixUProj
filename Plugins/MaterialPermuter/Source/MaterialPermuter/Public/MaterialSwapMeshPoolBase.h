#pragma once
#include "CoreMinimal.h"
#include "MaterialSwap.h"
#include "MaterialSwapMeshStatesAndData.h"
#include "MeshMaterialSwap.h"
#include "MaterialSwapMeshPoolBase.generated.h"

class UMeshComponent;

UCLASS(Abstract, Blueprintable, NonTransient)
class MATERIALPERMUTER_API UMaterialSwapMeshPoolBase : public UMaterialSwap {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UMeshComponent>, FMeshMaterialSwap> SwappedMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialSwapMeshStatesAndData MeshStates;
    
public:
    UMaterialSwapMeshPoolBase();
};

