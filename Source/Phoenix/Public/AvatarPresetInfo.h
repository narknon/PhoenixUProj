#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AvatarPresetIconInfo.h"
#include "AvatarPresetPieceInfo.h"
#include "AvatarPresetInfo.generated.h"

USTRUCT(BlueprintType)
struct FAvatarPresetInfo : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAvatarPresetPieceInfo> Meshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvatarPresetIconInfo MaleIconInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvatarPresetIconInfo FemaleIconInfo;
    
    PHOENIX_API FAvatarPresetInfo();
};

