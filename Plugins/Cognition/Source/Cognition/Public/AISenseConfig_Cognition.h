#pragma once
#include "CoreMinimal.h"
#include "Perception/AISenseConfig.h"
#include "InputContextWithType.h"
#include "StencilManagerEffectName.h"
#include "AISenseConfig_Cognition.generated.h"

class UCogGroupBestTargetProcess;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class COGNITION_API UAISenseConfig_Cognition : public UAISenseConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputContextWithType> LogicContexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCogGroupBestTargetProcess*> BestTargetProcesses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStencilPerceivedTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerEffectName StencilEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerEffectName StencilOwnedEffect;
    
    UAISenseConfig_Cognition();
};

