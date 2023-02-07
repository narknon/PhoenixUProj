#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStatesBaseComponent.h"
#include "MaterialSwapRules.h"
#include "MaterialSwapMeshStatesRulesComponent.generated.h"

class UMaterialSwapMeshState;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UMaterialSwapMeshStatesRulesComponent : public UMaterialSwapMeshStatesBaseComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshState*> MeshStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapRules Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdateOnTick;
    
    UMaterialSwapMeshStatesRulesComponent();
};

