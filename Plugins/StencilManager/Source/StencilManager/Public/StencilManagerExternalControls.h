#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StencilManagerExternalControls.generated.h"

class UStencilManagerExternalControl;

UCLASS(Blueprintable)
class STENCILMANAGER_API UStencilManagerExternalControls : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStencilManagerExternalControl* SystemEnable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FName, UStencilManagerExternalControl*> GroupEnable;
    
    UStencilManagerExternalControls();
};

