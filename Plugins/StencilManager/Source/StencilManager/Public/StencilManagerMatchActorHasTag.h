#pragma once
#include "CoreMinimal.h"
#include "StencilManagerMatchActor.h"
#include "StencilManagerMatchActorHasTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class STENCILMANAGER_API UStencilManagerMatchActorHasTag : public UStencilManagerMatchActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeChildActors;
    
    UStencilManagerMatchActorHasTag();
};

