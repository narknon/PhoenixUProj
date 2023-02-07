#pragma once
#include "CoreMinimal.h"
#include "StencilManagerExternalControl.h"
#include "StencilManagerExternalControlLogicList.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UStencilManagerExternalControlLogicList : public UStencilManagerExternalControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStencilManagerExternalControl*> Controls;
    
    UStencilManagerExternalControlLogicList();
};

