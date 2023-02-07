#pragma once
#include "CoreMinimal.h"
#include "StencilManagerMatchActor.h"
#include "StencilManagerMatchActorOR.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UStencilManagerMatchActorOR : public UStencilManagerMatchActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStencilManagerMatchActor*> Expressions;
    
    UStencilManagerMatchActorOR();
};

