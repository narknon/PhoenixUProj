#pragma once
#include "CoreMinimal.h"
#include "AvatarHouse.h"
#include "FullbodyAvatarPreset.h"
#include "GearBackSlotName.h"
#include "GearHandSlotName.h"
#include "GearHeadSlotName.h"
#include "GearNeckSlotName.h"
#include "GearOutfitSlotName.h"
#include "GenderVoice.h"
#include "HumanCharacterId.h"
#include "CinematicAvatarSettings.generated.h"

USTRUCT(BlueprintType)
struct FCinematicAvatarSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHumanCharacterId Character;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFullbodyAvatarPreset FullBodyPreset;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGenderVoice GenderVoice;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearHeadSlotName HeadGear;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearOutfitSlotName OutfitGear;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearBackSlotName BackGear;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearNeckSlotName NeckGear;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearHandSlotName HandGear;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvatarHouse House;
    
    PHOENIX_API FCinematicAvatarSettings();
};

