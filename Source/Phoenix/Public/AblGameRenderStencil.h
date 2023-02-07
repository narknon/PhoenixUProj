#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "StencilManagerEffectName.h"
#include "AblGameRenderStencil.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblGameRenderStencil : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerEffectName StencilEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool resetStencilOnExit;
    
public:
    UAblGameRenderStencil();
};

