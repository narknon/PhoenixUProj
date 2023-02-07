#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapParameters.h"
#include "MaterialSwapRules.h"
#include "ESkinFXEnvelopeState.h"
#include "SkinFXASREnvelopeState.h"
#include "SkinFXParameterDriverContext.h"
#include "SkinFXRunningEffect.h"
#include "SkinFXRunningEffectInstance.generated.h"

class UMaterialSwap;
class UNiagaraMaterialSwapDriver;

USTRUCT(BlueprintType)
struct FSkinFXRunningEffectInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSkinFXRunningEffect Effect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSkinFXASREnvelopeState Envelope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSkinFXParameterDriverContext DriverContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraMaterialSwapDriver* NiagaraDriver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialSwap* MaterialSwap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialSwapRules MaterialSwapRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters HistoryParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters CommitBlueprintParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters StagedBlueprintParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 EventBroadcastMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ESkinFXEnvelopeState EnvelopeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bEnvelopeStateValid;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bHaveAppliedInitialParameters;
    
public:
    SKINFX_API FSkinFXRunningEffectInstance();
};

