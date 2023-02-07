#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PerkInfoFX.h"
#include "PerksSettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class UPerksSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FPerkInfoFX> PerkFXMap;
    
    UPerksSettings();
};

