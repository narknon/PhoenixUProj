#pragma once
#include "CoreMinimal.h"
#include "StencilManagerSkinFXColor.h"
#include "Templates/SubclassOf.h"
#include "StencilManagerSkinFX.generated.h"

class ASkinFXDefinition;

USTRUCT(BlueprintType)
struct FStencilManagerSkinFX {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASkinFXDefinition> SkinFX;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerSkinFXColor ForceEmissiveColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceEmissive;
    
    STENCILMANAGER_API FStencilManagerSkinFX();
};

