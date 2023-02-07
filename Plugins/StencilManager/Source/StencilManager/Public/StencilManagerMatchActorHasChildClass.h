#pragma once
#include "CoreMinimal.h"
#include "StencilManagerMatchActor.h"
#include "StencilManagerMatchActorHasChildClass.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class STENCILMANAGER_API UStencilManagerMatchActorHasChildClass : public UStencilManagerMatchActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ChildClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowSubclasses;
    
    UStencilManagerMatchActorHasChildClass();
};

