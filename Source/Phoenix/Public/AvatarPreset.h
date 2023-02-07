#pragma once
#include "CoreMinimal.h"
#include "EGenderEnum.h"
#include "Engine/DataTable.h"
#include "EAvatarPresetType.h"
#include "AvatarPreset.generated.h"

class UAvatarPresetDefinition;

USTRUCT(BlueprintType)
struct PHOENIX_API FAvatarPreset : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAvatarPresetType PresetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGenderEnum Gender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAvatarPresetDefinition> AvatarPresetDefinition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisplayInEditor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SortOrder;
    
    FAvatarPreset();
};

