#pragma once
#include "CoreMinimal.h"
#include "StencilManagerMatchActorName.h"
#include "StencilManagerMatchActorNameContains.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class STENCILMANAGER_API UStencilManagerMatchActorNameContains : public UStencilManagerMatchActorName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CONTAINS;
    
    UStencilManagerMatchActorNameContains();
};

