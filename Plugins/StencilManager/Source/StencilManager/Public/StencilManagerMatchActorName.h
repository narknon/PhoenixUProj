#pragma once
#include "CoreMinimal.h"
#include "StencilManagerMatchActor.h"
#include "StencilManagerMatchActorName.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class STENCILMANAGER_API UStencilManagerMatchActorName : public UStencilManagerMatchActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreCase;
    
    UStencilManagerMatchActorName();
};

