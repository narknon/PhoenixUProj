#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StencilManagerSkinFXColor.generated.h"

USTRUCT(BlueprintType)
struct FStencilManagerSkinFXColor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MaterialParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    STENCILMANAGER_API FStencilManagerSkinFXColor();
};

