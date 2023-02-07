#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterLightRigAdjustments.h"
#include "CharacterLightRigAdjustmentsSettings.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API UCharacterLightRigAdjustmentsSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCharacterLightRigAdjustments> Settings;
    
    UCharacterLightRigAdjustmentsSettings();
};

