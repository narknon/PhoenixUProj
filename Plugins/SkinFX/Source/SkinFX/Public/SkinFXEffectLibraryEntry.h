#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SkinFXEffectLibraryEntry.generated.h"

class ASkinFXDefinition;

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXEffectLibraryEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASkinFXDefinition> Effect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FXName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TypeOverride;
    
    FSkinFXEffectLibraryEntry();
};

