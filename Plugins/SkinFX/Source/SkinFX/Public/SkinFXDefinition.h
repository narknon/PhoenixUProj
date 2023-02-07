#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MaterialSwapRules.h"
#include "ESkinFXEffectPriority.h"
#include "ESkinFXEffectSwapType.h"
#include "ESkinFXEffectTimeSource.h"
#include "NiagaraMaterialDriverSetup.h"
#include "SkinFXASREnvelope.h"
#include "SkinFXColor.h"
#include "SkinFXColorCurve.h"
#include "SkinFXFunctionMod.h"
#include "SkinFXNoiseFunctionMod.h"
#include "SkinFXScalar.h"
#include "SkinFXScalarCurve.h"
#include "SkinFXSocket.h"
#include "SkinFXSocketLerp.h"
#include "SkinFXStandardParams.h"
#include "SkinFXStandardParamsInitial.h"
#include "SkinFXSubTypeProperty.h"
#include "SkinFXTexture.h"
#include "SkinFXDefinition.generated.h"

class UMaterialInterface;
class UMaterialSwapMeshState;
class UObject;
class USkinFXEventTrigger;
class USkinFXParameterDriver;

UCLASS(Abstract, Blueprintable, NotPlaceable)
class SKINFX_API ASkinFXDefinition : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXEffectPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MaterialSuffixOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXSubTypeProperty MaterialSubTypeOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXEffectSwapType SwapType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> OverrideMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapRules DefaultSwapRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshState*> DefaultMeshStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXASREnvelope ASREnvelope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USkinFXEventTrigger*> EventTriggers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXScalar> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXScalarCurve> ScalarCurves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXColor> Colors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXColorCurve> ColorCurves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXSocket> Sockets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXSocketLerp> LerpSockets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXTexture> Textures;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USkinFXParameterDriver*> Drivers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXFunctionMod> FunctionMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXNoiseFunctionMod> NoiseFunctionMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraMaterialDriverSetup NiagaraParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXStandardParamsInitial StandardParamsStartOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXStandardParams StandardParamsEveryFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UObject>> ExtraPreloads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowInBackground;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXEffectTimeSource TimeSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyActorWhenDone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFullRetriggerOnRestart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowSwapErrors;
    
    ASkinFXDefinition();
};

