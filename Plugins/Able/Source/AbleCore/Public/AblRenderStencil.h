#pragma once
#include "CoreMinimal.h"
#include "StencilManagerEffectName.h"
#include "AblAbilityTask.h"
#include "AblRenderStencil.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblRenderStencil : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerEffectName StencilEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool resetStencilOnExit;
    
public:
    UAblRenderStencil();
};

