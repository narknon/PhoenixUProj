#pragma once
#include "CoreMinimal.h"
#include "MultiVfxSfx.h"
#include "Templates/SubclassOf.h"
#include "MultiFX.generated.h"

class ASkinFXDefinition;

USTRUCT(BlueprintType)
struct FMultiFX : public FMultiVfxSfx {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASkinFXDefinition> SkinFX;
    
    PHOENIX_API FMultiFX();
};

