#pragma once
#include "CoreMinimal.h"
#include "EGenderEnum.h"
#include "Engine/DataTable.h"
#include "EAvatarPresetType.h"
#include "AvatarFullbodyPreset.generated.h"

class UAvatarPresetDefinition;

USTRUCT(BlueprintType)
struct FAvatarFullbodyPreset : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGenderEnum Gender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAvatarPresetType, TSoftObjectPtr<UAvatarPresetDefinition>> AvatarPresetDefinitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisplayInEditor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SortOrder;
    
    PHOENIX_API FAvatarFullbodyPreset();
};

