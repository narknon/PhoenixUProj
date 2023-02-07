#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapParameters.h"
#include "MaterialSwapRules.h"
#include "MultiFX2_Filtered.h"
#include "ESkinFXEffectEndStyle.h"
#include "NiagaraMaterialDriverSetup.h"
#include "SkinFXASREnvelope.h"
#include "MultiFX2_SkinFxImpactOptions.h"
#include "Templates/SubclassOf.h"
#include "MultiFX2_SkinFx.generated.h"

class ASkinFXDefinition;
class UMaterialSwapMeshState;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_SkinFx : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASkinFXDefinition> SkinFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters Params;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapRules Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXASREnvelope EnvelopeOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraMaterialDriverSetup NiagaraOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshState*> OverrideMeshStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXEffectEndStyle EndStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFX2_SkinFxImpactOptions ImpactOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseEnvelopeOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseNiagaraOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseMeshStatesOverride;
    
public:
    UMultiFX2_SkinFx();
};

