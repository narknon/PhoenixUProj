#pragma once
#include "CoreMinimal.h"
#include "StencilManagerMatchActorName.h"
#include "StencilManagerMatchActorNameStartsWith.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class STENCILMANAGER_API UStencilManagerMatchActorNameStartsWith : public UStencilManagerMatchActorName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StartOfName;
    
    UStencilManagerMatchActorNameStartsWith();
};

