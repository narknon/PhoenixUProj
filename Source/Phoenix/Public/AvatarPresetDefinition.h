#pragma once
#include "CoreMinimal.h"
#include "CharacterPieceDefinition.h"
#include "EGenderEnum.h"
#include "Engine/DataAsset.h"
#include "EAvatarPresetType.h"
#include "AvatarPresetDefinition.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API UAvatarPresetDefinition : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAvatarPresetType PresetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGenderEnum Gender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FCharacterPieceDefinition> CharacterItems;
    
    UAvatarPresetDefinition();
};

