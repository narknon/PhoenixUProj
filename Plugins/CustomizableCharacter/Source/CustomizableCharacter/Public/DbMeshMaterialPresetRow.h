#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DbMeshMaterialPresetRow.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FDbMeshMaterialPresetRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MeshName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PresetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FString> Params;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    CUSTOMIZABLECHARACTER_API FDbMeshMaterialPresetRow();
};

