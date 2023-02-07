#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AvatarHouse.h"
#include "EHoodPosition.h"
#include "FullbodyAvatarPreset.h"
#include "GearBackSlotName.h"
#include "GearFaceSlotName.h"
#include "GearHandSlotName.h"
#include "GearHeadSlotName.h"
#include "GearNeckSlotName.h"
#include "GearOutfitSlotName.h"
#include "HumanCharacterId.h"
#include "AvatarPresetsSettings.generated.h"

UCLASS(Blueprintable, Config=EditorPerProjectUserSettings)
class PHOENIX_API UAvatarPresetsSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHumanCharacterId DefaultPIECharacter;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFullbodyAvatarPreset DefaultPIEFullBodyPreset;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearHeadSlotName DefaultPIEHeadGear;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearOutfitSlotName DefaultPIEOutfitGear;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearBackSlotName DefaultPIEBackGear;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHoodPosition DefaultPIEHoodPosition;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearNeckSlotName DefaultPIENeckGear;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearHandSlotName DefaultPIEHandGear;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearFaceSlotName DefaultPIEFaceGear;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvatarHouse DefaultPIEHouse;
    
    UAvatarPresetsSettings();
};

