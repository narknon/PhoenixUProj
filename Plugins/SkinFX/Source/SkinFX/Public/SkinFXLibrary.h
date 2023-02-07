#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SkinFXEffectLibraryEntry.h"
#include "SkinFXEffectTypeOverrideEntry.h"
#include "SkinFXLibrary.generated.h"

UCLASS(Blueprintable)
class SKINFX_API USkinFXLibrary : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXEffectTypeOverrideEntry> TypeOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXEffectLibraryEntry> EffectEntries;
    
    USkinFXLibrary();
};

