#pragma once
#include "CoreMinimal.h"
#include "StencilManagerMatchActor.h"
#include "StencilManagerMatchActorIF.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UStencilManagerMatchActorIF : public UStencilManagerMatchActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStencilManagerMatchActor* Expression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStencilManagerMatchActor* ExpressionTrue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStencilManagerMatchActor* ExpressionFalse;
    
    UStencilManagerMatchActorIF();
};

