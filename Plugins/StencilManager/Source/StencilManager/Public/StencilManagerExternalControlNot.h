#pragma once
#include "CoreMinimal.h"
#include "StencilManagerExternalControl.h"
#include "StencilManagerExternalControlNot.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UStencilManagerExternalControlNot : public UStencilManagerExternalControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStencilManagerExternalControl* Control;
    
    UStencilManagerExternalControlNot();
};

